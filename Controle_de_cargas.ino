/*CONTROLE DE TOLDO E VENTILADOR*/



#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

int Temp;

int Temperatura_Minima = 30;

int Temperatura_Maxima = 40;



void setup ()



{

pinMode(8, INPUT);

digitalWrite(8, HIGH);

}



void loop ()



{

   Temp = analogRead(A0) * 500.0 / 1023.0;          // LÊ O SENSOR DE TEMPERATURA E CONVERTE O VALOR PARA Cº

   lcd.setCursor(0,0);

   lcd.print("TEMPERATURA=");

   lcd.print(Temp);

   lcd.print(char(223));                   // INSERI Cº     

   lcd.print("C");                  // INSERI O "C"

   lcd.setCursor(1,0);





if (digitalRead(8)==0)



  {

    digitalWrite(9, HIGH);

    digitalWrite(7, LOW);

    lcd.setCursor(0,1);

    lcd.print("TOLDO ACIONADO");

   }

if (Temp<=Temperatura_Minima)



   {

     digitalWrite(7, HIGH);

     digitalWrite(9, LOW);

     lcd.setCursor(0,1);

     lcd.print("VENTILADOR ACIONADO");

   }

if (Temp>=Temperatura_Maxima)



   {

    digitalWrite(7, LOW);

    digitalWrite(9, LOW);

   }

else



  {

   digitalWrite(7, LOW);

   digitalWrite(9, LOW);

  }

 }
