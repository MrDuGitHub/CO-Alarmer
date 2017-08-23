#include"MQ2.H"
#include<Arduino.h>

float reset_MQ2()//计算洁净空气数值R0
{
  float sensor_volt = 0;//传感器电压
  float RS_air = 0; //  Get the value of RS via in a clear air
  float R0 = 0; // Get the value of R0 via in H2
  float sensorValue = 0;//传感器数值

  /*--- Get a average data by testing 100 times ---*/
  for (int x = 0 ; x < 100 ; x++)
  {
    sensorValue = sensorValue + analogRead(A0);
  }
  sensorValue = sensorValue / 100.0;

  sensor_volt = sensorValue / 1024 * 5.0;
  RS_air = (5.0 - sensor_volt) / sensor_volt; // omit *RL
  R0 = RS_air / 9.8; // The ratio of RS/R0 is 9.8 in a clear air from Graph (Found using WebPlotDigitizer)
  return R0;
}

float get_ratio(float R0)   //得到当前空气指数与洁净空气指数R0的比值
{
  float R=R0;
  float sensor_volt;
  float RS_gas; // Get value of RS in a GAS
  float ratio; // Get ratio RS_GAS/RS_air
  int sensorValue;
  sensorValue = analogRead(A0);
  sensor_volt = (float)sensorValue / 1024 * 5.0;
  RS_gas = (5.0 - sensor_volt) / sensor_volt; // omit *RL
  ratio = RS_gas / R; // ratio = RS/R0
  return ratio;
}

