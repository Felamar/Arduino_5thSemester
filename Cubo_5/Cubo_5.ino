#define LEDS_SIZE 5
#define time 100
#define alphabet_SIZE 26
#define center 36

int columns[LEDS_SIZE][LEDS_SIZE] = {
  /*A*/ { 22, 24, 26, 28, 30 }, /*B*/ { 23, 25, 27, 29, 31 },
  /*C*/ { 32, 34, 36, 38, 40 }, /*D*/ { 33, 35, 37, 39, 41 },
  /*E*/ { 42, 44, 46, 48, 50 }
};

int layers[LEDS_SIZE] = { /*1*/ 43, /*2*/ 45, /*3*/ 47, /*4*/ 49, /*5*/ 51};

long unsigned int alphabet[] = {
  /*A*/ 0b0111110100101001010001111,
  /*B*/ 0b1111110101101011010101010,
  /*C*/ 0b0111010001100011000110001,
  /*D*/ 0b1111110001100011000101110,
  /*E*/ 0b1111110101101011010110001,
  /*F*/ 0b1111110100101001010010000,
  /*G*/ 0b0111010001101011010100111,
  /*H*/ 0b1111100100001000010011111,
  /*I*/ 0b1000110001111111000110001,
  /*J*/ 0b1000110001111101000010000,
  /*K*/ 0b1111100100001000101010001,
  /*L*/ 0b1111100001000010000100001,
  /*M*/ 0b1111101000001000100011111,
  /*N*/ 0b1111101000001000001011111,
  /*O*/ 0b0111010001100011000101110,
  /*P*/ 0b1111110100101001010001000,
  /*Q*/ 0b0111010001100011001101111,
  /*R*/ 0b1111110100101001010001011,
  /*S*/ 0b0100110101101011010110010,
  /*T*/ 0b1000010000111111000010000,
  /*U*/ 0b1111000001000010000111110,
  /*V*/ 0b1110000010000010001011100,
  /*W*/ 0b1111000001000100000111110,
  /*X*/ 0b1000101010001000101010001,
  /*Y*/ 0b1000001000001110100010000,
  /*Z*/ 0b1000110011101011100110001
};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < LEDS_SIZE; i++) {
    for (int j = 0; j < LEDS_SIZE; j++)
      pinMode(columns[i][j], OUTPUT);
    pinMode(layers[i], OUTPUT);
  }
}

void loop() {
  recorridos('X');
  recorridos('Y');
  recorridos('Z');
  orbit();
  rain();
  init_message();
}

void turnALL_off() {
  for (int i = 0; i < LEDS_SIZE; i++) {
    digitalWrite(layers[i], LOW);
    for (int j = 0; j < LEDS_SIZE; j++)
      digitalWrite(columns[i][j], LOW);
  }
}

void recorridos(char x) {
  turnALL_off();
  int increment = 1;
  switch (x) {
    case 'X':
      for (int i = 0; i < LEDS_SIZE; i++)
        digitalWrite(layers[i], HIGH);

      for (int i = 0; i < LEDS_SIZE && i > -1; i += increment) {
        for (int j = 0; j < LEDS_SIZE; j++) {
          digitalWrite(columns[i][j], HIGH);
          if (i > 0)
            digitalWrite(columns[i - increment][j], LOW);
        }
        delay(time);
        if(i == LEDS_SIZE - 1)
          increment = -1;
      }
      break;

    case 'Y':
      for (int i = 0; i < LEDS_SIZE; i++)
        for (int j = 0; j < LEDS_SIZE; j++)
          digitalWrite(columns[i][j], HIGH);

      for(int i = 0; i < LEDS_SIZE && i > -1; i += increment){
        digitalWrite(layers[i], HIGH);
        if(i > 0)
          digitalWrite(layers[i - increment], LOW);
        delay(time);
        if(i == LEDS_SIZE - 1)
          increment = -1;
      }
      break;

    case 'Z':
      for (int i = 0; i < LEDS_SIZE; i++)
        digitalWrite(layers[i], HIGH);

      for (int i = 0; i < LEDS_SIZE && i > -1; i += increment) {
        for (int j = 0; j < LEDS_SIZE; j++) {
          digitalWrite(columns[j][i], HIGH);
          if (i > 0)
            digitalWrite(columns[j][i - increment], LOW);
        }
        delay(time);
        if(i == LEDS_SIZE - 1)
          increment = -1;
      }
      break;

    default:
      break;
  }
}

void init_message() {
  turnALL_off();
  Serial.println("Introduzca su mensaje:  ");
  while (!Serial.available());
  String message = Serial.readStringUntil('\n');
  message.trim();
  message.toUpperCase();
  for (int i = 0; i < message.length(); i++)
    letters(message[i]);
}

void letters(char character) {
  if (character == 241 || character == 209) character = 'N';
  if (character < 'A' || character > 'Z') return;
  for (int i = 0; i < LEDS_SIZE * LEDS_SIZE; i++)
    digitalWrite(columns[i / LEDS_SIZE][i % LEDS_SIZE], ((1UL << i) & alphabet[(character - 'A')]) > 0);

  for(int i = 0; i < LEDS_SIZE; i++){
    digitalWrite(layers[i], HIGH);
    delay(time);
    digitalWrite(layers[i], LOW);
  }
}

void orbit() {
  turnALL_off();
  int orbit[] = {center, 
    /*Inner Orbit 00 - 07*/ 25, 27, 29, 38, 39, 37, 35, 34, 
    /*Outer Orbit 08 - 24*/ 26, 28, 30, 31, 40, 41, 50, 48, 46, 44, 42, 33, 32, 23, 22, 24
  };
  long int way = 0b000000000000000000000111;
  for(int k = 0; k < LEDS_SIZE; k++){
    digitalWrite(layers[k], HIGH);
    for(int i = 0; i < LEDS_SIZE * LEDS_SIZE; i++){
      for(int j = 0; j < LEDS_SIZE * LEDS_SIZE; j++){
        digitalWrite(orbit[j], ((1UL << i) & (way << j)) > 0);
      }
        delay(time / 2);
      }
        digitalWrite(layers[k], LOW);
    }
}

void rain(){
  turnALL_off();
  for(int i = 0; i < pow(LEDS_SIZE, 3); i++){
    int x = random(0, LEDS_SIZE);
    int y = random(0, LEDS_SIZE);
    int z = random(0, LEDS_SIZE);
    digitalWrite(columns[x][y], HIGH);
    digitalWrite(layers[z], HIGH);
    if(z > 0) {
      delay(time);
      digitalWrite(layers[z - 1], HIGH);
    }
    
    digitalWrite(layers[z], LOW);
    if(z > 0) {
      delay(time);
      digitalWrite(layers[z - 1], LOW);
    }
    delay(time / 2);
    digitalWrite(columns[x][y], LOW);
  }
}