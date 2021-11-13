# Ejercicio 11.1 Guia TPS 2013

* Escriba un programa que lea el archivo de texto que recibe por socket (establece conexion cliente-servidor) y determine:
    * El cliente cuando establece la  conexion le envia al servidor un "hola"
    * El servidor le devuelve el nonmbre del archivo a leer

    * El cliente se encarga del resto del ejercicio.
    * Cantidad total de palabras
    * Cantidad de veces que aparece la palabra “diodo”

gcc -o servidor sock-lib.c server.c 
gcc -o cliente sock-lib.c client.c 