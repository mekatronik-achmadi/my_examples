/*
Project:	untitled
Board:		uno
MCU:		16MHzatmega328	
FRENQUENCY:	16000000

Created using Qt Creator
*/
#ifndef ARDUINO_H
#define ARDUINO_H
#include <Arduino.h>
#endif

#define LED_PIN     13
#define DELAY_MS    500
#define CONSTANT    0.005

void ADC_init(void);
uint16_t read_adc_10bit(uint8_t pin);

int uart_getchar(FILE*stream);
int uart_putchar(char ch,FILE*stream);
void UART_init(uint16_t uart_baud);

uint32_t s_adc;
uint16_t v_adc;
uint8_t i;

char inString[16];
FILE uart_out = {0} ;
FILE uart_in = {0} ;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    ADC_init();
    UART_init(9600);
}

void loop()
{
    s_adc = 0;
    for(i=0;i<100;i++){
        s_adc = s_adc + read_adc_10bit(0);
        _delay_us(1);
    }

    v_adc = s_adc/100;
    f_adc = CONSTANT*v_adc;

    digitalWrite(LED_PIN,HIGH);
    delay(DELAY_MS);
    digitalWrite(LED_PIN,LOW);
    delay(DELAY_MS);
}

ISR(USART_RX_vect){

    scanf("%s",&inString);

    if(strcmp(inString,"adc")==0){
      printf("%5.2f\n",f_adc);
    }
    else{
      printf("Unknown \n");
    }

    return;
}

void ADC_init(void){
    ADMUX &= ~_BV(ADLAR);
    ADMUX &= ~_BV(REFS1); ADMUX |= _BV(REFS0);
    ADCSRA &= ~_BV(ADPS2); ADCSRA |= _BV(ADPS1); ADCSRA |= _BV(ADPS0);
    ADCSRA |= _BV(ADEN);
}

uint16_t read_adc_10bit(uint8_t pin){
    ADMUX=pin;

    ADMUX &= ~_BV(ADLAR);
    ADMUX &= ~_BV(REFS1); ADMUX |= _BV(REFS0);

    ADCSRA |= _BV(ADEN);

    _delay_us(10);

    ADCSRA |= _BV(ADSC);
    while (!(ADCSRA & _BV(ADIF)));
    ADCSRA |= _BV(ADIF);

    return ADCW;
}

int uart_putchar(char ch,FILE*stream)
{
    if(ch == '\n'){uart_putchar('\r',stream);}
    while ((UCSR0A & _BV(UDRE0)) == 0) {};
    UDR0 = ch;
    return 0;
}

int uart_getchar(FILE*stream)
{
    char temp;
    while ((UCSR0A & _BV( RXC0)) == 0) {};
    temp = UDR0;
    uart_putchar(temp,stream);
    return(temp);
}

void UART_init(uint16_t uart_baud){

    UCSR0B|=1<<RXEN0;
    UCSR0B|=1<<TXEN0;
    UCSR0B|=1<<RXCIE0;

    UBRR0H=(((F_CPU / (baud * 16UL))) - 1)>>8;
    UBRR0L=(((F_CPU / (baud * 16UL))) - 1);

    UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);

    fdev_setup_stream (&uart_out, uart_putchar, NULL, _FDEV_SETUP_WRITE);
    fdev_setup_stream (&uart_in, NULL, uart_getchar, _FDEV_SETUP_READ);
    stdout=&uart_out;
    stdin=&uart_in;

    sei();
}
