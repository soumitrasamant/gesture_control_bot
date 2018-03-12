/*
 * Project : Gesture Control Toy Car (https://github.com/soumitrasamant/gesture_control_bot/)
 * Author : Soumitra Samant (https://github.com/soumitrasamant)
 * Version : 1.0
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
  
  //Serial.print("xval=");
  //Serial.println(xval);
  
  //Serial.print("yval=");
  //Serial.println(yval); 
  
  //delay(500);   //used to display values after 1s delay
  
  //Serial.print("\n");
  
  if ((xval>349 && xval<376) && (yval>359 && yval<395)) //stationary or stop(transmitter parallel to ground)
  {
    send('s');
    Serial.println("Parallel");
  } 
  else 
  { 
    if ((xval>344 && xval<388) && (yval>425 && yval<460)) //forward(transmitter tilted forward)
    {
      send('f');
      Serial.println("Forward"); 
    }
    if ((xval>350 && xval<365) && (yval>280 && yval<300)) //backward(transmitter tilted backward)
    {
      send('a');
      Serial.println("Backward");
    }
    if ((xval>280 && xval<300) && (yval>350 && yval<370)) //left(transmitter tilted to left)
    {
      send('l');
      Serial.println("Left");
    }
     if ((xval>420 && xval<451) && (yval>350 && yval<380))//right(transmitter tilted to right)
    {
      send('r');
      Serial.println("Right"); 
    }
  }
  delay(1000);
  
}


void send(char *message)  //send function definition
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
}
