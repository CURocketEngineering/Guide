#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

/* Set the delay between fresh samples */
uint16_t BNO055_SAMPLERATE_DELAY_MS = 100;

Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28); // Check I2C device address and correct line below (by default address is 0x29 or 0x28)



void setup(void)
{
  Serial.begin(115200);
  Serial.println("Orientation Sensor Test"); 
  Serial.println("");
  pinMode(13,OUTPUT);
  pinMode(7,OUTPUT);
  
  /* Initialise the sensor */
  if (!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while (1);
  }

  delay(1000);
}



void loop(void)
{
  sensors_event_t orientationData , angVelocityData , linearAccelData;
  bno.getEvent(&angVelocityData, Adafruit_BNO055::VECTOR_GYROSCOPE);

  printEvent(&angVelocityData);

  delay(BNO055_SAMPLERATE_DELAY_MS);
}

void printEvent(sensors_event_t* event) {
  Serial.println();
//  Serial.print(event->type);
  double x = -1000000, y = -1000000 , z = -1000000; //dumb values, easy to spot problem
  
  
  if (event->type == SENSOR_TYPE_ORIENTATION) {
    x = event->orientation.x;
    y = event->orientation.y;
    z = event->orientation.z;
  }
  else if (event->type == SENSOR_TYPE_ROTATION_VECTOR) {
    x = event->gyro.x;
    y = event->gyro.y;
    z = event->gyro.z;
  }
  
  // Serial.print("x= ");
  Serial.print(x);
  // Serial.print("| y= ");
  Serial.print(" ");
  Serial.print(y);
  // Serial.print("| z= "); // this value will be used for testing, should not be used for real application
  Serial.print(" ");
  Serial.println(z);

  if (z > 10){
    digitalWrite(7,HIGH); // if the ang vel about the z-axis is above 10 [rad/s]
    delay(50); // Because the data refresh rate is so low, without this, the arduino would constantly overcorrect and would not be able to make fine corrections.
    digitalWrite(7,LOW); // terminates the command to open the solenoid valve, to prevent over correction.
    }
    else if (z < -10) 
    {
    digitalWrite(13,HIGH); // or below -10 [rad/s] the light turns on
    delay(50);
    digitalWrite(13,LOW); 
    }
    else 
    {
    digitalWrite(7,LOW); // if the ang vel about the z-axis is between 10 and -10 then the light turns off
    digitalWrite(13,LOW);
    // delay(500); // delay to prevent over correcting
  }

  
}
