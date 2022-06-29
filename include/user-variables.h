#include <Arduino.h>

//CONEXION CON IoTPROJECTS
String dId = "did_dashboard";
String webhook_pass = "pass_dashboard";
String webhook_endpoint = "http://YOUR_SERVER/api/getdevicecredentials";
const char *mqtt_server= "YOUR_SERVER";


//CONFIGURACION DE WiFi
const char *wifi_ssid = "AP_31607";
const char *wifi_password = "";

const long sendDBInterval = 60000;
