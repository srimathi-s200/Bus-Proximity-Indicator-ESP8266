const int PIR = 8;
const int LED = 7;
const int BUZZER = 3;

void setup()
{
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop()
{
  int motion = digitalRead(PIR);

  if (motion == HIGH)
  {
    digitalWrite(LED, HIGH);
    tone(BUZZER, 1000);
  }
  else
  {
    digitalWrite(LED, LOW);
    noTone(BUZZER);
  }

  delay(100);
}