/**
 * Interface to LM259 multiplex latch chip
 */

// 74HC259 pins: (note we don't use PWM-capable output pins, SPI or I2C pins)
// 1's bit of output line (pin 1 of 74HG259)
const uint8_t PIN_X0 = 2;
// 2's bit of output line (pin 2 of 74HC259)
const uint8_t PIN_X1 = 4;
// 3's bit of output line (pin 3 of 74HC259)
const uint8_t PIN_X2 = 7;
// output latch data (pin 13 of 74HC259)
const uint8_t PIN_XDATA = 8;

// aliases for address lines on the 74HC259 (pass to write259 function)
const uint8_t X0 = 0;
const uint8_t X1 = 1;
const uint8_t X2 = 2;
const uint8_t X3 = 3;
const uint8_t X4 = 4;
const uint8_t X5 = 5;
const uint8_t X6 = 6;
const uint8_t X7 = 7;

void write259(uint8_t addr, bool value) {
  digitalWrite(PIN_X0, addr & 0x1);
  digitalWrite(PIN_X1, (addr & 0x2) >> 1);
  digitalWrite(PIN_X2, (addr & 0x4) >> 2);
  digitalWrite(PIN_XDATA, value);
}

// reset all output latches to 0
// (Note we don't use the reset functionality of the chip; need to do it manually)
void reset259() {
  for (uint8_t i = 0; i < 8; i++) {
    write259(i, LOW);
  }
}

void setup() {
  pinMode(PIN_X0, OUTPUT);
  pinMode(PIN_X1, OUTPUT);
  pinMode(PIN_X2, OUTPUT);
  pinMode(PIN_XDATA, OUTPUT);
  reset259();

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
