#include <UI1306LPL.h>

UI1306LPL menu9; //empty menu, acessible from main_menu
UI1306LPL menu8; //empty menu, acessible from main_menu
UI1306LPL menu7; //empty menu, acessible from main_menu
UI1306LPL menu6; //empty menu, acessible from main_menu
UI1306LPL menu5; //empty menu, acessible from menu2

UI1306LPL Blink(&blink_function, MODE_FUNCTION);                                   //function, acessed by pressing "Blink FUNCTION" on main_menu 

UI1306LPL menu3(NULL, MODE_MENU, "6th menu", &menu6);                              //menu with one option (menu6), acessible from menu2

UI1306LPL menu2(NULL, MODE_MENU, "3rd menu", &menu3, "5th menu", &menu5);          //menu with two options (menu3 and menu5), acessible from main_menu

UI1306LPL main_menu(NULL, MODE_MENU, "Blink FUNCTION", &Blink, "2nd menu", &menu2, //main menu, using all 5 options
                      "7th menu", &menu7, "8th menu", &menu8, "9th menu", &menu9); 


int led_pin = 2; //change led pin for the blink function.
uint8_t buttonA = 27;
uint8_t buttonB = 26;     //buttons pins. these work on ESP32, but add whichever ones you like. 
uint8_t buttonUP = 25;    //on intializeDisplay(), they're all set to pinMode(x, INPUT_PULLUP).
uint8_t buttonDOWN = 33;

void setup() {
  pinMode(led_pin, OUTPUT);
  main_menu.initializeDisplay(); //call this once in setup to intialize display, before running the main/first menu.
  
}

void loop() {
  main_menu.runMenu(); //run this function in loop.               
}                      //after calling this function, the program stays in it forever: you need to create your own functions above.

void blink_function(){  //test function that gets called when, on the main menu, "Blink FUNCTION" is pressed.
  int blink_delay = 200;
  while(1){
    digitalWrite(led_pin, HIGH);
    delay(blink_delay);    //blink led
    digitalWrite(led_pin, LOW);
    delay(blink_delay);

    
    if(Blink.clickB()){ //exit function if B is pressed
      return;           //after returning, the program goes back to the menu where this function was pressed.
    }
  }
}       
