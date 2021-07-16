#include <WiFi.h>

// Informasi  sambungan Wi-Fi dan IP Address Server
const char* ssid = "kentang";
const char* password = "wifigratis";
const char* host = "192.168.43.50";

// Deklarasi Wi-Fi Server
WiFiClient client;

#define LEDPIN 4     // Digital pin yang tersambung ke LED

//Deklarasi inputServer nilaiDelay secara global
String inputServer;
int nilaiDelay;

#define TUNGGU_WIFI 250// Deklarasi konstanta Nilai Delay
#define TUNGGU_SETELAH_TERIMA_PERINTAH 250 //Deklarasi konstanta Nilai Delay

void terimaData() {
  if (client.connect(host, 10013)) {
    inputServer = client.readString() ; 
    nilaiDelay = inputServer.toInt();
    delay(TUNGGU_SETELAH_TERIMA_PERINTAH);
    ledControl();
 }
}

void ledControl()
{
  if (nilaiDelay <= 0)
  {
    digitalWrite(LEDPIN, LOW);
    }
    else
    {
    digitalWrite(LEDPIN, HIGH);
    delay(nilaiDelay);
    digitalWrite(LEDPIN, LOW);
    }
}

void setup() {
  
  pinMode(LEDPIN, OUTPUT);
  
  // Memulai Wi-Fi
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(TUNGGU_WIFI);
  }
}
void loop() { 
    terimaData();
    client.stop();
}
