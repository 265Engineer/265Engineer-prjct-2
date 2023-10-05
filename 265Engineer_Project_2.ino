#include <SoftwareSerial.h>

SoftwareSerial SIM900A(8,7);

int led = 13;
int buzzer = 4;
int obstacle = 2;

void setup() {
  // put your setup code here, to run once:

  
  SIM900A.begin(9600); // GSM Module Baud rate – communication speed
pinMode (obstacle , INPUT);
pinMode (buzzer , OUTPUT);
pinMode (led , OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(obstacle)== LOW)
{
  
  digitalWrite(buzzer, HIGH);
  digitalWrite(led, HIGH);
  Serial.println (digitalRead(buzzer));
  SendMessage();
}

  digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);

}


void SendMessage() {
  Serial.println("Sending Message, please wait...");
  SIM900A.println("AT+CMGF=1"); // Text Mode initialization
  delay(1000);
  Serial.println("Set SMS Number");
  SIM900A.println("AT+CMGS=\"+265XXXXXXXXXXXX\"\r"); // Receiver’s Mobile Number
  delay(1000);
  Serial.println("Set SMS Content");
  SIM900A.println("Alarm was tripped Mr 265Engineer"); // Message content
  delay(100);
  Serial.println("Done");
  SIM900A.write((char)26);
  delay(100);
  Serial.println("Message sent successfully");
}
