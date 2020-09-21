#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main(){
	datos_t datos;
	dias_t dias;
	datos = inicio();
	estados_t estados = silenciada;//ESTADO INICIAL//
	while(1){
	   	switch(estados){
	   		case silenciada: estados = silencio(datos);
	   		   break;
	   		    
	   		case disparar: estados = alarma(datos);
			   break;
			   
			case pospuesta: estados = posponer(datos);
			   break;       
		   }
	   }
}