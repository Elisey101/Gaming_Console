#ifndef BUTTON_FUNCTIONS_H
#define BUTTON_FUNCTIONS_H
#include <Arduino.h>

#define BUTTON_PIN 32 // First top button
#define BUTTON_PIN1 33 // Second top button
#define BUTTON_PIN2 14 // Third top button
#define BUTTON_PIN3 15 // First bottom button
#define BUTTON_PIN4 13 // Second bottom button
#define BUTTON_PIN5 12 // First bottom button
#define BUTTON_PIN6 4 // First bottom button


// Adding pullup resistor for pins (to input value from buttons)
void pullUpPins(){
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(BUTTON_PIN4, INPUT_PULLUP);
  pinMode(BUTTON_PIN5, INPUT_PULLUP);
  // pinMode(BUTTON_PIN6, INPUT_PULLUP);    
}

// Removing noises from buttons to get clear value (when it pressed or released)
bool antiRattling(int button){
  bool current = digitalRead(button);
  delay(10);
  current = digitalRead(button);
  return current;
}

class Button{ 
  private: int flag = false;
  public:bool onClick(bool button){  
    if(button == LOW && flag == false){
      flag = true;
      // Serial.println("1");
      return 1;
    }else if (button == HIGH){
      flag = false;
    }
    // Serial.println("0"); 
    return 0;
  }
};

#endif