#include <stdio.h>
#include <ctype.h>
/*
Ejercicio 2: Control de Asistencias de Estudiantes
Descripción:
Se requiere desarrollar un sistema de control de asistencia para M estudiantes durante N
días.s
1. Se pedirá al usuario ingresar la cantidad de estudiantes y la cantidad de días a
registrar.
2. Luego, para cada estudiante, se ingresará la asistencia (A para presente, F para
falta) de cada día.
3. El programa mostrará:
o Porcentaje de asistencia de cada estudiante.
o Los estudiantes con menos del 70% de asistencia (reprobados por
inasistencias).
Restricciones y requisitos:
• Definir un valor mínimo de asistencia como constante (#define)
*/

int main()
{
    int Students,assistance,repetir = 0; // Variables para almacenar la cantidad de estudiantes y días de asistencia
    int presente = 0,falta = 0;
    float porcentaje ;
    char attendance; // Matriz para almacenar la asistencia de los estudiantes 
    do
    {
        printf("Ingrese la cantidad de estudiantes: ");
        if(scanf("%d",&Students) == 0|| Students <= 0){
            printf("Entrada no valida\n");
            repetir = 1;
            while (getchar() != '\n');
        }else{
            repetir = 0;
        }
    } while (repetir);
    do
    {
        printf("Ingrese la cantidad de dias de asistencia: ");
        if(scanf("%d",&assistance) == 0|| assistance <= 0){
            printf("Entrada no valida\n");
            repetir = 1;
            while (getchar() != '\n');
        }else{
            repetir = 0;
        }
    } while (repetir);

  

    do
    {
        do
        {
            while (getchar() != '\n');
            printf("Ingrese la sistencia del estudiante (A para presente, F para falta): \n");
            if(scanf(" %c",&attendance) == 0){
                printf("No se permiten Numeros");
            }else{
                repetir = 0;
            }
            attendance = toupper(attendance);// Convertir la entrada a mayúsculas
        } while (repetir);
        switch (attendance)
        {

        case 'A':
            printf("Asistencia registrada como presente\n");
            presente++;
            repetir = 0;
            break;
        case 'F':
            printf("Asistencia registrada como falta\n");
            falta++;
            repetir = 0;
            break;
        default:
            printf("Entrada no válida. Por favor, ingrese 'A' o 'F'.\n");
            repetir = 1;
            while (getchar() != '\n');
            break;
        }
    } while (repetir);

    printf("\nAsistencia del estudiante: %d presentes, %d faltas\n", presente, falta);
    porcentaje = (float)presente / (presente + falta) * 100; // Calcular el porcentaje de asistencia
    printf("Porcentaje de asistencia: %.0f%%\n", porcentaje);
        return 0;
}
