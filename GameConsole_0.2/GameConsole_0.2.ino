#define TFT_DARK tft.color565(59, 59, 59)

// Libraries
#include <iostream>
#include "SPI.h"
#include "TFT_eSPI.h"
#include "Free_Fonts.h"
#include "Button.h"
// #include "SdCard.h"
TFT_eSPI tft;

bool tB1, tB2, tB3, bB1, bB2, bB3, bB4;
short int itemsCount = 3;
short int itemColor[3];

Button button;
Button button2;

  // Main main menu rendering
  void mainMenu(int selectId){
    tft.setFreeFont(FF21);
    // Header rendering
    // tft.fillScreen(TFT_BLACK);    
    tft.fillRect(0, 0, 320, 30, TFT_DARK);
    Text("Main menu", TFT_WHITE, 1, 8, 8);
    
    // Current list items highlighting
    for(int i = -1; i <= itemsCount; i++, itemColor[i] = TFT_DARK, itemColor[selectId] = TFT_WHITE);

    // List element items rendering
    Text("Games", itemColor[0], 1, 8, 42);
    Text("Watch", itemColor[1], 1, 8, 66);
    Text("Calculator", itemColor[2], 1, 8, 90);
    Text("Settings", itemColor[3], 1, 8, 114);
    tft.setFreeFont();
  }


  // Pseudo 3d text rendering
  void VolumTxt(String text, int baseClr, int backClr, int txtSize, int txtPosX, int txtPosY) {
    tft.setTextSize(txtSize);
    for (int i = 0; i < 4; i++, (i < 4) ? tft.setTextColor(backClr) : tft.setTextColor(baseClr), tft.drawString(text, txtPosX+=1, txtPosY+=1));
  }
  
  
  // Text rendering
  void Text(String text, int baseClr, int txtSize, int txtPosX, int txtPosY){
    tft.setTextSize(txtSize);
    tft.setTextColor(baseClr);
    tft.drawString(text, txtPosX, txtPosY); 
  }
  

/////////////////////////////////////////////////////////////////////////////
//-----------------------------Main_Functions------------------------------//
/////////////////////////////////////////////////////////////////////////////

  void setup() {
    Serial.begin(115200);
    pullUpPins();

    tft.init();
    tft.setRotation(1); 
    tft.fillScreen(TFT_BLACK);
    
    tft.begin();
    VolumTxt("Nostalgia", TFT_WHITE, TFT_BLUE, 4, 50, 90); //Drawing pseudo 3D text (my function)
    VolumTxt("Gaming Console", TFT_WHITE, TFT_RED, 2, 50, 130); //Drawing pseudo 3D text (my function)
    Text("By_LOSOS>", TFT_WHITE, 1, 260, 225);

    delay(1500);
    tft.fillScreen(TFT_BLACK);
    mainMenu(0);
    
  }

  void loop() {

    // Geting cleared button value by antiRattling function
    tB1 = antiRattling(BUTTON_PIN);
    tB2 = antiRattling(BUTTON_PIN1);
    tB3 = antiRattling(BUTTON_PIN2);
    bB1 = antiRattling(BUTTON_PIN3);
    bB2 = antiRattling(BUTTON_PIN4);
    bB3 = antiRattling(BUTTON_PIN5);
    // bB4 = antiRattling(BUTTON_PIN6);


    if(button.onClick(tB1) == true)mainMenu(0);
    if(button2.onClick(tB2) == true) mainMenu(1);
    if(tB2 == LOW)mainMenu(1);
    if(tB3 == LOW)mainMenu(2);
    if(bB1 == LOW)tft.fillScreen(TFT_GREEN);
    if(bB2 == LOW)tft.fillScreen(TFT_BLUE);
    if(bB3 == LOW)tft.fillScreen(TFT_YELLOW);
    if(bB4 == LOW)tft.fillScreen(TFT_VIOLET);
  }
  



  // switch(selectId) {
  //   case 0 :
  //     pointClr[0] = TFT_WHITE;
  //     break;
  //   case 1 :
  //     pointClr[1] = TFT_WHITE;
  //     break;
  //   case 2 :
  //     pointClr[2] = TFT_WHITE;
  //     break;
  // }

  // pointClr[0] = TFT_DARK;
  // pointClr[1] = TFT_DARK; 
  // pointClr[2] = TFT_DARK;

