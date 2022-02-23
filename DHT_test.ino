#include <dht.h>


#define dht_apin0 A0 // Analog Pin sensor is connected to
#define dht_apin1 A1 // Analog Pin sensor is connected to
 
dht DHT0, DHT1;
 
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT0.read11(dht_apin0); //reads data for first sensor
    
    Serial.print("Current humidity for first sensor = ");
    Serial.print(DHT0.humidity);
    Serial.print("%  ");
    Serial.print("temperature for first sensor = ");
    Serial.print(DHT0.temperature); 
    Serial.println("C  ");
    
    delay(2000);//Wait 2 seconds before accessing the second sensor.
    
    DHT1.read11(dht_apin1); //Reads data for second sensor
    
    Serial.print("Current humidity for second sensor = ");
    Serial.print(DHT1.humidity);
    Serial.print("%  ");
    Serial.print("temperature for second sensor = ");
    Serial.print(DHT1.temperature); 
    Serial.println("C  ");

    delay(2000);//Wait 2 seconds before accessing the first again.
 
}// end loop(











/*//
//    FILE: dht_test.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.07
// PURPOSE: DHT Temperature & Humidity Sensor library for Arduino
//     URL: https://arduino.cc/playground/Main/DHTLib
//
// Released to the public domain
//

#include <dht.h>

dht DHT;

#define DHT11_PIN 4
#define DHT21_PIN 5
#define DHT22_PIN 6

void setup()
{
  Serial.begin(115200);
  Serial.println("DHT TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT_LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
}

void loop()
{
  // READ DATA
  Serial.print("DHT22, \t");
  int chk = DHT.read22(DHT22_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
    Serial.print("OK,\t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.print("Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.print("Time out error,\t"); 
    break;
    default: 
    Serial.print("Unknown error,\t"); 
    break;
  }
  // DISPLAY DATA
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);

  delay(1000);


    // READ DATA
  Serial.print("DHT21, \t");
  chk = DHT.read21(DHT21_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
    Serial.print("OK,\t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.print("Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.print("Time out error,\t"); 
    break;
    default: 
    Serial.print("Unknown error,\t"); 
    break;
  }
  // DISPLAY DATA
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);

  delay(1000);

  // READ DATA
  Serial.print("DHT11, \t");
  chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
    Serial.print("OK,\t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.print("Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.print("Time out error,\t"); 
    break;
    default: 
    Serial.print("Unknown error,\t"); 
    break;
  }
 // DISPLAY DATA
  Serial.print(DHT.humidity,1);
  Serial.print(",\t");
  Serial.println(DHT.temperature,1);

  delay(1000);
}
//
// END OF FILE
//*/

