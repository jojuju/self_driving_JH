// A motor pins
#define ENA 6
#define IN1 7
#define IN2 8

// B motor pins
#define IN3 9
#define IN4 10
#define ENB 11

int apwm = 0;
int bpwm = 0;
char arr[7];
char s[3];

void setup() {
  // set up serial port
  Serial.begin(9600);
  
  // set all the motor pins OUTPUT mode
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // wait 2 seconds after power up
  delay(2000);

  //Serial.println();
  // set motors to move forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  while(1){
    Serial.println("a속도값을 입력하세요 : ");
    while(Serial.available() == 0) {}
    apwm = Serial.parseInt();
    //analogWrite(ENA, apwm); // A모터 pwm출력
    Serial.println(apwm);
    
    Serial.println("b속도값을 입력하세요 : ");
    while(Serial.available() == 0) {}
    bpwm = Serial.parseInt();
    //analogWrite(ENB, bpwm); // B모터 pwm출력
    Serial.println(bpwm);
  
    analogWrite(ENA, apwm); // A모터 pwm출력
    analogWrite(ENB, bpwm); // B모터 pwm출력
    while(Serial.available() == 0) {}
    //apwm = Serial.read();  // 넘김방지
  }
  
  delay(2000);
}
//(장비적인 결함 없다 가정했을 때 - 저가장비라 모터성능제각각, 모터와 바퀴연결부 이격상태로 삐걱거림 등;) 
// 직진 ENA의PWM = ENB의PWM)
// 좌회전 ENA의PWM > ENB의PWM 
// 우회전 ENA의PWM < ENB의PWM
  


void loop() {
  //dddddd
}
