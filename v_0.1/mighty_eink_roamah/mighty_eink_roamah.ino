/***************************************************
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#include "Adafruit_EPD.h"
#include <SoftwareSerial.h>
#include <TinyGPS.h>

TinyGPS gps;

SoftwareSerial ss(14, 15); //rx,tx

#define EPD_CS     22
#define EPD_DC     21
#define SRAM_CS     20
#define EPD_RESET   19 // can set to -1 and share with microcontroller Reset!
#define EPD_BUSY    18 // can set to -1 to not use a pin (will wait a fixed delay)

Adafruit_IL0373 display(152, 152, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);

#define COLOR1 EPD_BLACK
#define COLOR2 EPD_RED

int x = 10; // x position of the marker
int y = 10; // y "
 
int max_x = 150; // width of the gridsquare in pixels on the display
int max_y = 100; // height "

float xfrac=0; // fractional position (of max_x) of the marker on the gridsquare
float yfrac=0; // " (of max_y) "

char locator[9]; // gridsquare locator

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


void display_map(float lat, float lon, uint8_t max_x, uint8_t max_y, uint8_t x, uint8_t y, char locator[]) {

  display.clearBuffer();

  //big frame
  display.drawLine(0,0,max_x,0,COLOR1);
  display.drawLine(0,max_y,max_x,max_y,COLOR1);

  //minor frame
  display.drawLine(0,round(max_y/2),max_x,round(max_y/2),COLOR2);
  display.drawLine(round(max_x/2),0,round(max_x/2),max_y,COLOR2);


  display.drawCircle(x, y, 6, COLOR1);
  display.fillCircle(x, y, 3, COLOR2);

  // info display
  //display.drawLine(90,max_y,90,150,COLOR2);

  int current_y = max_y;
  int step_y = 10;
  int current_x = 5;

  display.setTextWrap(false);

  display.setTextSize(2);
  current_y=current_y+5;
  display.setCursor(current_x, current_y);
  display.setTextColor(COLOR2);
  //display.print(" GS: ");
  display.print(locator);

  display.setTextSize(1);
  current_y=current_y+step_y*2;
  display.setCursor(current_x,current_y);
  display.setTextColor(COLOR1);
  display.print("lat: ");
  display.print(lat);
  
  current_y=current_y+step_y;
  display.setCursor(current_x,current_y);
  display.setTextColor(COLOR1);
  display.print("lon: ");
  display.print(lon);
  


  
  
  display.display();

  /*
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(0, 0, i, display.height()-1, COLOR1);
  }

  for (int16_t i=0; i<display.height(); i+=4) {
    display.drawLine(display.width()-1, 0, 0, i, COLOR2);  // on grayscale this will be mid-gray
  }
  */
  
}

void initial_frame(uint8_t max_x, uint8_t max_y) {

/*
  u8g2.drawFrame(0,0,max_x,max_y);

  u8g2.setFontDirection(1);
  u8g2.drawStr(105, 8,"GPS ...");

  u8g2.drawFrame(max_x-1,0,13,max_y);
  
  u8g2.setFontDirection(0);
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.drawStr(113, 1, "N");

  u8g2.setFont(u8g2_font_unifont_t_symbols);
  u8g2.setFontPosTop();
  u8g2.drawUTF8(111, 12, "↑");
*/

}

void setup() {
  Serial.begin(115200);
  //while (!Serial) { delay(10); }
  Serial.println("Adafruit EPD test");

  ss.begin(9600);
  
  display.begin();

  // large block of text
  display.clearBuffer();
  testdrawtext("Warming up ...", COLOR1);
  display.display();

  //delay(5000);

  

  
  
  
}

void loop() {

  
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;


  // For one second we parse GPS data and report some key values
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (ss.available())
    {
      char c = ss.read();
      // Serial.write(c); // uncomment this line if you want to see the GPS data flowing
      if (gps.encode(c)) // Did a new valid sentence come in?
        newData = true;
    }
  }
  
 if (newData)
  {

  float flat, flon;
  unsigned long age;
  gps.f_get_position(&flat, &flon, &age);
  
  //flat =44.42849861396812;
  //flon =-69.00385950557286;
  
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
    
  Serial.println(getLocator(flat,flon, 4));
  
  display_map(flat,flon,max_x,max_y,x,y,getLocator(flat,flon, 4));

  delay(180000);
}

  gps.stats(&chars, &sentences, &failed);
  
  if (chars == 0)
    Serial.println("** No characters received from GPS: check wiring **");
    
}


void testdrawtext(char *text, uint16_t color) {
  display.setCursor(0, 0);
  display.setTextColor(color);
  display.setTextWrap(true);
  display.print(text);
}
