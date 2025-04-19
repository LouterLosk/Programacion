#include <time.h> 
#include<stdio.h>
#include<stdlib.h>
#define ANIO 2
#define MES 4



int main(){
float lluvia[ANIO][MES];
float promedioAnio[ANIO];
float AnioMax = 0 ,AnioMin = 100;
float MesMax = 0, MesMin = 100;
float promedioMes[MES];
float suma;
float promedio;
srand(time(NULL));
for(int i = 0; i < ANIO; i++){
    for(int j = 0; j < MES; j++)
    {
    lluvia[i][j] = rand() % 101;
    }
printf("\n");
}

//Imprimir datos
printf("Datos historicos de lluvia mensual en los ultimos %d anios\n", ANIO);
for(int i = 0; i < ANIO; i++){
    for(int j = 0; j < MES; j++){
        printf("%.2f\t", lluvia[i][j]);
    }
printf("\n");
}

//Promedio de lluvia por año
for(int i = 0; i < ANIO; i++){
    suma=0;
    for(int j = 0; j < MES; j++){
        suma+=lluvia[i][j];
    }
promedioAnio[i]=suma/MES;
}

//Promedio de lluvia por mes
for (int j = 0; j < MES; j++)
{
    suma=0;
    for (int i = 0; i < ANIO; i++)
    {
        suma+=lluvia[i][j];
    }
promedioMes[j]=suma/ANIO;
}
printf("\n");
printf("Promedio de lluvia por anio\n");
for(int i = 0; i < ANIO; i++){
    printf("El promedio de lluvia del anio %d es %.2f\n",i+1,promedioAnio[i]);
}
printf("\n");
printf("Promedio de lluvia por mes\n");
for(int i = 0; i < MES; i++){
    printf("El promedio de lluvia del mes %d es %.2f\n",i+1,promedioMes[i]);
}
//Anio que lluvio mas y menos 
for(int i = 0; i < ANIO; i++){
    if(promedioAnio[i] > AnioMax)
    AnioMax = promedioAnio[i];

    if(promedioAnio[i] < AnioMin)
    AnioMin = promedioAnio[i];
}
//Mes que lluvio mas y menos 
for(int i = 0; i < MES; i++){
    if(promedioMes[i] > MesMax)
    MesMax = promedioMes[i];

    if(promedioMes[i] < MesMin)
    MesMin = promedioMes[i];
}
printf("----------------------------\n");
printf("El anio que lluvio mas fue %.2f\n",AnioMax);
printf("El anio que lluvio menos fue %.2f\n",AnioMin);
printf("El mes que mas lluvio fue %.2f\n",MesMax);
printf("El mes que menos lluvio fue %.2f",MesMin);
printf("\n");
printf("----------------------------\n");
//El anio que llovio mas que el promedio   
suma=0; 
for(int i = 0; i < ANIO; i++){
    suma += promedioAnio[i];
}
promedio = suma / ANIO;
printf("El promedio de lluvia por anio es %.2f\n",promedio);
for (int i = 0; i < ANIO; i++)
{
    if (promedioAnio[i] > promedio)
    printf("El anio %d es mayor al promedio con %.2f\n", i+1, promedioAnio[i]);
}

printf("----------------------------\n");
suma=0; 
promedio = 0;
for(int i = 0; i < MES; i++){
    suma += promedioMes[i];
}
promedio = suma / MES;
printf("El promedio de lluvia de los meses es %.2f\n",promedio);
for (int i = 0; i < MES; i++)
{
    if (promedioMes[i] > promedio)
    printf("El mes %d es mayor al promedio de %.2f\n", i+1, promedioMes[i]);
}




return 0;
}
