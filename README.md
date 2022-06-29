# Gateway LoRa - Microcontrolador ESPTTGO v1

> Dispositivo disponible en: [CRCibernetica](https://www.crcibernetica.com/ttgo-esp32-with-lora-and-oled-display-us915/) - Una puerta de enlace simple privada.

Colección de proyectos IoT para el programa de Hortalizas de la Estación Experimental Fabio Baudrit [UCR](https://eeafbm.ucr.ac.cr/).


### Empezando

Estas instrucciones le proporcionarán una copia del proyecto en funcionamiento en su máquina local para fines de desarrollo y prueba. Muy útil para pruebas de rendimiento, distancia y ajustes de backend..

### Requisitos previos

Qué cosas necesita para compilar y cargar el código y cómo instalarlas

1. ESP TTGO OLED V1.1 (disponible en [CRCibernetica](https://www.crcibernetica.com/ttgo-esp32-with-lora-and-oled-display-us915/) 

2. Windows 10, Linux, MacOS con VSCode y Platformio instalado (mi versión VSCode: 1.68.1 (Universal))

3. Cable USB con Micro-B para conectar a ESPTTGO

4. Servidor MQTT (estoy ejecutando EMQX en Docker)


### Instalación y Uso

Un paso a paso que le indica cómo poner en marcha un entorno de desarrollo/producción

1. Abra el VSCODE
2. Clone el proyecto git clone https://github.com/AgroExperimentalFB/LoRaGateway_ESPTTGO.git
3. Agregue su información de red, endpoint, MQTT y servidor en user-variables.h
4. El main.cpp contiene un objeto llamado Config con las variables sensor1 y sensor2 que se modificaran con el dato proveniente de algún LoRaNode_ESPTTGO en la función listeningLora() o process_sensors(), dependiendo de la naturaleza del proyecto.
5. El listenerLora al recibir un paquete, cambiará a true la variable dataLoRa y ejecuta la función sendToDashboard(config) que envía el dato a su broker MQTT personalizado.
6. Este proyecto utiliza el broker MQTT, cuyas funciones de conexión se encuentran en el iotcrv2-conector.h. Recomendamos tomar este archivo como inspiración para realizar la conexión, envío y recepción de parametros desde y hacía tu propio broker MQTT.


### Funcionamiento

El LoRaGateway_ESPTTGO se activará cada (en este caso) vez que recibe un dato proveniente de un LoRaNode_ESPTTGO, le informará el estado al servidor MQTT y, al mismo tiempo, se actualizará las variables sensor1 con los valores recibidos en la comunicación.

Una vez que se completan las funciones del Loop, la variable dataLoRa vuelve a false y envía una confirmación de recibido al LoRaNode_ESPTTGO para que éste entre en modo ahorro de energía.

Este proyecto emplea una red LoRa privada entre este LoRa Gateway y un LoRa Nodo, recibe el dato y lo envía por MQTT a todos los dispositivos suscritos al mismo tópico (actuadores, sensores, paginas web, backends).

El envío por http no está implementado ya que recomendamos manejar las reglas de guardado en bases de datos desde un broker MQTT o en tu propio backend.


### Despliegue

Consulte las instrucciones en **Requisitos previos**

### Versión

1.5 Actualización de versión principal, introducción de registro, cambio a PubSubClient, y correcciones de errores menores.

1.6 ...

### Autores

* **Por rosa**
* [ISProjectsIoTCR (colaborador)](https://github.com/ISProjectsIoTCR)

### Licencia

Momentaneament: Este proyecto tiene la licencia MIT; consulte el archivo [LICENSE.md](LICENSE.md) para obtener más información.






