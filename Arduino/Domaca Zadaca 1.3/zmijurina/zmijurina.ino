// binarno brojilo

#define OP_NOOP   0
#define OP_DIGIT0 1
#define OP_DIGIT1 2
#define OP_DIGIT2 3
#define OP_DIGIT3 4
#define OP_DIGIT4 5
#define OP_DIGIT5 6
#define OP_DIGIT6 7
#define OP_DIGIT7 8
#define OP_DECODEMODE  9
#define OP_INTENSITY   10
#define OP_SCANLIMIT   11
#define OP_SHUTDOWN    12
#define OP_DISPLAYTEST 15
#define button A2


int CLK = 5; // 5 = PD5
int LOAD = 6; // 6 = PD6
int DIN = 7; // 7 = PD7


byte zmijurina[8] = {0b00000000,
                     0b00000000,
                     0b00000000,
                     0b00000000,
                     0b00000000,
                     0b00000000,
                     0b00000000,
                     0b00000000
                    };


int direc[4][2] =
{
  {1, 0},
  {0, 1},
  { -1, 0},
  {0, -1}
};


void sendData( byte address, byte data)
{
  byte packet[2];
  byte bitmask;
  byte i;
  packet[0] = address;
  packet[1] = data;

  for (i = 0; i < 2; i++)
    for ( bitmask = 0x80 ; bitmask != 0 ; bitmask = bitmask >> 1 )
    {
      if (bitmask & packet[i]) digitalWrite(DIN, 1);
      else digitalWrite(DIN, 0);

      digitalWrite(CLK, HIGH);
      digitalWrite(CLK, LOW);
    }
  digitalWrite(LOAD, HIGH);
  digitalWrite(LOAD, LOW);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(DIN, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(LOAD, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  digitalWrite(LOAD, LOW);

  randomSeed(analogRead(0));

  Serial.begin(9600);


  sendData(OP_DISPLAYTEST, 0);
  sendData(OP_INTENSITY, 0);
  sendData(OP_SCANLIMIT, 7);

  sendData(OP_DECODEMODE, 0);
  sendData(OP_SHUTDOWN, 1);
  for (int i = 0; i < 8; i++) sendData(i + 1, 0b00000000);



  Serial.println(direc[0][0]);
  Serial.println(direc[0][1]);



}

void printZmijurina()
{
  for (int i = 0; i < 8; i++) sendData(i + 1, zmijurina[i]);
  delay(100);

}

int counter = 0;

byte t = 0;
int direc_x = direc[t][0];
int direc_y = direc[t][1];

byte bitmask_x1 = 0x80;
byte bitmask_x2 = 0x02;

byte vertical_bitmask1 = 0x01;
byte vertical_bitmask2 = 0x80;
byte horizontal_bitmask1 = 0x80;
byte horizontal_bitmask2 = 0x02;


byte flag = 0;

byte times = 0;

void loop() {
  // put your main code here, to run repeatedly:


  if (zmijurina[4] == 0xFF && flag == 0)
  {
    counter = 0;
    t = 0;
    direc_x = direc[t][0];
    direc_y = direc[t][1];

    bitmask_x1 = 0x7F;
    bitmask_x2 = 0xFD;

    vertical_bitmask1 = 0xFE;
    vertical_bitmask2 = 0x7F;
    horizontal_bitmask1 = 0x7F;
    horizontal_bitmask2 = 0xFD;

    flag = 1;
  }

  if (zmijurina[4] == 0x00 && flag)
  {
    counter = 0;
    t = 0;
    direc_x = direc[t][0];
    direc_y = direc[t][1];

    bitmask_x1 = 0x80;
    bitmask_x2 = 0x02;

    vertical_bitmask1 = 0x01;
    vertical_bitmask2 = 0x80;
    horizontal_bitmask1 = 0x80;
    horizontal_bitmask2 = 0x02;

    flag = 0;

  }


  if (flag == 0)
  {
    if (direc_x == 1) //horizontal +
    {
      while ((horizontal_bitmask1 & zmijurina[counter]) == 0 && horizontal_bitmask1 > 0)
      {
        zmijurina[counter] = zmijurina[counter] | horizontal_bitmask1;
        horizontal_bitmask1 = horizontal_bitmask1 >> 1;
        printZmijurina();

      }
      t = (t + 1) % 4;
      direc_x = direc[t][0];
      direc_y = direc[t][1];

      counter++;

      bitmask_x1 = bitmask_x1 >> 1;
      horizontal_bitmask1 = bitmask_x1;
    }


    if (direc_y == 1)
    {
      while ((vertical_bitmask1 & zmijurina[counter]) == 0 && counter < 8)
      {
        zmijurina[counter] = zmijurina[counter] | vertical_bitmask1;
        counter++;
        printZmijurina();
      }
      vertical_bitmask1 = vertical_bitmask1 << 1;
      t = (t + 1) % 4;
      direc_x = direc[t][0];
      direc_y = direc[t][1];

      counter--;

    }

    if (direc_x == -1)
    {
      while ((horizontal_bitmask2 & zmijurina[counter]) == 0 && horizontal_bitmask2 > 0)
      {
        zmijurina[counter] = zmijurina[counter] | horizontal_bitmask2;
        horizontal_bitmask2 = horizontal_bitmask2 << 1;
        printZmijurina();
      }
      t = (t + 1) % 4;
      direc_x = direc[t][0];
      direc_y = direc[t][1];

      counter--;
      bitmask_x2 = bitmask_x2 << 1;
      horizontal_bitmask2 = bitmask_x2;

    }

    if (direc_y == -1)
    {
      while ((vertical_bitmask2 & zmijurina[counter]) == 0)
      {
        zmijurina[counter] = zmijurina[counter] | vertical_bitmask2;
        counter--;
        printZmijurina();
      }
      vertical_bitmask2 = vertical_bitmask2 >> 1;

      t = (t + 1) % 4;
      direc_x = direc[t][0];
      direc_y = direc[t][1];

      counter++;

    }
  }



  if (flag)
  {

    if (direc_x == 1) //horizontal +
    {
      while (zmijurina[counter] != 0)
      {
        zmijurina[counter] = zmijurina[counter] & horizontal_bitmask1;
        horizontal_bitmask1 = horizontal_bitmask1 >> 1;
        printZmijurina();

      }
      t = (t + 1) % 4;
      direc_x = direc[t][0];
      direc_y = direc[t][1];

      counter++;

      bitmask_x1 = bitmask_x1 >> 1;
      horizontal_bitmask1 = bitmask_x1;
    }


    if (direc_y == 1)
    {
      while (zmijurina[counter] != 0 && counter < 8)
      {
        zmijurina[counter] = zmijurina[counter] & vertical_bitmask1;
        counter++;
        printZmijurina();
      }
      vertical_bitmask1 = vertical_bitmask1 << 1;
      t = (t + 1) % 4;
      direc_x = direc[t][0];
      direc_y = direc[t][1];

      counter--;

    }

    if (direc_x == -1)
    {
      while (zmijurina[counter] != 0 && horizontal_bitmask2 > 0)
      {
        zmijurina[counter] = zmijurina[counter] & horizontal_bitmask2;
        horizontal_bitmask2 = horizontal_bitmask2 << 1;
        printZmijurina();
      }
      t = (t + 1) % 4;
      direc_x = direc[t][0];
      direc_y = direc[t][1];

      counter--;
      bitmask_x2 = bitmask_x2 << 1;
      horizontal_bitmask2 = bitmask_x2;

    }

    if (direc_y == -1)
    {
      while (zmijurina[counter] != 0)
      {
        zmijurina[counter] = zmijurina[counter] & vertical_bitmask2;
        counter--;
        printZmijurina();
      }
      vertical_bitmask2 = vertical_bitmask2 >> 1;

      t = (t + 1) % 4;
      direc_x = direc[t][0];
      direc_y = direc[t][1];

      counter++;

    }












  }




}

