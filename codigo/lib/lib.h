#ifndef MY_LIB
#define MY_LIB
#include <stdio.h>

typedef struct{
	int hora;
	int minutos;
	int rep;
	int extension;
	int dias[8],cdias;
}datos_t;

typedef enum{
	domingo = 0,
	lunes = 1,
	martes = 2,
	miercoles = 3,
	jueves = 4,
	viernes = 5,
	sabado = 6
}dias_t;

typedef enum{
	silenciada = 0,
	disparar = 1,
	pospuesta = 2
}estados_t;


datos_t inicio();
estados_t silencio(datos_t datos);
estados_t alarma(datos_t datos);
estados_t posponer(datos_t datos);
#endif