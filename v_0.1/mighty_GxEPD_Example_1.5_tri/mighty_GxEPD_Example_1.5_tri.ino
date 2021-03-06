// GxEPD_Example : test example for e-Paper displays from Waveshare and from Dalian Good Display Inc.


// include library, include base class, make path known
#include <GxEPD.h>

// select the display class to use, only one
//#include <GxGDEP015OC1/GxGDEP015OC1.h>    // 1.54" b/w
//#include <GxGDEH0154D67/GxGDEH0154D67.h>  // 1.54" b/w
//#include <GxGDEW0154Z04/GxGDEW0154Z04.h>  // 1.54" b/w/r 200x200
#include <GxGDEW0154Z17/GxGDEW0154Z17.h>  // 1.54" b/w/r 152x152

#include GxEPD_BitmapExamples

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>


#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

GxIO_Class io(SPI, /*CS=*/ A1, /*DC=*/ A0, /*RST=*/ A3); // arbitrary selection of 8, 9 selected for default of GxEPD_Class
GxEPD_Class display(io, /*RST=*/ A3, /*BUSY=*/ -1); // default selection of (9), 7


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");

  display.init(115200); // enable diagnostic output on Serial

  Serial.println("setup done");
}

void loop()
{
  showBitmapExample();
  delay(2000);
#if !defined(__AVR)
  //drawCornerTest();
  showFont("FreeMonoBold9pt7b", &FreeMonoBold9pt7b);
  showFont("FreeMonoBold12pt7b", &FreeMonoBold12pt7b);
  //showFont("FreeMonoBold18pt7b", &FreeMonoBold18pt7b);
  //showFont("FreeMonoBold24pt7b", &FreeMonoBold24pt7b);
#else
  display.drawCornerTest();
  delay(2000);
  display.drawPaged(showFontCallback);
#endif
  delay(10000);
}

#if defined(_GxGDEP015OC1_H_)
void showBitmapExample()
{
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2));
  delay(5000);
  display.fillScreen(GxEPD_WHITE);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
  delay(5000);
  showBoat();
}
#endif

#if defined(_GxGDEH0154D67_H_)
void showBitmapExample()
{
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2));
  delay(5000);
  display.fillScreen(GxEPD_WHITE);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
  delay(5000);
  showBoat();
}
#endif

#if defined(_GxGDEW0154Z04_H_)
#define HAS_RED_COLOR
void showBitmapExample()
{
#if !defined(__AVR)
  display.drawPicture(BitmapWaveshare_black, BitmapWaveshare_red, sizeof(BitmapWaveshare_black), sizeof(BitmapWaveshare_red), GxEPD::bm_normal);
  delay(5000);
#endif
  display.drawExamplePicture(BitmapExample1, BitmapExample2, sizeof(BitmapExample1), sizeof(BitmapExample2));
  delay(5000);
}
#endif

#if defined(_GxGDEW0154Z17_H_)
#define HAS_RED_COLOR
void showBitmapExample()
{
  display.drawExamplePicture(BitmapExample1, BitmapExample2, sizeof(BitmapExample1), sizeof(BitmapExample2));
  delay(5000);
  display.drawExamplePicture(BitmapExample3, BitmapExample4, sizeof(BitmapExample1), sizeof(BitmapExample2));
  delay(5000);
  //display.drawBitmap(BitmapExample2, sizeof(BitmapExample2));
}
#endif

#if defined(_GxGDE0213B1_H_)
void showBitmapExample()
{
  display.drawBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.drawBitmap(BitmapExample2, sizeof(BitmapExample2));
  delay(5000);
#if !defined(__AVR)
  display.drawBitmap(first, sizeof(first));
  delay(5000);
  display.drawBitmap(second, sizeof(second));
  delay(5000);
  display.drawBitmap(third, sizeof(third));
  delay(5000);
#endif
  display.fillScreen(GxEPD_WHITE);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
  delay(5000);
  showBoat();
}
#endif

#if defined(_GxGDEH0213B72_H_) || defined(_GxGDEH0213B73_H_)
void showBitmapExample()
{
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2));
  delay(5000);
#if !defined(__AVR)
  display.drawExampleBitmap(BitmapExample3, sizeof(BitmapExample3));
  delay(5000);
  display.drawExampleBitmap(logo, sizeof(logo));
  delay(5000);
  display.drawExampleBitmap(first, sizeof(first));
  delay(5000);
  display.drawExampleBitmap(second, sizeof(second));
  delay(5000);
  display.drawExampleBitmap(third, sizeof(third));
  delay(5000);
#endif
  display.fillScreen(GxEPD_WHITE);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
  delay(5000);
  showBoat();
}
#endif

#if defined(_GxGDEW0213I5F_H_)
void showBitmapExample()
{
  display.drawBitmap(BitmapExample1, sizeof(BitmapExample1), GxEPD::bm_invert);
  delay(5000);
  display.drawBitmap(BitmapExample2, sizeof(BitmapExample2));
  delay(5000);
#if !defined(__AVR)
  display.drawBitmap(BitmapExample3, sizeof(BitmapExample3));
  delay(5000);
  display.drawBitmap(BitmapExample4, sizeof(BitmapExample4));
  delay(5000);
#endif
  display.fillScreen(GxEPD_WHITE);
  display.drawBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
  delay(5000);
}
#endif

#if defined(_GxGDEW0213Z16_H_)
#define HAS_RED_COLOR
void showBitmapExample()
{
  display.drawPicture(BitmapWaveshare_black, BitmapWaveshare_red, sizeof(BitmapWaveshare_black), sizeof(BitmapWaveshare_red));
  delay(5000);
  display.drawExamplePicture(BitmapExample1, BitmapExample2, sizeof(BitmapExample1), sizeof(BitmapExample2));
  delay(5000);
#if !defined(__AVR)
  display.drawExamplePicture(BitmapExample3, BitmapExample4, sizeof(BitmapExample3), sizeof(BitmapExample4));
  delay(5000);
#endif
  display.drawExampleBitmap(BitmapWaveshare_black, sizeof(BitmapWaveshare_black));
  delay(2000);
  // example bitmaps for b/w/r are normal on b/w, but inverted on red
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2), GxEPD::bm_invert);
  delay(2000);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
}
#endif

#if defined(_GxGDEH029A1_H_)
void showBitmapExample()
{
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2));
  delay(5000);
  display.fillScreen(GxEPD_WHITE);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
  delay(5000);
  showBoat();
}
#endif

#if defined(_GxGDEW029T5_H_)
void showBitmapExample()
{
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2));
  delay(5000);
  display.drawExampleBitmap(BitmapExample3, sizeof(BitmapExample3));
  delay(5000);
  display.fillScreen(GxEPD_WHITE);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
  delay(5000);
  //  showBoat();
}
#endif

#if defined(_GxGDEW029Z10_H_)
#define HAS_RED_COLOR
void showBitmapExample()
{
#if defined(__AVR)
  display.drawExamplePicture(BitmapExample1, BitmapExample2, sizeof(BitmapExample1), sizeof(BitmapExample2));
  delay(5000);
#else
  display.drawPicture(BitmapWaveshare_black, BitmapWaveshare_red, sizeof(BitmapWaveshare_black), sizeof(BitmapWaveshare_red));
  delay(5000);
  display.drawExamplePicture(BitmapExample1, BitmapExample2, sizeof(BitmapExample1), sizeof(BitmapExample2));
  delay(5000);
  display.drawExamplePicture(BitmapExample3, BitmapExample4, sizeof(BitmapExample3), sizeof(BitmapExample4));
  delay(5000);
  display.drawExampleBitmap(BitmapWaveshare_black, sizeof(BitmapWaveshare_black));
  delay(2000);
  // example bitmaps for b/w/r are normal on b/w, but inverted on red
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2), GxEPD::bm_invert);
  delay(2000);
#endif
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
}
#endif

#if defined(_GxGDEW026T0_H_)
void showBitmapExample()
{
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
#if !defined(__AVR)
  display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2));
  delay(2000);
  display.drawExampleBitmap(BitmapExample3, sizeof(BitmapExample3));
  delay(2000);
#endif
  display.fillScreen(GxEPD_WHITE);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
}
#endif

#if defined(_GxGDEW027C44_H_)
#define HAS_RED_COLOR
void showBitmapExample()
{
  // draw black and red bitmap
  display.drawPicture(BitmapExample1, BitmapExample2, sizeof(BitmapExample1), sizeof(BitmapExample2));
  delay(5000);
  return;
  display.drawBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.fillScreen(GxEPD_WHITE);
  display.drawBitmap(0, 0, BitmapExample1, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
}
#endif

#if defined(_GxGDEW027W3_H_)
void showBitmapExample()
{
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
#if !defined(__AVR)
  display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2));
  delay(2000);
  display.drawExampleBitmap(BitmapExample3, sizeof(BitmapExample3));
  delay(2000);
  display.drawExampleBitmap(BitmapExample4, sizeof(BitmapExample4));
  delay(2000);
  display.drawExampleBitmap(BitmapExample5, sizeof(BitmapExample5));
  delay(2000);
#endif
  display.drawExampleBitmap(BitmapWaveshare, sizeof(BitmapWaveshare));
  delay(5000);
  display.fillScreen(GxEPD_WHITE);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
}
#endif

#if defined(_GxGDEW0371W7_H_)
void showBitmapExample()
{
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
#if !defined(__AVR)
  display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2));
  delay(2000);
  display.drawExampleBitmap(BitmapExample3, sizeof(BitmapExample3));
  delay(2000);
#endif
  display.fillScreen(GxEPD_WHITE);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
}
#endif

#if defined(_GxGDEW042T2_H_)
void showBitmapExample()
{
#if defined(__AVR)
  display.drawBitmap(BitmapExample1, sizeof(BitmapExample1));
#else
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2));
  delay(5000);
  display.fillScreen(GxEPD_WHITE);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
#endif
}
#endif

#if defined(_GxGDEW042Z15_H_)
#define HAS_RED_COLOR
void showBitmapExample()
{
#if defined(__AVR)
  display.drawBitmap(BitmapExample1, sizeof(BitmapExample1));
#else
  // draw black and red bitmap
  display.drawPicture(BitmapExample1, BitmapExample2, sizeof(BitmapExample1), sizeof(BitmapExample2));
  delay(5000);
  display.drawPicture(BitmapExample3, BitmapExample4, sizeof(BitmapExample3), sizeof(BitmapExample4));
  delay(5000);
  display.drawPicture(BitmapWaveshare_black, BitmapWaveshare_red, sizeof(BitmapWaveshare_black), sizeof(BitmapWaveshare_red));
  delay(5000);
  display.drawBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
#endif
}
#endif

#if defined(_GxGDEW0583T7_H_)
void showBitmapExample()
{
#if defined(__AVR)
  //display.drawBitmap(BitmapExample1, sizeof(BitmapExample1));
#else
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.fillScreen(GxEPD_WHITE);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
#endif
}
#endif

#if defined(_GxGDEW075T8_H_)
void showBitmapExample()
{
#if defined(__AVR)
  display.drawBitmap(BitmapExample1, sizeof(BitmapExample1));
#else
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2));
  delay(5000);
  display.fillScreen(GxEPD_WHITE);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
#endif
}
#endif

#if defined(_GxGDEW075Z09_H_)
#define HAS_RED_COLOR
void showBitmapExample()
{
#if defined(__AVR)
  display.drawBitmap(BitmapExample1, sizeof(BitmapExample1));
#elif defined(ARDUINO_GENERIC_STM32F103C)
  display.drawBitmap(BitmapExample1, sizeof(BitmapExample1));
#elif defined(ARDUINO_GENERIC_STM32F103V)
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.drawExamplePicture_3C(BitmapPicture_3C, sizeof(BitmapPicture_3C));
#else
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2));
  delay(5000);
  display.drawExamplePicture_3C(BitmapPicture_3C, sizeof(BitmapPicture_3C));
#endif
}
#endif

#if defined(_GxGDEW075T7_H_)
void showBitmapExample()
{
#if defined(__AVR)
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
#else
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2));
  delay(5000);
  display.drawExampleBitmap(BitmapExample3, sizeof(BitmapExample1));
  delay(2000);
  display.drawExampleBitmap(BitmapExample4, sizeof(BitmapExample2));
  delay(5000);
  display.fillScreen(GxEPD_WHITE);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
#endif
}
#endif

#if defined(_GxGDEW075Z08_H_)
#define HAS_RED_COLOR
void showBitmapExample()
{
#if defined(__AVR) || defined(MCU_STM32F103C8)
  // draw (part of) black bitmap, not enough space for red
  display.drawPicture(BitmapExample1, 0, sizeof(BitmapExample1), 0);
#else
  // draw black and red bitmap
  display.drawExamplePicture(BitmapExample1, BitmapExample2, sizeof(BitmapExample1), sizeof(BitmapExample2));
  //delay(5000);
  //display.drawPicture(BitmapExample1, 0, sizeof(BitmapExample1), 0);
  //delay(5000);
  //display.drawPicture(0, BitmapExample2, 0, sizeof(BitmapExample2));
  //delay(5000);
  //display.drawExamplePicture(BitmapExample1, 0, sizeof(BitmapExample1), 0);
  //delay(5000);
  //display.drawExamplePicture(0, BitmapExample2, 0, sizeof(BitmapExample2));
  //delay(5000);
  //display.fillScreen(GxEPD_WHITE);
  //display.drawBitmap(0, 0, BitmapExample1, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  //display.update();
  //delay(5000);
  //display.fillScreen(GxEPD_WHITE);
  //display.drawBitmap(0, 0, BitmapExample2, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  //display.update();
  //display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  //display.updateWindow(0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, false);
#endif
}
#endif

void showFont(const char name[], const GFXfont* f)
{
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(0, 0);
  display.println();
  display.println(name);
  display.println(" !\"#$%&'()*+,-./");
  display.println("0123456789:;<=>?");
  display.println("@ABCDEFGHIJKLMNO");
  display.println("PQRSTUVWXYZ[\\]^_");
#if defined(HAS_RED_COLOR)
  display.setTextColor(GxEPD_RED);
#endif
  display.println("`abcdefghijklmno");
  display.println("pqrstuvwxyz{|}~ ");
  display.update();
  delay(5000);
}

void showFontCallback()
{
  const char* name = "FreeMonoBold9pt7b";
  const GFXfont* f = &FreeMonoBold9pt7b;
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(0, 0);
  display.println();
  display.println(name);
  display.println(" !\"#$%&'()*+,-./");
  display.println("0123456789:;<=>?");
  display.println("@ABCDEFGHIJKLMNO");
  display.println("PQRSTUVWXYZ[\\]^_");
#if defined(HAS_RED_COLOR)
  display.setTextColor(GxEPD_RED);
#endif
  display.println("`abcdefghijklmno");
  display.println("pqrstuvwxyz{|}~ ");
}

void drawCornerTest()
{
  display.drawCornerTest();
  delay(5000);
  uint8_t rotation = display.getRotation();
  for (uint16_t r = 0; r < 4; r++)
  {
    display.setRotation(r);
    display.fillScreen(GxEPD_WHITE);
    display.fillRect(0, 0, 8, 8, GxEPD_BLACK);
    display.fillRect(display.width() - 18, 0, 16, 16, GxEPD_BLACK);
    display.fillRect(display.width() - 25, display.height() - 25, 24, 24, GxEPD_BLACK);
    display.fillRect(0, display.height() - 33, 32, 32, GxEPD_BLACK);
    display.update();
    delay(5000);
  }
  display.setRotation(rotation); // restore
}

#if defined(_GxGDEP015OC1_H_) || defined(_GxGDEH0154D67_H_) || defined(_GxGDE0213B1_H_) || defined(_GxGDEH0213B72_H_) || defined(_GxGDEH0213B73_H_)|| defined(_GxGDEH029A1_H_)
#include "IMG_0001.h"
void showBoat()
{
  // thanks to bytecrusher: http://forum.arduino.cc/index.php?topic=487007.msg3367378#msg3367378
  uint16_t x = (display.width() - 64) / 2;
  uint16_t y = 5;
  display.fillScreen(GxEPD_WHITE);
  display.drawExampleBitmap(gImage_IMG_0001, x, y, 64, 180, GxEPD_BLACK);
  display.update();
  delay(500);
  uint16_t forward = GxEPD::bm_invert | GxEPD::bm_flip_x;
  uint16_t reverse = GxEPD::bm_invert | GxEPD::bm_flip_x | GxEPD::bm_flip_y;
  for (; y + 180 + 5 <= display.height(); y += 5)
  {
    display.fillScreen(GxEPD_WHITE);
    display.drawExampleBitmap(gImage_IMG_0001, x, y, 64, 180, GxEPD_BLACK, forward);
    display.updateWindow(0, 0, display.width(), display.height());
    delay(500);
  }
  delay(1000);
  for (; y >= 5; y -= 5)
  {
    display.fillScreen(GxEPD_WHITE);
    display.drawExampleBitmap(gImage_IMG_0001, x, y, 64, 180, GxEPD_BLACK, reverse);
    display.updateWindow(0, 0, display.width(), display.height());
    delay(1000);
  }
  display.update();
  delay(1000);
}
#endif
