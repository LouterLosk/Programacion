#include  <stdio.h>
#define productos 3

int main()
{
    //Globales
    int TotalVentTienda = 0,MayorIngreso = 0 ,CodigoMayorVent = 0,MayorVentas = 0,IdMayorVentas = 0;
    int repetir = 0,global = productos,codigo,CantVendida,Continuar = 0;
    float precio;
do
{
    
    do
    {
        repetir = 0;
        printf("Ingrese el codigo del producto: ");
        if (scanf("%d",&codigo) == 0 || codigo <= 0){
            printf("No ingrese un caracter o numero negativo\n");
            repetir = 1;
        }  
        while ((getchar()) != '\n'); 
    } while (repetir == 1);
    
    do
    {
        repetir = 0;
        printf("Ingrese el precio del producto: ");
        if (scanf("%f",&precio) == 0 || precio <= 0){
            printf("No ingrese un caracter o numero negativo\n");
            repetir = 1;
        } 
    while ((getchar()) != '\n');
    } while (repetir == 1);
    
    do
    {
        repetir = 0;
        printf("Ingrese la cantidad vendida del producto: "); 
        if (scanf("%d",&CantVendida) == 0 || CantVendida <= 0){
            printf("No ingrese un caracter o numero negativo\n");
            repetir = 1;
        }  
    TotalVentTienda += CantVendida;
    while ((getchar()) != '\n'); 
    } while (repetir == 1);
    

    //Calcula el producto con n mayor cantidad vendida
    if (CantVendida > MayorVentas)
    {
        MayorVentas = CantVendida;
        IdMayorVentas = codigo;
    }
    //Calcula el producto con mayor ingreso
    if((precio * CantVendida)>MayorIngreso){
        MayorIngreso = precio * CantVendida;
        CodigoMayorVent = codigo;
    }
global -= 1;
if (global > 0)
{
    do
    {
        printf("Desea agregar otro producto?\n");
        printf("SI = 1   No = 0\n");
        if(scanf("%d",&Continuar) == 0){
            printf("No ingrese un caracter o un numero diferente a 0 y 1\n");
            repetir = 1;
            while ((getchar()) != '\n'); 
        }
        else{
            if(Continuar == 0){
                repetir = 0;
                global = 0;
            }
        }
        while ((getchar()) != '\n'); 
    } while (repetir == 1);
}else{
    global = 0;
}

} while (global > 0);
printf("\nEl total de ventas de la tienda es de %d\n",TotalVentTienda);
printf("El producto con id %d tuvo la mayor contidad de ventas con %d\n",IdMayorVentas,MayorVentas);
printf("El producto con mayor ingreso es %d con %d $",CodigoMayorVent,MayorIngreso);
return 0;
}
