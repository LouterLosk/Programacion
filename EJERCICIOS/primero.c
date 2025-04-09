#include <stdio.h>
#include <string.h>
#define MAX 5

int main()
{
    int notas[MAX],cont = 0;
    float promedio = 0;
    int suma = 0,mayor= 0,menor = 10;

    for (int  i = 0; i < MAX; i++)
    {
        printf("Ingrese la nota del estudiante %d: ", i + 1);
        scanf("%d", &notas[i]);
        suma += notas[i];
        if (notas[i] < menor){
            menor = notas[i];
        }
        if (notas[i] > mayor){
            mayor = notas[i];
        }

    }
    for (int i = 0; i < MAX; i++)
    {
        printf("La nota del estudiante %d es: %d\n", i + 1, notas[i]);
    }
    promedio = (float)suma / MAX;
    printf("El promedio de las notas es: %.2f\n", promedio);
    printf("La nota mayor es: %d\n", mayor);
    printf("La nota menor es: %d\n", menor);

    printf("Numeros repetidos:\n");
    int repetido = 0;
    for (int i = 0; i < MAX; i++)
    {
        cont = 0;
        for (int j = i + 1; j < MAX; j++)
        {
            
            if (notas[i] == notas[j])
            {
                cont ++;
                repetido = 1;
            }
        }
        if (cont > 0)
        {
            printf("La nota %d se repite %d veces.\n", notas[i],cont);
        }
    }
    if (repetido == 0)
    {
        printf("No hay números repetidos.\n");
    }

}
