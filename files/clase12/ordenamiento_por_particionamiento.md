# Paralelizar Ordenamiento

## Ordenamiento por particion

Existen varios algoritmos y variantes que se basan en la técnica de **particionamiento** (dividir el conjunto de datos en subconjuntos alrededor de un elemento pivote o criterio).

Aquí te muestro los más destacados:

### 1. Introsort (Ordenamiento Introspectivo)

* **¿Qué es?** Es un algoritmo híbrido creado por David Musser en 1997. Comienza operando como **Quicksort**, pero monitorea la profundidad de la recursión.
* **¿Por qué usa particionamiento?** Hereda la fase de partición de Quicksort, pero si la profundidad supera un límite predeterminado (lo que evitaría su peor caso de $O(n^2)$), cambia automáticamente a **Heapsort** para garantizar un rendimiento óptimo de $O(n \log n)$. Además, suele usar **Insertion Sort** para arreglos pequeños. Es el algoritmo estándar en muchas librerías de C++ (`std::sort`).

### 2. Quicksort de Doble Pivote (Dual-Pivot Quicksort)

* **¿Qué es?** Una evolución del Quicksort clásico desarrollada por Yaroslav Andreyanov en 2009.
* **¿Por qué usa particionamiento?** En lugar de elegir un solo pivote, elige **dos pivotes** que dividen el arreglo en **tres partes** (elementos menores que el primer pivote, elementos entre ambos pivotes, y elementos mayores que el segundo pivote). Esto reduce drásticamente el número de comparaciones y saltos de memoria, siendo el algoritmo estándar en Java (`Arrays.sort()` para tipos primitivos).

### 3. Quicksort de Tres Vías (Three-Way Partitioning / Algoritmo de la Bandera Holandiza)

* **¿Qué es?** Una variante diseñada específicamente para lidiar eficientemente con arreglos que contienen **muchos elementos duplicados**.
* **¿Por qué usa particionamiento?** Particiona el arreglo en tres secciones: los menores que el pivote, los **iguales** al pivote, y los mayores. Al aislar los elementos duplicados para que no necesiten ser reordenados, mejora drásticamente el rendimiento en conjuntos de datos con baja variedad de valores (donde el Quicksort tradicional sufre de redundancia).

### 4. Flashsort

* **¿Qué es?** Un algoritmo de ordenamiento por distribución propuesto por Karl-Dietrich Neubert.
* **¿Por qué usa particionamiento?** Clasifica y **particiona** los elementos directamente en clases o cubetas (buckets) según su valor esperado. Una vez distribuidos en estas clases, el algoritmo aplica ordenamiento por inserción de manera local, logrando un ordenamiento muy rápido en distribuciones de datos uniformes.

---

## Particionamiento en búsquedas

El concepto de **particionamiento** (dividir un todo en partes más pequeñas bajo un criterio lógico o espacial) no solo se aplica a los algoritmos de ordenamiento. Tiene dos vertientes principales: **cómo particionar dentro de los algoritmos de ordenamiento** y **cómo particionar estructuras para la búsqueda**.

### Part 1: Métodos de Particionamiento en Algoritmos de Ordenamiento

Cuando implementas algoritmos como Quicksort, la forma en que divides los elementos (la estrategia del pivote y los punteros) cambia drásticamente la eficiencia. Los dos esquemas clásicos son:

* **Esquema de particionamiento de Lomuto:**
* *Cómo funciona:* Utiliza un puntero que recorre el arreglo y otro que marca la frontera de los elementos menores que el pivote. Si encuentra un elemento menor, incrementa la frontera y hace un intercambio (*swap*).
* *Ventaja:* Es muy fácil de entender y programar (es el que se suele enseñar en los libros de texto).
* *Desventaja:* Hace muchos más intercambios innecesarios si hay muchos elementos iguales o desordenados en comparación con Hoare.

* **Esquema de particionamiento de Hoare:**
* *Cómo funciona:* Utiliza **dos punteros que empiezan en los extremos opuestos** del arreglo y avanzan hacia el centro. Se detienen cuando encuentran elementos que deberían estar en el otro lado y los intercambian.
* *Ventaja:* Es mucho más eficiente que Lomuto porque realiza en promedio tres veces menos intercambios. (Es el esquema original que Tony Hoare propuso en 1960).

### Part 2: Métodos de Particionamiento para Búsqueda (Estructuras de Datos y Espacio)

En el ámbito de la búsqueda, el particionamiento se utiliza para no tener que recorrer toda la información linealmente ($O(n)$), sino recortar drásticamente el espacio de búsqueda.

Aquí destacan varios métodos según el tipo de datos:

#### 1. Particionamiento Espacial (Para buscar coordenadas, mapas, gráficos y videojuegos)

* **Árboles K-D (K-Dimensional Trees):**
* *Qué hacen:* Particionan un espacio de $k$ dimensiones alternando los ejes (ej. en 2D, divide primero por la coordenada X, luego los hijos por la Y, luego otra vez X).
* *Para qué sirve:* Búsqueda rápida de vecinos más cercanos (*k-NN search*) y consultas de rangos geográficos.

* **Quadtrees (Árboles Cuaternarios) y Octrees:**
* *Qué hacen:* Dividen recursivamente un espacio bidimensional (Quadtree en 4 cuadrantes) o tridimensional (Octree en 8 octantes) cuando hay acumulación de puntos u objetos.
* *Para qué sirve:* Motores de videojuegos para detección de colisiones y sistemas de información geográfica (SIG).

* **R-Trees:**
* *Qué hacen:* Agrupan objetos espaciales cercanos mediante rectángulos contenedores delimitados (*bounding boxes*).
* *Para qué sirve:* Índices espaciales en bases de datos geográficas (como PostGIS).

#### 2. Particionamiento de Índices y Bases de Datos (Para buscar registros masivos)

* **Árboles B y B+ (B-Trees):**
* *Qué hacen:* Particionan grandes volúmenes de datos en bloques ordenados en forma de árbol balanceado en disco. Cada nodo contiene múltiples claves e hijos.
* *Para qué sirve:* Es la estructura estándar detrás de casi todas las **bases de datos relacionales** (MySQL, PostgreSQL) para hacer búsquedas puntuales y por rangos de forma ultra rápida ($O(\log n)$).

* **Particionamiento Hash (Hash Partitioning):**
* *Qué hacen:* Aplican una función matemática (hash) a una clave para determinar exactamente en qué partición o "cubeta" se almacena el dato.
* *Para qué sirven:* Tablas hash en memoria ($O(1)$) y bases de datos distribuidas (como Cassandra o Hadoop) para repartir la carga de búsqueda en múltiples servidores.

## Metodos de Particionamiento

En programación y algoritmos, el **particionamiento** es una técnica fundamental utilizada principalmente en algoritmos de ordenamiento Divide y Vencerás (como **Quicksort**) y de selección. Consiste en elegir un elemento de referencia llamado **pivote** y reorganizar el arreglo de modo que los elementos menores (o iguales) queden a un lado y los mayores al otro.

Los principales métodos de particionamiento que existen son:

### 1. Esquema de partición de Lomuto (Lomuto Partition Scheme)

Es el método más sencillo y fácil de implementar, popularizado por Edsger Dijkstra y utilizado frecuentemente en libros de texto.

* **Cómo funciona:** Por lo general, selecciona el **último elemento** del arreglo como pivote. Utiliza un puntero que recorre el arreglo de izquierda a derecha para mantener la frontera de los elementos menores que el pivote. Cada vez que encuentra un elemento menor o igual al pivote, lo intercambia y avanza la frontera.
* **Ventajas:** Código muy compacto, intuitivo y fácil de escribir sin errores lógicos.
* **Desventajas:** Realiza muchos más intercambios (*swaps*) en comparación con otros métodos y su rendimiento decae significativamente si hay muchos elementos duplicados.

### 2. Esquema de partición de Hoare (Hoare Partition Scheme)

Es el método original diseñado por C.A.R. Hoare cuando inventó el algoritmo Quicksort en 1959.

* **Cómo funciona:** Utiliza **dos punteros** que comienzan en los extremos opuestos del arreglo (`izquierda` y `derecha`) y se mueven hacia el centro. El puntero izquierdo busca elementos mayores o iguales al pivote, y el derecho busca elementos menores o iguales. Cuando ambos se detienen, se intercambian sus valores hasta que los punteros se cruzan.
* **Ventajas:** Es **más eficiente que Lomuto**, ya que realiza hasta tres veces menos intercambios en promedio.
* **Desventajas:** Es ligeramente más complejo de implementar de forma correcta (es fácil cometer errores con los límites del arreglo) y no garantiza que el pivote quede en su posición final exacta al terminar la partición (solo garantiza que las dos mitades están separadas).

### 3. Partición de tres vías (Three-Way Partitioning / Algoritmo de la Bandera Neerlandesa)

Diseñado por Jon Bentley y M. Douglas McIlroy, y basado en el problema clásico de la bandera neerlandesa de Edsger Dijkstra.

* **Cómo funciona:** En lugar de dividir el arreglo en dos partes, lo divide en **tres secciones**:
1. Elementos **menores** que el pivote.
2. Elementos **iguales** al pivote.
3. Elementos **mayores** que el pivote.

* **Ventajas:** Es **extremadamente eficiente cuando hay muchos elementos duplicados** en el arreglo (un escenario donde Quicksort tradicional con Lomuto o Hoare sufre una degradación de rendimiento a $O(N^2)$). Hoy en día es el estándar de la industria para implementaciones robustas de Quicksort.

### 4. Partición de doble pivote (Dual-Pivot Partitioning)

Una evolución moderna del particionamiento que utiliza más de un punto de referencia.

* **Cómo funciona:** Selecciona **dos pivotes** (por ejemplo, el primer y el último elemento) que dividen el espacio en tres partes: menores que el primer pivote, entre ambos pivotes, y mayores que el segundo pivote.
* **Ventajas:** Reduce la profundidad de la recursión y aprovecha mejor las jerarquías de caché modernas. Es el algoritmo de ordenamiento utilizado por defecto en **Java (`Arrays.sort`)** para tipos de datos primitivos desde la versión 7.

### Resumen Comparativo

| Método | Pivotes | Particiones | Ventaja Principal | Desventaja Principal |
| --- | --- | --- | --- | --- |
| **Lomuto** | 1 (último) | 2 | Sencillo de implementar | Muchos intercambios innecesarios |
| **Hoare** | 1 (primero/medio) | 2 | Menor cantidad de intercambios | Lógica de punteros compleja |
| **Tres Vías** | 1 | 3 | Excelente con elementos duplicados | Sobrecarga menor en arreglos sin duplicados |
| **Doble Pivote** | 2 | 3 | Muy rápido en la práctica (usado en Java) | Complejidad de implementación alta |
