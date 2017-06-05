#include <dht.h>

dht DHT;

#define DHT11_PIN A0

void setup(){
  
Serial.begin(9600);
}
void loop()
{
  int chk = DHT.read11(DHT11_PIN);
 // Serial.print("Temperature = ");
  Serial.print(DHT.humidity);
  Serial.print(',');
  //Serial.println("Humidity = ");
  Serial.println(DHT.temperature);
  
  delay(900000);
}

