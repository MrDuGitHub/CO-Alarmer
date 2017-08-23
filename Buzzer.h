#ifndef BUZZER_H_INCLUDED
#define BUZZER_H_INCLUDED
#include <Arduino.h>

const int pinBuzzer = A1; //A1为输出端口

void Buzzer_Init();
void Buzzer_();
void newtone(int duration,int frequency);
void Buzzer_stop();

#endif // BUZZER_H_INCLUDED

