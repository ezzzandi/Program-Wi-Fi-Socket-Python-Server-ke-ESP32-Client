#include <WiFi.h>

// Informasi  sambungan Wi-Fi dan IP Address Server
const char* ssid = "SSID"; //Isi dengan SSID jaringan wifi yang digunakan
const char* password = "pass"; //Isi dengan password jaringan wifi yang digunakan
const char* host = "192.168.0.0"; //Isi dengan IP address yang digunakan server
const int port = 80;

// Deklarasi Wi-Fi Server
WiFiClient client;

#define LEDPIN 4     // Digital pin yang tersambung ke LED

//Deklarasi variabel secara global
String bacaData;
int dataInt;

void kelolaData(){
  if (client.connect(host, port)) {
    bacaData = client.readString() ; 
    dataInt = bacaData.toInt();
    delay(300);
    hidupLampu();
 }
}

void hidupLampu()
{
  if (dataInt <= 0)
  {
    digitalWrite(LEDPIN, LOW);
    }
    else
    {
    digitalWrite(LEDPIN, HIGH);
    delay(dataInt);
    digitalWrite(LEDPIN, LOW);
    }
}

void setup() {
  
  pinMode(LEDPIN, OUTPUT);
  
  // Memulai Wi-Fi
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}
void loop() { 
    kelolaData();
    client.stop();
}
