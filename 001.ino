#define LED1_PIN 2
#define LED2_PIN 4
#define LED3_PIN 5
#define LED4_PIN 18
#define LED5_PIN 19

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  pinMode(LED5_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED1_PIN, HIGH);
  delay(500);
  digitalWrite(LED1_PIN, LOW);
  delay(500);

  digitalWrite(LED2_PIN, HIGH);
  delay(500);
  digitalWrite(LED2_PIN, LOW);
  delay(500);

  digitalWrite(LED3_PIN, HIGH);
  delay(500);
  digitalWrite(LED3_PIN, LOW);
  delay(500);

  digitalWrite(LED4_PIN, HIGH);
  delay(500);
  digitalWrite(LED4_PIN, LOW);
  delay(500);

  digitalWrite(LED5_PIN, HIGH);
  delay(500);
  digitalWrite(LED5_PIN, LOW);
  delay(500);
}
