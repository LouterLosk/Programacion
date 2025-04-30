#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Una tienda desea implementar un programa en C que permita gestionar su inventario de productos. 
El programa debe recibir los nombres de los productos y sus precios, para luego realizar varias operaciones, tales como:
•	Calcular el precio total del inventario.
•	Encontrar el producto más caro y el más barato.
•	Calcular el precio promedio de todos los productos.
•	Buscar un producto por su nombre y mostrar su precio.
*/
#define MAX_PRODUCTOS 2
#define LONGITUD 50

int validacion(char palabra[LONGITUD]);

int main()
{
    char NombreProducto[MAX_PRODUCTOS][LONGITUD];
    float PrecioProducto[MAX_PRODUCTOS];
    for (int i = 0; i < MAX_PRODUCTOS; i++){
        printf("Ingrese el nombre del producto %d: ", i + 1);
        fgets(NombreProducto[i], LONGITUD, stdin);
        size_t len = strlen(NombreProducto[i]);

        if (len > 0 && NombreProducto[i][len - 1] == '\n') {
            NombreProducto[i][len - 1] = '\0'; // elimina el salto de línea
        }


        if (!validacion(NombreProducto[i])){
            printf("No se permite el ingreso de numeros\n");
            i --;
        }
        else{
            printf("Ingrese el precio del producto %d: ", i+1);
            while (scanf("%f",&PrecioProducto[i]) != 1)
            {
                printf("Solo se permiten numeros\n");
                printf("Ingrese el precio del producto %d: ", i+1);
                while ((getchar()) != '\n'); 
            }
            while ((getchar()) != '\n'); 
        }
    }

    printf("\nLista de productos:\n");
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        printf("Producto %d: %s\t %.2f\n", i + 1, NombreProducto[i],PrecioProducto[i]);
    }
}




int validacion(char palabra[LONGITUD]){
    for (int i = 0; i < strlen(palabra); i++) {
        if (!isalpha(palabra[i]) && palabra[i] != ' ') {
            return 0;
        }
    }
return 1;
}
