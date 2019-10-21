#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

// SCL GPIO5
// SDA GPIO4
#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

Servo servo;
Servo servo2;
unsigned long previousMillis = 0;
unsigned long previousMillis_1 = 0;
unsigned long previousMillis_2 = 0;

int state = 0;
int servo_state = 0;
int servo2_state = 0;

void setup() {
  servo.attach(D3);
  servo2.attach(D6);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // iniciamos la comunicacion I2C en la direccion 0x3C (para la pantalla)
  display.display();
  delay(100);
  display.clearDisplay();
  display.drawRect(17, 19, 5, 2, WHITE);
  display.drawRect(38, 19, 5, 2, WHITE);
  display.drawRect(19, 30, 22, 1, WHITE);
  display.display();
  servo.write(20);
  servo2.write(20);
  previousMillis = millis();
  previousMillis_1 = millis();
  previousMillis_2 = millis();
}

void loop() {
  // Aqui va el codigo principal que se repetira mientras este prendida la tarjeta
  blink_eyes();
  move_servo();
  move_servo2();
}

void move_servo2() {
  unsigned long currentMillis = millis();
  if ((servo2_state == 0) && (currentMillis - previousMillis_2 >= 300)) {
    servo2.write(20);
    previousMillis_2 = currentMillis;
    servo2_state += 1;
  } else if ((servo2_state == 1) && (currentMillis - previousMillis_2 >= 300)) {
    servo2.write(90);
    previousMillis_2 = currentMillis;
    servo2_state += 1;
  } else if ((servo2_state == 2) && (currentMillis - previousMillis_2 >= 300)) {
    servo2.write(180);
    previousMillis_2 = currentMillis;
    servo2_state = 0;
  }
}

void move_servo() {
  unsigned long currentMillis = millis();
  if ((servo_state == 0) && (currentMillis - previousMillis_1 >= 300)) {
    servo.write(20);
    previousMillis_1 = currentMillis;
    servo_state += 1;
  } else if ((servo_state == 1) && (currentMillis - previousMillis_1 >= 300)) {
    servo.write(90);
    previousMillis_1 = currentMillis;
    servo_state += 1;
  } else if ((servo_state == 2) && (currentMillis - previousMillis_1 >= 300)) {
    servo.write(180);
    previousMillis_1 = currentMillis;
    servo_state = 0;
  }
}

void blink_eyes() {
  unsigned long currentMillis = millis();
  if ((state == 0) && (currentMillis - previousMillis >= 2500)) {
    display.clearDisplay();
    display.drawRect(19, 15, 2, 5, WHITE);
    display.drawRect(40, 15, 2, 5, WHITE);
    display.drawRect(19, 30, 22, 1, WHITE);
    display.display();
    previousMillis = currentMillis;
    state += 1;
  } else if ((state == 1) && (currentMillis - previousMillis >= 60)) {
    display.clearDisplay();
    display.drawRect(17, 19, 5, 2, WHITE);
    display.drawRect(38, 19, 5, 2, WHITE);
    display.drawRect(19, 30, 22, 1, WHITE);
    display.display();
    previousMillis = currentMillis;
    state += 1;
  } else if ((state == 2) && (currentMillis - previousMillis >= 60)) {
    display.clearDisplay();
    display.drawRect(19, 15, 2, 5, WHITE);
    display.drawRect(40, 15, 2, 5, WHITE);
    display.drawRect(19, 30, 22, 1, WHITE);
    display.display();
    previousMillis = currentMillis;
    state = 0;
  }
}