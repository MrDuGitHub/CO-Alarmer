#include "irrecv.h"
#include "MQ2.h"
#include "Buzzer.h"

float RO = 0, ratio = 0;  //初始化MQ2初值

bool buzzer = false;      //是否报警

IRrecv irrecv(RECV_PIN);
decode_results results;  //初始定义红外遥控模块

void setup()
{
  // 初始化传感器
  Serial.begin(9600);
  RO = reset_MQ2();
  Buzzer_Init();
  irrecv.enableIRIn();
}

void loop()
{
  //接受红外编码
  if (irrecv.decode(&results))
  {
    //Serial.println(results.value);//以16进制换行输出接收代码
    switch (results.value)
    {
      case OK:                     //OK键重置烟雾传感器
        Serial.println("初始化烟雾传感器");//以16进制换行输出接收代码
        RO = reset_MQ2();
        break;
      case ZERO:
        // buzzer = false;
        break;
    }
   delay(200);
   irrecv.resume(); 
  }
  //判断空气质量
  ratio = get_ratio(RO);
  //Serial.println(ratio);
  if (ratio < 4.5)
    buzzer = true;
  else
    buzzer = false;
  //判断是否报警
  if (buzzer)
    Buzzer_();
  else
    Buzzer_stop();
}
