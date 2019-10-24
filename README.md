# CACEROLOBOT
El codigo de nuestro pequeño luchador, si quieren ver mas actualizaciones o videos del robot pueden verlos desde mi instagram [@nicosepuvilla](https://www.instagram.com/nicosepuvilla)

![](https://media.giphy.com/media/QWvamj343WErKEmCqz/giphy.gif)

## Piezas Requeridas
El cerebro del bot corresponde a una placa wemos d1 mini que tiene un microprocesador ESP8266. La pantalla OLED es de 64x48 tambien de wemos. Los brazos corresponden a servomotores SG90.

- wemos D1 mini v3.0.0
![](https://wiki.wemos.cc/_media/products:d1:d1_mini_v3.0.0_1_16x9.jpg)

- wemos OLED SHIELD v1.1.0
![](https://wiki.wemos.cc/_media/products:d1_mini_shields:oled_v1.1.0_1.jpg)

- Servomotor SG90
![](https://robu.in/wp-content/uploads/2017/09/IMG_0521.jpg)

- Jumpers macho-macho
![](https://www.electrio.es/WebRoot/StoreES3/Shops/80295836/5725/DB96/856C/5C75/2BBB/C0A8/2AB9/8875/Cables_Dupont_macho_macho_00con_marca_ml.JPG)

- Protoboard
![](https://www.geekfactory.mx/wp-content/uploads/2014/04/prototipos_1.jpg)

## Donde comprar? (Chile)
Muchas personas me han preguntado donde pueden conseguir los materiales para la construcción de su propio cacerolobot. La verdad existen muchas tiendas donde pueden conseguir los materiales aquí en Chile. Idealmente, por precio les recomendaría encargar por aliexpress dado que las tiendas establecidas en Chile cobran más caro por los materiales, pero los tienen disponibles inmediatamentes.
Lo importante es que cotizen bien donde comprar, hay varias tiendas, por lo general el recorrido que hago para buscarlas es

- Google (directamente para ver las tiendas disponibles)
- AliExpress (necesitan tarjeta de crédito para esto, pero la app Match da una buena ayuda en ese sentido)
- Mercadolibre (para ver el rango de precios a que esta mas o menos en el país)

Distribuidores de componentes electrónicos y de hobby que conozco en Santiago son los siguientes
- [Afel](https://afel.cl/)
- [amgkits](https://amgkits.com/)
- [mirax](https://mirax.cl/)
- [olimex](http://olimex.cl/)

Nuevamente les recomiendo cotizar bien si van a comprar directamente en Chile, dado que a veces hay lugares donde es más baratos que en otros.


## Conexiones

Las conexiones que se deben hacer son las siguientes

![](https://i.ibb.co/GW3tRz3/conexiones.jpg)

Si bien el cable que se ve de los dos servos es del mismo color, cada uno está conectado a un pin distinto de la placa, uno conectado al pin D3 y otro conectado al pin D6.

Los cables del servomotor tienen colores y estos estan indicados en la imagen a que corresponden.


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
