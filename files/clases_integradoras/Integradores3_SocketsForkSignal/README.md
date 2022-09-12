# Ejercicio didáctico que usa la librería de la cátedra, pero no hace wait().

* Puede atender varios clientes al mismo tiempo
* El cliente cuando establece la conexion le envia al servidor un "hola"
* El servidor le devuelve una confirmación de recibir el "hola"

gcc -o servidor sock-lib.c server.c 
gcc -o cliente sock-lib.c client.c 
