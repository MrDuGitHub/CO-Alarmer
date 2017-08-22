#include "MQ2.h"
#include "Buzzer.h"

float RO = 0, ratio = 0;

void setup()
{
  Serial.begin(9600);
  Buzzer_Init();
  RO = reset_MQ2();
}


void loop()
{
  ratio = get_ratio(RO);
      Serial.println(ratio);
      delay(1000);
  if (ratio < 4.5)
  {

    Buzzer_();
  }
  else
  {
    Buzzer_stop();
  }
}
