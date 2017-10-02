
#define DATA_OUT 2
#define CLK_OUT 3
#define FRAME 10

void setup() {
  pinMode(DATA_OUT, OUTPUT);
  pinMode(CLK_OUT, OUTPUT);
  Serial.begin(9600);
  }

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    for (int i = 0; i < 8; i++) {
      send(c & 1);
      c = c >> 1;
      }
    }
  }

void send (int bit) {
  digitalWrite(DATA_OUT, bit);
  digitalWrite(CLK_OUT, HIGH);
  delay(FRAME);
  digitalWrite(CLK_OUT, LOW);
  delay(FRAME);
  }
