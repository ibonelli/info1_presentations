# Protocolo de comunicación por sockets: TLV

En el contexto de protocolos de comunicación (ya sea sobre sockets TCP/UDP, protocolos de red como DHCP/LLDP, o formatos de serialización en C y otros lenguajes), **TLV** significa **Type-Length-Value** (Tipo-Longitud-Valor).

Es una estructura de formato de datos (o codificación de tramas) que permite empaquetar información de forma estructurada, flexible y extensible.

---

## ¿Cómo se compone?

Cada campo o mensaje enviado a través del socket se divide en tres partes consecutivas:

1. **Type (Tipo / Identificador):** Un código numérico (habitualmente de 1, 2 o 4 bytes) que indica qué clase de dato se está enviando (ej. `1` = ID de usuario, `2` = Nombre, `3` = Comando).
2. **Length (Longitud):** Un entero (habitualmente de 1, 2 o 4 bytes) que especifica el tamaño en bytes del campo *Value*.
3. **Value (Valor / Payload):** Los datos reales (texto, enteros, una imagen, u otra estructura TLV anidada) con la cantidad exacta de bytes indicados en el campo *Length*.

## Esquema visual de la trama

```text
+-------------------+---------------------+----------------------------------+
|   Type (1-4 B)    |    Length (1-4 B)   |         Value (L bytes)          |
+-------------------+---------------------+----------------------------------+
| Ej: 0x01 (Nombre) | Ej: 0x0006 (6 B)    | "Juan\0" o datos binarios        |
+-------------------+---------------------+----------------------------------+
```

## ¿Por qué se usa en sockets?

A nivel de sockets (especialmente TCP, que es un flujo continuo de bytes sin delimitadores de mensaje natural o *stream-oriented*):

1. **Resuelve el delimitado de mensajes en TCP:** TCP no garantiza que un `send()` se reciba en un único `recv()`. Al leer primero el *Type* y el *Length*, el receptor sabe exactamente cuántos bytes le faltan por leer del socket para completar el mensaje.
2. **Soporta campos de longitud variable:** Permite enviar cadenas de texto, buffers de archivos o estructuras cambiantes sin necesidad de desperdiciar ancho de banda fijando un tamaño máximo (padding).
3. **Extensibilidad y compatibilidad hacia atrás:** Si agregas nuevos tipos de datos en una versión futura del protocolo, un cliente o servidor viejo que no conozca ese *Type* puede leer el *Length*, saltarse (*skip*) los bytes correspondientes en el buffer del socket y seguir procesando los siguientes campos sin romperse.
4. **Anidamiento (TLV jerárquico):** Un *Value* puede contener a su vez una secuencia de sub-estructuras TLV.

---

## Ejemplo práctico en C

Imagina un protocolo personalizado donde enviamos los datos de un usuario:

```c
#include <stdint.h>

// Definición de Tipos (Type)
#define TLV_USER_ID    1  // Value: uint32_t (4 bytes)
#define TLV_USERNAME   2  // Value: string (variable)
#define TLV_AUTH_TOKEN 3  // Value: byte array (variable)

// Estructura de cabecera fija
typedef struct {
    uint16_t type;
    uint16_t length;
} __attribute__((packed)) tlv_header_t;

```

Si deseas enviar el nombre de usuario `"Ignacio"`:

* **Type:** `2` (`TLV_USERNAME`)
* **Length:** `7` (7 bytes para los caracteres)
* **Value:** `'I', 'g', 'n', 'a', 'c', 'i', 'o'`

Al recibirlo del socket:

1. Haces un `recv()` de 4 bytes para leer la cabecera (`tlv_header_t`).
2. Mapeas `type = 2` y `length = 7`.
3. Reservas un buffer de 7 bytes y ejecutas `recv()` hasta completar esos 7 bytes para obtener `"Ignacio"`.

