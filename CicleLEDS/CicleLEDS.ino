#define Button 13
int LEDS[] = {7, 6, 5, 4};
int N_LEDS = 4;
int timer = 200;

void setup() {
  // put your setup code here, to run once:
  pinMode(Button, INPUT);
  for(int i = 0; i < N_LEDS; i++)
    pinMode(LEDS[i], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pressed = digitalRead(Button);

  if(pressed == 1){
    for(int i = N_LEDS; i >= 0; i--){
      digitalWrite(LEDS[i], HIGH);
      delay(timer);
      digitalWrite(LEDS[i], LOW);
      delay(timer);
    }
  }
  else{
    for(int i = 0; i < N_LEDS; i++){
      digitalWrite(LEDS[i], HIGH);
      delay(timer);
      digitalWrite(LEDS[i], LOW);
      delay(timer);
    }
  }
}