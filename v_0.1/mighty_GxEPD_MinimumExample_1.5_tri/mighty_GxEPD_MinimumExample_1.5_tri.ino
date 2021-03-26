// GxEPD_MinimumExample by Jean-Marc Zingg

#include <GxEPD.h>

// select the display class to use, only one
//#include <GxGDEP015OC1/GxGDEP015OC1.h>    // 1.54" b/w
//#include <GxGDEH0154D67/GxGDEH0154D67.h>  // 1.54" b/w
//#include <GxGDEW0154Z04/GxGDEW0154Z04.h>  // 1.54" b/w/r 200x200
#include <GxGDEW0154Z17/GxGDEW0154Z17.h>  // 1.54" b/w/r 152x152

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

GxIO_Class io(SPI, /*CS=*/ A1, /*DC=*/ A0, /*RST=*/ A3); // arbitrary selection of 8, 9 selected for default of GxEPD_Class
GxEPD_Class display(io, /*RST=*/ A3, /*BUSY=*/ -1); // default selection of (9), 7

void setup()
{
  display.init();
  display.eraseDisplay();
  // comment out next line to have no or minimal Adafruit_GFX code
  display.drawPaged(drawHelloWorld); // version for AVR using paged drawing, works also on other processors
}

void drawHelloWorld()
{
  display.setTextColor(GxEPD_BLACK);
  display.print("Hello World!");
}

void loop() {};
