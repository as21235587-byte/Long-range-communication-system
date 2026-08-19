/*
 * ================================================================
 * LoRa-Based Communication System
 * TRANSMITTER (ESP32) — Phase 1: Wokwi Software Simulation
 * ================================================================
 *
 * SX1278 is not natively available in Wokwi, so this phase
 * simulates the "LoRa wireless link" using the ESP32's second
 * hardware UART (Serial2) connecting two ESP32 boards directly.
 *
 * The moment you move to real hardware (Phase 2), only the
 * sendMessage() function needs to change — everything else
 * (button logic, packet format, debug prints) stays the same.
 * ================================================================
 */

#define BUTTON_PIN 4
#define RXD2 16   // not used on TX side, but Serial2 needs a pair
#define TXD2 17

int packetId = 0;

void setup() {
  Serial.begin(115200);                          // USB debug monitor
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);    // simulated LoRa link
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.println("=================================");
  Serial.println(" LoRa Transmitter (Simulated) Ready");
  Serial.println("=================================");
}

void sendMessage(String text) {
  packetId++;
  String packet = "ID:" + String(packetId) + ",MSG:" + text;

  // ---------------------------------------------------------
  // PHASE 2 (real hardware): replace the line below with:
  //   LoRa.beginPacket();
  //   LoRa.print(packet);
  //   LoRa.endPacket();
  // ---------------------------------------------------------
  Serial2.println(packet);

  Serial.println("Sent -> " + packet);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    sendMessage("HELLO AYUSH");
    delay(500); // simple debounce, replace with millis() based debounce later
  }
}
