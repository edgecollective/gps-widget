// PartialUpdateExample : example for Waveshare 1.54", 2.31" and 2.9" e-Paper and the same e-papers from Dalian Good Display Inc.
//
// Created by Jean-Marc Zingg based on demo code from Good Display for GDEP015OC1.
//
// The e-paper displays are available from:
//
// https://www.aliexpress.com/store/product/Wholesale-1-54inch-E-Ink-display-module-with-embedded-controller-200x200-Communicate-via-SPI-interface-Supports/216233_32824535312.html
//
// http://www.buy-lcd.com/index.php?route=product/product&path=2897_8363&product_id=35120
// or https://www.aliexpress.com/store/product/E001-1-54-inch-partial-refresh-Small-size-dot-matrix-e-paper-display/600281_32815089163.html
//

// Supporting Arduino Forum Topics:
// Waveshare e-paper displays with SPI: http://forum.arduino.cc/index.php?topic=487007.0
// Good Dispay ePaper for Arduino : https://forum.arduino.cc/index.php?topic=436411.0

// mapping suggestion from Waveshare 2.9inch e-Paper to Wemos D1 mini
// BUSY -> D2, RST -> D4, DC -> D3, CS -> D8, CLK -> D5, DIN -> D7, GND -> GND, 3.3V -> 3.3V

// mapping suggestion from Waveshare 2.9inch e-Paper to generic ESP8266
// BUSY -> GPIO4, RST -> GPIO2, DC -> GPIO0, CS -> GPIO15, CLK -> GPIO14, DIN -> GPIO13, GND -> GND, 3.3V -> 3.3V

// mapping suggestion for ESP32, e.g. LOLIN32, see .../variants/.../pins_arduino.h for your board
// NOTE: there are variants with different pins for SPI ! CHECK SPI PINS OF YOUR BOARD
// BUSY -> 4, RST -> 16, DC -> 17, CS -> SS(5), CLK -> SCK(18), DIN -> MOSI(23), GND -> GND, 3.3V -> 3.3V

// mapping suggestion for AVR, UNO, NANO etc.
// BUSY -> 7, RST -> 9, DC -> 8, CS-> 10, CLK -> 13, DIN -> 11

// mapping suggestion for Arduino MEGA
// BUSY -> 7, RST -> 9, DC -> 8, CS-> 53, CLK -> 52, DIN -> 51

// mapping suggestion for Arduino DUE
// BUSY -> 7, RST -> 9, DC -> 8, CS-> 77, CLK -> 76, DIN -> 75
// SPI pins are also on 6 pin 2x3 SPI header

// include library, include base class, make path known
#include <GxEPD.h>

// select the display class to use, only one
#include <GxGDEH0154D67/GxGDEH0154D67.h>  // 1.54" b/w

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>

#include GxEPD_BitmapExamples


GxIO_Class io(SPI, /*CS=*/ 10, /*DC=*/ 9, /*RST=*/ 6);
GxEPD_Class display(io, /*RST=*/ 6, /*BUSY=*/ 5);


//#define DEMO_DELAY 3*60 // seconds
//#define DEMO_DELAY 1*60 // seconds
#define DEMO_DELAY 3

void setup(void)
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");
  display.init(115200); // enable diagnostic output on Serial
  Serial.println("setup done");
  display.update();

}

int x=30;
int y=30;
int w = 3;
int h = 3;
void loop()
{
  
  
    placePoint(x,y,w,h);
    delay(DEMO_DELAY * 1000);
    x=x-3+2*random(0,3);
    y=y-3+2*random(0,3);


}

void placePoint(int box_x,int box_y,int box_w,int box_h) {
  display.fillRect(box_x, box_y, box_w, box_h, GxEPD_BLACK);
  display.updateWindow(box_x, box_y, box_w, box_h, true);
  //display.update();
  
}

void showPartialUpdate()
{
  // use asymmetric values for test
  uint16_t box_x = 10;
  uint16_t box_y = 15;
  uint16_t box_w = 70;
  uint16_t box_h = 20;
  uint16_t cursor_y = box_y + box_h - 6;
  float value = 13.95;
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  display.setRotation(0);
  // draw background
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
  delay(2000);

  // partial update to full screen to preset for partial update of box window
  // (this avoids strange background effects)
  display.updateWindow(0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, false);

  // show where the update box is
  for (uint16_t r = 0; r < 4; r++)
  {
    display.setRotation(r);
    display.fillRect(box_x, box_y, box_w, box_h, GxEPD_BLACK);
    display.updateWindow(box_x, box_y, box_w, box_h, true);
    delay(1000);
    display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
    display.updateWindow(box_x, box_y, box_w, box_h, true);
  }
  // show updates in the update box
  for (uint16_t r = 0; r < 4; r++)
  {
    // reset the background
    display.setRotation(0);
    display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
    display.updateWindow(0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, false);
    display.setRotation(r);
    for (uint16_t i = 1; i <= 10; i++)
    {
      display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
      display.setCursor(box_x, cursor_y);
      display.print(value * i, 2);
      display.updateWindow(box_x, box_y, box_w, box_h, true);
      delay(2000);
    }
    delay(2000);
    display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
    display.updateWindow(box_x, box_y, box_w, box_h, true);
  }
  // should have checked this, too
  box_x = GxEPD_HEIGHT - box_x - box_w - 1; // not valid for all corners
  // should show on right side of long side
  // reset the background
  display.setRotation(0);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.updateWindow(0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, false);
  // show where the update box is
  for (uint16_t r = 0; r < 4; r++)
  {
    display.setRotation(r);
    display.fillRect(box_x, box_y, box_w, box_h, GxEPD_BLACK);
    display.updateWindow(box_x, box_y, box_w, box_h, true);
    delay(1000);
    display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
    display.updateWindow(box_x, box_y, box_w, box_h, true);
  }
  // show updates in the update box
  for (uint16_t r = 0; r < 4; r++)
  {
    // reset the background
    display.setRotation(0);
    display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
    display.updateWindow(0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, false);
    display.setRotation(r);
    if (box_x >= display.width()) continue; // avoid delay
    for (uint16_t i = 1; i <= 10; i++)
    {
      display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
      display.setCursor(box_x, cursor_y);
      display.print(value * i, 2);
      display.updateWindow(box_x, box_y, box_w, box_h, true);
      delay(2000);
    }
    delay(2000);
    display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
    display.updateWindow(box_x, box_y, box_w, box_h, true);
  }
  display.setRotation(0);
  display.powerDown();
}

//#endif

/*
#if defined(_GxGDEW075Z09_H_) && !(defined(ESP8266) || defined(ARDUINO_ARCH_STM32F1))

void showPartialUpdate_75Z09()
{
  // use asymmetric values for test
  uint16_t box_x = 10;
  uint16_t box_y = 15;
  uint16_t box_w = 70;
  uint16_t box_h = 20;
  uint16_t cursor_y = box_y + box_h - 6;
  float value = 13.95;
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  display.setRotation(0);
  // draw background, partial update to full screen to preset for partial update of box window
  // (updateWindow() would clear display if partial update not set, to avoid strange background effect)
  display.drawExamplePicture_3C(BitmapPicture_3C, sizeof(BitmapPicture_3C), GxEPD::bm_partial_update);
  // show where the update box is
  for (uint16_t r = 0; r < 4; r++)
  {
    display.setRotation(r);
    display.fillRect(box_x, box_y, box_w, box_h, GxEPD_BLACK);
    display.updateWindow(box_x, box_y, box_w, box_h, true);
    delay(1000);
    display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
    display.updateWindow(box_x, box_y, box_w, box_h, true);
  }
  // show updates in the update box
  for (uint16_t r = 0; r < 4; r++)
  {
    // reset the background
    display.setRotation(0);
    display.drawExamplePicture_3C(BitmapPicture_3C, sizeof(BitmapPicture_3C), GxEPD::bm_partial_update);
    display.setRotation(r);
    for (uint16_t i = 1; i <= 10; i++)
    {
      display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
      display.setCursor(box_x, cursor_y);
      display.print(value * i, 2);
      display.updateWindow(box_x, box_y, box_w, box_h, true);
      delay(2000);
    }
    delay(2000);
    display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
    display.updateWindow(box_x, box_y, box_w, box_h, true);
  }
  // should have checked this, too
  box_x = GxEPD_HEIGHT - box_x - box_w - 1; // not valid for all corners
  // should show on right side of long side
  // reset the background
  display.setRotation(0);
  display.drawExamplePicture_3C(BitmapPicture_3C, sizeof(BitmapPicture_3C), GxEPD::bm_partial_update);
  // show where the update box is
  for (uint16_t r = 0; r < 4; r++)
  {
    display.setRotation(r);
    display.fillRect(box_x, box_y, box_w, box_h, GxEPD_BLACK);
    display.updateWindow(box_x, box_y, box_w, box_h, true);
    delay(1000);
    display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
    display.updateWindow(box_x, box_y, box_w, box_h, true);
  }
  // show updates in the update box
  for (uint16_t r = 0; r < 4; r++)
  {
    // reset the background
    display.setRotation(0);
    display.drawExamplePicture_3C(BitmapPicture_3C, sizeof(BitmapPicture_3C), GxEPD::bm_partial_update);
    display.setRotation(r);
    if (box_x >= display.width()) continue; // avoid delay
    for (uint16_t i = 1; i <= 10; i++)
    {
      display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
      display.setCursor(box_x, cursor_y);
      display.print(value * i, 2);
      display.updateWindow(box_x, box_y, box_w, box_h, true);
      delay(2000);
    }
    delay(2000);
    display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
    display.updateWindow(box_x, box_y, box_w, box_h, true);
  }
  display.setRotation(0);
  display.powerDown();
}

#endif
*/
/*
#if defined(__AVR) || (defined(_GxGDEW075Z09_H_) || defined(_GxGDEW075Z08_H_)) && (defined(ESP8266) || defined(ARDUINO_ARCH_STM32F1)) || false

// modified to avoid float; reduces program size ~2k (for GxGDEW042T2)

void showBlackBoxCallback(uint32_t v)
{
  uint16_t box_x = 10;
  uint16_t box_y = 15;
  uint16_t box_w = 70;
  uint16_t box_h = 20;
  display.fillRect(box_x, box_y, box_w, box_h, v);
}

void showValueBoxCallback(const uint32_t v)
{
  uint16_t box_x = 10;
  uint16_t box_y = 15;
  uint16_t box_w = 70;
  uint16_t box_h = 20;
  uint16_t cursor_y = box_y + box_h - 6;
  display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
  display.setCursor(box_x, cursor_y);
  display.print(v / 100);
  display.print(v % 100 > 9 ? "." : ".0");
  display.print(v % 100);
}

void showPartialUpdatePaged()
{
  uint16_t box_x = 10;
  uint16_t box_y = 15;
  uint16_t box_w = 70;
  uint16_t box_h = 20;
  uint16_t cursor_y = box_y + box_h - 6;
  uint32_t value = 1395;
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  display.setRotation(0);
  // draw background
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);

  // partial update to full screen to preset for partial update of box window
  // (this avoids strange background effects)
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1), GxEPD::bm_default | GxEPD::bm_partial_update);
  delay(1000);

  // show where the update box is
  for (uint16_t r = 0; r < 4; r++)
  {
    display.setRotation(r);
    display.drawPagedToWindow(showBlackBoxCallback, box_x, box_y, box_w, box_h, GxEPD_BLACK);
    delay(1000);
    display.drawPagedToWindow(showBlackBoxCallback, box_x, box_y, box_w, box_h, GxEPD_WHITE);
  }

  // show updates in the update box
  for (uint16_t r = 0; r < 4; r++)
  {
    // reset the background
    display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1), GxEPD::bm_default | GxEPD::bm_partial_update);
    display.setRotation(r);
    for (uint16_t i = 1; i <= 10; i++)
    {
      uint32_t v = value * i;
      display.drawPagedToWindow(showValueBoxCallback, box_x, box_y, box_w, box_h, v);
      delay(500);
    }
    delay(1000);
    display.drawPagedToWindow(showBlackBoxCallback, box_x, box_y, box_w, box_h, GxEPD_WHITE);
  }
  // reset the background
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1), GxEPD::bm_default | GxEPD::bm_partial_update);
  display.setRotation(0);
  display.powerDown();
}

#endif
*/
