#include <nRF24L01.h>
#include <RF24.h>
#include<SPI.h>
int X_axis = A0;
int Y_axis = A1;
int Z_axis = 2;
int x = 0;
int y = 0;
int z = 0;
RF24 radio(9,10);
const byte address[6] = "00001";
const char var1[32] = "up";
const char var2[32] = "down";
const char var3[32] = "left";
const char var4[32] = "right"; 
const char var5[32] = "ON";
const char var6[32] = "OFF";
boolean light = true;
int thresholdUP = 460;
int thresholdDOWN = 560;
int thresholdLEFT = 460;
int thresholdRIGHT = 560;
void setup()
{
radio.begin();
Serial.begin(9600);
pinMode(X_axis, INPUT);
pinMode(Y_axis, INPUT);
pinMode(Z_axis, INPUT);
digitalWrite(Z_axis, HIGH);
radio.openWritingPipe(address);
radio.setChannel(100);
radio.setDataRate(RF24_250KBPS);
radio.setPALevel(RF24_PA_MAX);
radio.stopListening();
}
void loop()
{
x = analogRead(X_axis);
y = analogRead(Y_axis);
z = digitalRead(Z_axis);
if(y <= thresholdUP)
{
radio.write(&var1, sizeof(var1));
}
if(y >= thresholdDOWN)
{
radio.write(&var2, sizeof(var2));
}
if(x <= thresholdLEFT)
{
radio.write(&var3, sizeof(var3));
}
if(x >= thresholdRIGHT)
{
radio.write(&var4, sizeof(var4));
}
if(z == LOW)
{
if(light == true)
{
radio.write(&var5, sizeof(var5));
light = false;
delay(200);
}
else
{
radio.write(&var6, sizeof(var6));
light = true;
delay(200);
}
}
}
