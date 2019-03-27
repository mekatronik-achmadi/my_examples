#include "uart.h"

char vstr[16];

static int uart_putchar(char ch,FILE*stream)
{
    if(ch=='\n'){uart_putchar('\r',stream);}
    while ((UCSRA & (1 << UDRE)) == 0) {};
    UDR=ch;
    return 0;
}

static int uart_getchar(FILE*stream)
{
    (void) stream;
    char temp;

    while ((UCSRA & (1 << RXC)) == 0) {};
    temp=UDR;
    return(temp);
}

static FILE uart_stdout=FDEV_SETUP_STREAM(uart_putchar,NULL,_FDEV_SETUP_WRITE);
static FILE uart_stdin=FDEV_SETUP_STREAM(NULL,uart_getchar,_FDEV_SETUP_READ);

static void uart_baud(void){
    UBRRH=(((F_CPU / (BAUDRATE * 16UL))) - 1)>>8;
    UBRRL=(((F_CPU / (BAUDRATE * 16UL))) - 1);
}

void uart_init(void){
    uart_baud();

    UCSRB |= 1<<RXEN | 1<<TXEN | 1<<RXCIE;
    UCSRC|=(1<<UCSZ1)|(1<<UCSZ0);

    stdin=&uart_stdin;
    stdout=&uart_stdout;

    sei();
}

ISR(USART_RXC_vect){
    scanf("%s",vstr);
    if(strcmp(vstr,"test") == 0){
        printf("serial OK\n\r");
    }
    else{
        printf("%s?\n\r",vstr);
    }
}
