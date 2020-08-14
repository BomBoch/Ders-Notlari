#include <keypad.h>

void goster(int8,int8,int1); // sembolik tanim.
int8 tusAlgila(); // Sembolik tanim yapildi.


void main()
{

   while(TRUE)
   {
      goster(0,tusAlgila(),0);
   }

}

int8 tusAlgila()
{
   int8 key;  // int8 key = 0 ya da 1...16 degerlerinden farkli bir  deger verilebilir.
   output_d(0b11110111);  // RD3 = 0 oldušundan bu satir secildi.
   delay_ms(1);
   if(input(PIN_D4)==0) key=1;
   if(input(PIN_D5)==0) key=2; 
   if(input(PIN_D6)==0) key=3; 
   if(input(PIN_D7)==0) key=4; 
   output_d(0b11111011);  // RD2 = 0 oldušundan bu satir secildi.
   delay_ms(1);
   if(input(PIN_D4)==0) key=5;
   if(input(PIN_D5)==0) key=6; 
   if(input(PIN_D6)==0) key=7; 
   if(input(PIN_D7)==0) key=8;
   output_d(0b11111101);  // RD1 = 0 oldušundan bu satir secildi.
   delay_ms(1);
   if(input(PIN_D4)==0) key=9;
   if(input(PIN_D5)==0) key=10; 
   if(input(PIN_D6)==0) key=11; 
   if(input(PIN_D7)==0) key=12;
   output_d(0b11111110);  // RD0 = 0 oldušundan bu satir secildi.
   delay_ms(1);
   if(input(PIN_D4)==0) key=13;
   if(input(PIN_D5)==0) key=14; 
   if(input(PIN_D6)==0) key=15; 
   if(input(PIN_D7)==0) key=16;
   
   return key; // basili olan hangi buton degeri varsa o return ediliyor.

}

void goster(int8 saat, int8 dakika, int1 k)
{
   int8 s_onlar, s_birler, d_onlar, d_birler;
   static int8 sayac;
   sayac++;
   if(sayac>=250) sayac = 0;
   s_onlar  = saat / 10;
   s_birler = saat % 10;
   d_onlar  = dakika / 10;
   d_birler = dakika % 10;
   output_b(0b00000001);
   output_d(s_onlar);
   delay_ms(1);
   output_b(0b00000010);
   if(sayac<=125 && k) s_birler = s_birler | 0b00010000;
   output_d(s_birler);
   delay_ms(1);
   output_b(0b00000100);
   output_d(d_onlar);
   delay_ms(1);
   output_b(0b00001000);
   output_d(d_birler);
   delay_ms(1);

}
