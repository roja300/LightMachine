#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int pinButton = 12;
const int pinLightOne = 5;
const int pinLightTwo = 6;
const int pinLightThree = 7;
int shouldWriteOn = 0;
int shouldWriteOff = 0;
int buttonState = 0;
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  lcd.begin();

  lcd.backlight();
  pinMode(pinButton, INPUT);
  pinMode(pinLightOne, OUTPUT);
  pinMode(pinLightTwo, OUTPUT);
  pinMode(pinLightThree, OUTPUT);
}

void loop() {
  buttonState = digitalRead(pinButton);
  Serial.println(buttonState);
  if (buttonState == 1){
    shouldWriteOff = 0;
    if (shouldWriteOn == 0){
      lcd.clear();
      lcd.println("LIGHTS ACTIVE                                                               ");
      shouldWriteOn = 1;
    }
    CycleLights();
  }
  else {
    shouldWriteOn = 0;
    if (shouldWriteOff == 0){
      lcd.clear();
      lcd.println("INACTIVE                                                                    ");
      shouldWriteOff = 1;
    }
    TurnAllLightsOff();
  }
}

void TurnAllLightsOff(){
  digitalWrite(pinLightOne, HIGH);
  digitalWrite(pinLightTwo, HIGH);
  digitalWrite(pinLightThree, HIGH);
}

void CycleLights(){
  TurnAllLightsOff();
  digitalWrite(pinLightOne, LOW);
  delay(200);
  TurnAllLightsOff();
  digitalWrite(pinLightTwo, LOW);
  delay(200);
  TurnAllLightsOff();
  digitalWrite(pinLightThree, LOW);
  delay(200);
}


