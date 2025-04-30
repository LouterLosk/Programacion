#include <stdio.h>
#include <math.h>

float hipotenusa(float Cat1 , float Cat2);
float leerNumero(char* mensaje);

int main()
{
    float Lado1,Lado2,hipo;
    Lado1 = leerNumero("Ingrese el lado 1: ");
    Lado2 = leerNumero("Ingrese el lado 2: ");
    printf("-----------------------------\n");
    printf("La hipotenusa es %.2f",hipotenusa(Lado1,Lado2));
}

float hipotenusa(float Cat1 , float Cat2){
    float hipotenusa;
    hipotenusa = sqrtf(powf(Cat1 , 2) + powf(Cat2 , 2));
    return hipotenusa;
}

float leerNumero(char* mensaje){
    float valor;
    printf(" %s: ",mensaje);
    while (scanf("%f",&valor) != 1)
    {
        printf("Dato mal ingresado\n");
        while ((getchar()) != '\n'); 
        printf("%s ",mensaje);
    }
    return valor;
}