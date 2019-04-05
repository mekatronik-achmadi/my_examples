#include <avr/io.h>
#include <util/delay.h>

unsigned char adc_read(unsigned char pin){
		ADMUX=pin;
		ADMUX|=1<<ADLAR;
		ADMUX|=1<<REFS0;
		ADCSRA|=1<<ADEN;

		_delay_us(10);

		ADCSRA|=1<<ADSC;
		while (!(ADCSRA & 1<<ADIF));
		ADCSRA|=1<<ADIF;

		return ADCH;
}

int main(void){

	DDRB |= 1<<3;

	TCCR0|=(1<<CS02)|(0<<CS01)|(0<<CS00);
	TCCR0|=(0<<WGM01)|(1<<WGM00);
	TCCR0|=(1<<COM01)|(0<<COM00);

    while(1){
    	OCR0 = adc_read(0);
        _delay_ms(255);
    }
    return 0;
}
