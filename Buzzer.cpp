#include "Buzzer.h"

void Buzzer_Init()
{
  pinMode(pinBuzzer, OUTPUT);
}

void Buzzer_()      
{
    for (int i=500;i<=1000;i++)
      newtone(15,i);
    for (int i=1000;i>=500;i--)
      newtone(15,i);
}

void Buzzer_stop()
{
}

//模拟tone以消除tone函数和红外模块的冲突
//durtion为频率frequency作用的周期
void newtone(int duration,int frequency)  
{
  int period = 1000000L / frequency;
  int pulse = period / 2;
  for (long i = 0; i < duration * 1000L; i += period)
  {
    digitalWrite(pinBuzzer, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(pinBuzzer, LOW);
    delayMicroseconds(pulse);
  }
}

