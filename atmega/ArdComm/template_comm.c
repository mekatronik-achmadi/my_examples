#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>

#define baud_rate   9600

////////////////////////////////////////////////////////////

void delay_ms(unsigned int time){
    unsigned int i;

    for(i=0;i<time;i++){
        _delay_ms(1);
    };
    return;
}

void delay_us(unsigned int time){
    unsigned int i;

    for(i=0;i<time;i++){
        _delay_us(1);
    };
    return;
}

static int uart_putchar(char ch,FILE*stream)
{
    if(ch=='\n'){uart_putchar('\r',stream);}
    while ((UCSR0A & (1 << UDRE0)) == 0) {};
    UDR0=ch;
    return 0;
}

static int uart_getchar(FILE*stream)
{
    char temp;
    while ((UCSR0A & (1 << RXC0)) == 0) {};
    temp=UDR0;
    return(temp);
}

static FILE uart_stdout=FDEV_SETUP_STREAM(uart_putchar,NULL,_FDEV_SETUP_WRITE);
static FILE uart_stdin=FDEV_SETUP_STREAM(NULL,uart_getchar,_FDEV_SETUP_READ);

void serial_init(void){
	UCSR0B|=1<<TXEN0;
	UCSR0B|=1<<RXEN0;
	UCSR0B|=1<<RXCIE0;
	UBRR0H=(((F_CPU / (baud_rate * 16UL))) - 1)>>8;
	UBRR0L=(((F_CPU / (baud_rate * 16UL))) - 1);
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);
}

////////////////////////////////////////////////////////////

volatile char var_str[16];

ISR(USART_RX_vect){

    scanf("%s",&var_str);

    if(strcmp(var_str,"test")==0){
        printf("test ok\n");
    }
    else{
        printf("%s\n",&var_str);
    }
    
    // tambahi sendiri yang kurang

    return;
}

////////////////////////////////////////////////////////////

void setup() {                
	serial_init();
	stdin=&uart_stdin;
	stdout=&uart_stdout;  
	sei();
	
	// tambahi sendiri yang kurang
	
}

void loop() {
	// tambahi sendiri yang kurang
}
