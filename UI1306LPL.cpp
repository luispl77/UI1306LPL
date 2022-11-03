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

void UI1306LPL::drawRectangle(){
  display.drawRect(0, 0, display.width(), display.height(), SSD1306_WHITE);
  display.display();
}

void UI1306LPL::runMenu(){
  drawMenuFirst(_func1, _func2, _func3, _func4, _func5, cursor);
  while(1){
    if(clickA()){
      selectFunction(cursor);
    }
  
    if(clickB()){
      break;
    }
    
    if(clickUP()){
      decrement_cursor(&cursor, &lcursor);
      drawMenu(_func1, _func2, _func3, _func4, _func5, cursor, lcursor);
    }
  
    if(clickDOWN()){
      increment_cursor(&cursor, &lcursor);
      drawMenu(_func1, _func2, _func3, _func4, _func5, cursor, lcursor);
    }
  }
}

void UI1306LPL::drawMenu(String func1, String func2, String func3, String func4, String func5, uint8_t text_cursor, uint8_t last_cursor){
  if(text_cursor == 0){
    drawText(func1, 10, 6, 1, INVERS);
  }
  if(last_cursor == 0){
    deleteLine(last_cursor);
    drawText(func1, 10, 6, 1, NORMAL);
  }


  if(text_cursor == 1){
    drawText(func2, 10, 17, 1, INVERS);
  }
  if(last_cursor == 1){
    deleteLine(last_cursor);
    drawText(func2, 10, 17, 1, NORMAL);
  }


  if(text_cursor == 2){
    drawText(func3, 10, 28, 1, INVERS);
  }
  
  if(last_cursor == 2){
    deleteLine(last_cursor);
    drawText(func3, 10, 28, 1, NORMAL);
  }
  

  if(text_cursor == 3){
    drawText(func4, 10, 39, 1, INVERS);
  }
  if(last_cursor == 3){
    deleteLine(last_cursor);
    drawText(func4, 10, 39, 1, NORMAL);
  }


  if(text_cursor == 4){
    drawText(func5, 10, 50, 1, INVERS);
  }
  if(last_cursor == 4){
    deleteLine(last_cursor);
    drawText(func5, 10, 50, 1, NORMAL);
  }
  delay(100);
}

void UI1306LPL::drawMenuFirst(String func1, String func2, String func3, String func4, String func5, uint8_t text_cursor){
  display.clearDisplay();
  drawRectangle();
  if(text_cursor == 0) drawText(func1, 10, 6, 1, INVERS); else drawText(func1, 10, 6, 1, NORMAL);
  if(text_cursor == 1) drawText(func2, 10, 17, 1, INVERS); else drawText(func2, 10, 17, 1, NORMAL);
  if(text_cursor == 2) drawText(func3, 10, 28, 1, INVERS); else drawText(func3, 10, 28, 1, NORMAL);
  if(text_cursor == 3) drawText(func4, 10, 39, 1, INVERS); else drawText(func4, 10, 39, 1, NORMAL);
  if(text_cursor == 4) drawText(func5, 10, 50, 1, INVERS); else drawText(func5, 10, 50, 1, NORMAL);
}

void UI1306LPL::selectFunction(uint8_t text_cursor){
  if(text_cursor == 0){
    _UI1->runMenu();
  }
  else if(text_cursor == 1){
    _UI2->runMenu();
  }
  else if(text_cursor == 2){
    _UI3->runMenu();
  }
  else if(text_cursor == 3){
    _UI4->runMenu();
  }
  else if(text_cursor == 4){
    _UI5->runMenu();
  }
}


void UI1306LPL::deleteLine(int l_cursor){
  display.fillRect(10, 6 + (l_cursor * 11), 100, 10, SSD1306_BLACK);
  display.display();
}


bool UI1306LPL::clickA(){
  if(digitalRead(buttonA) == LOW){
    return true;
  }
  else{
    return false;
  }
}

bool UI1306LPL::clickB(){
  if(digitalRead(buttonB) == LOW){
    return true;
  }
  else{
    return false;
  }
}

bool UI1306LPL::clickUP(){
  if(digitalRead(buttonUP) == LOW){
    return true;
  }
  else{
    return false;
  }
}

bool UI1306LPL::clickDOWN(){
  if(digitalRead(buttonDOWN) == LOW){
    return true;
  }
  else{
    return false;
  }
}

void UI1306LPL::increment_cursor(uint8_t* text_cursor, uint8_t* last_cursor){
  if(*text_cursor < 4){
    *last_cursor = *text_cursor;
    (*text_cursor)++;
  }
  else{
    *last_cursor = *text_cursor;
    *text_cursor = 0;
  }

}

void UI1306LPL::decrement_cursor(uint8_t* text_cursor, uint8_t* last_cursor){
  if(*text_cursor > 0){
    *last_cursor = *text_cursor;
    (*text_cursor)--;
  }
  else{
    *last_cursor = *text_cursor;
    *text_cursor = 4;
  }
}