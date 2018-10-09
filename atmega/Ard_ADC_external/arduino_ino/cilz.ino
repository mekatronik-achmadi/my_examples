#include <NAU7802.h>

#define COMM_DATA 0 // 0: use data-burst | 1: use reply-request
#define ADC_DATA  0 // 0: data in mV float | 1: data in 32bit integer
#define DIFF_DATA 2 // 0: data as present value | 1: data as differences | 2: both

long v_adc;
float a_adc;
NAU7802 adc = NAU7802();

#if DIFF_DATA != 0
long dv_adc,v_adc0;
float da_adc,a_adc0;
uint8_t first_data;
#endif

#if COMM_DATA == 1
String inputString = "";
boolean stringComplete = false;

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if ((inChar == '\n') || (inChar == '\r')) {
      stringComplete = true;
    }
  }
}
#endif

void data_view(){
#if DIFF_DATA == 0

#if ADC_DATA == 1
    v_adc = adc.readADC();
    Serial.println(v_adc);
#else
    a_adc = adc.readmV();
    Serial.println(a_adc,10);
#endif

#elif DIFF_DATA == 1

#if ADC_DATA == 1
    v_adc = adc.readADC();
    if(first_data!=0){
      if(v_adc>=v_adc0){dv_adc=v_adc-v_adc0;}
      else{dv_adc=v_adc0-v_adc;}
      v_adc0=v_adc;
    }
    else{
      v_adc0=v_adc;
      first_data=1;
    }
    Serial.println(dv_adc);
#else
    a_adc = adc.readmV();
    if(first_data!=0){
      if(a_adc>=a_adc0){da_adc=a_adc-a_adc0;}
      else{da_adc=a_adc0-a_adc;}
      a_adc0=a_adc;
    }
    else{
      a_adc0=a_adc;
      first_data=1;
    }  
    Serial.println(da_adc,10);
#endif

#elif DIFF_DATA == 2

#if ADC_DATA == 1
    v_adc = adc.readADC();
    if(first_data!=0){
      if(v_adc>=v_adc0){dv_adc=v_adc-v_adc0;}
      else{dv_adc=v_adc0-v_adc;}
      v_adc0=v_adc;
    }
    else{
      v_adc0=v_adc;
      first_data=1;
    }
    Serial.print(v_adc);
    Serial.print(" | ");
    Serial.println(dv_adc);
#else
    a_adc = adc.readmV();
    if(first_data!=0){
      if(a_adc>=a_adc0){da_adc=a_adc-a_adc0;}
      else{da_adc=a_adc0-a_adc;}
      a_adc0=a_adc;
    }
    else{
      a_adc0=a_adc;
      first_data=1;
    }  
    Serial.print(a_adc,10);
    Serial.print(" | ");
    Serial.println(da_adc,10);
#endif

#endif
}

void setup() {

  adc.begin();
  adc.selectCh1();
  
  Serial.begin(9600);

#if COMM_DATA == 1
  inputString.reserve(200);
#elif COMM_DATA == 0
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("system started");
#endif
  
}

void loop() {

#if COMM_DATA == 1
  serialEvent();
  if (stringComplete) {
    data_view();
    inputString = "";
    stringComplete = false;
  }

#elif COMM_DATA == 0
  digitalWrite(LED_BUILTIN, HIGH); 
  data_view();  
  delay(500);
  digitalWrite(LED_BUILTIN, LOW); 
  delay(500);
#endif

}
