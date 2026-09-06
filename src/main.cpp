#include <MotorDriver.h>
MotorDriver md;

const int sensorKiri   = A0;
const int sensorTengah = A1;
const int sensorKanan  = A2;

int kecepatan = 150; // Nilai PWM dasar (0-255)

void setup() {
  pinMode(sensorKiri, INPUT);
  pinMode(sensorTengah, INPUT);
  pinMode(sensorKanan, INPUT);
  Serial.begin(9600);
}

void loop() {
  int K  = digitalRead(sensorKiri);
  int T  = digitalRead(sensorTengah);
  int Ka = digitalRead(sensorKanan);

  Serial.print("K:"); Serial.print(K);
  Serial.print(" T:"); Serial.print(T);
  Serial.print(" Ka:"); Serial.println(Ka);

  if (T == LOW && K == HIGH && Ka == HIGH) {
    // Garis di tengah -> Maju lurus
    md.motor(1, FORWARD, kecepatan);
    md.motor(2, FORWARD, kecepatan);
  }
  else if (K == LOW && Ka == HIGH) {
    // Garis bergeser ke kiri -> Belok kiri
    md.motor(1, RELEASE, 0);
    md.motor(2, FORWARD, kecepatan);
  }
  else if (Ka == LOW && K == HIGH) {
    // Garis bergeser ke kanan -> Belok kanan
    md.motor(1, FORWARD, kecepatan);
    md.motor(2, RELEASE, 0);
  }
  else if (K == HIGH && T == HIGH && Ka == HIGH) {
    // Garis hilang -> Berhenti
    md.motor(1, BRAKE, 0);
    md.motor(2, BRAKE, 0);
  }

  delay(50);
}