#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

//////////////////////////////////////////////
//             CACEROLOBOT                  //
//////////////////////////////////////////////
// Se que hay codigo que sobra, pero fue hecho a la rapida jaja
// aun hay varias cosas que pulir, pero de momento funciona asi que \_( ._. )_/
//

// SCL GPIO5
// SDA GPIO4
#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);   // Le decimos al microporcesadorq que estamos usando una pantalla

Servo servo;    // le decimos al microprocesador que tenemos un servo que se llama servo
Servo servo2;   // le decimos al microprocesador que tenemos un servo que se llama servo2
unsigned long previousMillis = 0;   // Indicamos que vamos a usar una variable llamada previousMillis
unsigned long previousMillis_1 = 0; // Indicamos que vamos a usar una variable llamada previousMillis_1
unsigned long previousMillis_2 = 0; // Indicamos que vamos a usar una variable llamada previousMillis_2

// Dado que queremos hacer cosas en paralelo, tenemos que tener una variable para saber en que estado del programa
// nos encontramos, asi cuando pase el tiempo esperado, le cambiamos el valor a nuestro estado.

int state = 0;  // Esta variable guarda el estado del parpadeo de los ojos del bot
int servo_state = 0;    // Aqui guardamos el estado en el que se encuentra el servo 1
int servo2_state = 0;   // Aqui el estado del servo 2


void setup() {
    // void setup() {} se ejecuta una sola vez cuando prendemos el microprocesador
  servo.attach(D3);  // Aqui le decimos al micro que uno de los servo motores se encuentra conectado en el conector D3
  servo2.attach(D6); // Aqui le decimos al micro que uno de los servo motores se encuentra conectado en el conector D6

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // iniciamos la comunicacion I2C en la direccion 0x3C (para la pantalla)
  display.display();    // Con este comando cargamos en pantalla el dibujo que se encuentre en el buffer de la pantalla
  delay(100);   // esperamos 100 milisegundos
  display.clearDisplay();   // Borramos el contenido del buffer de la pantalla
  display.drawRect(17, 19, 5, 2, WHITE);    // Dibujamos el ojo izquiedo del bot como un rectangulo de 5x2
  display.drawRect(38, 19, 5, 2, WHITE);    // dibujamos el ojo derecho del bot como un rectangulo de 5x2
  display.drawRect(19, 30, 22, 1, WHITE);   // dibujamos la boca del bot como un rectangulo de 22x1
  display.display();    // La cara del robot no sera mostrada en pantalla hasta que ejecutemos este comando
  servo.write(20);  // Movemos el servo 1 a un angulo de 20° como posicion inicial
  servo2.write(20); // movemos el servo 2 a un angulo de 20° como posicion inicial
  // el comando millis() retorna el tiempo en milisegundos que lleva funcionando el microprocesador
  previousMillis = millis();    // actualizamos el tiempo de funcionamiento en la variable previousMillis
  previousMillis_1 = millis();  // actualizamos el tiempo de funcionamiento en la variable previousMillis_1
  previousMillis_2 = millis();  // actualizamos el tiempo de funcionamiento en la variable previousMillis_2
}


void loop() {
  // Aqui va el codigo principal que se repetira mientras este prendida la tarjeta
  blink_eyes(); // ejecutamos el codigo que se encarga de hacer que parpadee
  move_servo(); // ejecutamos el codigo que se encarga de mover el servo 1
  move_servo2();// ejecutamos el codigo que se encarga de mover el servo 2
}


void move_servo() {
  unsigned long currentMillis = millis(); // Al momento de ejecurar esta funcion, debemos ver "que hora es" en el micro
  if ((servo_state == 0) && (currentMillis - previousMillis_1 >= 300)) {
    // Si se cumple que la variable servo_state vale 0 y desde la ejecucion previa han pasado mas de 300 milisegundos
    // entonces ejecuta los siguientes comandos:
    servo.write(20);   // mueve el servo a un angulo de 20°
    previousMillis_1 = currentMillis;   // actualizamos el tiempo de ejecucion en nuestra variable
    servo_state += 1;  // modificamos el estado a 1
  } else if ((servo_state == 1) && (currentMillis - previousMillis_1 >= 300)) {
    // Si la condicion del if anterior no se cumplio, entonces debemos ver que nos encontremos en el estado 1 y que
    // además hayan pasado 300 milisegundos de la ultima actualizacion de posicion del servo, si se cumple, entonces:
    servo.write(90);   // mueve el servo a un angulo de 90°
    previousMillis_1 = currentMillis;   // actualiza el tiempo de ejecucion en la variable previousMillis_1
    servo_state += 1;  // nos movemos al siguiente estado que sería el estado 2
  } else if ((servo_state == 2) && (currentMillis - previousMillis_1 >= 300)) {
    // Si no se cumplio lo del primer if ni tampoco lo del segundo if, debemos corroborar que nos encontremos en el
    // estado 2 y que además hayan pasado mas de 300 milisegundos desde la ultima vez que modificamos la posicion del
    // servo, si se cumplen estas condiciones, entonces:
    servo.write(180); // mueve el servo a un angulo de 180°
    previousMillis_1 = currentMillis; // actualiza el tiempo de ejecucion en la variable
    servo_state = 0;   // nos movemos al estado 0
  }
}


void move_servo2() {
    // Esta funcion funciona de la misma forma que la funcion move_servo(), la unica diferencia es que esta funcion
    // modifica la posicion del servo2
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


void blink_eyes() {
    // Al igual que en las funciones move_servo() y move_servo2() aqui hacemos uso de la funcion millis() para calcular
    // el paso del tiempo para asi ejecutar varias funciones al mismo tiempo
  unsigned long currentMillis = millis();
  if ((state == 0) && (currentMillis - previousMillis >= 2500)) {
    // Si se cumple que nos encontramos en el estado 0, y, han pasado mas de 2500 milisegundos (2,5 segundos) entonces
    // dibuja los ojos abiertos:
    display.clearDisplay(); // Borra la imagen que se encuentre en el buffer de la pantalla
    display.drawRect(19, 15, 2, 5, WHITE);  // Dibuja un rectangulo en la posicion 19,15 de 2x5 de color blanco
    display.drawRect(40, 15, 2, 5, WHITE);  // Dibuja un rectangulo en la posicion 40,15 de 2x5 de color blanco
    display.drawRect(19, 30, 22, 1, WHITE); // Dibuja un rectangulo en la posicion 19,30 de 22x1 de color blanco
    display.display();  // Actualiza la pantalla con el dibujo que hemos guardado en el buffer
    previousMillis = currentMillis; // actualiza el tiempo de ejecucion
    state += 1; // modifica el estado a estado 1
  } else if ((state == 1) && (currentMillis - previousMillis >= 60)) {
    // Si no se cumple el if anterior y se cumple que estamos en el estado 1 y han pasado mas de 60 milisegundos
    // entonces dibuja los ojos cerrados:
    display.clearDisplay(); // Borra la imagen que se encuentre en el buffer de la pantalla
    display.drawRect(17, 19, 5, 2, WHITE);  // Dibuja un rectangulo en la posicion 17,19 de 5x2 de color blanco
    display.drawRect(38, 19, 5, 2, WHITE);  // Dibuja un rectangulo en la posicion 38,19 de 5x3 de color blanco
    display.drawRect(19, 30, 22, 1, WHITE);  // Dibuja un rectangulo en la posicion 19,30 de 22x1 de color blanco
    display.display();  // Actualiza la pantalla con el dibujo que hemos guardado en el buffer
    previousMillis = currentMillis; // actualiza el tiempo de ejecucion
    state += 1; // modifica el estado a estado 2
  } else if ((state == 2) && (currentMillis - previousMillis >= 60)) {
    // Si no se cumple ninguno de los dos if anterior y se cumple que estamos en el estado 2 y han pasado
    // mas de 60 milisegundos entonces dibuja los ojos abiertos:
    display.clearDisplay(); // Borra la imagen que se encuentre en el buffer de la pantalla
    display.drawRect(19, 15, 2, 5, WHITE);  // Dibuja un rectangulo en la posicion 19,15 de 2x5 de color blanco
    display.drawRect(40, 15, 2, 5, WHITE);  // Dibuja un rectangulo en la posicion 40,15 de 2x5 de color blanco
    display.drawRect(19, 30, 22, 1, WHITE); // Dibuja un rectangulo en la posicion 19,30 de 22x1 de color blanco
    display.display();  // Actualiza la pantalla con el dibujo que hemos guardado en el buffer
    previousMillis = currentMillis; // actualiza el tiempo de ejecucion
    state = 0; // modifica el estado a estado 0
  }
}