#include <Arduino.h>

// Deklarasi pin digital untuk 3 sensor IR (Anda bisa menyesuaikan nomor pin-nya)
const int irSensor1 = 2; // IR Sensor 1 terhubung ke pin digital 2
const int irSensor2 = 3; // IR Sensor 2 terhubung ke pin digital 3
const int irSensor3 = 4; // IR Sensor 3 terhubung ke pin digital 4

void setup() {
  // Mengaktifkan komunikasi serial
  Serial.begin(9600);
  
  // Mengatur pin sensor sebagai jalur INPUT
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(irSensor3, INPUT);
  
  Serial.println("Program Pembaca 3 Sensor IR Dimulai...");
}

void loop() {
  // Membaca status masing-masing sensor (1/HIGH jika tidak ada halangan, 0/LOW jika mendeteksi objek, tergantung jenis sensornya)
  int valSensor1 = digitalRead(irSensor1);
  int valSensor2 = digitalRead(irSensor2);
  int valSensor3 = digitalRead(irSensor3);
  
  // Menampilkan hasil bacaan ke Serial Monitor
  Serial.print("Sensor 1: ");
  Serial.print(valSensor1);
  Serial.print(" | Sensor 2: ");
  Serial.print(valSensor2);
  Serial.print(" | Sensor 3: ");
  Serial.println(valSensor3);
  
  // Jeda 500 ms (setengah detik) sebelum membaca ulang
  delay(500);
}
