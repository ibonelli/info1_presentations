# Streams/Sockets y Threads

Usando la librería de sockets de la cátedra.

## Objetivos

- Manejar conexiones de red mediante las mismas funciones de lectura y escritura que utilizamos para acceder a archivos.
- Ocultar los detalles de implementación de un par de conexiones que requieren un coocimiento detallado de la interfaz de sockets de TCP IP. no es el objetivo de Info I describir esos conceptos, sino utilizar la interfaz de sockets como una aplicación mas de streams.
- Permitir manejar más de un cliente en el server mediante el uso de threads.

## Archivos

- server.c: Programa servidor que crea una interfaz para escuchar pedidos de conexión. Una vez que es contactado por un cliente remoto le envía un string. El server puede manejar varios clientes mediante threads.
- client.c: Programa cliente que conecta al servidor anterior y lee la string que aquel le envía. Luego finaliza.
- sock-lib.h: Archivo header de la librería que provee las funciones de conexión a los programas cliente y servidor.
- sock-lib-c: Archivo fuente de la libraría que provee las funciones de conexión a los programas cliente y servidor.

## Para compilar

- server: ```gcc -o srv server.c sock-lib.c -lpthread -Wall```
- client: ```gcc -o clt client.c sock-lib.c -lpthread -Wall```
