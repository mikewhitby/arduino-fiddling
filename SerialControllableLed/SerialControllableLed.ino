/**
 * This sketch allows you to send 1 or 0 via the serial, which will control the
 * LED attached to pin 13, turning it on or off respectively
 */

// the LED pin
int ledPin = 13;

// the incoming serial data
int incomingByte = 0;

void setup()
{
    // opens serial port, sets data rate to 9600 bps
    Serial.begin(9600);

    // initialize the digital pin as an output.
    pinMode(ledPin, OUTPUT); 
}

void loop()
{
    // run code only when the serial port has some data waiting
    if (Serial.available()) {
        // read the incoming byte
        incomingByte = Serial.read();

        // turn the LED on (byte 49) or off (byte 48)
        if (incomingByte == 49) {
            digitalWrite(ledPin, HIGH);
            Serial.print("LED turned on\r\n");
        } else if (incomingByte == 48) {
            digitalWrite(ledPin, LOW);
            Serial.print("LED turned off\r\n");
        } else {
            Serial.print("Unknown byte - Please only send 1 (on) or 0 (off)\r\n");
        }
    }
}
