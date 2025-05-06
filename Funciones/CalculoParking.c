#include <stdio.h>
/*La función calculo_carga() determina la cuenta de cada cliente en un estacionamiento público, con
una base de 2 dólares de estacionamiento mínimo por las primeras tres horas. El estacionamiento
tiene 50 centavos adicionales por cada hora o fracción. La cuenta máxima para cualquier período de
24 horas es de 10 dólares. Suponer que no existe ningún vehículo que se quede más de 24 horas a la
vez*/

#define VALOR  2
#define VALORMAX 10
#define HorasMax 24
#define HorasMin 0
#define MinutosMin 0
#define MinutosMax 59 

float calculo_carga(float horas,float minutos);
float leerNumero(char* mensaje,float max,float min);

int main()
{
    float horas = 0;
    horas = leerNumero("Ingrese las horas: ",HorasMax,HorasMin);
    float minutos = 0;
    if(horas != 24){
        minutos = leerNumero("Ingrese los minutos: ",MinutosMax,MinutosMin); 
    }
    printf("El valor que tiene que pagar es %.2f$\n",calculo_carga(horas,minutos));
    return 0;
}

float calculo_carga(float horas,float minutos){
    float valor = VALOR;
    if(horas == HorasMax){
        valor = VALORMAX;
        return valor;
    }
   if(horas <= 3 && minutos == 0){
    return valor;
   }else
   {
        horas -= 3;
        valor += horas * 0.5 ;
        if(minutos != 0){
            valor += 0.5;
        }
        return valor;
    }
}

float leerNumero(char* mensaje,float max,float min){
    float valor = 0;
    printf("%s",mensaje);
    while (scanf("%f",&valor) != 1 || valor < 0 || valor > max ||valor < min)
    {
        printf("Dato mal ingresado\n");
        printf("Minutos entre 0 y 60\n");
        printf("Horas 0 y 24\n");
        while ((getchar()) != '\n'); 
        printf("%s",mensaje);
    }
    return valor;
}