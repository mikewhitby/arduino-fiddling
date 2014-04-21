/**
 * Reads an analog input and displays the reading and voltage. Used this to
 * fiddle with plugging the 3.3v and 5v outputs in to the input, and also to
 * mess about with an LDR (light dependant resistor)
 *
 * All worked fine, however I soon discovered my lack of electronics knowledge.
 * Turns out you can't just stick an LDR over the 5v and A0 pins - it works but
 * the reading is always high and only varied about .2v with the presence/lack
 * of light, so some googling found this page:
 *
 * http://bildr.org/2012/11/photoresistor-arduino/
 *
 * Still not really sure how this works, but it does work. The voltage varied
 * from .5v to 1.5v when dark / light.
 */

// the analog input pin
int inputPin = 0;

void setup()
{
    // opens serial port, sets data rate to 9600 bps
    Serial.begin(9600);

    // we don't need to call pinMode() for analog inputs apparently, probably
    // because they're already set as inputs, wonder if it's also true that
    // digital pins are always outputs? not sure
}

void loop()
{
    // get the reading, which is from int 0 (0v) to 1023 (5v)
    int reading = analogRead(inputPin);

    // turn the reading into a proper voltage by dividing by 214.6 (because
    // 5 * 204.6 = 1023)
    float voltage = reading / 204.6;

    Serial.print("Reading = ");
    Serial.print(reading);
    Serial.print(", voltage = ");
    Serial.print(voltage);
    Serial.print("v\r\n");

    delay(500);
}
