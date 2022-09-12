# Fork and virtual memory

[About pointers after fork()](https://stackoverflow.com/questions/26534613/about-pointers-after-fork)

Lo mas importante en este sentido es que lo que nosotros en un programa en C vemos un virtual address. Solo el Kernel sabe que virtual address corresponde a un physical address.

Los programas que corremos nosotros están en "user mode" y no pueden acceder a la información de la MMU que corre en modo Kernel.

[How the memory is mapped when fork is used?](https://stackoverflow.com/questions/9724473/how-the-memory-is-mapped-when-fork-is-used)

Es importante remarcar que lo que usa el sistema operativo es una funcionalidad de los procesadores 386 y superiores que permite manejar tablas de páginas lo que hace que cualquier address de memoria sea relativo a la página del proceso y no a la memoria física.

[Page table](https://en.wikipedia.org/wiki/Page_table)

El proc filesystem tiene información adicional sobre los mapas de memoria que maneja el procesador, pero yo no logré decodificarlos y conseguir la dirección de memoria física:

´´´
/proc/<pid>/mem
/proc/<pid>/maps
/proc/<pid>/pagemap
´´´

Hay información adicional en:

- [Hack The Virtual Memory: C strings & /proc](https://blog.holbertonschool.com/hack-the-virtual-memory-c-strings-proc/)
- [Capturing Process Memory Usage Under Linux](https://www.eqware.net/articles/CapturingProcessMemoryUsageUnderLinux/index.html)
