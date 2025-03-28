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

int ValidarNum(char *num){
    if (esNumero(num)) {
        long numero = strtol(num, NULL, 10);
        return 1;
    } else {
        printf("Entrada invalida: No es un numero positivo.\n");
        return 0;
    } 
}

int main() {
    int cantidad, opcion,resultado,stockint;
    int repetir = 1;
    float precio = 0,total_ganancias = 0;
    char nombre[50],cantidadStr[20];
    char id[20],stock[20];
/*
    // Registro del producto
    do //ID
    {
        printf("Ingrese el ID del producto: ");
        scanf("%s", &id);
        if (ValidarNum(id) != 0) {
            repetir = 1; // Si la validación es exitosa
        } else {
            repetir = 0; // Si la validación falla
        }
    }while (repetir == 0);

    while ((getchar()) != '\n'); 

    do//Nombre del producto
    {
        int es_valido = 1; // Asumimos que es válido inicialmente
        printf("Ingrese el nombre del producto: ");
        fgets(nombre, sizeof(nombre), stdin);
        // Eliminamos el salto de línea si existe
        size_t longitud = strlen(nombre);
        if (nombre[longitud - 1] == '\n') {
            nombre[longitud - 1] = '\0';
        }
        // Validamos que todos los caracteres sean letras o espacios
        for (int i = 0; i < strlen(nombre); i++) {
            if (!isalpha(nombre[i]) && nombre[i] != ' ') {
                es_valido = 0;
                break;
            }
        }
        if (es_valido) {
            printf("Entrada valida: %s\n", nombre);
            repetir = 0;
        } else {
            printf("Entrada invalida: contiene numeros u otros caracteres no permitidos.\n");
            repetir = 1;
        }
    }while (repetir);
*/

    do//inicial stock
    {
        printf("Ingrese la cantidad inicial en stock: ");
        scanf("%s", &stock);
        if (ValidarNum(stock) != 0) {
            repetir = 1; // Si la validación es exitosa
        } else {
            repetir = 0; // Si la validación falla
        }
        stockint = atoi(stock);
    }while (repetir == 0 || stockint < 0);
    
    do //Valor unitario del precio
    {
        printf("Ingrese el precio unitario del producto: ");
        resultado = scanf("%f", &precio);

        if (resultado == 1 && precio > 0) {
         repetir = 0;
        }
        else {
        printf("Entrada no valida. Por favor, ingresa un numero flotante.\n");
        repetir = 1;
         while (getchar() != '\n');
        }

    }while (repetir || precio < 0);

    do//menu 
    {
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
            do
            {
                printf("\nIngrese la cantidad a vender: ");
                scanf("%s", &cantidadStr);
                if (ValidarNum(cantidadStr) != 0) {
                    repetir = 0; // Si la validación es exitosa
                } else {
                    repetir = 1; // Si la validación falla
                }
                cantidad = atoi(cantidadStr);
                while ((getchar()) != '\n'); 
            } while (repetir || cantidad < 0);
            if(cantidad <= stockint){
                printf("Venta exitosa\n");
                printf("El valor de la venta es: %.2f $\n",precio * cantidad);
                stockint -= cantidad;
            }else{
                printf("No hay el stock suficiente\n");
                printf("Stock disponible: %d\n", stockint);
            }
            break;
            case 2:
                printf("Ingrese la cantidad a agregar al stock: ");
                scanf("%d", &cantidad);
                break;

            case 3:
                printf("\nInformacion del producto:\n");
                printf("ID: %s\n", id);
                printf("Nombre: %s\n", nombre);
                printf("Stock disponible: %d\n", stockint);
                printf("Precio unitario: %.2f $\n", precio);
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
    }while (opcion != 5);

    return 0;
}
