#include <Wire.h> // for SD stock
#include "DS3231.h" // for rtc

RTClib RTC;
DS3231 Clock;

// connect motor controller pins to Arduino digital pins
// motor one
int Houv = 8;
int Mouv = 56;
int Hferm = 17;
int Mferm = 57;
int enA = 4;
int in1 = 3;
int in2 = 2;
int pin_button = 7; // port numérique lié au bouton poussoir
int Year;
int Month;
int Date;
int Hour;
int Minute;
int Second;
int interval = 1;
int Minute_last;
int Date_last;
int i = 0;

void setup()
{
  //Initialize Serial Monitor

  Serial.begin(9600);
  Wire.begin(); //for DS3231 for RTC
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  analogWrite(enA, 255); 
  DateTime now = RTC.now();
  Minute = now.minute();
}
 
void loop()
{  
  delay(1000);
  Serial.println();
  Serial.print(Year);
  Serial.print("/");
  Serial.print(Month);
  Serial.print("/");
  Serial.print(Date);
  Serial.print(" ");
  Serial.print(Hour);
  Serial.print(":");
  Serial.print(Minute);
  Serial.print(":");
  Serial.print(Second);
  if (Hour >= Houv && Hour < Hferm && i == 0) { // Si l'heure est supérieur à l'heure minimale d'ouverture et que la porte est fermé
      ouverture(); // Ouverture de la porte
   }
  if (Hour >= Hferm && Hour > Houv && i == 1) { // Si l'heure est supérieur à l'heure minimale de fermeture et que la porte est fermé
      fermeture(); // Ouverture de la porte
   }
  DateTime now = RTC.now();
  Year = now.year();
  Month = now.month();
  Date = now.day();
  Hour = now.hour();
  Minute = now.minute();
  Second = now.second();
}

void ouverture(){
  Serial.println();
  Serial.print("Ouverture de la porte...");
  while (digitalRead(pin_button) == HIGH){ // Tant que le bouton est en position High, le moteur tourne
      //le moteur tourne
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
  }
  Serial.println();
  Serial.print("Porte ouverte ;-)");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  i = 1;
  delay(1000);
}
void fermeture(){
  Serial.println();
  Serial.print("Fermeture de la porte...");
  while (digitalRead(pin_button) == HIGH){ // Tant que le bouton est en position High, le moteur tourne
      //le moteur tourne
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
  }
  Serial.println();
  Serial.print("Porte fermé ;-)");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  i = 0;
  delay(1000);
}
