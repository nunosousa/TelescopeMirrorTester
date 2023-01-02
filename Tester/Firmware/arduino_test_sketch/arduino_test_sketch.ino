#include <Wire.h>

// PCA9535 Interrupt pin
const byte interruptPin = 13;

// H-bridge enable pins
const byte hBridgeEn1 = 7;
const byte hBridgeEn2 = 2;
const byte hBridgeEn3 = 12;

// H-bridge PWM pins
const byte hBridgePWM1 = 11;
const byte hBridgePWM2 = 3;

// Current measurement pins
const int analogPin1 = A1;
const int analogPin2 = A2;
const int analogPin3 = A0;

// PCA9535 interript pint flag
char interruptFlag = 0;

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
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), printSwitch, FALLING);

  // Initialize h bridge enable pins as outputs and set their initial values
  pinMode(hBridgeEn1, OUTPUT);
  digitalWrite(hBridgeEn1, LOW);
  pinMode(hBridgeEn2, OUTPUT);
  digitalWrite(hBridgeEn2, LOW);
  pinMode(hBridgeEn3, OUTPUT);
  digitalWrite(hBridgeEn3, LOW);

  // Initialize h bridge PWM pins as normal outputs and set their initial values
  pinMode(hBridgePWM1, OUTPUT);
  digitalWrite(hBridgePWM1, LOW);
  pinMode(hBridgePWM2, OUTPUT);
  digitalWrite(hBridgePWM2, LOW);

  // Initialize analoge input pins
  pinMode(A0, INPUT);
  digitalWrite(A0, LOW);
  pinMode(A1, INPUT);
  digitalWrite(A1, LOW);
  pinMode(A2, INPUT);
  digitalWrite(A2, LOW);
}

void loop() {
  int rawCurrentValue = 0;
  float CurrentValue = 0.0;
  
  // ############################# Toggle LEDs one by one

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

  // #############################
  // Test the motors in both directions, one by one, and measure the current
  // H-bridge 1 direction a
  digitalWrite(hBridgeEn1, HIGH);
  digitalWrite(hBridgePWM1, HIGH);
  digitalWrite(hBridgePWM2, LOW);
  delay(1000);

  // Measure current
  rawCurrentValue = analogRead(analogPin1);
  CurrentValue = (rawCurrentValue / 20.0) / 0.25;
  Serial.println("Current on H-bridge 1, direction a");
  Serial.println(CurrentValue);
  delay(1000);

  // H-bridge 1 direction b
  digitalWrite(hBridgeEn1, HIGH);
  digitalWrite(hBridgePWM1, LOW);
  digitalWrite(hBridgePWM2, HIGH);
  delay(1000);

  // Measure current
  rawCurrentValue = analogRead(analogPin1);
  CurrentValue = (rawCurrentValue / 20.0) / 0.25;
  Serial.println("Current on H-bridge 1, direction b");
  Serial.println(CurrentValue);
  delay(1000);

  // H-bridge 1 disable
  digitalWrite(hBridgeEn1, LOW);
  digitalWrite(hBridgePWM1, LOW);
  digitalWrite(hBridgePWM2, LOW);
  delay(1000);

  // H-bridge 2 direction a
  digitalWrite(hBridgeEn2, HIGH);
  digitalWrite(hBridgePWM1, HIGH);
  digitalWrite(hBridgePWM2, LOW);
  delay(1000);

  // Measure current
  rawCurrentValue = analogRead(analogPin2);
  CurrentValue = (rawCurrentValue / 20.0) / 0.25;
  Serial.println("Current on H-bridge 2, direction a");
  Serial.println(CurrentValue);
  delay(1000);

  // H-bridge 2 direction b
  digitalWrite(hBridgeEn2, HIGH);
  digitalWrite(hBridgePWM1, LOW);
  digitalWrite(hBridgePWM2, HIGH);
  delay(1000);

  // Measure current
  rawCurrentValue = analogRead(analogPin2);
  CurrentValue = (rawCurrentValue / 20.0) / 0.25;
  Serial.println("Current on H-bridge 2, direction b");
  Serial.println(CurrentValue);
  delay(1000);

  // H-bridge 2 disable
  digitalWrite(hBridgeEn2, LOW);
  digitalWrite(hBridgePWM1, LOW);
  digitalWrite(hBridgePWM2, LOW);
  delay(1000);

  // H-bridge 3 direction a
  digitalWrite(hBridgeEn3, HIGH);
  digitalWrite(hBridgePWM1, HIGH);
  digitalWrite(hBridgePWM2, LOW);
  delay(1000);

  // Measure current
  rawCurrentValue = analogRead(analogPin3);
  CurrentValue = (rawCurrentValue / 20.0) / 0.25;
  Serial.println("Current on H-bridge 3, direction a");
  Serial.println(CurrentValue);
  delay(1000);

  // H-bridge 3 direction b
  digitalWrite(hBridgeEn3, HIGH);
  digitalWrite(hBridgePWM1, LOW);
  digitalWrite(hBridgePWM2, HIGH);
  delay(1000);

  // Measure current
  rawCurrentValue = analogRead(analogPin3);
  CurrentValue = (rawCurrentValue / 20.0) / 0.25;
  Serial.println("Current on H-bridge 3, direction b");
  Serial.println(CurrentValue);
  delay(1000);

  // H-bridge 3 disable
  digitalWrite(hBridgeEn3, LOW);
  digitalWrite(hBridgePWM1, LOW);
  digitalWrite(hBridgePWM2, LOW);

  // #############################
  // Check for switch interrupt and print which one was pressed
  if(interruptFlag != 0)
  {
    Serial.println("Interrupt activated");
    interruptFlag = 0;  // Clear flag
  }
  else
  {
    Serial.println("Interrupt not activated");
  }
  
  if(digitalRead(interruptPin) == HIGH)
  {
    Serial.println("Interrupt pin high");
  }
  else
  {
    Serial.println("Interrupt pin low");
  }

  char pinState1 = 0, pinState2 = 0, pinState3 = 0;

  // Read IO switch pins
  Wire.beginTransmission(0x20);   // begins a transmission to PCA9535 on address 0x20
  Wire.write(0x00);               // Input port 0 address
  Wire.requestFrom(0x20, 2);
  pinState1 = Wire.read();
  pinState2 = Wire.read();
  pinState3 = Wire.read();
  Wire.endTransmission();

  Serial.println("Switch input state:");
  Serial.println(pinState1, BIN);
  Serial.println(pinState2, BIN);
  Serial.println(pinState3, BIN);
}

void printSwitch() {
  interruptFlag = 1;
}
