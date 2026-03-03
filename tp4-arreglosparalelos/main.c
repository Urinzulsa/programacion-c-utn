#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///PROTOTIPADO///////////////////////////////////////////////////////////////////


///EJ1

int cargaAlumnos(int dimF, int dimC, int legajos[], int anios[], char nombres[dimF][dimC]);

///EJ2

int buscaLegajos(int validos, int legajos[validos], int legajo);

///EJ3

void buscaDevuelveNombre(int validos, int dimC, int legajos[], char nombres[validos][dimC], int anios[], int posicion);

///EJ4

int posicion_menor(int validos, int dimC, int nombres[validos][dimC], int anios[], int legajos[], int pos);
void ordenaPorNombre(int validos, int dimC, int nombres[validos][dimC], int anios[], int legajos[]);
void muestraAlumno(int validos, int dimC, char nombres[validos][dimC], int legajos[], int anios[]);
void intercambiarPalabras(int dimC,char palabra1[dimC], char palabra2[dimC]);
void intercambiarEnterosDeArreglos(int dimC,int arreglo[dimC],int pos1, int pos2);

///FUNCION MAIN//////////////////////////////////////////////////////////////////

int main()
{
    printf("-------------------------------------------\nBienvenido al TP5: Arreglos Paralelos!\n-------------------------------------------\n\n");

    int opcion, validos, buscar, posicion;
    char control;
    int legajos[20];
    char nombres[20][30];
    int anios[20];
    do
    {
        printf("Ingrese el numero del ejercicio al que desea ingresar: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            /*1. Crear una función que los cargue, hasta que el usuario lo decida. */

            validos=cargaAlumnos(20,30,legajos,anios,nombres);
            break;

        case 2:
            /*2. Crear una función que busque dentro del arreglo de legajos y retorne la posición de un determinado valor.*/

            validos=cargaAlumnos(20,30,legajos,anios,nombres);
            printf("Ingrese el legajo que desea buscar: ");
            fflush(stdin);
            scanf("%d", &buscar);
            posicion=buscaLegajos(validos,legajos,buscar);
            if(posicion==-1)
                printf("El legajo ingresado no existe. :(");
            else
                printf("El legajo fue encontrado! :)");
            break;

        case 3:
            /*3. Hacer una función que reciba como parámetro todos los arreglos
            y encuentre el nombre correspondiente a un determinado legajo y lo imprima por pantalla.
            Se debe invocar la función 2.*/

            validos=cargaAlumnos(20,30,legajos,anios,nombres);
            printf("Ingrese el legajo que desea buscar: ");
            fflush(stdin);
            scanf("%d", &buscar);
            posicion=buscaLegajos(validos,legajos,buscar);
            if(posicion==-1)
                printf("El legajo ingresado no existe. :(");
            else
            {
                buscaDevuelveNombre(validos, 30, legajos, nombres, anios, posicion);
            }
            break;

        case 4:
            /*Hacer una función que reciba como parámetro todos los arreglos
             y los ordene por nombre. (por el método de selección o inserción).*/

            validos=cargaAlumnos(20,30, legajos, anios, nombres);
            printf("Arreglo ordenado.\n\n");
            ordenaPorNombre(validos, 30, nombres, anios, legajos); ///no anda.
            muestraAlumno(validos, 30, nombres, legajos, anios);
            break;
        }
        printf("\n\nDesea continuar? (s/n) ");
        fflush(stdin);
        scanf("%c", &control);
    } while (control != 'n');
}

///FUNCIONES PROPIAS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///EJERCICIO 1/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cargaAlumnos(int dimF, int dimC, int legajos[], int anios[], char nombres[dimF][dimC])
{
    int validos=0;
    char control='s';
    while(control=='s' && validos<dimF)
    {
        printf("Ingrese el nombre del alumno: ");
        fflush(stdin);
        gets(nombres[validos]);

        printf("Ingrese el anio al que pertenece: ");
        fflush(stdin);
        scanf("%d", &anios[validos]);

        printf("Ingrese el legajo del alumno: ");
        fflush(stdin);
        scanf("%d", &legajos[validos]);

        printf("Desea continuar cargando alumnos al sistema? (s/n): ");
        fflush(stdin);
        scanf("%c", &control);
        validos++;
    }
    return validos;
}

///EJERCICIO 2/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buscaLegajos(int validos, int legajos[], int legajo)
{
    int i=0, flag=0, posicion=0;
    while(i<validos && flag==0)
    {
        if(legajos[i]==legajo)
        {
            flag=1;
            posicion++;
        }
        else
        {
            i++;
            posicion++;
        }
    }
    if(flag==0)
    {
        return -1;
    }
    else
        return posicion;
}

///EJERCICIO 3/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void buscaDevuelveNombre(int validos, int dimC, int legajos[], char nombres[validos][dimC], int anios[], int posicion)
{
    printf("El legajo corresponde al alumno: ");
    puts(nombres[posicion-1]);
}

///EJERCICIO 4/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ordenaPorNombre(int validos, int dimC, int nombres[validos][dimC], int anios[], int legajos[])
{
    int i=0;
    int pos;
    char palabramenor[dimC];

    while(i<validos-1)
    {
        pos=posicion_menor(validos, 30, nombres, anios, legajos, i);
        ///Intercambiar palabras
        intercambiarPalabras(dimC, nombres[i], nombres[pos]);
        ///Intercambiar legajos
        intercambiarEnterosDeArreglos(dimC,legajos,i,pos);
        ///Intercambiar anios
        intercambiarEnterosDeArreglos(dimC,anios,i,pos);

        i++;
    }
}

int posicion_menor(int validos, int dimC, int nombres[validos][dimC], int anios[], int legajos[], int pos)
{
    int i=pos+1;
    int posmenor;
    char palabramenor[dimC];
    strcpy(palabramenor, nombres[pos]);

    while(i<validos)
    {
        if(strcmpi(palabramenor, nombres[i])>0)
        {
            strcpy(palabramenor, nombres[i]);
            posmenor=i;
            i++;
        }
        i++;
    }
    return posmenor;
}

void intercambiarPalabras(int dimC,char palabra1[dimC], char palabra2[dimC])
{
    char aux[dimC];
    strcpy(aux,palabra1);
    strcpy(palabra1,palabra2);
    strcpy(palabra2,aux);
}

void intercambiarEnterosDeArreglos(int dimC,int arreglo[dimC],int pos1, int pos2)
{
    int aux;
    aux=arreglo[pos1];
    arreglo[pos1]=arreglo[pos2];
    arreglo[pos2]=aux;
}

void muestraAlumno(int validos, int dimC, char nombres[validos][dimC], int legajos[], int anios[])
{
    for(int i=0;i<validos;i++)
    {
        printf("Alumno %d:", i+1);
        printf("\nLegajo: %d", legajos[i]);
        printf("\nAnio: %d", anios[i]);
        printf("\nNombre: ");
        puts(nombres[i]);
        printf("\n");
    }
}

