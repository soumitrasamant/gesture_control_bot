/*
 * Project : Gesture Control Toy Car (https://github.com/soumitrasamant/gesture_control_bot/)
 * Author : Soumitra Samant (https://github.com/soumitrasamant)
 * Version : 1.1
 */

#include <VirtualWire.h>

int xPin=2;    // X pin of the ADXL335 accelerometer
int yPin=4;    // Y pin of the ADXL 335 accelerometer
void setup() 
{
  vw_setup(2000); //Bits per second
  Serial.begin(9600); //Initialise the serial connection debugging
}

void loop() 
{
  int xval=analogRead(xPin); // Storing the ADXL335 readings in xval and y val
  int yval=analogRead(yPin);
  
  // Unomment the next code for debugging and finding the threshold values for different orientations
  
  Serial.print("xval=");
  Serial.println(xval);
  
  Serial.print("yval=");
  Serial.println(yval); 
  
  //delay(500);   //used to display values after 1s delay
  
  Serial.print("\n");
  
  if ((xval>340 && xval<380) && (yval>350 && yval<395)) //stationary or stop(transmitter parallel to ground)
  {
    const char *msg0 = "parallel";
    Serial.println("Parallel");
    vw_send((uint8_t *)msg0, strlen(msg0));
    vw_wait_tx();
  } 
  else 
  { 
    if ((xval>340 && xval<388) && (yval>420 && yval<460)) //forward(transmitter tilted forward)
    {
      const char *msg1 = "forward";
      Serial.println("Forward");
      vw_send((uint8_t *)msg1, strlen(msg1));
      vw_wait_tx(); 
    }
    if ((xval>340 && xval<365) && (yval>270 && yval<300)) //backward(transmitter tilted backward)
    {
      const char *msg2 = "backward";
      Serial.println("Backward");
      vw_send((uint8_t *)msg2, strlen(msg2));
      vw_wait_tx();
    }
    if ((xval>260 && xval<310) && (yval>330 && yval<390)) //left(transmitter tilted to left)
    {
      const char *msg3 = "left";
      Serial.println("Left");
      vw_send((uint8_t *)msg3, strlen(msg3));
      vw_wait_tx();
    }
     if ((xval>410 && xval<451) && (yval>330 && yval<380))//right(transmitter tilted to right)
    {
      const char *msg4 = "right";
      Serial.println("Right");
      vw_send((uint8_t *)msg4, strlen(msg4));
      vw_wait_tx(); 
    }
  }
  delay(1000);
  
}
