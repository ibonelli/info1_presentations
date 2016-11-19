#include <cstdlib>
#include <iostream>
#include "Punto.h"

using namespace std;

int main(int argc, char *argv[])
//int main ()
{
    //class Punto;
    Punto a(1,1);
    Punto b(2,2);
    Punto c(0,0);
    float d;
    char e;
    cout << "Bienvenido" << endl;
    cin >> d;
    Punto f(0,0);
    f = a + c ;
    cout << "El punto a es: "<< endl; a.print();
    cout << "El punto b es: "; b.print(); 
    cout << "suma de a + c es: "; f.print();
    cout << "suma de a + b es: "; (a + b).print();
    cout << "resta de a - b es: "; (a - b).print();
    cout << "El punto a por un escalar es: "; (a * d).print();
    a=b;
    cout << "El punto a ahora es: "; a.print();
    cout << "Presione una tecla para finalizar..." << endl;
    
    // d= cin.get();
    system("PAUSE");
    return EXIT_SUCCESS;
}
