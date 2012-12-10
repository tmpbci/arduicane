/*
  Télèmetre avec sortie tactile v0.1 by Sam Neurohack (La Paillasee & /tmp/lab)
 For Arduino Uno. Beginner project.
 This code is in the public domain.
 
 2 wires motor connections : GND and Digital 11
 Sharp IR connections      : GND, 5V and Analogic A2
 */
 
int VibPin = 11;                          // connecteur vibreur = 11 / reset mesure infra rouge.
int sensorValue = 0;

void setup() {
  Serial.begin(9600);                     // initialise la connection serie 
  pinMode(VibPin, OUTPUT);                // Connecteur vibreur en sortie
}
void loop() {
  sensorValue = analogRead(A2);           // lecture du telemetre
  Serial.println(sensorValue);            // envoi sur ordinateur
  analogWrite(VibPin, sensorValue / 2);   // envoi PWM sur moteur
  delay(80);                             // délai 80 ms
}
