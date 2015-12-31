int sensorValue;
int potValDelay;
int potValPitch;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;
const int potPinDelay = A3;
const int potPinPitch = A1;
const int sensorPin = A0;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  //calibration
  while (millis() < 5000) {
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }  
  }
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() 
{
  //read light sensor vaue
  sensorValue = analogRead(sensorPin);
  
  //read potentiometer value who controls pitch destination range
  potValPitch = analogRead(potPinPitch);
  
  //compute pitch
  int pitch =
    map(sensorValue, sensorLow, sensorHigh, potValPitch, 4000);
    
 
  tone(8, pitch, 20);
 
  // read potentiometer value who controls delay
  potValDelay = analogRead(potPinDelay);
 
   
  delay(potValDelay);
 
}

