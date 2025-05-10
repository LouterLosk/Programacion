#include "funciones.h"
float calculo_carga(float horas,float minutos,float VALOR,float HorasMax,float VALORMAX){
    float valor = VALOR;
    if(horas == HorasMax){
        valor = VALORMAX;
        return valor;
    }
   if(horas <= 3 && minutos == 0){
    return valor;
   }else
   {
        horas -= 3;
        valor += horas * 0.5 ;
        if(minutos != 0){
            valor += 0.5;
        }
        return valor;
    }
}