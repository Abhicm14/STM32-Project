#include <WiFi.h>

// UART definitions
#define TX_SEND_PIN 34
#define RX_SEND_PIN 33
#define TX_RECV_PIN 17
#define RX_RECV_PIN 16

HardwareSerial ssidSender(1);   // UART1
HardwareSerial ssidReceiver(2); // UART2

String receivedSSID = "";
bool ssidSelected = false;
unsigned long lastScanTime = 0;
const unsigned long scanInterval = 10000;  // 10 seconds

void setup() {
  ssidSender.begin(9600, SERIAL_8N1, RX_SEND_PIN, TX_SEND_PIN);
  ssidReceiver.begin(9600, SERIAL_8N1, RX_RECV_PIN, TX_RECV_PIN);
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);
  delay(100);
}

void loop() {
  if ((millis() - lastScanTime > scanInterval) && !ssidSelected) {
    lastScanTime = millis();

    int n = WiFi.scanNetworks();
    int count = 0;
    String ssidsToSend[8];  // Store up to 8 SSIDs

    for (int i = 0; i < n && count < 8; i++) {
      String ssid = WiFi.SSID(i);
      if (ssid.length() < 15) {
        ssidsToSend[count++] = ssid;
      }
    }

    // Send the SSIDs 3 times
    for (int repeat = 0; repeat < 3; repeat++) {
      for (int i = 0; i < count; i++) {
        ssidSender.println(ssidsToSend[i]);
        Serial.println(ssidsToSend[i]);  // Debug output
        delay(300); // Small delay for STM32 to process
      }
    }
  }

  // Check for SSID selection only after sending is done
  if (!ssidSelected && ssidReceiver.available()) {
    receivedSSID = ssidReceiver.readStringUntil('\n');
    receivedSSID.trim();
    ssidSelected = true;

    Serial.print("Received SSID: ");
    Serial.println(receivedSSID);

    WiFi.begin(receivedSSID.c_str());

    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
      delay(500);
      Serial.print(".");
    }

    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("\nConnected successfully!");
      Serial.println(WiFi.localIP());
    } else {
      Serial.println("\nConnection failed.");
    }
  }
}
