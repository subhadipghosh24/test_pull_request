int relay1 = 6;
String datain;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, HIGH);
}

void loop() {
  if (Serial.available()) {
    while (Serial.available() > 0) {
      char c = Serial.read();
      datain += c;
      delay(10);
    }
    Serial.println(datain);
    if (datain == "*sanitizer on#") {
      Serial.println("hello");
      digitalWrite(relay1, LOW);
      // delay(10000);
      // digitalWrite(relay1, HIGH);
    } else if (datain == "*sanitizer off#") {
      digitalWrite(relay1, HIGH);
      Serial.println("turn off");
    }
    datain = "";
  }
}
