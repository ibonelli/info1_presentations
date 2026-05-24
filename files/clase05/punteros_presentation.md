---
marp: true
theme: default
paginate: true
---

# Punteros en C  
## Entendiendo desde memoria (no desde sintaxis)

---

# Memoria simplificada

```
Dirección     Valor
0x1000        25
0x1004        10
0x1008        ?
```

* La memoria es una tabla de celdas
* Cada celda tiene:
  * una dirección
  * un valor

---

# Variables en C

```c
int a = 25;
```

Mentalmente:

```
a → 0x1000
contenido(0x1000) = 25
```

👉 "a" es solo un nombre (alias)

---

# Separación clave

Siempre pensar en 3 cosas:

* Nombre → `a`
* Dirección → `0x1000`
* Valor → `25`

👉 Si no separan esto, fallan con punteros

---

# Introducción a punteros

```c
int *p;
```

NO es:

> "puntero a int"

Es:

> "variable que guarda una dirección donde hay un int"

---

# Visualización

```
p → 0x2000
```

Todavía NO apunta a nada útil

---

# Obtener una dirección

```c
p = &a;
```

Ahora:

```
a → 0x1000 → 25
p → 0x2000 → 0x1000
```

👉 p guarda una dirección, no un valor

---

# Operaciones fundamentales

| Expresión | Significado                           |
| --------- | ------------------------------------- |
| `&a`      | dirección de a                        |
| `*p`      | valor en la dirección almacenada en p |

---

# Desreferenciación

```c
*p
```

Proceso mental:

1. p → 0x1000
2. Ir a 0x1000
3. Leer valor → 25

👉 Resultado: 25

---

# Ejemplo básico

```c
int a = 25;
int *p = &a;

printf("%d", *p);
```

Salida:

```
25
```

---

# Escritura con punteros

```c
*p = 50;
```

Resultado:

```
a = 50
```

👉 Cambiaste memoria indirectamente

---

# Ejercicio mental obligatorio

```c
int a = 10;
int b = 20;
int *p;

p = &a;
*p = 15;
p = &b;
*p = 30;
```

---

# Aliasing (concepto clave)

```c
int a = 10;
int *p = &a;
int *q = &a;

*p = 50;
```

Pregunta:

👉 ¿qué vale `*q`?

---

# Visual

```
p ┐
   ├──> a (0x1000)
q ┘
```

👉 Respuesta: 50

## Insight importante

> Múltiples punteros pueden referirse al mismo lugar de memoria

---

# Punteros y funciones

```c
void cambiar(int *x) {
    *x = 100;
}
```

---

# Uso

```c
int a = 10;
cambiar(&a);
```

Resultado:

```
a = 100
```

---

# Qué pasó realmente

1. Se pasa la dirección de `a`
2. La función modifica el contenido de esa dirección

👉 Simulación de "pass by reference"

---

# Regla de oro

> Un puntero es solo una dirección.

> `*` significa: "ir a esa dirección"

---

# Conexión futura

Esto habilita:

* Arrays
* Strings
* Estructuras
* Memoria dinámica
* Listas enlazadas

---

# Modelo mental final

Cuando vean:

```c
*p = 20;
```

Deben pensar:

1. p tiene una dirección
2. Voy a esa dirección
3. Escribo 20

---

# Práctica recomendada

Herramienta:

👉 [Python Tutor (modo C)](https://pythontutor.com/visualize.html#mode=display)

Permite ver memoria y punteros visualmente
