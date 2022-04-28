#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include <DHT.h>
#include <MQ135.h>
#include "html.h"

// Sensor
#define MQ135IN A0       // Chân Analog của MQ135  ->  A0 của ESP
#define DHTIN D1    // Chân Data của DHT11    -> GPIO18 của ESP
#define DHTTYPE  DHT11      

 // Motor 
 //Motor 1 Right
 //Motor 2 Left
 
const int IN1 = D4;       //-> GPIO 02
const int IN2 = D7;       //-> GPIO 13
const int IN3 = D2;       //-> GPIO 04
const int IN4 = D8;       //-> GPIO 15

// Led
const int led = 3;       //->GPIO 03 /pin RX

// Define funtion
DHT dht(DHTIN, DHTTYPE);
MQ135 mq135 = MQ135(MQ135IN);

// declare variables
float nhietdo = dht.readTemperature();
float doam    = dht.readHumidity();
float nongdo  = mq135.getPPM();

const char* ssid = "Iphonehoang30";
const char* pass = "30082000";

ESP8266WebServer server(80);
WiFiClient client;

void ketnoi(){
  String s = MAIN_page; 
  server.send(200,"text/html",s);
}

void docdulieunhietdo(){
  nhietdo = dht.readTemperature();
  String snhietdo = String(nhietdo);
  if(isnan(nhietdo)){
    server.send(200,"text/plane","Cảm biến không hoạt động");
  }else{
    server.send(200,"text/plane",snhietdo);
  }
}

void docdulieudoam(){
  doam = dht.readHumidity();
  String sdoam = String(doam);
  if(isnan(doam)){
    server.send(200,"text/plane","Cảm biến không hoạt động");
  }else{
    server.send(200,"text/plane",sdoam);
  }
}
void docdulieunongdo(){
  nongdo = mq135.getPPM();
  String snongdo = String(nongdo);
  if(isnan(nongdo)){
    server.send(200,"text/plane","Cảm biến không hoạt động");
  }else{
    server.send(200,"text/plane",snongdo);
  }
}


void led_on (){
digitalWrite(led, HIGH);
server.send(200,"text/plain","ON");
  }
  
void led_off (){
digitalWrite(led,LOW);
server.send(200,"text/plain","OFF");
  }

void goforward (){
  digitalWrite(IN1, 150);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, 150);
  digitalWrite(IN4, LOW);
server.send(200,"text/plain"," Going Forward");
  }
  
void goback (){ 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, 150);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, 150);
server.send(200,"text/plain"," Going Back");
  }

void goright (){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, 150);
  digitalWrite(IN3, 150);
  digitalWrite(IN4, LOW);
server.send(200,"text/plain","Going Right");
 delay(1000);
}
    
void goleft (){
  digitalWrite(IN1, 150);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, 150);
server.send(200,"text/plain"," Going Left ");
 delay(1000);
  }
   
void stp(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
server.send(200,"text/plain","Going Stop");
   }

void setup() {
Serial.begin(115200);
dht.begin(); 

  //Define DHT 11
 pinMode(DHTIN, INPUT);

  //Define L298N Dual H-Bridge Motor Controller Pins
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 
 //Define Led
 pinMode(led,OUTPUT);
 digitalWrite(led, LOW);

  // WiFi Setup
Serial.println("");
Serial.print(" Ket noi toi wifi:");
Serial.println(ssid);
WiFi.begin(ssid,pass);
while (WiFi.status () != WL_CONNECTED){
  delay(500);
  Serial.print(".");
}
Serial.println("");
Serial.println(" Wifi da duoc ket noi");
Serial.println(" Dia chi IP: ");
Serial.println(WiFi.localIP());

//Server Setup

server.on("/", ketnoi);
server.on("/docnhietdo"   ,        docdulieunhietdo);
server.on("/docdoam"      ,        docdulieudoam);
server.on("/docnongdo"    ,        docdulieunongdo);
server.on("/ledon"        ,        led_on);
server.on("/ledoff"       ,        led_off);
server.on("/forward"      ,        goforward);
server.on("/back"         ,        goback);
server.on("/right"        ,        goright);
server.on("/left"         ,        goleft);
server.on("/stop"         ,        stp);

server.begin();
}
   
void loop() {
 server.handleClient(); // Thực thi các yêu cầu từ client
} // End loop
