unsigned short is_running =0;
unsigned short button_prev =0;
void alloff(){
PORTA = 0x00;
PORTB = 0x00;
}
unsigned short Delay_With_Check(unsigned int ms){
unsigned int i;
for(i=0; i<ms; i+=50){
if(PORTA.F4 == 1 && button_prev == 0){
Delay_ms(50);
if (PORTA.F4 == 1){
button_prev = 1;
 return 1;
 }
 }
else if(PORTA.F4 == 0){
 button_prev = 0;
 }
 Delay_ms(50);
 }
 return 0;
 }

void main(){
TRISA = 0b00010000;
TRISB = 0x00;
alloff();
while(1){
if(!is_running){
if(PORTA.F4 == 1 && button_prev == 0){
Delay_ms(50);
if(PORTA.F4 == 1){
is_running = 1;s
 }
 }else if(PORTA.F4 == 0){
 button_prev = 0;
 }
}
if(is_running){
alloff();
RA0_bit = 1;
RB1_bit = 1;
RB4_bit = 1;
RB5_bit = 1;
if(Delay_With_Check(5000))
{ is_running = 0; alloff(); continue; }
alloff();
RA0_bit = 1;
RB0_bit = 1;
RB3_bit = 1;
RB5_bit = 1;
if( Delay_With_Check(2000))
{ is_running = 0; alloff(); continue; }
 alloff();
 RA2_bit = 1;
 RA3_bit = 1;
 RB2_bit = 1;
 RB7_bit = 1;
 if( Delay_With_Check(5000))
 { is_running = 0; alloff(); continue; }
 alloff();
 RA1_bit = 1;
 RA3_bit = 1;
 RB2_bit = 1;
 RB6_bit = 1;
 if( Delay_With_Check(2000))
 { is_running = 0; alloff(); continue; }
}
}
}