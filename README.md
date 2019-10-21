# CACEROLOBOT
El codigo de nuestro pequeño luchador

## Piezas Requeridas
El cerebro del bot corresponde a una placa wemos d1 mini que tiene un microprocesador ESP8266. La pantalla OLED es de 64x48 tambien de wemos. Los brazos corresponden a servomotores SG90.

- wemos D1 mini v3.0.0
![](https://wiki.wemos.cc/_media/products:d1:d1_mini_v3.0.0_1_16x9.jpg)

- wemos OLED SHIELD v1.1.0
![](https://wiki.wemos.cc/_media/products:d1_mini_shields:oled_v1.1.0_1.jpg)

- Servomotor SG90
![](https://robu.in/wp-content/uploads/2017/09/IMG_0521.jpg)

## Descargas e instalación

Para programar la placa, es necesario descargar e instarlar el IDE de Arduino, esto se puede hacer directamente desde la página oficial de arduino.

- [ARDUINO](https://www.arduino.cc/en/Main/Software)

(Si quieres hacer esto con una placa Arduino, no debes seguir los siguientes pasos de esta sección)

Una vez instalado arduino, para poder programar nuestra placa con el microprocesador ESP8266, debemos instalar los "drivers" necesarios, esto se puede hacer directamente desde el IDE de Arduino. Para ello debemos ir a

- Archivo > Preferencias > Ajustes

En esta ventana debemos buscar en la parte que diga "Gestor de URLs Adicionales de Tarjetas: " y copiar el siguiente url (Si ya tienen otro url ahí, basta con poner un ; para separar y poder poner el nuevo url):

````
https://arduino.esp8266.com/stable/package_esp8266com_index.json
````

con esto le damos a "Ok" y procedemos a abrir el "Gestor de Tarjetas". Para esto es necesario ir en la barra superior del IDE de Arduino al seleccionador de placas

- Herramientas > Placa > "Gestor de Tarjetas..."

Una vez abierto el gestor en la barra de búsqueda debemos escribir ESP8266 y ahí nos saldrá uno que se llama 

- "esp8266 by ESP8266 Community" 

y le damos instalar.

Ya instalado el gestor de tarjetas, nos vamos al seleccionador de placas y escogemos la que dice

- "LOLIN(WEMOS) D1 mini Pro"

y con esto ya tenemos todo seteado para cargarle programas a nuestra tarjeta.

## Librerias
Para poder hacer funcionar la pantalla OLED de 64x48 se uso una librería modificada distinta a la que ofrece adafruit, esta libreria modificada está disponible en el mismo buscador de librerias de Arduino.

Las librerías a usar son:

- Adrafuit GFX Library
- Adafruit SSD1306 Wemos Mini OLED

Para buscar e instalar una librería en arduino, debemos ir a 

- Herramientas > Administrar Bibliotecas...

donde tendremos la opción de buscar las librerías, instalarlas y actualizarlas.