#include <mod10000.h>

void goster(int8,int8,int1); // sembolik tanim.

void main()
{  int8 s,d;
   int16 i;

   while(TRUE)
   {
      for(s=0;s<=99;s++)
         for(d=0;d<=99;d++)
            for(i=1;i<=100;i++) // yaklasik 40 ms araliklarla degisecek sekilde ayarlandi.
               goster(s,d,1);   // yaklasik 4ms zaman alir.
   }
  
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
