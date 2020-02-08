#define led 3
#define knob 0


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(knob);
  val = map(val, 1, 1024, 1, 255);
  analogWrite(led, val);

}
