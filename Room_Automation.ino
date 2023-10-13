#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>

//Firebase Host Name and Key
#define FIREBASE_HOST "innovatedroom.firebaseio.com"
#define FIREBASE_AUTH "YNiEvuLYOJ3CQBC4jWVol1dyq2gfg7ojSeRbXLsN"
#define WIFI_SSID "PLDTHOMEDSLC4QRY"
#define WIFI_PASSWORD "PLDTWIFI93870"

int light1 = D2;
int light2 = D1;

void setup() {
  Serial.begin(115200);
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  //Wifi Connection
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //begin initialization of wifi id and pass
  while(WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting...");
    delay(500);
  }
  Serial.print("Wifi is now connected.");
  Serial.println(WiFi.localIP());
  //Firebasee Initialization
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("/Lights/eyyyy", "On");
  
//  int obj = Firebase.getString('/Lights');
//  Serial.println(obj);
}

void loop() {
  int n1 = Firebase.getInt("/Lights/Light1");
  int n2 = Firebase.getInt("/Lights/Light2");
  int n3 = Firebase.getInt("/Lights/Light3");
  if(n1 == 0) {
    Serial.println(n1);
    Serial.println("Light1 is off");
    digitalWrite(light1, LOW);
  }
  if(n1 == 1) {
    Serial.println(n1);
    Serial.println("Light1 is on");
    digitalWrite(light1, HIGH);
  }
  if(n2 == 0) {
    Serial.println(n2);
    Serial.println("Light2 is off");
    digitalWrite(light2, LOW);
  }
  if(n2 == 1) {
    Serial.println(n2);
    Serial.println("Light2 is on");
    digitalWrite(light2, HIGH);
  }
  /*if(n1 == 0) {
    Serial.println(n1);
    Serial.println("Led Off");
    digitalWrite(light1, LOW);
    return;
    delay(500);
  }
  else if(n1 == 1) {
    Serial.println(n1);
    Serial.println("Led On");
    digitalWrite(light1, HIGH);
    return;
    delay(500);
  }*/
  delay(100);
}
