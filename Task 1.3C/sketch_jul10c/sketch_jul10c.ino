#define SIGNAL_PIN 2
#define SIGNAL_PIN_2 3


int led_green = 8;

uint8_t led_state = LOW;

void setup()
{
  Serial.begin(9600);
  
  pinMode(SIGNAL_PIN, INPUT);
  pinMode(SIGNAL_PIN_2, INPUT);
  pinMode(led_green,OUTPUT);

  attachInterrupt(digitalPinToInterrupt(SIGNAL_PIN), Turn_On, CHANGE);
  attachInterrupt(digitalPinToInterrupt(SIGNAL_PIN_2), Turn_Off, CHANGE);

}
void loop() {
  digitalWrite(led_green,led_state);
  if(digitalRead(SIGNAL_PIN)==HIGH) {
    Serial.println("Movement detected.");
  } else {
    Serial.println("Did not detect movement.");
  }
  int digital = digitalRead(SIGNAL_PIN_2);
    if(digitalRead(SIGNAL_PIN_2)==HIGH) {
    Serial.println("Did not detect sound.");
  } else {
    Serial.println("Sound detected.");
  }
  Serial.println("--------------------------");

  delay(1000);
  
}


void Turn_On()
{
  led_state = HIGH;
 }

void  Turn_Off()
{
  led_state = LOW;
}
