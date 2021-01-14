#define enA   11 //port pwm motor
#define in1   9 //port motor
#define in2   10 //port motor

#define IR1   5
#define IR2   6

#define butt1 2
#define butt2 3
#define butt3 4

#define LED1 7
#define LED2 8
#define LED3 9

uint8_t kec_motor;
uint8_t butts1 = 0;
uint8_t butts2 = 0;
uint8_t butts3 = 0;
uint8_t IRs1 = 0;
uint8_t IRs2 = 0;
uint8_t lantai;
uint8_t LantaiSekarang;
uint8_t res;

bool state1 = false;
bool state2 = false;
bool state3 = false;

void bandingkanlantai(uint8_t LantaiTujuan);

void setup() {
  Serial.begin(9600);

  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  
  pinMode(butt1,INPUT);
  pinMode(butt2,INPUT);
  pinMode(butt3,INPUT);
  
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(enA,OUTPUT);

}

void loop() {

  butts1 = digitalRead(butt1);
  butts2 = digitalRead(butt2);
  butts3 = digitalRead(butt3);
  
  IRs1 = digitalRead(IR1);
  IRs2 = digitalRead(IR2);

  if(butts1 == HIGH){
     state1 = true;
     
     if(state1==true){ // of course always true
         lantai = 1;
         bandingkanlantai(lantai);
     }
  }
  else if((state1==true) && (IRs1==LOW) && (IRs2==HIGH)){ // elseif with completely different parameters to check
     state1 = false;
     kec_motor = 0;
     analogWrite(in1,0);
     analogWrite(in2,0);
  }

  if(butts2 == HIGH){
    state2 = true;
    
    if(state2 == true){ // of course always true
      lantai = 2;
      bandingkanlantai(lantai);
    }
  }
  else if(state2 == true && IRs2 == LOW && IRs1 == HIGH){ // elseif with completely different parameters to check
      state2 = false;
      kec_motor = 0;
      analogWrite(in1,0);
      analogWrite(in1,0);
  }

  // struktur logika nya berbeda dengan 2 struktur sebelumnya
  if(butts3 == HIGH){
    state3 = true;
    
    if(state3 == true){
      lantai = 3;
      bandingkanlantai(lantai);
    }
    else if(state3 == true && IRs1 == LOW && IRs2 == LOW){
      state3 = false;
      analogWrite(in1,0);
      analogWrite(in2,0);
    }
  }
     
}// END of loop Function

void bandingkanlantai(uint8_t LantaiTujuan){
  LantaiSekarang; // what is this? this is should be syntax wrong

  if(LantaiTujuan>LantaiSekarang){
    kec_motor = 225;
    analogWrite(in1,kec_motor);
    analogWrite(in2,0);
    LantaiSekarang = LantaiTujuan;
  }

  else if(LantaiTujuan<LantaiSekarang){
    kec_motor = 225;
    analogWrite(in1,0);
    analogWrite(in2,kec_motor);
    LantaiSekarang = LantaiTujuan;
  }

  else if(LantaiTujuan == LantaiSekarang){
    analogWrite(in1,0);
    analogWrite(in2,0);
  }
  
  Serial.print(LantaiSekarang);  
}
