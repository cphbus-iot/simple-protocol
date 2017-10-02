#define DATA_IN 4
#define CLK_IN 5

void setup() {
  pinMode(DATA_IN, INPUT);
  pinMode(CLK_IN, INPUT);
  Serial.begin(9600);
  }

void loop() {
  if (ready()) {
    Serial.print(read());
    }
  }

int ready() {
  return digitalRead(CLK_IN);
  }

int read() {
  int bit = digitalRead(DATA_IN);
  while(digitalRead(CLK_IN));
  return bit;
  }
