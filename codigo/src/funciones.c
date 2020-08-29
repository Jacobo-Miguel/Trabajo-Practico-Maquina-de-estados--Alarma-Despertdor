#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "lib.h"

//CONFIGURAR ALARMA
datos_t inicio(){
	datos_t datos;

	int i=0;
	int k,h;
	char eleccion,elec;
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
		    printf("|(0)DOMINGO/(1)LUNES/(2)MARTES/(3)MIERCOLES/(4)JUEVES/(5)VIERNES/(6)SABADO|\n");
           	printf("SELECCIONE EL DIA: ");
		    scanf("%d",&datos.dias[i]);
		    while(datos.dias[i]!= 0 && datos.dias[i]!= 1 && datos.dias[i]!= 2 && datos.dias[i]!= 3 && datos.dias[i]!= 4 && datos.dias[i]!= 5 && datos.dias[i]!= 6){
		    	printf("DIA INEXISTENTE!!\n");
		    	printf("|(0)DOMINGO/(1)LUNES/(2)MARTES/(3)MIERCOLES/(4)JUEVES/(5)VIERNES/(6)SABADO|\n");
           	    printf("SELECCIONE EL DIA NUEVAMENTE: ");
		        scanf("%d",&datos.dias[i]);
			}
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
	   	while(datos.extension!= 5 && datos.extension!= 10 && datos.extension!= 15 && datos.extension!= 30){
	   		printf("NUMERO EQUIVOCADO!!\n");
	   		printf("\t5 MINUTOS\n\t10 MINUTOS\n\t15 MINUTOS\n\t30 MINUTOS\n");
	   	    scanf("%i",&datos.extension);
	    }
	   	printf("REPETIR CADA: \n\t3 VECES\n\t5 VECES\n");
	   	scanf("%d",&datos.rep);
	   	while(datos.rep!= 3 && datos.rep!= 5){
	   		printf("NUMERO EQUIVOCADO!!");
	   		printf("REPETIR CADA: \n\t3 VECES\n\t5 VECES\n");
	   	    scanf("%d",&datos.rep);
	    }
	  }
      system("cls");
      fflush(stdin);
      fwrite(&datos,sizeof(datos),1,alarmap);
      fclose(alarmap);
   }
	  
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
	    	if(datos.dias[j]==0){
	    		printf("DOMINGO/");
			}
			if(datos.dias[j]==1){
				printf("LUNES/");
			}
			if(datos.dias[j]==2){
				printf("MARTES/");
			}
			if(datos.dias[j]==3){
				printf("MIERCOLES/");
			}
			if(datos.dias[j]==4){
				printf("JUEVES/");
			}
			if(datos.dias[j]==5){
				printf("VIERNES/");
			}
			if(datos.dias[j]==6){
				printf("SABADO/");
			}
		}
		printf("\n");
		printf("*REPETIR A LOS %i MINUTOS %i VECES\n",datos.extension,datos.rep);
	    system("pause");
        system("cls");
	    fclose(alarmap);
	   }
	   return datos;
}


//ESTADO DE SILENCIO
estados_t silencio(datos_t datos){
	int hora,minuto,segundos,dia;
	est_t est;
	est = activada;
	time_t tiempoahora;
    time(&tiempoahora);
    struct tm *mitiempo = localtime(&tiempoahora);
	hora = mitiempo->tm_hour;
    minuto = mitiempo->tm_min;
    segundos = mitiempo->tm_sec;
    dia = mitiempo->tm_wday;
		
		if(hora<10 && minuto<10 && segundos<10){
			if(dia == 0){
    			printf("DOMINGO\n");
			}
			if(dia == 1){
				printf("LUNES\n");
			}
			if(dia == 2){
    			printf("MARTES\n");
			}
			if(dia == 3){
    			printf("MIERCOLES\n");
			}
			if(dia == 4){
    			printf("JUEVES\n");
			}
			
			if(dia == 5){
    			printf("VIERNES\n");
			}
			if(dia == 6){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("0%d:0%d:0%d",hora,minuto,segundos);
			Sleep(1000);
			system("cls");
		} 
		
		if(hora>=10 && minuto>=10 && segundos>=10){
			if(dia == 0){
    			printf("DOMINGO\n");
			}
			if(dia == 1){
				printf("LUNES\n");
			}
			if(dia == 2){
    			printf("MARTES\n");
			}
			if(dia == 3){
    			printf("MIERCOLES\n");
			}
			if(dia == 4){
    			printf("JUEVES\n");
			}
			
			if(dia == 5){
    			printf("VIERNES\n");
			}
			if(dia == 6){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("%d:%d:%d",hora,minuto,segundos);
			Sleep(1000);
			system("cls");	
		} 
		
		if(hora<10 && minuto<10 && segundos>=10){
			if(dia == 0){
    			printf("DOMINGO\n");
			}
			if(dia == 1){
				printf("LUNES\n");
			}
			if(dia == 2){
    			printf("MARTES\n");
			}
			if(dia == 3){
    			printf("MIERCOLES\n");
			}
			if(dia == 4){
    			printf("JUEVES\n");
			}
			
			if(dia == 5){
    			printf("VIERNES\n");
			}
			if(dia == 6){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("0%d:0%d:%d",hora,minuto,segundos);
			Sleep(1000);
			system("cls");
		} 
		
		if(hora<10 && segundos<10 && minuto>=10){
			if(dia == 0){
    			printf("DOMINGO\n");
			}
			if(dia == 1){
				printf("LUNES\n");
			}
			if(dia == 2){
    			printf("MARTES\n");
			}
			if(dia == 3){
    			printf("MIERCOLES\n");
			}
			if(dia == 4){
    			printf("JUEVES\n");
			}
			
			if(dia == 5){
    			printf("VIERNES\n");
			}
			if(dia == 6){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("0%d:%d:0%d",hora,minuto,segundos);
			Sleep(1000);
			system("cls");
		}
		
		if(minuto<10 && segundos<10 && hora>=10){
			if(dia == 0){
    			printf("DOMINGO\n");
			}
			if(dia == 1){
				printf("LUNES\n");
			}
			if(dia == 2){
    			printf("MARTES\n");
			}
			if(dia == 3){
    			printf("MIERCOLES\n");
			}
			if(dia == 4){
    			printf("JUEVES\n");
			}
			
			if(dia == 5){
    			printf("VIERNES\n");
			}
			if(dia == 6){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("%d:0%d:0%d",hora,minuto,segundos);
			Sleep(1000);
			system("cls");
		}
		
		if(hora<10 && minuto>=10 && segundos>=10){
			if(dia == 0){
    			printf("DOMINGO\n");
			}
			if(dia == 1){
				printf("LUNES\n");
			}
			if(dia == 2){
    			printf("MARTES\n");
			}
			if(dia == 3){
    			printf("MIERCOLES\n");
			}
			if(dia == 4){
    			printf("JUEVES\n");
			}
			
			if(dia == 5){
    			printf("VIERNES\n");
			}
			if(dia == 6){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("0%d:%d:%d",hora,minuto,segundos);
			Sleep(1000);
			system("cls");
		}
		
		if(minuto<10 && hora>=10 && segundos>=10){
			if(dia == 0){
    			printf("DOMINGO\n");
			}
			if(dia == 1){
				printf("LUNES\n");
			}
			if(dia == 2){
    			printf("MARTES\n");
			}
			if(dia == 3){
    			printf("MIERCOLES\n");
			}
			if(dia == 4){
    			printf("JUEVES\n");
			}
			
			if(dia == 5){
    			printf("VIERNES\n");
			}
			if(dia == 6){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("%d:0%d:%d",hora,minuto,segundos);
			Sleep(1000);
			system("cls");
		}
		
		if(segundos<10 && hora>=10 && minuto>=10){
			if(dia == 0){
    			printf("DOMINGO\n");
			}
			if(dia == 1){
				printf("LUNES\n");
			}
			if(dia == 2){
    			printf("MARTES\n");
			}
			if(dia == 3){
    			printf("MIERCOLES\n");
			}
			if(dia == 4){
    			printf("JUEVES\n");
			}
			
			if(dia == 5){
    			printf("VIERNES\n");
			}
			if(dia == 6){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("%d:%d:0%d",hora,minuto,segundos);
			Sleep(1000);
			system("cls");
		}	

	return (hora<datos.hora || minuto!=datos.minutos || est == desactivada)? silenciada : disparar;	
}

//ESTADO DE POSPONER
estados_t posponer(datos_t datos){
	int minuto,hora,segundos,ext;
	time_t tiempoahora;
    time(&tiempoahora);
    struct tm *mitiempo = localtime(&tiempoahora);
	hora = mitiempo->tm_hour;
    minuto = mitiempo->tm_min;
    segundos = mitiempo->tm_sec;
    
    printf("ALARMA POSPUESTA %i MINUTOS\n",datos.extension);
    printf("%d:%d:%d",hora,minuto,segundos);
	Sleep(1000);
    datos.minutos=datos.minutos+(datos.extension);
		
    if(datos.minutos>=60){
        datos.hora= datos.hora+1;
        ext=datos.minutos-60;
      	datos.minutos=ext;
    }
    system("cls");
	
    return (hora<datos.hora || minuto!=datos.minutos)? pospuesta : disparar;
}

//ESTADO DE ALARMA
estados_t alarma(datos_t datos){
	int elec;
	est_t est;
	estados_t estados = disparar;
	printf("ALARMA\n(1)POSPONER|(2)DESACTIVAR\n");
	printf("\a");
	scanf("%i",&elec);
	
	if(elec==1){
		 estados = pospuesta;
	}
	if(elec==2){
		 est = desactivada;
		 printf("ALARMA DESACTIVADA\n");
		 estados = silenciada;
	}
	return estados;
}