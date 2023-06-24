#ifndef SD_FUNCTIONS_H
#define SD_FUNCTIONS_H
#include <Arduino.h>

#include "FS.h"
#include "SD.h"
#include "SPI.h"

void SetupSD() {
  
  // Initialize SD card
  if (!SD.begin(5)) {
    Serial.println("SD card initialization failed!");
    return;
  }

  Serial.println("SD card initialized.");
}

void LoopSD() {
  // Open file for writing
  File file = SD.open("/data.txt", FILE_WRITE);
  
  if (file) {
    // Write data to file
    file.println("Hello, world!");
    file.close();
  } else {
    Serial.println("Failed to open file for writing.");
  }

  delay(1000);
}

#endif