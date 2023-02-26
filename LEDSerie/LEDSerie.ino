int LEDS[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 14, 15};
int N_LEDS = 16;
int thisLED = -1;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < N_LEDS; i++)
    pinMode(LEDS[i], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  thisLED = thisLED < N_LEDS - 1 ? thisLED + 1 : 0;
  digitalWrite(LEDS[thisLED], HIGH);
  delay(150);
  digitalWrite(LEDS[thisLED], LOW);
}
