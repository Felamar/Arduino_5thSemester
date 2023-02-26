#define RED_1 7
#define YELLOW_1 6
#define GREEN_1 5
#define RED_2 19
#define YELLOW_2 20
#define GREEN_2 21
void setup() {
  // put your setup code here, to run once:
  pinMode(RED_1, OUTPUT);
  pinMode(YELLOW_1, OUTPUT);
  pinMode(GREEN_1, OUTPUT);
  pinMode(RED_2, OUTPUT);
  pinMode(YELLOW_2, OUTPUT);
  pinMode(GREEN_2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED_1, LOW);
  digitalWrite(RED_2, HIGH);
  digitalWrite(GREEN_1, HIGH);
  delay(4000);
  digitalWrite(GREEN_1, LOW);

  for(int i = 0; i < 5; i++){
    digitalWrite(YELLOW_1, HIGH);
    delay(300);
    digitalWrite(YELLOW_1, LOW);
    delay(200);
  }

  digitalWrite(RED_1, HIGH);
  digitalWrite(RED_2, LOW);
  digitalWrite(GREEN_2, HIGH);
  delay(4000);
  digitalWrite(GREEN_2, LOW);

  for(int i = 0; i < 5; i++){
    digitalWrite(YELLOW_2, HIGH);
    delay(300);
    digitalWrite(YELLOW_2, LOW);
    delay(200);
  }
}


