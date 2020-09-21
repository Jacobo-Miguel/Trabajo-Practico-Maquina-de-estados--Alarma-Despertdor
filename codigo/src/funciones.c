#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "lib.h"

//CONFIGURAR ALARMA
datos_t inicio(){
	datos_t datos; 
    dias_t dias1;
    datos.cdias=0;
	int i=0;
	int k,h;
	char eleccion,elec;
	//CREANDO EL ARCHIVO DE CONFIGURACION//
	FILE *alarmap;
	if((alarmap=fopen("alarmap.txt","wb"))==NULL){
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
		    while(datos.dias[i]!= domingo && datos.dias[i]!= lunes && datos.dias[i]!= martes && datos.dias[i]!= miercoles && datos.dias[i]!= jueves && datos.dias[i]!= viernes && datos.dias[i]!= sabado){
		    	printf("DIA INEXISTENTE!!\n");
		    	printf("|(0)DOMINGO/(1)LUNES/(2)MARTES/(3)MIERCOLES/(4)JUEVES/(5)VIERNES/(6)SABADO|\n");
           	    printf("SELECCIONE EL DIA NUEVAMENTE: ");
		        scanf("%d",&datos.dias[i]);
			}
			datos.cdias++;
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
	  
	  if(elec=='N' || elec=='n'){
	  	datos.extension=0;
	  }
      system("cls");
      fflush(stdin);
      fwrite(&datos,sizeof(datos),1,alarmap);
      fclose(alarmap);
   }
	  
	if((alarmap=fopen("alarmap.txt","rb"))==NULL){
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
	    	if(datos.dias[j]==domingo){
	    		printf("DOMINGO/");
			}
			if(datos.dias[j]==lunes){
				printf("LUNES/");
			}
			if(datos.dias[j]==martes){
				printf("MARTES/");
			}
			if(datos.dias[j]==miercoles){
				printf("MIERCOLES/");
			}
			if(datos.dias[j]==jueves){
				printf("JUEVES/");
			}
			if(datos.dias[j]==viernes){
				printf("VIERNES/");
			}
			if(datos.dias[j]==sabado){
				printf("SABADO/");
			}
		}
		printf("\n");
		if(elec=='S' || elec=='s'){
			printf("*REPETIR A LOS %i MINUTOS %i VECES\n",datos.extension,datos.rep);	
		}
		
	    system("pause");
        system("cls");
	    fclose(alarmap);
	   }
	   return datos;
}


//ESTADO DE SILENCIO
estados_t silencio(datos_t datos){
	int hora,minuto,segundos,dia,i,diaselec=0;
	time_t tiempoahora;
	dias_t dias;
    time(&tiempoahora);
    struct tm *mitiempo = localtime(&tiempoahora);
	hora = mitiempo->tm_hour;
    minuto = mitiempo->tm_min;
    segundos = mitiempo->tm_sec;
    dia = mitiempo->tm_wday;
		
		if(hora<10 && minuto<10 && segundos<10){
			if(dia == domingo){
    			printf("DOMINGO\n");
			}
			if(dia == lunes){
				printf("LUNES\n");
			}
			if(dia == martes){
    			printf("MARTES\n");
			}
			if(dia == miercoles){
    			printf("MIERCOLES\n");
			}
			if(dia == jueves){
    			printf("JUEVES\n");
			}
			
			if(dia == viernes){
    			printf("VIERNES\n");
			}
			if(dia == sabado){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("0%d:0%d:0%d",hora,minuto,segundos);
			system("cls");
		} 
		
		if(hora>=10 && minuto>=10 && segundos>=10){
			if(dia == domingo){
    			printf("DOMINGO\n");
			}
			if(dia == lunes){
				printf("LUNES\n");
			}
			if(dia == martes){
    			printf("MARTES\n");
			}
			if(dia == miercoles){
    			printf("MIERCOLES\n");
			}
			if(dia == jueves){
    			printf("JUEVES\n");
			}
			
			if(dia == viernes){
    			printf("VIERNES\n");
			}
			if(dia == sabado){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("%d:%d:%d",hora,minuto,segundos);
			system("cls");	
		} 
		
		if(hora<10 && minuto<10 && segundos>=10){
			if(dia == domingo){
    			printf("DOMINGO\n");
			}
			if(dia == lunes){
				printf("LUNES\n");
			}
			if(dia == martes){
    			printf("MARTES\n");
			}
			if(dia == miercoles){
    			printf("MIERCOLES\n");
			}
			if(dia == jueves){
    			printf("JUEVES\n");
			}
			
			if(dia == viernes){
    			printf("VIERNES\n");
			}
			if(dia == sabado){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("0%d:0%d:%d",hora,minuto,segundos);
			system("cls");
		} 
		
		if(hora<10 && segundos<10 && minuto>=10){
			if(dia == domingo){
    			printf("DOMINGO\n");
			}
			if(dia == lunes){
				printf("LUNES\n");
			}
			if(dia == martes){
    			printf("MARTES\n");
			}
			if(dia == miercoles){
    			printf("MIERCOLES\n");
			}
			if(dia == jueves){
    			printf("JUEVES\n");
			}
			
			if(dia == viernes){
    			printf("VIERNES\n");
			}
			if(dia == sabado){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("0%d:%d:0%d",hora,minuto,segundos);
			system("cls");
		}
		
		if(minuto<10 && segundos<10 && hora>=10){
			if(dia == domingo){
    			printf("DOMINGO\n");
			}
			if(dia == lunes){
				printf("LUNES\n");
			}
			if(dia == martes){
    			printf("MARTES\n");
			}
			if(dia == miercoles){
    			printf("MIERCOLES\n");
			}
			if(dia == jueves){
    			printf("JUEVES\n");
			}
			
			if(dia == viernes){
    			printf("VIERNES\n");
			}
			if(dia == sabado){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("%d:0%d:0%d",hora,minuto,segundos);
			system("cls");
		}
		
		if(hora<10 && minuto>=10 && segundos>=10){
			if(dia == domingo){
    			printf("DOMINGO\n");
			}
			if(dia == lunes){
				printf("LUNES\n");
			}
			if(dia == martes){
    			printf("MARTES\n");
			}
			if(dia == miercoles){
    			printf("MIERCOLES\n");
			}
			if(dia == jueves){
    			printf("JUEVES\n");
			}
			
			if(dia == viernes){
    			printf("VIERNES\n");
			}
			if(dia == sabado){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("0%d:%d:%d",hora,minuto,segundos);
			system("cls");
		}
		
		if(minuto<10 && hora>=10 && segundos>=10){
			if(dia == domingo){
    			printf("DOMINGO\n");
			}
			if(dia == lunes){
				printf("LUNES\n");
			}
			if(dia == martes){
    			printf("MARTES\n");
			}
			if(dia == miercoles){
    			printf("MIERCOLES\n");
			}
			if(dia == jueves){
    			printf("JUEVES\n");
			}
			
			if(dia == viernes){
    			printf("VIERNES\n");
			}
			if(dia == sabado){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("%d:0%d:%d",hora,minuto,segundos);
			system("cls");
		}
		
		if(segundos<10 && hora>=10 && minuto>=10){
			if(dia == domingo){
    			printf("DOMINGO\n");
			}
			if(dia == lunes){
				printf("LUNES\n");
			}
			if(dia == martes){
    			printf("MARTES\n");
			}
			if(dia == miercoles){
    			printf("MIERCOLES\n");
			}
			if(dia == jueves){
    			printf("JUEVES\n");
			}
			
			if(dia == viernes){
    			printf("VIERNES\n");
			}
			if(dia == sabado){
    			printf("SABADO\n");
			}
			printf("SILENCIO\n");
			printf("%d:%d:0%d",hora,minuto,segundos);
			system("cls");
		}	
		
		for(i=0;i<datos.cdias;i++){
			if(datos.dias[i]==dia){
				diaselec=1;
			}
			else{
				diaselec=0;
			}
		}

	return (hora<datos.hora || minuto!=datos.minutos || diaselec!=1)? silenciada : disparar;	
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
    
    printf("ALARMA POSPUESTA\n",datos.extension);
        if(hora<10 && minuto<10 && segundos<10){
			printf("0%d:0%d:0%d",hora,minuto,segundos);
		} 
		
		if(hora>=10 && minuto>=10 && segundos>=10){
			printf("%d:%d:%d",hora,minuto,segundos);
		} 
		
		if(hora<10 && minuto<10 && segundos>=10){
			printf("0%d:0%d:%d",hora,minuto,segundos);
		} 
		
		if(hora<10 && segundos<10 && minuto>=10){
			printf("0%d:%d:0%d",hora,minuto,segundos);
		}
		
		if(minuto<10 && segundos<10 && hora>=10){
			printf("%d:0%d:0%d",hora,minuto,segundos);
		}
		
		if(hora<10 && minuto>=10 && segundos>=10){
			printf("0%d:%d:%d",hora,minuto,segundos);
		}
		
		if(minuto<10 && hora>=10 && segundos>=10){
			printf("%d:0%d:%d",hora,minuto,segundos);
		}
		
		if(segundos<10 && hora>=10 && minuto>=10){
			printf("%d:%d:0%d",hora,minuto,segundos);
		}
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
	int elec=0;
	estados_t estados = disparar;
	if(datos.extension>0){
		printf("ALARMA\n(1)POSPONER|(2)DESACTIVAR\n");
    	printf("\a");
	    scanf("%i",&elec);
	
	    if(elec==1){
		    estados = pospuesta;
     	}
     	if(elec==2){
		    printf("ALARMA DESACTIVADA\n");
		    estados = silenciada;
    	}
		
	}
	if(datos.extension==0){
		printf("ALARMA\n(1)DESACTIVAR\n");
    	printf("\a");
	    scanf("%i",&elec);
	
     	if(elec==1){
		    printf("ALARMA DESACTIVADA\n");
		    estados = silenciada;
    	}
		
	}
	return estados;
}