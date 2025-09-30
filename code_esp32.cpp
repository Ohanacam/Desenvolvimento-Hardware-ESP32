#include <WiFi.h>
#include <PubSubClient.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

// WIFI
const char* ssid = "visitantes"; 
const char* password = "";    

// MQTT
const char* mqtt_server = "broker.mqtt.cool";
const char* mqtt_topic = "esp32/display";

// DISPLAY
#define TFT_MOSI  7
#define TFT_SCLK  6
#define TFT_CS    10
#define TFT_DC    11
#define TFT_RST   8

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

WiFiClient espClient;
PubSubClient client(espClient);

// MOSTRAR TEXTO
void showMessage(String msg) {
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(5, 30);
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(2);
  tft.println(msg);
}

//CALLBACK MQTT
void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("Mensagem recebida [");
  Serial.print(topic);
  Serial.print("]: ");
  Serial.println(message);

  showMessage(message);
}

//CONECTAR WIFI
void setup_wifi() {
  delay(10);
  Serial.println("Conectando ao WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi conectado!");
}

//RECONECTAR MQTT
void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conectar ao MQTT...");
    if (client.connect("ESP32C6_Client")) {
      Serial.println("Conectado!");
      client.subscribe(mqtt_topic); 
    } else {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando de novo em 5s...");
      delay(5000);
    }
  }
}

//SETUP
void setup() {
  Serial.begin(115200);

  // Inicia o display
  tft.initR(INITR_MINI160x80);
  tft.setRotation(1);
  showMessage("Iniciando...");

  // WiFi
  setup_wifi();

  // MQTT
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

//LOOP
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
