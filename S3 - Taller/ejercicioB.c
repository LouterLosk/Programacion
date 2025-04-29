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
#define ESTUDIANTES 3
#define ASIGNATURAS 3
#define NOTAS 10 

int main()
{
float calificaciones[ESTUDIANTES][ASIGNATURAS];//NOTAS FINALES
float notasAsignatura[ESTUDIANTES][ASIGNATURAS][NOTAS] = {0};
int CantCalificaciones = 0;
float suma = 0;
float promedio[ESTUDIANTES];
float calificacionMax[ESTUDIANTES][1] = {0};
float calificacionMin[ESTUDIANTES][1];
float calificacionMaxNota[ASIGNATURAS][1];
float calificacionMinNota[ASIGNATURAS][1];
float estudiantesAprobados[ASIGNATURAS][1] = {0};
srand(time(NULL));

for (int i = 0; i < ESTUDIANTES; i++) {
    for (int j = 0; j < ASIGNATURAS; j++) {
        calificacionMin[i][j] = 11; // Mayor que el rango de calificaciones (0-10)
        calificacionMinNota[i][j] = 11; // Mayor que el rango de calificaciones (0-10)
    }
}

for (int i = 0; i < ASIGNATURAS; i++) {
    calificacionMax[i][0] = -1; // Inicializar con un valor menor al rango de calificaciones
    calificacionMaxNota[i][0] = -1; // Inicializar con un valor menor al rango de calificaciones
}

printf("Ingrese la cantidad de calificaciones: ");
while (scanf("%d", &CantCalificaciones) == 0){
    printf("Error: Ingrese un numero valido.\n");
    printf("Entre 1 y 10\n");
    while (getchar() != '\n'); 
    printf("Ingrese la cantidad de calificaciones: ");
}


for(int i = 0 ; i < ESTUDIANTES; i++){
    printf("Estudiante %d:\n", i + 1);
    for(int j = 0; j < ASIGNATURAS; j++){
        printf("Materia %d: \n", j + 1);
        for (int k = 0; k < CantCalificaciones; k++){
            printf("Ingrese la calificacion %d: ", k + 1);
            //notasAsignatura[i][j][k] = rand() % 11;
            while (scanf("%f", &notasAsignatura[i][j][k]) == 0 || notasAsignatura[i][j][k] < 0 || notasAsignatura[i][j][k] > 10){
                printf("Error: Ingrese un numero valido.\n");
                printf("Entre 1 y 10\n");
                while (getchar() != '\n'); 
                printf("Ingrese la calificacion %d : ", k + 1);
            }
        }
    }
}
//calculo de promedio por asignatura y por estudiante
for(int i = 0;i < ESTUDIANTES; i++){
   for (int j = 0; j < ASIGNATURAS; j++){
        suma = 0;
        for (int k = 0;k < CantCalificaciones; k++){
            suma += notasAsignatura[i][j][k];
        }
        calificaciones[i][j] = suma / CantCalificaciones;
    } 
   //calculo de promedio por estudiante
    suma = 0;
    for (int j = 0; j < ASIGNATURAS; j++)
    {
        suma += calificaciones[i][j];
    }
    promedio[i] = suma / ASIGNATURAS;
    //calculo de calificacion maxima
    for(int j = 0; j < ASIGNATURAS; j++){
        if(calificaciones[i][j] > calificacionMax[i][0]){
            calificacionMax[i][0] = calificaciones[i][j];
        }   
    }
    //calculo de calificacion minima
    for(int j = 0; j < ASIGNATURAS; j++){
        if(calificaciones[i][j] < calificacionMin[i][0]){
            calificacionMin[i][0] = calificaciones[i][j];
        }   
    }
}
//estudiantes aprobados
for(int i = 0; i < ESTUDIANTES; i++){
    for(int j = 0; j < ASIGNATURAS; j++){
        if (calificaciones[i][j] >= 6){
            estudiantesAprobados[j][0] += 1; // Estudiante aprobado
        } else {
            estudiantesAprobados[j][0] += 0; // Estudiante reprobado
        }
    }
}


//nota mas alta por materia
for (int i = 0; i < ASIGNATURAS; i++)
{
    for(int j = 0; j < ESTUDIANTES; j++){
        if(calificaciones[j][i] > calificacionMaxNota[i][0]){
            calificacionMaxNota[i][0] = calificaciones[j][i];
        }   
    }
    for(int j = 0; j < ESTUDIANTES; j++){
        if(calificaciones[j][i] < calificacionMinNota[i][0]){
            calificacionMinNota[i][0] = calificaciones[j][i];
        }   
    }
}



printf("Calificaciones ingresadas:\n");
printf("-----------------------------------------------\n");
for(int i = 0; i < ESTUDIANTES; i++){
    printf("Estudiante %d: \n", i + 1);
    for(int j = 0; j < ASIGNATURAS; j++){
        printf("\tMateria %d\n", j + 1);
        for (int k = 0; k < CantCalificaciones; k++){
            printf("\tCalificacion %d: %.2f\n", k + 1, notasAsignatura[i][j][k]);
        }
        printf("\tPromedio por materia: %.2f\n", calificaciones[i][j]);
    }
    printf("-----------------------------------------------\n");
    printf("\tPromedio por estudiante: %.2f\n", promedio[i]);
    printf("-----------------------------------------------\n");
}

printf("\nCalificaciones Maxima:\n");
for(int i = 0; i < ESTUDIANTES; i++){   
    printf("La nota de promedio mayor del estudiante %d: %.2f\n", i + 1, calificacionMax[i][0]);
}
printf("\nCalificaciones Minima:\n");
for(int i = 0; i < ESTUDIANTES; i++){   
    printf("La nota de promedio menor del estudiante %d: %.2f\n", i + 1, calificacionMin[i][0]);
}
printf("\n");
printf("Estudiantes aprobados:\n");
for (int i = 0; i < ASIGNATURAS; i++){
    printf("Materia %d: ", i + 1);
    if (estudiantesAprobados[i][0] > 0){
        printf("Aprobados %.0f\n", estudiantesAprobados[i][0]);
    } else {
        printf("No hay estudiantes aprobados.\n");
    }
} 

printf("\nCalificaciones Maxima por materia:\n");

for(int i = 0; i < ASIGNATURAS; i++){   
    printf("La nota mayor de la materia %d: %.2f\n", i + 1, calificacionMaxNota[i][0]);
}
printf("\nCalificaciones Minima:\n");
for(int i = 0; i < ASIGNATURAS; i++){   
    printf("La nota menor de la materia %d: %.2f\n", i + 1, calificacionMinNota[i][0]);
}

}