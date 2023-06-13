#include <ESP8266WiFi.h>
#include <DNSServer.h>

#ifndef STASSID
#define STASSID "LUCAS-BAESSE"
#define STAPSK  "123456@lcs"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

const char* host = "api.tago.io";
const uint16_t port = 80;

unsigned long flow_frequency; 
unsigned long currentTime;
unsigned long lastTime;
double fluxo;

void ICACHE_RAM_ATTR flow () {
   flow_frequency++;
}

void setup() {
  Serial.begin(115200);
  pinMode(4, INPUT);
  attachInterrupt(4, flow, RISING);
  currentTime = millis();
  lastTime = currentTime;
  
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  currentTime = millis();
  sei(); // Enable interrupts 
  if(currentTime >= (lastTime + 1000)){
    lastTime = currentTime;
    fluxo = (flow_frequency / 7.5); // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
    flow_frequency = 0;
  }
  
  String envio = "";

  Serial.print("connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);

  WiFiClient client;
  if (!client.connect(host, port)) {
    Serial.println("connection failed");
    delay(1000);
    return;
  }

  if (fluxo > 0) {

    if (client.connect(host, port)){

    envio = "POST /data  HTTP/1.1\n";
    envio += "Host: api.tago.io\n";

    envio += String("Device-Token: ") + "6615871e-6222-4e2e-9325-f02e611ff39f" + "\n";
    envio += " ssl: false\n";
    envio += String("Content-Type: ") + "application/json" + "\n";
    
    //String dados = "[ { \"variable\" : \"valor1\" , \"value\": \"+String(fluxo)+\"} ]";
    String dados =  "[{\"variable\":\"valor1\",\"value\":\"";
    dados += String(fluxo)+"\"}]";
    
    envio += String("Content-Length: ") + String(dados.length()) + "\n";
    envio += "\n";
    envio += dados;
    Serial.println(envio);
    client.print(envio);
    }

    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(" Client Timeout !");
        client.stop();
        delay(5000);
        return;
      }
    }
  }

  
  



  /*Serial.println("receiving from remote server");
  while (client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
  }*/

  Serial.println();
  
}
