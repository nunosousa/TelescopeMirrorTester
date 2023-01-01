#include <Wire.h>

// PCA9535 Interrupt pin
const byte interruptPin = 13;

void setup() {
  // Initialize UART
  Serial.begin(9600);  // start serial for output

  // Initialize I2C and configure PCA9535 I/Os
  Wire.begin();                   // join I2C bus as master
  Wire.setClock(100000);          // standard mode
  
  Wire.beginTransmission(0x20);   // begins a transmission to PCA9535 on address 0x20
  Wire.write(0x03);               // Output port 1 register address
  Wire.write(0x0F);               // Set outputs on port 0 (LEDs) to high
  Wire.endTransmission();
  
  Wire.beginTransmission(0x20);   // begins a transmission to PCA9535 on address 0x20
  Wire.write(0x06);               // Configuration port 0 register address
  Wire.write(0xFF);               // Set configuration port 0 (inputs only)
  Wire.write(0xF0);               // Set configuration port 1 (outputs and inputs)
  Wire.endTransmission();

  // Initialize interrupt pin
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), printSwitch, FALLING);



    // initialize the LED pin as an output:
  //pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  //pinMode(buttonPin, INPUT);
}

void loop() {

  // Toggle LEDs one by one

  // LED 0 () on
  Wire.beginTransmission(0x20);   // begins a transmission to PCA9535 on address 0x20
  Wire.write(0x03);               // Output port 1 register address
  Wire.write(0x0E);               // Set outputs on port 0 (LEDs)
  Wire.endTransmission();

  delay(1000);

  // LED 0 () off
  Wire.beginTransmission(0x20);   // begins a transmission to PCA9535 on address 0x20
  Wire.write(0x03);               // Output port 1 register address
  Wire.write(0x0F);               // Set outputs on port 0 (LEDs)
  Wire.endTransmission();

  delay(1000);

  // LED 1 () on
  Wire.beginTransmission(0x20);   // begins a transmission to PCA9535 on address 0x20
  Wire.write(0x03);               // Output port 1 register address
  Wire.write(0x0D);               // Set outputs on port 0 (LEDs)
  Wire.endTransmission();

  delay(1000);

  // LED 1 () off
  Wire.beginTransmission(0x20);   // begins a transmission to PCA9535 on address 0x20
  Wire.write(0x03);               // Output port 1 register address
  Wire.write(0x0F);               // Set outputs on port 0 (LEDs)
  Wire.endTransmission();

  delay(1000);

  // LED 2 () on
  Wire.beginTransmission(0x20);   // begins a transmission to PCA9535 on address 0x20
  Wire.write(0x03);               // Output port 1 register address
  Wire.write(0x0B);               // Set outputs on port 0 (LEDs)
  Wire.endTransmission();

  delay(1000);

  // LED 2 () off
  Wire.beginTransmission(0x20);   // begins a transmission to PCA9535 on address 0x20
  Wire.write(0x03);               // Output port 1 register address
  Wire.write(0x0F);               // Set outputs on port 0 (LEDs)
  Wire.endTransmission();

  delay(1000);

  // LED 3 () on
  Wire.beginTransmission(0x20);   // begins a transmission to PCA9535 on address 0x20
  Wire.write(0x03);               // Output port 1 register address
  Wire.write(0x07);               // Set outputs on port 0 (LEDs)
  Wire.endTransmission();

  delay(1000);

  // LED 3 () off
  Wire.beginTransmission(0x20);   // begins a transmission to PCA9535 on address 0x20
  Wire.write(0x03);               // Output port 1 register address
  Wire.write(0x0F);               // Set outputs on port 0 (LEDs)
  Wire.endTransmission();

  // Test the motors in both directions, one by one, and measure the current
  // do stuf




/*
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  delay(1);  // delay in between reads for stability
  */
}

void printSwitch() {
  char pinState;

  // Read IO switch pins
  Wire.beginTransmission(0x20);   // begins a transmission to PCA9535 on address 0x20
  Wire.write(0x00);               // Input port 0 address
  pinState = Wire.read();         // Get input port 0 bit status
  Wire.endTransmission();

  switch (pinState)
  {
    case 0x01:
      Serial.println("LIM_SW00 pressed");
      break;
    case 0x02:
      Serial.println("LIM_SW01 pressed");
      break;
    case 0x04:
      Serial.println("LIM_SW02 pressed");
      break;
    case 0x08:
      Serial.println("LIM_SW03 pressed");
      break;
    case 0x10:
      Serial.println("LIM_SW04 pressed");
      break;
    case 0x20:
      Serial.println("LIM_SW05 pressed");
      break;
  }
}
