#include <stdio.h>
/*
Una compañía de refrescos comercializa n productos. 
Se desea realizar un programa
que calcule las ventas realizadas de cada producto. 
Para ello, se leerá la cantidad vendida
y el precio en dólares de cada producto y 
se mostrará un informe de ventas como el que
se muestra
*/

#define MAX_CANTIDAD 4



int main()
{

    //int Producto[MAX][MAX];
    //                fila    columan
    float Cantidad[MAX_CANTIDAD][2] = {0};
    int ProductosVendidos = 0;


    printf("Ingrese la cantidad de productos: ");
    while (scanf("%d", &ProductosVendidos) == 0 || ProductosVendidos <= 0 || ProductosVendidos > MAX_CANTIDAD)
    {
        while (getchar() != '\n');
        printf("Error, ingrese un valor valido: \n");
        printf("Ingrese la cantidad de productos: ");
    }
  
    for (int i = 0; i < ProductosVendidos; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if(j == 0)
            { 
                printf("Ingrese la cantidad del producto %d vendidos: ", i + 1); 
                scanf("%f", &Cantidad[i][j]);
            }
            else if (j == 1)
            {
                printf("Ingrese el precio del producto %d vendido: ", i + 1);
                scanf("%f", &Cantidad[i][j]);
            }
        }
    }
    printf("Producto\tCantidad\tPrecio\tTotal\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < ProductosVendidos; i++)
    {
        printf("%d\t\t%.2f\t\t%.2f\n", i + 1,Cantidad[i][0],Cantidad[i][1]); 
    }
    
    return 0;
}
