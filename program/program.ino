#include "Keyboard.h"
int encoderPin1 = 2;
int encoderPin2 = 3;

volatile int lastEncoded = 0;
volatile long encoderValue = 0;

long lastencoderValue = 0;

int lastMSB = 0;
int lastLSB = 0;
int temp;
bool before[17];

void setup() {
  Serial.begin (9600);
  attachInterrupt(0, updateEncoder, CHANGE); 
  attachInterrupt(1, updateEncoder, CHANGE);
  for (int i = 0; i <= 17; i++)
  {
    before[i] == false;
    pinMode(i, INPUT_PULLUP);
  }
  pinMode(encoderPin1, INPUT); 
  pinMode(encoderPin2, INPUT);
  digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
  digitalWrite(encoderPin2, HIGH); //turn pullup resistor on
  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3) 
}

void loop(){ 
  temp = encoderValue;
  delay(10);
  buttonFunc(6, 'g');
  buttonFunc(7, 'h');
  buttonFunc(8, 'j');
  buttonFunc(9, 'v');
  buttonFunc(10, 'b');
  buttonFunc(14, 'n');
  buttonFunc(16, 'm');
  buttonFunc(4, 'q');
  buttonFunc(15, 'e');
  encoderFunc(3, KEY_RIGHT_SHIFT, KEY_LEFT_SHIFT);
  //Serial.println(encoderValue);
}

void buttonFunc(int serie, char keyValue)
{
  int state = digitalRead(serie);
  if (state == LOW && before[serie] == false)
  {
    before[serie] = true;
    Keyboard.press(keyValue);
    return;
  }
  else if (state == HIGH && before[serie] == true)
  {
    before[serie] = false;
    Keyboard.release(keyValue);
    return;
  }
}

void encoderFunc(int encoderSensi, char counterclockwise, char clockwise)
{
  if (encoderValue - temp >= encoderSensi)
  {
    Keyboard.press(counterclockwise);
  }
  else if (temp - encoderValue >= encoderSensi)
  {
    Keyboard.press(clockwise);
    Serial.println("clock");
  }
  else
  {
    Keyboard.release(counterclockwise);
    Keyboard.release(clockwise);
  }
  encoderValue = 0;
  temp = 0;
  return;
}

void updateEncoder()
{
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;

  lastEncoded = encoded; //store this value for next time
}
