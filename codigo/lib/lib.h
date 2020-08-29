#ifndef MY_LIB
#define MY_LIB
#include <stdio.h>

typedef struct{
	int hora;
	int minutos;
	int rep;
	int extension;
	int dias[8];
}datos_t;

typedef enum{
	silenciada = 0,
	disparar = 1,
	pospuesta = 2
}estados_t;

typedef enum{
	activada = 1,
	desactivada = 0
}est_t;

datos_t inicio();
void reloj();
estados_t silencio(datos_t datos);
estados_t alarma(datos_t datos);
estados_t posponer(datos_t datos);

#endif