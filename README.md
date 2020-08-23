# Trabajo-Practico-Maquina-de-estados--Alarma-Despertador

# Memoria descriptiva
Mi sistema representa una alarma/despertador con hora, minutos, extensiones (por si el usuario decide posponer), y dias de repeticion que seran ingresados por el usuario.
La misma inicia luego de recibir el archivo de configuracion con los datos antes mencionados, esta permanecera en el primer estado de Silencio hasta que se llegue a la hora programada o si la misma esta desactivada, si se llega a la hora programada ira al estado de Alarma y se quedara ahi hasta que no se posponga o desactive a la misma.
Si el usario elije posponer la alarma entonces entrara en el tercer estado de Posponer en el que se quedara hasta que se llegue a la hora pospuesta o no se la desactive, por otro lado si el usario elije la opcion de desactivar entonces, automaticamente, la misma retorna al estado de Silencio. 
# Diagrama


