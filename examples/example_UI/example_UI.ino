#include <RFM69LPL.h>
#include <SPI.h>
#include <RFM69LPLregisters.h>

#include <UI1306LPL.h>

#define DIO2_T 15
#define DIO2_R 16

#define R_CS 4
#define T_CS 5
#define SD_CS 13

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

UI1306LPL menu6;
UI1306LPL menu5;
UI1306LPL menu4(&blink_function, MODE_FUNCTION);
UI1306LPL menu3(NULL, MODE_MENU, "Sexto menu", &menu6);
UI1306LPL menu2(NULL, MODE_MENU, "Terceiro menu", &menu3, "Quarto menu", &menu4);
UI1306LPL menu1(NULL, MODE_MENU, "Segundo menu", &menu2, "Quinto menu", &menu5);


RFM69LPL radio_R(R_CS, DIO2_R, true);
RFM69LPL radio_T(T_CS, DIO2_T, true);

void setup() {
  pinMode(buttonUP, INPUT_PULLUP);
  pinMode(buttonDOWN, INPUT_PULLUP);  
  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);
  initializeTransmit_R();
  initializeTransmit_T();
  radio_R.setModulationType(MOD_OOK);
  radio_R.setModulationType(MOD_OOK);
  radio_R.send(0);
  radio_T.send(0);
  menu1.initializeDisplay(SHOW_BOOT_SCREEN);
  menu1.runMenu();
}

void loop() {
  
}

void blink_function(){
  while(1){
    ledOn();
    delay(400);
    ledOff();
    delay(400);
  }
}
