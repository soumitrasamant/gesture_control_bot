/*
 * Project : Gesture Control Toy Car (https://github.com/soumitrasamant/gesture_control_bot/)
 * Author : Soumitra Samant (https://github.com/soumitrasamant)
 * Version : 1.0
 */
#include <VirtualWire.h>

void setup()
{
    Serial.begin(9600); // Debugging only
    pinMode(13,OUTPUT);
    //vw_set_ptt_inverted(true); // Required when using encoder/decoder
    vw_setup(2000);  // Bits per sec

    vw_rx_start();       // Start the receiver
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
    int i;

        digitalWrite(13, HIGH); // Turn led 13 pin on 
    Serial.print("Received: ");

    for (i = 0; i < buflen; i++)
    {
        Serial.print(char(buf[i]));
    }
    Serial.println("");
        digitalWrite(13, LOW);
    }
}
