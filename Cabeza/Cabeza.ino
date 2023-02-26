#include <LedControl.h>

LedControl lc = LedControl(12, 11, 10, 1);  // (DIN,CLK,CS,Nro de dispositivos conectados)



byte Ojo_1[10] = {

  0x3c, 0x7e, 0x7e, 0x72, 0x72, 0x7e, 0x7e, 0x3c
};

byte Ojo_2[10] = {

  0x3c, 0x7e, 0x7e, 0x7e, 0x72, 0x72, 0x7e, 0x3c
};

byte Ojo_3[10] = {

  0x3c, 0x7e, 0x7e, 0x7e, 0x66, 0x66, 0x7e, 0x3c
};

byte Ojo_4[10] = {

  0x3c, 0x7e, 0x7e, 0x66, 0x66, 0x7e, 0x7e, 0x3c
};

byte Ojo_5[10] = {

  0x3c, 0x7e, 0x7e, 0x66, 0x66, 0x7e, 0x7e, 0x3c
};

byte Ojo_6[10] = {

  0x3c, 0x7e, 0x72, 0x72, 0x7e, 0x7e, 0x7e, 0x3c
};

// Lado izquierdo

byte Ojo_7[10] = {

  0x3c, 0x7e, 0x4e, 0x4e, 0x7e, 0x7e, 0x7e, 0x3c
};

byte Ojo_8[10] = {

  0x3c, 0x7e, 0x7e, 0x4e, 0x4e, 0x7e, 0x7e, 0x3c
};

byte Ojo_9[10] = {

  0x3c, 0x7e, 0x7e, 0x7e, 0x4e, 0x4e, 0x7e, 0x3c
};



#include <Servo.h>

Servo cabeza;

//SENSORES INFRARROJOS

int infrarrojo_1 = 2;

int infrarrojo_2 = 4;

int infrarrojo_3 = 6;

int Valor_1;

int Valor_2;

int Valor_3;



void setup()

{

  pinMode(infrarrojo_1, INPUT);

  pinMode(infrarrojo_2, INPUT);

  pinMode(infrarrojo_3, INPUT);

  cabeza.attach(3);

  lc.shutdown(0, false);  //0=Numero de dispositivos iniciando desde 0(0,7)//valor boleano

  lc.setIntensity(0, 4);  //=0 numero de dispostivo // (0,15)  valor de luminacion como maximo 15

  lc.clearDisplay(0);  //=0 borra o blancela la matriz del numero de dispositivo

  lc.shutdown(1, false);  //0=Numero de dispositivos iniciando desde 0(0,7)//valor boleano

  lc.setIntensity(1, 4);  //=0 numero de dispostivo // (0,15)  valor de luminacion como maximo 15

  lc.clearDisplay(1);  //=0 borra o blancela la matriz del numero de dispositivo
}



void loop()

{

  Valor_1 = digitalRead(infrarrojo_1);

  Valor_2 = digitalRead(infrarrojo_2);

  Valor_3 = digitalRead(infrarrojo_3);







  if ((Valor_2 == Valor_3) && (Valor_1 == 0))

  {

    cabeza.write(20);

    for (int i = 0; i < 2; i++)

    {

      mostrar_1();

      delay(250);

      mostrar_2();

      delay(250);

      mostrar_3();

      delay(250);
    }
  }



  if ((Valor_1 == Valor_3) && (Valor_2 == 0))

  {

    cabeza.write(60);

    for (int i = 0; i < 2; i++)

    {



      mostrar_4();

      delay(250);

      mostrar_5();

      delay(250);

      mostrar_6();

      delay(250);
    }
  }

  if ((Valor_1 == Valor_2) && (Valor_3 == 0))

  {

    cabeza.write(100);

    for (int i = 0; i < 2; i++)

    {

      mostrar_7();

      delay(250);

      mostrar_8();

      delay(250);

      mostrar_9();

      delay(250);
    }
  }
}

// funciones OJOS

void mostrar_1()

{

  for (int i = 0; i < 8; i++)

  {

    lc.setRow(0, i, Ojo_1[i]);
  }
}

void mostrar_2()

{

  for (int i = 0; i < 8; i++)

  {

    lc.setRow(0, i, Ojo_2[i]);
  }
}

void mostrar_3()

{

  for (int i = 0; i < 8; i++)

  {

    lc.setRow(0, i, Ojo_3[i]);
  }
}

void mostrar_4()

{

  for (int i = 0; i < 8; i++)

  {

    lc.setRow(0, i, Ojo_4[i]);
  }
}

void mostrar_5()

{

  for (int i = 0; i < 8; i++)

  {

    lc.setRow(0, i, Ojo_5[i]);
  }
}

void mostrar_6()

{

  for (int i = 0; i < 8; i++)

  {

    lc.setRow(0, i, Ojo_6[i]);
  }
}

void mostrar_7()

{

  for (int i = 0; i < 8; i++)

  {

    lc.setRow(0, i, Ojo_7[i]);
  }
}

void mostrar_8()

{

  for (int i = 0; i < 8; i++)

  {

    lc.setRow(0, i, Ojo_8[i]);
  }
}

void mostrar_9()

{

  for (int i = 0; i < 8; i++)

  {

    lc.setRow(0, i, Ojo_9[i]);
  }
}