#include <stdio.h>
/*Super que estamos en las elecciones y usted está haciendo un programa que le permite saber cuántos votos tiene cada candidato 
N votantes*/
 #define MAX_CANDIDATOS 5 // Definimos el número máximo de candidatos

int main() {
    int voto;
    int numCandidatos;
    int votos[MAX_CANDIDATOS] = {0};
    int cont=0;
    printf("Programa de votaciones\n");
    printf("Ingrese el numero de votantes: ");

    while (scanf("%d", &numCandidatos) == 0 || numCandidatos <= 0)
    {
        printf("Error, ingrese un numero positivo\n");
        printf("Ingrese el numero de votantes: ");
        while(getchar() != '\n');
    }
    do
    {
        printf("Ingrese su voto: ");
        printf("\n1. Candidato 1\n2. Candidato 2\n3. Candidato 3\n4. Candidato 4\n5. Candidato 5\n");
        printf("Ingrese su voto: ");
        while (scanf("%d", &voto)== 0||voto < 1 || voto > 5)
        {
            printf("Error, ingrese un numero entre 1 y 5\n");
            printf("Ingrese su voto: ");
            while(getchar() != '\n');
        }
        switch (voto) {
        case 1:
            printf("\nUsted ha votado por el candidato 1\n");
            votos [0]++;
            break;  
        case 2 :
            printf("\nUsted ha votado por el candidato 2\n");
            votos [1]++;
            break;
        case 3 :
            printf("\nUsted ha votado por el candidato 3\n");
            votos [2]++;
            break;
        case 4 :
            printf("\nUsted ha votado por el candidato 4\n");
            votos [3]++;
            break;
        case 5 :
            printf("\nUsted ha votado por el candidato 5\n");
            votos [4]++;
            break;
        
        default:
            break;
        }
        cont++;
        printf("Votos restantes: %d\n\n", numCandidatos-cont);
    } while (cont<numCandidatos);
    
    
    printf("\nResultados de la votacion:\n");
    printf("Candidato 1: %d votos\n", votos[0]);
    printf("Candidato 2: %d votos\n", votos[1]);
    printf("Candidato 3: %d votos\n", votos[2]);
    printf("Candidato 4: %d votos\n", votos[3]);
    printf("Candidato 5: %d votos\n", votos[4]);

    printf("\nCalculo de porcentajes:\n");
    for (int i = 0; i < MAX_CANDIDATOS; i++) {
        float porcentaje = (float)votos[i] / (float)numCandidatos * 100;
        if(porcentaje != 0){
            printf("Candidato %d: %.2f%%\n", i + 1, porcentaje);
        }
    }
    return 0;
}