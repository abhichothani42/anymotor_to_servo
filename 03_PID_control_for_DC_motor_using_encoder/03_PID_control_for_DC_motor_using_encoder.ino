/* dc motor and encoder PID control 
  please make sure all the wiring are correct so encoder 
  might have different color wire for encoder power connection

  1 rotation = 300 pulse in encoder
  
  Abhi
  Oct 20 2025*/

// we are using interrupts so make sure pins
// that we are using do have this function avaiable
#define enca 2 //white
#define encb 3 //yellow

#define in1 4
#define in2 5

int pos = 0;
//analog write takes values between 0 (always off) and 255 (always on).
int valo = 100;

unsigned long prevT = 0; 
float eprev = 0;
float eintegral = 0;

void setup() {
  Serial.begin(9600);
  pinMode(enca, INPUT);
  pinMode(encb, INPUT);
  attachInterrupt(digitalPinToInterrupt(enca), readEncoder,RISING);

  pinMode(in2, OUTPUT);
  pinMode(in1, OUTPUT);
}

void loop() {
  // set the target position
  int target_degree = 360;
  int target = int(0.8333 * target_degree);

  // PID constants
  float kp = 1;
  float kd = 0.055;
  float ki = 0.001;

  // time difference
  unsigned long currT = micros(); // Change to unsigned long
  unsigned long et = currT - prevT;
  float deltaT = ((float)(currT - prevT)) / 1.0e6;
  prevT = currT;

  // error
  int e = target - pos;

  // derivative
  float dedt = (e - eprev) / deltaT;

  // integral
  eintegral = eintegral + e * deltaT;

  // control signal
  float u = kp * e + kd * dedt + ki * eintegral;
  //float u = kp * e + kd * dedt;

  // motor power
  float pwr = fabs(u);
  if (pwr > 200) {
    pwr = 200;
  }

  if (pwr < 50){
    pwr = 50;
  }

  // motor direction
  int dir = 1;
  if (u < 0) {
    dir = -1;
  }

  // signal the motor
  setMotor(dir, (uint8_t)pwr, in1, in2); // Cast pwmVal to uint8_t

  // store previous error
  eprev = e;

  Serial.print(target);
  Serial.print(" ");
  Serial.print(pos);
  Serial.println();
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




