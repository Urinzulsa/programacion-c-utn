#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///PROTORIPADO

///EJ1

int cargaArregloYDevuelveCantidad(int arr1[]);

///EJ2

void muestraArreglo(int arr1[], int validos);

///EJ3

int sumaArreglo(int arr1[], int validos);

///EJ4

void arregloApila(int arr1[], int validos, Pila*pila);

///EJ5

int cargarArregloFloat(float arr2[]);

float sumaArregloFloat(float arr2[], int validos);

///EJ6

int cargarArregloChar(char arreglo[]);

int buscarChar(char arreglo[], int validos, char elemento);

void mostrarArregloChar(char arreglo[], int validos);

///EJ7

int insertarCaracterEnArreglo(char arreglo[], int validos, char insertar);

///EJ8

char maximoChar(char arreglo[], int validos);

///EJ9

int esCapicua(char arreglo[], int validos);

///EJ10



int main()
{
    int opcion;
    char control;
    printf("---------------------------------\nBienvenido a TP3: Arreglos!\n---------------------------------\n\n");

    int arr1[10];
    float arr2[100];
    char arreglochar[50];
    char insertar;
    Pila pila;
    inicpila(&pila);


    do
    {
        printf("Ingrese el numero del ejercicio al que desea ingresar: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            int cantidad, suma, cantidadfloat, cantidadchar, flag, cantidadinsert;
            float sumafloat;
            char elemento;

        case 1:
            /*1. Hacer una función que reciba como parámetro un arreglo de números enteros y permita que
            el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de
            elementos cargados en el arreglo (o pueden utilizar como puntero válidos)*/

            cantidad = cargaArregloYDevuelveCantidad(arr1);
            printf("En el arreglo 1 hay %d elementos. \n", cantidad);
            break;

        case 2:
            /*2. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
            cargados en él y los muestre por pantalla*/

            muestraArreglo(arr1, cantidad);
            break;

        case 3:
            /*3. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
            cargados en él y calcule la suma de sus elementos.*/

            suma= sumaArreglo(arr1, cantidad);
            printf("La suma de los elementos del arreglo es: %d\n", suma);
            break;

        case 4:
            /*4. Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos)
            cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.*/

            arregloApila(arr1, cantidad, &pila);
            printf("Pila: ");
            mostrar(&pila);
            break;

        case 5:
            /*5. Realizar una función que sume los elementos de un arreglo de números reales (float) de
            dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este
            tipo de dato asociado al arreglo)*/

            cantidadfloat = cargarArregloFloat(arr2);
            sumafloat = sumaArregloFloat(arr2, cantidadfloat);
            printf("La suma de los elementos del arreglo de reales es: %.2f\n\n", sumafloat);
            break;

        case 6:
            /*6. Realizar una función que indique si un elemento dado se encuentra en un arreglo de
            caracteres.*/

            cantidadchar = cargarArregloChar(arreglochar);

            printf("Ingrese el elemento que desea buscar: ");
            fflush(stdin);
            scanf("%c", &elemento);

            flag = buscarChar(arreglochar, cantidadchar, elemento);
            if(flag == 1)
            {
                printf("El elemento se encuentra en la cadena de caracteres.\n\n");
            }
            else
            {
                printf("El elemento no se encontro en la cadena de caracteres.\n\n");
            }

            printf("El arreglo: ");
            mostrarArregloChar(arreglochar, cantidadchar);

            break;

        case 7:
            /*7. Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente,
            conservando el orden.*/

            cantidadchar=cargarArregloChar(arreglochar);
            mostrarArregloChar(arreglochar, cantidadchar);

            printf("Ingrese el caracter que desea insertar: ");
            fflush(stdin);
            scanf("%c", &insertar);

            cantidadinsert=insertarCaracterEnArreglo(arreglochar,cantidadchar,insertar);

            printf("Arreglo final: \n\n");

            mostrarArregloChar(arreglochar,cantidadinsert);

            break;

        case 8:
            /*8. Realizar una función que obtenga el máximo carácter de un arreglo dado.*/

            cantidadchar = cargarArregloChar(arreglochar);
            elemento=maximoChar(arreglochar,cantidadchar);
            printf("El arreglo:\n\n");
            mostrarArregloChar(arreglochar, cantidadchar);
            printf("\n\nEl maximo caracter del arreglo de caracteres es: %c", elemento);
            break;

        case 9:
            /*9. Realizar una función que determine si un arreglo es capicúa.*/

            cantidadchar = cargarArregloChar(arreglochar);
            flag=esCapicua(arreglochar, cantidadchar);
            if(flag==0)
            {
                printf("El arreglo es capicua.");
            }
            else
            {
                printf("El arreglo no es capicua.");
            }

            printf("El arreglo:\n\n");
            mostrarArregloChar(arreglochar,cantidadchar);
            break;

        }
        printf("\n\nDesea continuar? (s/n) ");
        fflush(stdin);
        scanf("%c", &control);
    } while (control != 'n');
}

///EJ1//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cargaArregloYDevuelveCantidad(int arr1[])
{
    char seguir;
    int elemento;
    int validos=0;
    printf("Desea cargar un elemento?(s/n)");
    fflush(stdin);
    scanf("%c", &seguir);
    do
    {
        printf("Ingrese el elemento: ");
        fflush(stdin);
        scanf("%d", &elemento);
        arr1[validos] = elemento;
        validos++;
        printf("Desea continuar cargando elementos? (s/n)");
        fflush(stdin);
        scanf("%c", &seguir);
    } while(seguir!='n');

    return validos;
}

///EJ2//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void muestraArreglo(int arr1[], int validos)
{
    printf("Arreglo: [ ");
    for(int i=0; i<validos; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("]\n\n");
}

///EJ3//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int sumaArreglo(int arr1[], int validos)
{
    int suma=0;
    for(int i=0; i<validos; i++)
    {
        suma = suma + arr1[i];
    }
    return suma;
}

///EJ4//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void arregloApila(int arr1[], int validos, Pila*pila)
{
    for(int i=0; i<validos; i++)
    {
        apilar(pila, arr1[i]);
    }
}

///EJ5//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cargarArregloFloat(float arr2[])
{
char seguir;
    float elemento;
    int validos=0;
    printf("Desea cargar un elemento?(s/n)");
    fflush(stdin);
    scanf("%c", &seguir);
    do
    {
        printf("Ingrese el elemento: ");
        fflush(stdin);
        scanf("%f", &elemento);
        arr2[validos] = elemento;
        validos++;
        printf("Desea continuar cargando elementos? (s/n)");
        fflush(stdin);
        scanf("%c", &seguir);
    } while(seguir!='n');

    return validos;
}

float sumaArregloFloat(float arr2[], int validos)
{
    float suma=0;
    for(int i=0; i<validos; i++)
    {
        suma=suma+arr2[i];
    }
    return suma;
}

///EJ6//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cargarArregloChar(char arreglo[])
{
    int posicion=0;
    char control;
    do
    {
        printf("Ingrese un caracter: ");
        fflush(stdin);
        scanf("%c", &arreglo[posicion]);
        posicion++;
        printf("Desea continuar cargando caracteres? (s/n): ");
        fflush(stdin);
        scanf("%c", &control);
    } while(control=='s');

    return posicion;
}

int buscarChar(char arreglo[], int validos, char elemento)
{
    int flag=0;
    int i=0;
    do
    {
        if(elemento == arreglo[i])
        {
            flag==1;
        }
        else
            i++;
    }while((flag == 0)&&(i<validos));
    return flag;
}

void mostrarArregloChar(char arreglo[], int validos)
{
    for(int i=0;i<validos;i++)
    {
        printf("|%c", arreglo[i]);
    }
}

///EJ7//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int insertarCaracterEnArreglo(char arreglo[], int validos, char insertar)
{
    char arregloaux[validos+1]; ///arreglo auxiliar.
    int flag=0;
    int i=0;

    while((flag==0)&&(i<validos))
    {
        if(insertar<arreglo[i])
        {
            arregloaux[i]=insertar;
            flag==1;
        }
        else
        {
            arregloaux[i]=arreglo[i];
            i++;
        }
    }
    if(flag==0)
    {
        arreglo[validos]=insertar;
    }
    else
    {
        while(i<validos+1)
        {
            arregloaux[i+1]=arreglo[i];
            i++;
        }
        while(i<validos+1)
        {
            arreglo[i]=arregloaux[i]; ///vuelvo a armar el arreglo original.
            i++;
        }
    }
    return validos+1;
}

///EJ8//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char maximoChar(char arreglo[], int validos)
{
    char max;
    int i=0;
    max=arreglo[i];
    for(i=1;i<validos;i++)
    {
        if(arreglo[i]>max)
        {
            max=arreglo[i];
        }
    }
    return max;
}

///EJ9//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int esCapicua(char arreglo[], int validos)
{
    int i=0;
    int j=validos-1;
    int flag=0;
    char aux[validos];

    for(int x=0;x<validos;x++)
    {
        aux[x]=arreglo[x];
    }

    while (flag==0 && i<validos)
    {
        if(arreglo[i]==aux[j])
        {
            i++;
            j--;
        }
        else
        {
            flag==1;
        }
    }
    return flag;
}
