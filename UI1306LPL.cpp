#include <UI1306LPL.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

UI1306LPL* UI1306LPL::selfPointer;

bool UI1306LPL::initializeDisplay(){
  pinMode(BUILTIN_LED, OUTPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  drawText("LPL", 64, 32, 2, 0);
  display.drawRect(0, 0, display.width(), display.height(), SSD1306_WHITE);
  display.display();
  delay(1500);
  return true;
}

void UI1306LPL::drawText(String text, int x, int y, int text_size, int inverse){
  display.setTextSize(text_size); 
  if(inverse == 1){
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
  }
  else if (inverse == 0){
    display.setTextColor(SSD1306_WHITE);
  }
  else if (inverse == 2){
    display.setTextColor(SSD1306_BLACK);
  }
  display.setCursor(x, y);
  display.print(text);
  display.display();
}
