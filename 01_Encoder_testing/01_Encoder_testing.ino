/* encoder testing 
  please make sure all the wiring are correct so encoder 
  might have different color wire for encoder power connection
  
  1 rotation = 300 pulse in encoder
  
  Abhi
  Oct 19 2025*/

// we are using interrupts so make sure pins
// that we are using do have this function avaiable
#define enca 2 //white
#define encb 3 //yellow

int pos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(enca, INPUT);
  pinMode(encb, INPUT);
  attachInterrupt(digitalPinToInterrupt(enca), readEncoder,RISING);
}

void loop() {
  Serial.println(pos);

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
