/*
    Title: Program to connect your phone to ADAFRUIT BLUEFRUIT UART LE
    Author: This code was orignally created by FREENOVE.COM and
            modified by David Elmo Ross on May 10th 2025
    Description: You must connect the ADAFRUIT BLUEFRUIT Friend LE
                 from TX on BLuefruit to TX on ESP32
                 and RX on Bluefruit to RX on the ESP32.
                 
                 IMPORTANT: YOU MUST DISCONNECT the TX line from the
                            Bluefruit BEFORE you UPLOAD CODE to the ESP32.
                            When code has been uploaded, hit the RESET
                            on the ESP32, then when message comes up 
                            CONNECT the TX .
                            
                            The Simplest way to do this is add a switch to
                            toggle between connecting and disconnecting the
                            TX Line.
*/
#include "arduino.h"                      // Include arduino library
#include "BluetoothSerial.h"              // Include BluetoothSerial library

BluetoothSerial SerialBT;                 // make SerialBT and instance of BluetoothSerial

void setup() 
{
  Serial.begin(9600);                     // set baud rate to 9600 and also in the .ini file
                                          // put reminder message on cleared PC Screen
  printf("\e[2;1H");
  printf("\e[2J");
  printf("Bluefruit Ready to pair\n");
  printf("Toggle Switch when upload complete\nTo interact with BLUEFRUIT device\n");
  printf("Then PAIR Adafruit Bluefruit LE \nto one with STRONGEST SIGNAL STRENGTH\n");
  printf("When DONE and you want to uploaod \nanother program, Toggle Switch to Disconnect\n");
}

void loop() 
{
  if (Serial.available())                // if char available from PC Keyboard 
  {
    SerialBT.write(Serial.read());       // write it to Bluefruit Uart Friend
                                         // make sure you have chosen TEXT not TIMESTAMP
  }
  if (SerialBT.available())              // if char available from BLUEFRUIT UART FRIEND
  {
    Serial.write(SerialBT.read());       // write it to PC Screen
  }
  delay(20);                             // wait 20 milliseconds
}
