/*Descripción del Problema: 
Una escuela desea implementar un programa en C que le permita gestionar las calificaciones de
un grupo de estudiantes en varias asignaturas. 
Además de gestionar las calificaciones, el programa debe calcular y 
mostrar información relevante como el 
promedio de calificaciones por estudiante y por asignatura,
la calificación más alta y baja,
y cuántos estudiantes aprobaron cada asignatura.*/
#include <time.h> 
#include<stdio.h>
#include<stdlib.h>
#define ESTUDIANTES 2
#define ASIGNATURAS 3
#define NOTAS 10 

int main()
{
float calificaciones[ASIGNATURAS][ESTUDIANTES];//NOTAS FINALES
float notasAsignatura[ASIGNATURAS][NOTAS] = {0};
int CantCalificaciones = 0;
float suma;
float promedio[ESTUDIANTES];
float calificacionMax[ESTUDIANTES][1] = {0};
float calificacionMin[ESTUDIANTES][1] = {100};
srand(time(NULL));






printf("Ingrese las calificaciones de los estudiantes: ");
while (scanf("%d", &CantCalificaciones) == 0){
    printf("Error: Ingrese un número válido.\n");
    printf("Entre 1 y 10\n");
    printf("Ingrese las calificaciones de los estudiantes:");
    printf("\n");
    while (getchar() != '\n'); 
}

for(int i = 0; i < ESTUDIANTES; i++){
    printf("Estudiante %d:\n", i + 1);
    for(int j = 0; j < ASIGNATURAS; j++){
        printf("Materia %d: \n", j + 1);
        //scanf("%f", &calificaciones[j][i]);
        calificaciones[j][i] = rand() % 11;
    }
}

for(int i = 0 ; i < CantCalificaciones; i++){
    for(int j = 0; j < ASIGNATURAS; j++){
        printf("Materia %d: \n", i + 1);
        printf("Ingrese la calificacion %d del estudiante %d: ",i + 1, j + 1);
        scanf("%f", &notasAsignatura[j][i]);
    }
}



//calculo de promedio 
for(int i = 0; i < ESTUDIANTES; i++){
    suma = 0;
    for(int j = 0; j < ASIGNATURAS; j++){
        suma += calificaciones[j][i];
    }
    promedio[i] = suma / ASIGNATURAS;
}
//minima y maxima nota
for(int i = 0; i < ESTUDIANTES; i++){
    for(int j = 0; j < ASIGNATURAS; j++){
        if(calificaciones[j][i] > calificacionMax[i][0]){
            calificacionMax[i][0] = calificaciones[j][i];
        }
    }
}

printf("\nCalificaciones Maxima:\n");
for(int i = 0; i < ESTUDIANTES; i++){   
    printf("La nota mayor del estudiante %d: %.2f\n", i + 1, calificacionMax[i][0]);
}

printf("\nCalificaciones Maxima:\n");
for(int i = 0; i < ESTUDIANTES; i++){   
    printf("La nota mayor del estudiante %d: %.2f\n", i + 1, calificacionMax[i][0]);
}

printf("\nCalificaciones ingresadas:\n");
for(int i = 0; i < ESTUDIANTES; i++){   
    for(int j = 0; j < ASIGNATURAS; j++){
        if(calificaciones[j][i] > calificacionMax[i][0]){
            calificacionMax[i][0] = calificaciones[j][i];
        }
    }
    printf("Estudiante %d:\n", i + 1);
    printf("Materia 1: %.2f\n", calificaciones[0][i]);
    printf("Materia 2: %.2f\n", calificaciones[1][i]);
    printf("Materia 3: %.2f\n", calificaciones[2][i]);  
    printf("El promedio del estudiante %d es %.2f\n", i + 1, promedio[i]);
    printf("La nota mayor del estudiante %d: %.2f\n", i + 1, calificacionMax[i][0]);
}   
}
