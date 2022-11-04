#ifndef UI1306LPL_h
#define UI1306LPL_h
#include <Arduino.h>            //assumes Arduino IDE v1.0 or greater

#define BUILTIN_LED 2

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define INVERS 1
#define NORMAL 0
#define BLAC 2

#define buttonA 27
#define buttonB 26
#define buttonUP 25
#define buttonDOWN 33

#define MODE_MENU 1
#define MODE_FUNCTION 2

class UI1306LPL {
  public:

    UI1306LPL(void (*mode_function)(void) = NULL, uint8_t mode = MODE_MENU, String func1 = "null", UI1306LPL* UI1 = NULL, String func2 = "null", UI1306LPL* UI2 = NULL,
     String func3 = "null", UI1306LPL* UI3 = NULL, String func4 = "null", UI1306LPL* UI4 = NULL, String func5 = "null", UI1306LPL* UI5 = NULL) {
      _mode = mode;   //decides if, when pressing a menu, it is called a custom function or another custom menu
      _func1 = func1;
      _func2 = func2;
      _func3 = func3;
      _func4 = func4;   //each 5 menus/functions available to press
      _func5 = func5;
      _UI1 = UI1;
      _UI2 = UI2;
      _UI3 = UI3;     //address to next menu
      _UI4 = UI4;
      _UI5 = UI5;
      _mode_function = mode_function; //address to function that gets executed upon button pressing a MODE_FUNCTION type of menu.
      _last_menu = this;
    }
    //public functions
    bool initializeDisplay();
    void drawText(String text, int x, int y, int text_size, int inverse);
    void drawRectangle();
    void runMenu();
    void drawMenu(String func1, String func2, String func3, String func4, String func5, uint8_t text_cursor, uint8_t last_cursor);
    void drawMenuFirst(String func1, String func2, String func3, String func4, String func5, uint8_t text_cursor);
    void selectFunction(uint8_t text_cursor);
    void deleteLine(int l_cursor);
    bool clickA();
    bool clickB();
    bool clickUP();
    bool clickDOWN();
    void increment_cursor(uint8_t* text_cursor, uint8_t* last_cursor);
    void decrement_cursor(uint8_t* text_cursor, uint8_t* last_cursor);
    
    //protected functions
  protected:
    static UI1306LPL* selfPointer;
    uint8_t _mode;
    String _func1;
    String _func2;
    String _func3;
    String _func4;
    String _func5;
    UI1306LPL* _UI1;
    UI1306LPL* _UI2;
    UI1306LPL* _UI3;
    UI1306LPL* _UI4;
    UI1306LPL* _UI5;
    void (*_mode_function)(void); //address to function
    uint8_t cursor = 0;
    uint8_t lcursor = 0;
    UI1306LPL* _last_menu;
    

};

#endif
