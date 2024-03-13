#include <WiFi.h>                                                
#include <IOXhop_FirebaseESP32.h>    
                                         
#define FIREBASE_Host "https://testing-led-2f53a-default-rtdb.firebaseio.com"                   // replace with your Firebase Host
#define FIREBASE_authorization_key "rmh4wTTBJWQHTOARizWtEsRo3VCAt48SdLetTzHQ" // replace with your secret key
#define Your_SSID "tirosh"       // replace with your SSID
#define Your_PASSWORD "12345678"          //replace with your Password

String led_state = "";                                                     
int led_gpio = 2;                                                               

void setup() {

  Serial.begin(115200);
  delay(1000);
  pinMode(2, OUTPUT);                
  WiFi.begin(Your_SSID, Your_PASSWORD);                                      
  Serial.print("Connecting to WIFI");
  while (WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
  delay(500);
  }

  Serial.println();
  Serial.print("Connected to WIFI!");
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());                                                      
  Firebase.begin(FIREBASE_Host, FIREBASE_authorization_key);                                       
  Firebase.setString("LED State: ", "OFF");                                          

}

void loop() {

  led_state = Firebase.getString("LED State: ");         
  if (led_state == "ON") {                   

    Serial.println("Led is ON");                 
    digitalWrite(led_gpio, HIGH);                                                         

  }

  else if (led_state == "OFF") {             

    Serial.println("Led is OFF");
    digitalWrite(led_gpio, LOW);                                                         

  }

  else {
     Serial.println("Wrong value entered! Only ON or OFF accepted");

  }

}
