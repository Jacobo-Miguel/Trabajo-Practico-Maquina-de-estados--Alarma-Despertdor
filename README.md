# Trabajo-Practico-Maquina-de-estados--Alarma-Despertador

# Memoria descriptiva
Mi sistema representa una alarma/despertador con hora, minutos, extensiones (por si el usuario decide posponer), y dias de repeticion que seran ingresados por el usuario.
La misma inicia luego de recibir el archivo de configuracion con los datos antes mencionados, esta permanecera en el primer estado de Silencio hasta que se llegue a la hora programada y si la misma esta desactivada, si se llega a la hora programada y esta activada ira al estado de Alarma y se quedara ahi hasta que no se posponga o desactive.
Si el usario elije posponer la alarma entonces entrara en el tercer estado de Posponer en el que se quedara hasta que se llegue a la hora pospuesta o no se la desactive, por otro lado si el usario elije la opcion de desactivar entonces, automaticamente, la misma retorna al estado de Silencio. 
# Diagrama
![imagenError](https://github.com/Jacobo-Miguel/Trabajo-Practico-Maquina-de-estados--Alarma-Despertdor/blob/master/imagen/Copia%20de%20Copia%20de%20Mi%20primer%20documento.png)

.Extension= tiempo que se pospone la alarma

.Hora= tiempo que transcurre en el momento

.Horaprog= tiempo programado por el usuario

.A= activada

.D= desactivada

