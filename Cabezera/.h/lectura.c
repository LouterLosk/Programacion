#include<stdio.h>
#include "lectura.h"



float leerNumeroFloatEntre(char* mensaje,float max,float min){
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