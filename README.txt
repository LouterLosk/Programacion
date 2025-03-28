Constantes 
Var constante
Const int MAX = 10;
Definido 
#define DESCUENTO 0,2
Secuencial 

Condicional 			if 		switch		if/else

Repetitivas 			while 		do while 	for 

&& and 
|| or 
! not 

falso = o 
verdad = cualquier numero deferente a 0

CONTADORES 
a+ = 1

ACUMULADORRES 

a+ = b

CARACTER
'a'

CADENA
"casa"

//librerias #include<stdlib.h> #include<time.h>

srand(time(NULL)); numero=rand()%100;

#include <stdio.h>

int x //crear una variable//

//leer// scanf("",&variable) %d entero %f real %c caracter //mostrar// printf("Hola") printf("VAlor de %d",valor) printf("%d %d %d",x1,x2,x3)

int main(){ }

/areglos int[] j

simpre empieza en 0

ejemplo for(int i=0 ; i<= 4 ;i++) scanf("%d",&numero[i])

###Git

abrebiatura git --global user.name"" git -- global user.email"" git init git status git add carpeta/*.js git reset git commit git commit -am "" //Comit a un archivo ya seguido git checkout .--. utiliza en Git para descartar cualquier cambio no guardado git branch ramas git Log
##Crar Aliaz git Status --short git config --global alias.s "status" git config --global alias.lg "log --oneline --all --graph --decorate --date=short"

##Cambiar nombre a un commit git commit --amend -m "" HEAD utimo commit ^anterior ^3 anterior x3 git reset --soft HEAD --mix

git reflog

##<string.h>

strcpy ( c1, c2 ); Copia c2 en c1 strcat ( c1, c2 ); Añade c2 al final de c1 int strlen ( cadena ); Devuelve la longitud de la cadena int strcmp ( c1, c2 ); Devuelve cero si c1 es igual a c2; no-cero en caso contrario


leer cadena 

char nombre[30];
scanf("%s",nombre)



solo para careacteres 
gets(nombre)
fgets(nombre, 30 ,stdin)


Muchas funciones de la biblioteca estándar de C utilizan . Por ejemplo:
sizeof devuelve el tamaño de un objeto en bytes como un size_t.
Funciones como strlen (para medir la longitud de cadenas) tambien devuelven valores de tipo size_t


int entero = 42;
    char cadena[10]; // Asegúrate de que el tamaño sea suficiente para almacenar la cadena.
    
    sprintf(cadena, "%d", entero); // Convierte el entero a cadena.
    
    printf("La cadena es: %s\n", cadena);