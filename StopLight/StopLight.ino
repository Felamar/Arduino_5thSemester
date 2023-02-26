#define RED 7
#define YELLOW 6
#define GREEN 5
void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(GREEN, HIGH);
  delay(4000);
  digitalWrite(GREEN, LOW);
  for(int i = 0; i < 5; i++){
    digitalWrite(YELLOW, HIGH);
    delay(300);
    digitalWrite(YELLOW, LOW);
    delay(200);
  }
  digitalWrite(RED, HIGH);
  delay(4000);
  digitalWrite(RED, LOW);
}
