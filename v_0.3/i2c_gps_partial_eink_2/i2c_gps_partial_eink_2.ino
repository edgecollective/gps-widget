/*
  Read NMEA sentences over I2C using u-blox module SAM-M8Q, NEO-M8P, etc
  By: Nathan Seidle
  SparkFun Electronics
  Date: August 22nd, 2018
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example reads the NMEA characters over I2C and pipes them to MicroNMEA
  This example will output your current long/lat and satellites in view
 
  Feel like supporting open source hardware?
  Buy a board from SparkFun!
  ZED-F9P RTK2: https://www.sparkfun.com/products/15136
  NEO-M8P RTK: https://www.sparkfun.com/products/15005
  SAM-M8Q: https://www.sparkfun.com/products/15106

  For more MicroNMEA info see https://github.com/stevemarple/MicroNMEA

  Hardware Connections:
  Plug a Qwiic cable into the GNSS and a BlackBoard
  If you don't have a platform with a Qwiic connection use the SparkFun Qwiic Breadboard Jumper (https://www.sparkfun.com/products/14425)
  Open the serial monitor at 115200 baud to see the output
  Go outside! Wait ~25 seconds and you should see your lat/long
*/

#include <Wire.h> //Needed for I2C to GNSS
#include <SparkFun_u-blox_GNSS_Arduino_Library.h> //http://librarymanager/All#SparkFun_u-blox_GNSS
SFE_UBLOX_GNSS myGNSS;
#include <MicroNMEA.h> //http://librarymanager/All#MicroNMEA
char nmeaBuffer[100];
MicroNMEA nmea(nmeaBuffer, sizeof(nmeaBuffer));

// include library, include base class, make path known
#include <GxEPD.h>

// select the display class to use, only one
#include <GxGDEH0154D67/GxGDEH0154D67.h>  // 1.54" b/w

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>

#include GxEPD_BitmapExamples

#define DELAY_TIME 10000

GxIO_Class io(SPI, /*CS=*/ 10, /*DC=*/ 9, /*RST=*/ 6);
GxEPD_Class display(io, /*RST=*/ 6, /*BUSY=*/ 5);

int x = 10; // x position of the marker
int y = 10; // y "
 
int max_x = 200; // width of the gridsquare in pixels on the display
int max_y = 133; // height "

float xfrac=0; // fractional position (of max_x) of the marker on the gridsquare
float yfrac=0; // " (of max_y) "


char locator[9]; // gridsquare locator
char old_locator[9];

float unit = 0.004166666666666667;

char * getLocator(float lat, float lon, int precision) {
  
  float ydiv_arr[] = {10,1,0.04166666666,0.00416666666,0.00017361111};
  char d1[]="ABCDEFGHIJKLMNOPQR";
  char d2[]="ABCDEFGHIJKLMNOPQRSTUVWX";

  int this_precision = 4;

  strcpy(locator,"");
  
  float q = lon;
  float p = lat;
  float rlon,rlat;
  char cstr[]="1";
  int num;
  
  while (q < -180) {q += 360;}
      while (q > 180) {q -=360;}
      q = q + 180;
      p = p + 90;
      
      strncat(locator,&d1[(int) floor(q/20)],1);
      
      strncat(locator, &d1[(int) floor(p/10)],1);
  
   
      for (int i=0; i<4; i=i+1) {
    if (this_precision > i+1) {
        rlon = fmod(q,ydiv_arr[i]*2);
        rlat = fmod(p,ydiv_arr[i]);
      if ((i%2)==0) {
        num = floor(rlon/(ydiv_arr[i+1]*2));
        itoa(num, cstr, 10);

        strcat(locator,cstr);
        strcat(locator,"");
        num = floor(rlat/(ydiv_arr[i+1]));
        itoa(num, cstr, 10);
        strcat(locator,cstr);

      } else {

        strncat(locator,&d2[(int) floor(rlon/(ydiv_arr[i+1]*2))],1);
        strcat(locator,"");
        strncat(locator,&d2[(int) floor(rlat/(ydiv_arr[i+1]))],1);
      }
    }
    }  
    return (locator);
}


void setup()
{
  Serial.begin(115200);
  Serial.println("SparkFun u-blox Example");

  Wire.begin();

  if (myGNSS.begin() == false)
  {
    Serial.println(F("u-blox GNSS not detected at default I2C address. Please check wiring. Freezing."));
    while (1);
  }

  display.init(115200); // enable diagnostic output on Serial
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.update();

  

x=30;
y=30;

}


int w = 3;
int h = 3;


int initial_loop = 1;

int loopcount=0;

void loop()
{

  
  myGNSS.checkUblox(); //See if new data is available. Process bytes as they come in.

  if(nmea.isValid() == true)
  {

    
    loopcount++;
    Serial.println();
    Serial.println("--------------------");
    Serial.print("loopcount=");
    Serial.println(loopcount);

    long latitude_mdeg = nmea.getLatitude();
    long longitude_mdeg = nmea.getLongitude();

    float flat;
    float flon;

    flat = latitude_mdeg / 1000000.;
    flon = longitude_mdeg / 1000000.;

    if(loopcount==-1) {
      Serial.println("forced!");
      flat = 42.4112;
      flon = -71.23;
    }
    
    Serial.print("Latitude (deg): ");
    Serial.println(latitude_mdeg / 1000000., 6);
    Serial.print("Longitude (deg): ");
    Serial.println(longitude_mdeg / 1000000., 6);
    
  if (initial_loop) {
    getLocator(flat,flon,4);
    draw_grid();
    display_locator();
    strcpy(old_locator, locator);
    display.update();
    initial_loop=0;
  }
  else{
    getLocator(flat,flon,4);
    Serial.print("new_locator:");
    Serial.println(locator);
    // only update if there's a change of gridsquare
    Serial.print("comparison:");
    Serial.print(locator);
    Serial.print(" and ");
    Serial.println(old_locator);
    Serial.print("strcmp:");
    Serial.println(strcmp(locator,old_locator));
    if(strcmp(locator,old_locator)!=0) {
      strcpy(old_locator, locator);
      Serial.print("updated old_locator to:");
      Serial.println(locator);
      display.fillScreen(GxEPD_WHITE);
      draw_grid();
      display_locator();
      display.update();
    }
  }


    float myLat = flat;
    if (myLat > 85) myLat = 85;
    if (myLat < -85) myLat = -85;
  
    //find lat/lon bounds of the gridsquare
    float lon_left = floor(flon/(unit*2))*(unit*2);
    float lon_right = ceil(flon/(unit*2))*(unit*2);
    float lat_top = ceil(myLat/unit)*unit;
    float lat_bottom=floor(myLat/unit)*unit;
  
    float xfrac = (flon-lon_left)/(lon_right-lon_left);
    
    float yfrac = 1-(flat-lat_bottom)/(lat_top-lat_bottom);
  
    x=round(xfrac*max_x);
    y=round(yfrac*max_y);

  
    placePoint(x,y,w,h);
    delay(DELAY_TIME);
    
    //x=x-3+2*random(0,3);
    //y=y-3+2*random(0,3);

    
  }
  else
  {
    Serial.print("No Fix - ");
    Serial.print("Num. satellites: ");
    Serial.println(nmea.getNumSatellites());
  }

delay(300); //Don't pound too hard on the I2C bus

}

void draw_grid() {

   //big frame
  display.drawLine(0,0,max_x,0,GxEPD_BLACK);
  display.drawLine(0,max_y,max_x,max_y,GxEPD_BLACK);

  //minor frame
  display.drawLine(0,round(max_y/2),max_x,round(max_y/2),GxEPD_BLACK);
  display.drawLine(round(max_x/2),0,round(max_x/2),max_y,GxEPD_BLACK);
  display.update();

}

void display_locator() {

  int current_y = max_y;
  int step_y = 10;
  int current_x = 5;
  
    display.setTextWrap(false);

  display.setTextSize(2);
  current_y=current_y+5;
  display.setCursor(current_x, current_y);
  display.setTextColor(GxEPD_BLACK);
  //display.print(" GS: ");
  display.print(locator);
  //display.update();
}
  
void placePoint(int box_x,int box_y,int box_w,int box_h) {
  display.fillRect(box_x, box_y, box_w, box_h, GxEPD_BLACK);
  display.updateWindow(box_x, box_y, box_w, box_h, true);
  //display.update();
  
}

//This function gets called from the SparkFun u-blox Arduino Library
//As each NMEA character comes in you can specify what to do with it
//Useful for passing to other libraries like tinyGPS, MicroNMEA, or even
//a buffer, radio, etc.
void SFE_UBLOX_GNSS::processNMEA(char incoming)
{
  //Take the incoming char from the u-blox I2C port and pass it on to the MicroNMEA lib
  //for sentence cracking
  nmea.process(incoming);
}
