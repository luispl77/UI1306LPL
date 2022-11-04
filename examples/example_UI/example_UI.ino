#include <UI1306LPL.h>


UI1306LPL menu6;
UI1306LPL menu5;
UI1306LPL menuBlink1(&blink_function1, MODE_FUNCTION);
UI1306LPL menu3(NULL, MODE_MENU, "6th menu", &menu6);
UI1306LPL menu2(NULL, MODE_MENU, "3rd menu", &menu3, "5th menu", &menu5);
UI1306LPL menu1(NULL, MODE_MENU, "Blink Menu", &menuBlink1, "2nd menu", &menu2);



void setup() {
  pinMode(2, OUTPUT);
  menu1.initializeDisplay(SHOW_BOOT_SCREEN);
  
}

void loop() {
  menu1.runMenu();
}

void blink_function1(){
  int blink_delay = 200;
  while(1){
    digitalWrite(2, HIGH);
    delay(blink_delay);
    digitalWrite(2, LOW);
    delay(blink_delay);
    if(menuBlink1.clickB()){
      return;
    }
  }
}
