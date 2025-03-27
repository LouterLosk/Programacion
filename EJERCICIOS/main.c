#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

int esNumero(const char *str) {
    // Verificar si la cadena está vacía
    if (*str == '\n' || *str == '\0') {
        return 0;
    }

    // Recorrer cada carácter de la cadena
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (!isdigit((unsigned char)str[i])) {
            return 0;  // Si hay un carácter no numérico, retorna falso (0)
        }
    }
    return 1;  // Si todos son dígitos, retorna verdadero (1)
}

int Validar(char *num){
    if (esNumero(num)) {
        long numero = strtol(num, NULL, 10);
        printf("Numero valido: %ld\n", numero);
        return 1;
        getchar(); // Limpia el buffer
    } else {
        printf("Entrada invalida: No es un numero.\n");
        return 0;
        getchar();
    } 
}

int main() {
    int cantidad, opcion;
    int repetir = 1;
    float precio, total_ganancias = 0;
    char nombre[30];
    char id[20],stock[20];

    // Registro del producto
    do
    {

        printf("Ingrese el ID del producto: ");
        scanf("%s", &id);
        if (Validar(id) != 0) {
            repetir = 1; // Si la validación es exitosa
        } else {
            repetir = 0; // Si la validación falla
        }
    } while (repetir == 0);
     
    printf("Ingrese el nombre del producto: ");
    fgets(nombre, 30, stdin);
    getchar(); // Limpia el buffer
    do
    {
        printf("Ingrese la cantidad inicial en stock: ");
        scanf("%s", &stock);
        if (Validar(stock) != 0) {
            repetir = 1; // Si la validación es exitosa
        } else {
            repetir = 0; // Si la validación falla
        }
    } while (repetir == 0);
    
    printf("Ingrese el precio unitario del producto: ");
    scanf("%f", &precio);

    do {
        printf("\nMenu de Opciones:\n");
        printf("1. Vender producto\n");
        printf("2. Reabastecer producto\n");
        printf("3. Mostrar informacion del producto\n");
        printf("4. Mostrar total de ganancias\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese la cantidad a vender: ");
                scanf("%d", &cantidad);
                
                
                break;

            case 2:
                printf("Ingrese la cantidad a agregar al stock: ");
                scanf("%d", &cantidad);
                
                
                break;

            case 3:
                printf("\nInformacion del producto:\n");
                printf("ID: %s\n", id);
                printf("Nombre: %s", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                break;

            case 4:
                printf("Total de ganancias: $%.2f\n", total_ganancias);
                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion involida. Intente nuevamente.\n");
        }
    } while (opcion != 5);

    return 0;
}
