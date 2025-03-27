#include <stdio.h>
#include <string.h>


int main()
{
    /*
    int VALOR1 =0;
    int VALOR2 =3;

    if (VALOR1){
        printf("CASA");
    }
    
    char nombre[5];
    char apellido[5];

    printf("Ingrese el nombre ");
    scanf("%s",nombre);
    printf("Ingrese el apellido ");
    scanf("%s",apellido);
    */
    char nombre[30];
    char apellido[30];
    printf("Ingrese el nombre: ");
    fgets(nombre, 30,stdin);
    printf("Ingrese el apellido: ");
    fgets(apellido, 30,stdin);


    printf("El nombre es %s",nombre);
    printf("El apellido es %s",apellido);
}
