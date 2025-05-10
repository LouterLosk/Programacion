#include <stdio.h>
#include "lectura.h"
#include "funciones.h"
#define VALOR  2
#define VALORMAX 10
#define HorasMax 24
#define HorasMin 0
#define MinutosMin 0
#define MinutosMax 59 


int main()
{
    float horas = 0;
    horas = leerNumero("Ingrese las horas: ",HorasMax,HorasMin);
    float minutos = 0;
    if(horas != 24){
        minutos = leerNumero("Ingrese los minutos: ",MinutosMax,MinutosMin); 
    }
    printf("El valor que tiene que pagar es %.2f$\n",calculo_carga(horas,minutos,VALOR,HorasMax,VALORMAX));
    return 0;
}
    