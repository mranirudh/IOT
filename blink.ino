#include <ESP8266WebServer.h>

ESP8266WebServer server;
const char username[]="akshay";
const char password[]="9740736474";
void setup() {
  // put your setup code here, to run once:

pinMode(16,OUTPUT);
Serial.begin(115200);
WiFi.softAP(username,password);
IPAddress myIP=WiFi.softAPIP();
Serial.println(myIP);

server.begin();
server.on("/led",led);
}

void loop() {
  // put your main code here, to run repeatedly:
server.handleClient();
}
void led()
{
  String myhtml="<html><head><title>My First Webpage</title></head><body style=\"background-color: lightblue\"><h1 ><center>IOT</center></h1><div><form><center><BUTTON  type=\"submit\" name=\"state\" value=\"0\" >LED ON </BUTTON><BUTTON  type=\"submit\" name=\"state\" value=\"1\" >LED OFF </BUTTON></center></form></div></body></html>";
  
server.send(200, "text/html",myhtml);

if(server.arg("state")=="1")
{
  digitalWrite(16,HIGH);
}
else
{
  digitalWrite(16,LOW);
}
}

