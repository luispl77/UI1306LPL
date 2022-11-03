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

#define MODE_MENU 1
#define MODE_FUNCTION 0

class UI1306LPL {
  public:

    UI1306LPL(uint8_t mode = MODE_MENU, String func1 = "func1", UI1306LPL* UI1 = NULL, String func2 = "func2", UI1306LPL* UI2 = NULL,
     String func3 = "func3", UI1306LPL* UI3 = NULL, String func4 = "func4", UI1306LPL* UI4 = NULL, String func5 = "func5", UI1306LPL* UI5 = NULL) {
      _mode = mode;
      _func1 = func1;
      _func2 = func2;
      _func3 = func3;
      _func4 = func4;
      _func5 = func5;
      _UI1 = UI1;
      _UI2 = UI2;
      _UI3 = UI3;
      _UI4 = UI4;
      _UI5 = UI5;
    }
    //public functions
    bool initializeDisplay();
    void drawText(String text, int x, int y, int text_size, int inverse);
    
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

};

#endif
