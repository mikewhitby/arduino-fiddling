/**
 * Turns on an led when an LDR detects the board is in shade, which I'm saying
 * is below a reading of 205 (about 1v)
 */

// the LDR input pin
int analogInputPin = 0;

// the LED output pin
int ledPin = 13;

// the state of the LED (0 is off, 1 is on)
int ledState;

void setup()
{
    Serial.begin(9600);

    pinMode(ledPin, OUTPUT); 

    // turn the LED off initially
    digitalWrite(ledPin, LOW);
    ledState = 0;
}

void loop()
{
    // get the reading, which is from int 0 (0v) to 1023 (5v)
    int reading = analogRead(analogInputPin);

    // we wouldn't need ledState if it wasn't for printing to the console,
    // but seeing as we only want to display state changes, we need to maintain
    // state
    if (reading < 205 && !ledState) {
        digitalWrite(ledPin, HIGH);
        ledState = 1;
        Serial.print("Turned LED on\r\n");
    } else if (reading >= 205 && ledState) {
        digitalWrite(ledPin, LOW);
        ledState = 0;
        Serial.print("Turned LED off\r\n");
    }
}
