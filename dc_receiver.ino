#include <nRF24L01.h>
#include <RF24.h>
#include<SPI.h>
RF24 radio(9,10);
const byte address[6] = "00002";
const char var1[32] = "up";
const char var2[32] = "down";
const char var3[32] = "left";
const char var4[32] = "right";
const char var5[32] = "ON";
const char var6[32] = "OFF";
char input[32] = "";
const int output1 = 2;
const int output2 = 3;
const int output3 = 4;
const int output4 = 5;
const int light = 7;
void setup()
{
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, address);
radio.setChannel(100);
radio.setDataRate(RF24_250KBPS);
radio.setPALevel(RF24_PA_MAX);
radio.startListening();
pinMode(output1, OUTPUT);
pinMode(output2, OUTPUT);
pinMode(output3, OUTPUT);
pinMode(output4, OUTPUT);
pinMode(light, OUTPUT);
digitalWrite(output1, LOW);
digitalWrite(output2, LOW);
digitalWrite(output3, LOW);
digitalWrite(output4, LOW);
digitalWrite(light, LOW);
}
void loop()
{
while(!radio.available())
{
digitalWrite(output1, LOW);
digitalWrite(output2, LOW);
digitalWrite(output3, LOW);
digitalWrite(output4, LOW);
}
radio.read(&input, sizeof(input));
if((strcmp(input,var1) == 0))
{
digitalWrite(output1, HIGH);
digitalWrite(output2, LOW);
digitalWrite(output3, HIGH);
digitalWrite(output4, LOW);
delay(10);
}
else if((strcmp(input,var2) == 0))
{
digitalWrite(output1, LOW);
digitalWrite(output2, HIGH);
digitalWrite(output3, LOW);
digitalWrite(output4, HIGH);
delay(10);
}
else if((strcmp(input,var3) == 0))
{
digitalWrite(output3, HIGH);
digitalWrite(output4, LOW);
delay(10);
}
else if((strcmp(input,var4) == 0))
{
digitalWrite(output1, HIGH);
digitalWrite(output2, LOW);
delay(10);
}
else if((strcmp(input,var5) == 0))
{
digitalWrite(light, HIGH);
}
else if((strcmp(input,var6) == 0))
{
digitalWrite(light, LOW);
}
}
