/*
 * mesure dehors : 23 <=> Aube = 10
 *                39 <=> 75
 */
int sensorValue;
int digitSensorValue;
int PIN_D0 = 7;
int PIN_LED_VERT = 8;
int PIN_LED_ORANGE = 9;
int PIN_LED_ROUGE = 10;
int PIN_LED_ROUGE_ROUGE = 11;
int SEUIL_VERT = 50;
int SEUIL_ORANGE = 100;
int SEUIL_ROUGE = 150;
int SEUIL_ROUGE_ROUGE = 250;

void setup()
{
  Serial.begin(9600);      // sets the serial port to 9600
  pinMode(PIN_D0,OUTPUT);
  pinMode(PIN_LED_VERT,OUTPUT);
  pinMode(PIN_LED_ORANGE,OUTPUT);
  pinMode(PIN_LED_ROUGE,OUTPUT);
  pinMode(PIN_LED_ROUGE_ROUGE,OUTPUT);
}

void loop()
{
  sensorValue = analogRead(0);       // read analog input pin 0
//  digitSensorValue = digitalRead(PIN_D0);
  Serial.print("Analog : ");  
  Serial.println(sensorValue, DEC);  // prints the value read
  Serial.print("Digital : ");  
  Serial.println(digitSensorValue);  // prints the value read
  if (sensorValue>SEUIL_ROUGE_ROUGE)
  {
    digitalWrite(PIN_LED_ROUGE_ROUGE, HIGH);   
    digitalWrite(PIN_LED_ROUGE, HIGH);   
    digitalWrite(PIN_LED_ORANGE, HIGH);   
    digitalWrite(PIN_LED_VERT, HIGH);   
    digitalWrite(PIN_D0, LOW);   
  } 
  else if (sensorValue>SEUIL_ROUGE)
  {
    digitalWrite(PIN_LED_ROUGE_ROUGE, LOW);   
    digitalWrite(PIN_LED_ROUGE, HIGH);   
    digitalWrite(PIN_LED_ORANGE, HIGH);   
    digitalWrite(PIN_LED_VERT, HIGH);   
    digitalWrite(PIN_D0, LOW);   
  } 
  else if (sensorValue>SEUIL_ORANGE)
  {
    digitalWrite(PIN_LED_ROUGE_ROUGE, LOW);   
    digitalWrite(PIN_LED_ROUGE, LOW);   
    digitalWrite(PIN_LED_ORANGE, HIGH);   
    digitalWrite(PIN_LED_VERT, HIGH);   
    digitalWrite(PIN_D0, LOW);
    delay(200);   
    digitalWrite(PIN_D0, HIGH);   
    delay(200);   
    digitalWrite(PIN_D0, LOW);   
  } 
  else if (sensorValue>SEUIL_VERT)
  {
    digitalWrite(PIN_LED_ROUGE_ROUGE, LOW);   
    digitalWrite(PIN_LED_ROUGE, LOW);   
    digitalWrite(PIN_LED_ORANGE, LOW);   
    digitalWrite(PIN_LED_VERT, HIGH);   
    digitalWrite(PIN_D0, HIGH);
    delay(200);   
    digitalWrite(PIN_D0, LOW);   
    delay(200);   
    digitalWrite(PIN_D0, HIGH);   
  } 
  else //(sensorValue<= 50)
  {
    digitalWrite(PIN_LED_ROUGE_ROUGE, LOW);   
    digitalWrite(PIN_LED_ROUGE, LOW);   
    digitalWrite(PIN_LED_ORANGE, LOW);   
    digitalWrite(PIN_LED_VERT, LOW);   
    digitalWrite(PIN_D0, HIGH);   
  } 
  delay(500);                        // wait 500ms for next reading
}
