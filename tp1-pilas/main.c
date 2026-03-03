#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
Pila cargarPila(Pila pilaA);
void pasarPilas (Pila *pilaA, Pila *pilaB);
void pasarPilasEnOrden(Pila *pilaA, Pila *pilaB);
int encontrarElMenor (Pila *pilaA);
void ordenarSeleccion(Pila *origen, Pila *destino);
void insertarNumeroOrdenado(Pila *pilaA, int valor);
Pila pilaOrdenamientoPorInsercion(Pila *pilaA);
int sumaPila(Pila pilaA);
void sumaTotalPila(Pila pilaA, int *totalPila);
void contadorPila(Pila pilaA,int *cantidadElementos);
int division (int a, int b);
void promedioPila(Pila pilaA, int *promedio);
int main()
{
    int opcionSwitch;


    Pila pilaA, pilaB, pilaC, pilaD;
    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&pilaC);
    inicpila(&pilaD);
    int menorElemento, valor, suma, promedio;
    do {
        printf("-------menu-------- \n");
        printf("opcion 1: cargar pila\n");
        printf("opcion 2: pasar de pila A a pila B\n");
        printf("opcion 3: pasar de pila A a pila B en orden\n");
        printf("opcion 4: encontrar el menor elemento y eliminarlo de la pila\n");
        printf("opcion 5: ordenar pila (ordenamiento por seleccion)\n");
        printf("opcion 6: ingresar un numero en una pila ordenada");
        printf("opcion 7: ordenar pila (ordenamiento por inserccion)");
        printf("opcion 0: salir\n");
        scanf("%d", &opcionSwitch);

       ///1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.
        switch (opcionSwitch) {

        case 1:
            pilaA = cargarPila(pilaA);
            break;

        case 2:
            pasarPilas (&pilaA, &pilaB);
            break;

        case 3:
            pasarPilasEnOrden (&pilaA, &pilaB);
            break;

        case 4:
            menorElemento = encontrarElMenor(&pilaA);
            printf("menor elemento es: %d \n", menorElemento);
            break;

        case 5:
            inicpila(&pilaC);
            ordenarSeleccion(&pilaA, &pilaC);
            printf("Pila ordenada:\n");
            mostrar(&pilaC);
            break;

        case 6:
            printf("ingrese el valor que desea agregar en la pila\n");
            scanf("%d", &valor);
            insertarNumeroOrdenado(&pilaA, valor);

        case 7:
            pilaD = pilaOrdenamientoPorInsercion(&pilaA);

        case 8:
            suma = sumaPila(pilaA);
            printf("la suma de la pila es: \n", suma);

        case 9:
           promedioPila(pilaA, &promedio);

    }}while (opcionSwitch != 0);

    return 0;
}

Pila cargarPila (Pila pilaA){
    char opcion;
    int valor;
    do {
        printf("ingrese el valor que desea cargar en la pila\n");
        scanf("%d", &valor);
        apilar (&pilaA, valor);
        printf("desea seguir cargando datos? s/n \n");
        fflush(stdin);
        scanf(" %c", &opcion);
    } while (opcion == 's');
    mostrar(&pilaA);
    return pilaA;
}

void pasarPilas (Pila *pilaA, Pila *pilaB){
    while (!pilavacia(pilaA))
    {
        apilar(pilaB, desapilar(pilaA));
    }

    printf("mostrando la pila A: \n");
    mostrar(pilaA);

    printf("mostrando la pila B: \n");
    mostrar(pilaB);
}

void pasarPilasEnOrden(Pila *pilaA, Pila *pilaB){
Pila pilaAux;
inicpila(&pilaAux);

while (!pilavacia(pilaA)) {
    apilar(&pilaAux, desapilar(pilaA));
}
while (!pilavacia(&pilaAux)) {
    apilar(pilaB, desapilar(&pilaAux));
}

 printf("mostrando la pila A: \n");
    mostrar(pilaA);

    printf("mostrando la pila B: \n");
    mostrar(pilaB);
}

int encontrarElMenor (Pila *pilaA) {
    Pila aux;
    inicpila(&aux);
    int menorElemento, valor;
    valor = desapilar(pilaA);
    menorElemento = valor;
    apilar(&aux, valor);

    while (!pilavacia(pilaA)) {
            valor = desapilar(pilaA);
            if (valor < menorElemento) {
                menorElemento = valor;
            }
            apilar(&aux, valor);
    }

    while (!pilavacia(&aux)){
        valor = desapilar(&aux);
        if (valor != menorElemento) {
            apilar(pilaA, valor);
        }
    }

    printf("Pila sin el elemento menor: \n ");
    mostrar(pilaA);

    return menorElemento;
}

void ordenarSeleccion(Pila *origen, Pila *destino)
{
    int menor;

    while (!pilavacia(origen)) {
        menor = encontrarElMenor(origen);
        apilar(destino, menor);
    }
}

void insertarNumeroOrdenado(Pila *pilaA, int valor){
Pila aux;
inicpila(&aux);


printf("pila sin el valor \n");
mostrar(pilaA);

while (!pilavacia(pilaA) && valor < tope(pilaA)){
    apilar(&aux, desapilar (pilaA));
}
apilar(pilaA, valor);
while (!pilavacia(&aux)){
    apilar(pilaA, desapilar(&aux));
}
  printf("Pila actualizada:\n");
    mostrar(pilaA);
}

 Pila pilaOrdenamientoPorInsercion(Pila *pilaA){
 Pila pilaAux;
 inicpila(&pilaAux);
 int valor;
 while (!pilavacia(pilaA)){
    valor = desapilar(pilaA);
    insertarNumeroOrdenado(&pilaAux, valor);
 }
 mostrar(&pilaAux);
 return pilaAux;
 }

 int sumaPila(Pila pilaA){
    int valor;
    int resultado=0;
    if (pilavacia(&pilaA)){
        printf("la pila se encuentra vacia");
        return -1;
        }
        valor = desapilar(&pilaA);
        if (!pilavacia(&pilaA)){
            resultado = tope(&pilaA) + valor;
            return resultado;
        } else {
        return valor;
        }
 }

 void sumaTotalPila(Pila pilaA, int *totalPila){
 while (!pilavacia(&pilaA)){
    *totalPila = *totalPila + desapilar(&pilaA);
 }
 }

 void contadorPila(Pila pilaA,int *cantidadElementos){
 while (!pilavacia(&pilaA)){
    (*cantidadElementos)++;
    desapilar(&pilaA);
 }
 }

 int division (int a, int b){
 if (b!= 0){
 int c = a/b;
 return c;
 }
 return -1;
 }

void promedioPila(Pila pilaA, int* promedio){
    int totalPila = 0;
    int cantidadElementos = 0;
    int valorTotal = 0;
    sumaTotalPila(pilaA, &totalPila);
    contadorPila(pilaA, &cantidadElementos);
    valorTotal = division(totalPila, cantidadElementos);
    *promedio = valorTotal;
}
