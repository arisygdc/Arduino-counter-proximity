int sig = 2;
int sig2 = 3;
int buzz = 4 ;
int counter = 1;
int d_limit = 100;
int r_sig;
int r_sig2;
int full = 5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sig, INPUT_PULLUP);
  pinMode(sig2, INPUT_PULLUP);
  pinMode(buzz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  r_sig = digitalRead(sig);
  r_sig2 = digitalRead(sig2);
  delay(d_limit);

  if(r_sig == 0){
    if (counter > full) {
      digitalWrite(buzz, HIGH);
      Serial.println("Full");
      delay(100);
      digitalWrite(buzz, LOW);
    } else {
      Serial.print("Counter : ");
      Serial.println(counter++);
    }
    while(r_sig != 1){
      r_sig = digitalRead(sig);
      delay(d_limit);
    }
  }

  if(r_sig2 == 0){
    Serial.print("Counter : ");
    Serial.println(counter--);
    while(r_sig2 != 1){
      r_sig2 = digitalRead(sig2);
      delay(d_limit);
    }
  }
}
