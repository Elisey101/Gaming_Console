// #include "Button.h"

// // Adding pullup resistor for pins (to input value from buttons)
// void pullUpPins(){
//   pinMode(BUTTON_PIN, INPUT_PULLUP);
//   pinMode(BUTTON_PIN1, INPUT_PULLUP);
//   pinMode(BUTTON_PIN2, INPUT_PULLUP);
//   pinMode(BUTTON_PIN3, INPUT_PULLUP);
//   pinMode(BUTTON_PIN4, INPUT_PULLUP);
//   pinMode(BUTTON_PIN5, INPUT_PULLUP);
//   // pinMode(BUTTON_PIN6, INPUT_PULLUP);    
// }

// // Removing noises from buttons to get clear value (when it pressed or released)
// bool antiRattling(int button){
//   bool current = digitalRead(button);
//   delay(10);
//   current = digitalRead(button);
//   return current;
// }

// class Button{
//   public: 
//   bool onClick(bool button){  
//     static int flag;
//     if(button == LOW && flag == false){
//       flag = true;
//       Serial.println("1");
//       return 1;
//     }else if (button == HIGH){
//       flag = false;
//     }
//     Serial.println("0"); 
//     return 0;
//   }
// };











