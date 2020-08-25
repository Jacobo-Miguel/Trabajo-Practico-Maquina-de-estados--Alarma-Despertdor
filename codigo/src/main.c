#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


int main(){
	datos_t datos;
	estados_t estados = silencio;//ESTADO INICIAL//

	int i=0;
	char eleccion,elec;
	char dias[1][7][20];
	//CREANDO EL ARCHIVO DE CONFIGURACION//
	FILE *alarmap;
	if((alarmap=fopen("alarmap","wb"))==NULL){
		printf("NO SE PUDO LEER EL ARCHIVO");
	}
	else{
	printf("--------------------------------------------------ALARMA DESPERTADOR---------------------------------------------------\n");
	printf("*AGREGAR ALARMA\n");
	printf("\tHORA: ");
	scanf("%i",&datos.hora);
	printf("\tMINUTOS: ");
	scanf("%i",&datos.minutos);
	fflush(stdin);
    do{
		    printf("*LUNES/MARTES/MIERCOLES/JUEVES/VIERNES/SABADO/DOMINGO*\n");
           	printf("SELECCIONE EL DIA: ");
		    fflush(stdin);
		    gets(dias[0][i]);
		    fflush(stdin);
		    i++;
		    printf("AGREGAR OTRO DIA (S/N): ");
		    scanf("%c",&eleccion);
		    
			
		}while(eleccion=='S'|| eleccion=='s');
	     fflush(stdin);	
	     printf("REPETIR (S/N): ");
         scanf("%c",&elec);
	     if(elec=='S' || elec== 's'){
	     	printf("\n\t5 MINUTOS\n\t10 MINUTOS\n\t15 MINUTOS\n\t30 MINUTOS\n");
	    	scanf("%i",&datos.extension);
	      }
		   system("cls");
	       fflush(stdin);
	       fwrite(&datos,sizeof(datos),1,alarmap);
		   fclose(alarmap);
	  }//FIN DE LA CREACION DEL ARCHIVO DE CONFIGURACION//
	  est_t est = activada;
	  
	if((alarmap=fopen("alarmap","rb"))==NULL){
	   	printf("NO SE PUEDE LEER EL ARCHIVO DE CONFIGURACION");
	   } 
	   
    else{
	   	
	   	fread(&datos,sizeof(datos),1,alarmap);
	   	if(datos.minutos<10){
	    	printf("ALARMA PROGRAMADA: %i:0%i HS",datos.hora,datos.minutos);
	    	
		 }
		else{
			printf("ALARMA PROGRAMADA: %i:%i HS",datos.hora,datos.minutos);
		 }
		
		fflush(stdin);
	    printf("\nDIA/S: ");
	    int j;
	    for(j=0;j<i;j++)
	    {
	    	printf("%s ",dias[0][j]);
		}
		printf("\n");
		printf("*REPETIR A LOS %i MINUTOS\n",datos.extension);
		
		system("pause");
	    system("cls");
	   	fclose(alarmap);
	   }
	   
	   while(1){
	   	switch(estados){
	   		case silencio: estados = silencio_t(datos);
	   		   break;
	   		    
	   		case alarma: estados = alarma_t(datos);
			   break;
			   
			case posponer: estados = posponer_t(datos);
			   break;       
		   }
	   }
	
	
	return 0;
}

