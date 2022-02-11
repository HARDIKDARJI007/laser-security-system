int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 12;
int D2 = 13;
int i = 0;
int k = 0;
int j = 0;
int Arduino_Pins[7] = {pinA, pinB, pinC, pinD, pinE, pinF, pinG};
int Segment_Pins[10][7] = {{0, 0, 0, 0, 0, 0, 1}, // 0
  {1, 0, 0, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0}, // 2
  {0, 0, 0, 0, 1, 1, 0}, // 3
  {1, 0, 0, 1, 1, 0, 0}, // 4
  {0, 1, 0, 0, 1, 0, 0}, // 5
  {0, 1, 0, 0, 0, 0, 0}, // 6
  {0, 0, 0, 1, 1, 1, 1}, // 7
  {0, 0, 0, 0, 0, 0, 0}, // 8
  {0, 0, 0, 0, 1, 0, 0}, // 9
};

void setup() {
  // put your setup code here, to run once:
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int n = 0; n < 600; n++)
  {
    for (j = 0; j < 7; j++)
    {
      digitalWrite(Arduino_Pins[j], Segment_Pins[i][j]);
    }
    digitalWrite(D1, 1);
    digitalWrite(D2, 0);
    delay(1);

    for (j = 0; j < 7; j++)
    {
      digitalWrite(Arduino_Pins[j], Segment_Pins[k][j]);
    }
    digitalWrite(D1, 0);
    digitalWrite(D2, 1);
    delay(1);

    if(analogRead(A0) >500)
    {Serial.println(A0);
      while(analogRead(A0) > 500)
      {
        delay(100);
      }
      i++;
      if(i == 10)
      {
        k = k + 1;
        i = 0;
        if(k == 10)
        {
          k = 0;
        }
      }
    }
  }  
}
