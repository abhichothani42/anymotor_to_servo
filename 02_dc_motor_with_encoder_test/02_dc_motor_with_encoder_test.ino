/* dc motor and encoder testing 
  please make sure all the wiring are correct so encoder 
  might have different color wire for encoder power connection
  
  1 rotation = 300 pulse in encoder
  
  Abhi
  Oct 19 2025*/

// we are using interrupts so make sure pins
// that we are using do have this function avaiable
#define enca 2 //white
#define encb 3 //yellow

#define in1 4
#define in2 5

int pos = 0;
//analog write takes values between 0 (always off) and 255 (always on).
int valo = 100;

void setup() {
  Serial.begin(9600);
  pinMode(enca, INPUT);
  pinMode(encb, INPUT);
  attachInterrupt(digitalPinToInterrupt(enca), readEncoder,RISING);

  pinMode(in2, OUTPUT);
  pinMode(in1, OUTPUT);
}

void loop() {
  setMotor(1, valo, in1, in2);
  delay(2000);
  Serial.println(pos);

  setMotor(-1, valo, in1, in2);
  delay(2000);
  Serial.println(pos);

  setMotor(0,valo, in1, in2);
  delay(2000);
  Serial.println(pos);

}

void setMotor(int dir, int pwmVal, int in1_pin, int in2_pin){
  if(dir == 1){
    analogWrite(in1_pin, pwmVal);
    digitalWrite(in2_pin, LOW);
  }
  else if(dir == -1){
    digitalWrite(in1_pin, LOW);
    analogWrite(in2_pin, pwmVal);
  }
  else{
    digitalWrite(in1_pin, LOW);
    digitalWrite(in2_pin, LOW);
  }
}

void readEncoder(){
  int b = digitalRead(encb);

  if (b>0){
    pos++;
  }
  else {
    pos--;
  }
}
