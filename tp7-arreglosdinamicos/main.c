#include <stdio.h>
#include <stdlib.h>

///PROTOTIPADO/////////////////////////////////////////////////////////////////////////////////

int contarPares(int dimA, int arreglo[dimA]);

void traspasaPares(int dimA, int arreglo[dimA], int pares[]);



///FUNCION MAIN////////////////////////////////////////////////////////////////////////////////

int main()
{
    printf("------------------------------------------------------------------\nBienvenido al TP8: Arreglos Dinamicos y Punteros Dobles!\n------------------------------------------------------------------\n\n");
    int dimA=10;
    int opcion, valor, *pint=&valor, **ppint=&pint, cantpares;
    int arreglo[10]={1,2,3,4,5,6,7,8,9,10};
    char control;
    do
    {
        printf("Ingrese el numero del ejercicio al que desea ingresar: ");
        fflush(stdin);
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            /*1. Se desea construir un programa que ilustre la situación que se tiene al emplear punteros y dobles punteros.
            Para ello, declare un puntero de int y un puntero de puntero del anterior, en la forma:
            int valor;
            int * pint = &valor;
            int ** ppint = &pint;
            Se pide construir un programa que muestre las direcciones de valor, pint y ppint, y que asigne distintos valores a la
            variable valor empleando pint y ppint. */

            printf("Direccion de valor: %p\n", &valor);
            printf("Direccion de pint: %p\n", &pint);
            printf("Direccion de ppint: %p\n\n", &ppint);

            *pint=10;
            printf("Valor: %d\n", valor);

            **ppint=20;
            printf("Valor: %d\n", valor);
            break;

        case 2:
            /*2.Se cuenta con un arreglo de números enteros que ya fue cargado.
            a)	Se pide hacer una función que copie los datos de todos los valores
            del arreglo mencionado que sean pares en otro arreglo del tamaño justo.
            A tal fin, desarrolle una función que cuente la cantidad de elementos
            pares y otra función que se encargue del traspaso de los datos pares.
            El ejercicio deberá ser realizado usando en la función dos parámetros
            de tipo arreglo (uno para el arreglo original de enteros y otro para el
            arreglo de pares) y creando el arreglo dinámico utilizando malloc en el
            Main antes de la invocación de la función de traspaso.

            b)	Ahora deberá realizarse lo mismo del ejercicio anterior pero creando
            el arreglo dinámico utilizando malloc dentro de la función y retornando el arreglo

            c)	Ahora deberá realizarse lo mismo del ejercicio anterior pero usando malloc
            dentro de la función, y en lugar de retornar el arreglo, trabajar con puntero doble*/

            cantpares=contarPares(dimA, arreglo);
            printf("Hay %d numeros pares en el arreglo.\n", cantpares);
            int *pares = (int*) malloc(cantpares*sizeof(int));
            traspasaPares(dimA,arreglo,pares);
            printf("Arreglo de números pares: ");
            for (int i = 0; i < cantpares; i++)
            {
                printf("%d ", pares[i]);
            }
            break;
        }
        printf("\n\nDesea continuar? (s/n) ");
        fflush(stdin);
        scanf("%c", &control);
    } while (control != 'n');
}

///FUNCIONES PROPIAS///////////////////////////////////////////////////////////////////////////

int contarPares(int dimA, int arreglo[dimA])
{
    int pares=0;
    for(int i=0;i<dimA;i++)
    {
        if(arreglo[i]%2==0)
        {
            pares++;
        }
    }
    return pares;
}

void traspasaPares(int dimA, int arreglo[dimA], int pares[])
{
    int cantpares=0;
    for(int i=0;i<dimA;i++)
    {
        if(arreglo[i]%2==0)
        {
            pares[cantpares]=arreglo[i];
            cantpares++;
        }
    }
}
