#ifndef MY_LIB
#define MY_LIB
#include <stdio.h>

typedef struct{
	int hora;
	int minutos;
	char dia;
	int extension;
}datos_t;

typedef enum{
	silencio = 0,
	alarma = 1,
	posponer = 2
}estados_t;

typedef enum{
	activada = 1,
	desactivada = 0
}est_t;

//ESTADO DE SILENCIO
estados_t silencio_t(datos_t datos){
	int hora,minuto;
	est_t est;
	printf("SILENCIO\n");
	scanf("%i:%i",&hora,&minuto);
	return (hora<datos.hora || minuto<datos.minutos && est == desactivada)? silencio : alarma;	
}

//ESTADO DE POSPONER
estados_t posponer_t(datos_t datos){
	int minuto,hora;
	printf("ALARMA POSPUESTA %i MINUTOS\n",datos.extension);
    datos.minutos=datos.minutos+datos.extension; 
		
	if(datos.minutos>=60){
	int ext;
	datos.hora= datos.hora+1;
    ext=datos.minutos-60;
	datos.minutos=ext;
    }
    scanf("%i:%i",&hora,&minuto);
    return (hora<datos.hora || minuto!=datos.minutos)? silencio : alarma;
}

//ESTADO DE ALARMA
estados_t alarma_t(datos_t datos){
	int elec;
	est_t est;
	estados_t estados = alarma;
	printf("ALARMA\n(1)POSPONER|(2)DESACTIVAR\n");
	scanf("%i",&elec);
	
	if(elec==1){
		 estados = posponer;
	}
	if(elec==2){
		 est = desactivada;
		 printf("ALARMA DESACTIVADA\n");
		 estados = silencio;
	}
	return estados;
}

#endif