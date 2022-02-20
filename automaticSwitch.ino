#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Servo.h>  //Include the Servo Library

#include "automaticSwitchWeb.h"; //--> Include the contents of the User Interface Web page from website, stored in the same folder as the .ino file  

#define ServoPort D4    //--> Defining Servo Port

//Make a wifi name and password as access point

const char* ssid = "ESPServo";  // your SSID

const char* password = "12345678"; //WIFI Password


Servo myservo;  //--> create servo object to control a servo

ESP8266WebServer server(80);  //--> Server on port 80

String SERstate1 = "OFF";

//This routine is executed when you open NodeMCU ESP8266 IP Address in browser

void handleRoot() {

  String s = web_page; //Read HTML contents

  server.send(200, "text/html", s); //Send web page

}

//Procedure for handling servo control

void handleServo() {
  String POS = server.arg("servoPOS");
  int pos = POS.toInt();
  myservo.write(pos);   //--> Move the servo motor according to the POS value
  delay(1);
  server.send(200, "text/plane", "");
}

void controlServo() {
  String t_state = server.arg("SERstate1");
  Serial.println(t_state);
  int pos;
  
  if (t_state == "3") {
    SERstate1 = pos;
    myservo.write(0);
 
  }
  else if (t_state == "4") {
    SERstate1 = pos;
    myservo.write(100);
 
  }
  else {
    SERstate1 = "OFF";
  }
  server.send(200, "text/plane", SERstate1);
}

void statusSER() {
  server.send(200, "text/plane", SERstate1);
}


void setup() {

//  Serial.begin(115200);
//  delay(500);
  myservo.attach(ServoPort); //--> attaches the servo on D1 to the servo object
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();


  //Initialize Webserver
  server.on("/", handleRoot); //--> Routine to handle at root location. This is to display web page.
  server.on("/setPOS", handleServo); //--> Sets servo position from Web request
  server.on("/setSER1", controlServo);
  server.on("/readSER1", statusSER);
  server.begin();

  Serial.println("HTTP server started");

}


void loop() {

  server.handleClient();

}
