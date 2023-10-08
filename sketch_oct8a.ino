#include <WiFiNINA.h>

#include <BH1750.h>
#include <Wire.h>

//please enter your sensitive data in the Secret tab
char ssid[] = "ryan.n";
char pass[] = "12345678";

WiFiClient client;
BH1750 lightMeter;

char HOST_NAME[] = "maker.ifttt.com";
String PATH_NAME   = "/trigger/Light/with/key/e1qOxnSfrXsSfL_QrVp1zHRVYabpxFrPMPKmYojfAPQ"; // change your EVENT-NAME and YOUR-KEY
String queryString = "?value1=57&value2=25";

void setup() {
  // initialize WiFi connection
  WiFi.begin(ssid, pass);
  Serial.begin(9600);
  Serial.println("START");
  delay(900);
  while (!Serial);
  // connect to web server on port 80:
  while(true)
  {
  if (client.connect(HOST_NAME, 80)) {
    // if connected:
    Serial.println("Connected to server");
    break;
  }
  else {// if not connected:
    Serial.println("connection failed");
     WiFi.begin(ssid, pass);
  }
  delay(400);
  }
  Serial.print("Connection Successful!!!");
    Wire.begin();
  lightMeter.begin();
}

void loop() {
Serial.println(queryString);
float lux = lightMeter.readLightLevel();

  // Serial.println("Light sensor: ");
  // Serial.p'int(lux);

  queryString +="?value1=" ;
  queryString += lux;
  Serial.println(queryString);
  if (client.connect(HOST_NAME, 80)){

  if (lux > 500) {

    // make a HTTP request:
    // send HTTP header
    Serial.print("Sending!!!");
    client.println("GET " + PATH_NAME + queryString + " HTTP/1.1");
    client.println("Host: " + String(HOST_NAME));
    client.println("Connection: close");
    client.println(); // end HTTP header

Serial.print("CLIENT saying: ");
    while (client.connected()) {
      if (client.available()) {
        // read an incoming byte from the server and print it to serial monitor:
        char c = client.read();
        
        Serial.print(c);
      }
    }

    // the server's disconnected, stop the client:
    client.stop();
    Serial.println();
    Serial.println("disconnected");
  }
  }
   queryString = "";
delay(3000);
}#include <WiFiNINA.h>

#include <BH1750.h>
#include <Wire.h>

//please enter your sensitive data in the Secret tab
char ssid[] = "ryan.n";
char pass[] = "12345678";

WiFiClient client;
BH1750 lightMeter;

char HOST_NAME[] = "maker.ifttt.com";
String PATH_NAME   = "/trigger/Light/with/key/e1qOxnSfrXsSfL_QrVp1zHRVYabpxFrPMPKmYojfAPQ"; // change your EVENT-NAME and YOUR-KEY
String queryString = "?value1=57&value2=25";

void setup() {
  // initialize WiFi connection
  WiFi.begin(ssid, pass);
  Serial.begin(9600);
  Serial.println("START");
  delay(900);
  while (!Serial);
  // connect to web server on port 80:
  while(true)
  {
  if (client.connect(HOST_NAME, 80)) {
    // if connected:
    Serial.println("Connected to server");
    break;
  }
  else {// if not connected:
    Serial.println("connection failed");
     WiFi.begin(ssid, pass);
  }
  delay(400);
  }
  Serial.print("Connection Successful!!!");
    Wire.begin();
  lightMeter.begin();
}

void loop() {
Serial.println(queryString);
float lux = lightMeter.readLightLevel();

  // Serial.println("Light sensor: ");
  // Serial.p'int(lux);

  queryString +="?value1=" ;
  queryString += lux;
  Serial.println(queryString);
  if (client.connect(HOST_NAME, 80)){

  if (lux > 500) {

    // make a HTTP request:
    // send HTTP header
    Serial.print("Sending!!!");
    client.println("GET " + PATH_NAME + queryString + " HTTP/1.1");
    client.println("Host: " + String(HOST_NAME));
    client.println("Connection: close");
    client.println(); // end HTTP header

Serial.print("CLIENT saying: ");
    while (client.connected()) {
      if (client.available()) {
        // read an incoming byte from the server and print it to serial monitor:
        char c = client.read();
        
        Serial.print(c);
      }
    }

    // the server's disconnected, stop the client:
    client.stop();
    Serial.println();
    Serial.println("disconnected");
  }
  }
   queryString = "";
delay(3000);
}