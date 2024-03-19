int led = 3;
float analogsignal = 0;
int analogTime;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop() {
  analogsignal = analogRead(A0);
  analogTime = map(analogsignal, 0, 1023, 500, 4000);

  if(analogsignal == 0){
    digitalWrite(led, LOW);
    delay(77);
  }else{
    analogLedUP(10);
  	analogLedDOWN(10);
  
  }
  
  Serial.println(analogTime);
  
  


  

}

void analogLedUP(int up){
  for(int i=0;i<255;i+=up){
    analogWrite(led, i);
    delay(analogTime/2);
  }
}
void analogLedDOWN(int down){
  for(int j=255;j>1;j-=down){
  	analogWrite(led, j);
    delay(analogTime/2);
  }
}
