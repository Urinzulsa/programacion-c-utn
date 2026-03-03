#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define MAXLONG 30
typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
} stAlumno;

void cargarAlFinal(char nombreArchivo[]);
void mostrarArchivo(char nombreArchivo[]);
int contarElementos(char nombreArchivo[]);
void cargarArchivoAlumnos (char nombreArchivoAlumnos[]);
void mostrarAlumnos(char nombreArchivoAlumnos[]);
void mostrarAlumno(stAlumno aux);
stAlumno cargarAlumno();
void cargarMasAlumnos (char nombreArchivoAlumnos[]);
void pasarAPila(char nombreArchivoAlumnos[]);
void contarMayoresA(char nombreArchivoAlumnos[], int edad);
void mostarAlumnosEntreEdades (char nombreArchivoAlumnos[], int edadMin, int edadMax);
void mostrarMayor (char nombreArchivoAlumnos[]);
int mostrarAlumnosSegunAnio(char nombreArchivoAlumnos[], int anio);
void copiarArreglo(stAlumno alumnosArreglo[],char nombreArchivoAlumnos[], int cantidad);
void pasarArregloAnio (stAlumno alumnmosArreglo2[], char nombreArchivoAlumnos[], int cantidad);
int cantidadRegistrosArchivo(char nombreArchivoAlumnos[]);
void copiarArreglo(stAlumno alumnosArreglo2[],char nombreArchivoAlumnos2[], int cantidad2);
void buscarXNumeroEnArchivo(char nombreArchivoAlumnos2[], int cantidad3, int numElegido);


int main()
{
    char nombreArchivo[MAXLONG] = "archivoRandom.bin";
    char nombreArchivoAlumnos[MAXLONG] = "archivoAlumnos.bin";
    int opcion;
    int edad;
    int edadMin;
    int edadMax;
    int anio;
    int cantidadAlumnosAnio;
    int cantidad;
    int cantidadeRegistros = 0;
    int cantidad2=10;
    int cantidad3;
    char nombreArchivoAlumnos2[MAXLONG] = "archivoAlumnos2.bin";
    int numElegido = 0;
    stAlumno alumnosArreglo[10] =
    {
        {1001, "Juan Perez", 20, 1},
        {1002, "Maria Gomez", 22, 2},
        {1003, "Lucas Fernandez", 19, 1},
        {1004, "Sofia Martinez", 23, 3},
        {1005, "Tomas Rodriguez", 21, 2},
        {1200, "Bruno Lopez", 18, 1},
        {1201, "Camila Torres", 25, 5},
        {1202, "Franco Diaz", 20, 2},
        {1203, "Valentina Ruiz", 23, 3},
        {1204, "Mateo Castro", 19, 1}
    };

    stAlumno alumnosArreglo2[10];

    do
    {
        printf("menu de opciones\n");
        printf("\n opcion 1: agregar elemento al final.\n");
        printf("\n opcion 2: mostrar archivo x pantalla \n");
        printf("\n opcion 3: contar la cantidad de elementos que tiene un archivo\n");
        printf("\n opcion 4: cargar el archivo con alumnos\n");
        printf("\n opcion 5: mostrar alumnos x pantalla \n");
        printf("\n opcion 6: cargar archivo con mas alumnos \n");
        printf("\n opcion 7: pasar a pila los legajos de los mayores de edad \n");
        printf("\n opcion 8: contar cantidad de alumnos mayores a x edad \n");
        printf("\n opcion 9: mostrar nombres de los alumnos entre 'x' e 'y' edades \n");
        printf("\n opcion 10: mostrar el alumno de mayor edad \n");
        printf("\n opcion 11: mostrar alumnos segun anio \n");
        printf("\n opcion 12: copiar arreglo en archivo, y de archivo a arreglo, filtrando por anio \n");
        printf("\n opcion 13: contar la cantidad de elementos en el archivo\n");
        printf("\n opcion 14: buscar alumno por numero\n");
        scanf("%d", &opcion);

        switch (opcion)
        {

        case 1:
            cargarAlFinal(nombreArchivo);
            break;

        case 2:
            mostrarArchivo(nombreArchivo);
            break;

        case 3:
            int cantidad = contarElementos(nombreArchivo);
            printf("%d elementos en el archivo \n", cantidad);
            break;
        case 4:
            cargarArchivoAlumnos (nombreArchivoAlumnos);
            break;
        case 5:
            mostrarAlumnos(nombreArchivoAlumnos);
            break;
        case 6:
            cargarMasAlumnos(nombreArchivoAlumnos);
            break;
        case 7:
            pasarAPila(nombreArchivoAlumnos);
            break;
        case 8:
            printf("\n ingrese una edad para mostrar la cantidad de alumnos mayores a esa misma \n");
            scanf("%d", &edad);
            contarMayoresA(nombreArchivoAlumnos, edad);
            break;
        case 9:
            printf("\n ingrese una edad minima y una maxima para mostrar los alumnos entre esas mismas \n");
            printf("Edad minima: \n");
            scanf("%d", &edadMin);
            printf("Edad maxima: \n");
            scanf("%d", &edadMax);
            mostarAlumnosEntreEdades(nombreArchivoAlumnos, edadMin, edadMax);
            break;
        case 10:
            mostrarMayor(nombreArchivoAlumnos);
            break;

        case 11:
            printf("\n ingrese el anio que desea buscar\n");
            scanf("%d", &anio);
            cantidadAlumnosAnio = mostrarAlumnosSegunAnio(nombreArchivoAlumnos, anio);
            break;
        case 12:
            printf("\n Copiando arreglo en archivo alumnos\n");
            copiarArreglo(alumnosArreglo, nombreArchivoAlumnos, cantidad);
            pasarArregloAnio (alumnosArreglo2, nombreArchivoAlumnos, cantidad);
            break;
        case 13:
            printf("contando la cantidad de alumnos en el archivo... \n;");
            cantidadeRegistros = cantidadRegistrosArchivo(nombreArchivoAlumnos);
            printf("\n la cantidad de alumnos es de: %d\n", cantidadeRegistros);
            break;
        case 14:
            copiarArreglo(alumnosArreglo2, nombreArchivoAlumnos2, cantidad2);
            cantidad3 = cantidadRegistrosArchivo(nombreArchivoAlumnos2);
            do {
            printf("ingrese un numero entre 1 y %d\n", cantidad3);
            scanf("%d", &numElegido);
            if (numElegido >= cantidad3 || numElegido < 1){
                printf("\nnumero fuera de rango, intente de nuevo\n");
            }
            }while (numElegido >= cantidad3 || numElegido < 1);

            buscarXNumeroEnArchivo(nombreArchivoAlumnos2, cantidad3, numElegido);


        }


    }
    while (opcion != 0);


    return 0;
}
///1. Hacer una función que agregue un elemento al final de un archivo.

void cargarAlFinal(char nombreArchivo[])
{
    int elemento = 32;
    FILE* buffer = fopen(nombreArchivo, "ab");
    if (buffer)
    {
        fwrite(&elemento, sizeof (int), 1, buffer);
        fclose(buffer);
    }
    else
    {
        printf("no se pudo abrir el archivo \n");
    }
}

///2. Hacer una función que muestre por pantalla el contenido de un archivo.

void mostrarArchivo(char nombreArchivo[])
{
    FILE* buffer = fopen(nombreArchivo, "rb");
    int aux;
    if (buffer)
    {
        while (fread(&aux, sizeof(int), 1, buffer) == 1)
        {
            printf("\n%d \n", aux);
        }
        fclose(buffer);
    }
    else
    {
        printf(" no se pudo abrir el archivo \n");
    }
}

///3. Hacer una función que retorne la cantidad de registros que contiene un archivo.


int contarElementos(char nombreArchivo[])
{
    int cantidad = 0;
    FILE* buffer = fopen(nombreArchivo, "rb");
    if (buffer)
    {
        int aux;
        while (fread(&aux, sizeof(int), 1, buffer) == 1)
        {
            cantidad++;
        }
        fclose(buffer);
        return cantidad;
    }
    else
    {
        printf("no se pudo abrir el archivo\n");
        return -1;
    }
}

///4. Crear una función que cargue un archivo de alumnos. Abrirlo de manera tal de verificar si el archivo ya está creado previamente.
///Cargar el archivo con 5 datos. Cerrarlo dentro de la función

void cargarArchivoAlumnos (char nombreArchivoAlumnos[])
{
    FILE* buffer = fopen(nombreArchivoAlumnos, "rb");
    if(buffer)
    {
        printf("\n El archivo ya fue creado previamente \n");
        fclose(buffer);
    }
    else
    {
        buffer = fopen(nombreArchivoAlumnos, "wb");
        if (buffer)
        {
            stAlumno alumno;
            for (int i = 0; i < 5 ; i++)
            {
                printf("\n\n Cargando al alumno n%d\n", i+1);
                alumno = cargarAlumno();
                fwrite(&alumno, sizeof(stAlumno), 1, buffer);

            }
            fclose(buffer);
        }
        else
        {
            printf("no se pudo abrir el archivo\n");
        }
    }
}

stAlumno cargarAlumno()
{
    stAlumno alumno;
    printf("\n ingrese el legajo del alumno \n");
    scanf("%d", &alumno.legajo);
    printf("\n ingrese el nombre y apellido del alumno \n");
    getchar();
    gets(alumno.nombreYapellido);
    printf("\n ingrese la edad del alumno \n");
    scanf(" %d", &alumno.edad);
    printf("\n ingrese el anio del alumno \n");
    scanf("%d", &alumno.anio);
    return alumno;
}

///5. Crear una función que muestre por pantalla los registros de un archivo de alumnos. Modularizar.

void mostrarAlumnos(char nombreArchivoAlumnos[])
{
    FILE* buffer = fopen(nombreArchivoAlumnos, "rb");
    if (buffer)
    {
        stAlumno aux;
        int contador = 0;
        while (fread(&aux, sizeof(stAlumno), 1, buffer) == 1)
        {
            printf("\nAlumno N%d \n", contador+1);
            mostrarAlumno(aux);
            contador ++;
        }
        if (contador == 0)
        {
            printf("No se encontraron alumnos\n");
        }
        fclose(buffer);
    }
    else
    {
        printf("no se pudo abrir el archivo\n");
    }
}

void mostrarAlumno(stAlumno aux)
{
    printf ("legajo: %d\n", aux.legajo);
    printf("nombre y apellido: %s\n", aux.nombreYapellido);
    printf("edad: %d\n", aux.edad);
    printf("anio: %d\n", aux.anio);
    printf("\n-----------------\n");
}

///6. Crear una función que permita agregar de a un elemento al final del archivo. O sea, se debe
///abrir el archivo, se piden los datos (se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra.

void cargarMasAlumnos (char nombreArchivoAlumnos[])
{
    FILE* buffer = fopen(nombreArchivoAlumnos, "rb");
    if(!buffer)
    {
        printf("\n El archivo no existe\n");
    }
    else
    {
        fclose(buffer);
        buffer = fopen(nombreArchivoAlumnos, "ab");
        char opcion = 's';
        stAlumno alumno;
        do
        {
            alumno = cargarAlumno();
            fwrite(&alumno, sizeof(stAlumno), 1, buffer);
            printf("\n Desea seguircargando alumnos? s/n\n");
            scanf(" %c", &opcion);
        }
        while (opcion == 's');
        fclose(buffer);
    }
}

///7. Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad.

void pasarAPila(char nombreArchivoAlumnos[])
{
    FILE* buffer = fopen(nombreArchivoAlumnos, "rb");
    if (buffer)
    {
        printf("\n cargando pila...\n");
        Pila pila;
        inicpila(&pila);
        stAlumno aux;
        while(fread(&aux, sizeof(stAlumno), 1, buffer) == 1)
        {
            if (aux.edad >= 18)
            {
                apilar(&pila, aux.legajo);
            }
        }
        fclose(buffer);
        mostrar(&pila);
    }
    else
    {
        printf("no se pudo abrir el archivo\n");
    }
}

///8. Dado un archivo de alumnos, hacer una función que cuente la cantidad de alumnos mayores a edad específica que se envía por parámetro.

void contarMayoresA(char nombreArchivoAlumnos[], int edad)
{
    FILE* buffer = fopen(nombreArchivoAlumnos, "rb");
    if (buffer)
    {
        int cantidad = 0;
        stAlumno aux;
        while (fread(&aux, sizeof(stAlumno), 1, buffer) == 1)
        {
            if (aux.edad >= edad)
            {
                cantidad++;
            }
        }
        fclose(buffer);
        printf("\n\n cantidad de alumnos mayores a %d= %d\n\n", edad, cantidad);
    }
    else
    {
        printf("no se pudo abrir el archivo\n");
    }
}

///9. Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre un rango de edades específico (por ejemplo, entre 17 y 25 años). Dicho rango debe recibirse
///por parámetro. Modularizar

void mostarAlumnosEntreEdades (char nombreArchivoAlumnos[], int edadMin, int edadMax)
{
    FILE* buffer = fopen(nombreArchivoAlumnos, "rb");
    if (buffer)
    {
        stAlumno aux;
        while (fread(&aux, sizeof(stAlumno), 1, buffer) ==1)
        {
            if(aux.edad>=edadMin && aux.edad<=edadMax)
            {
                mostrarAlumno(aux);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("no se pudo abrir el archivo\n");
    }
}

///10. Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.

void mostrarMayor (char nombreArchivoAlumnos[])
{
    FILE* buffer = fopen(nombreArchivoAlumnos, "rb");
    if (buffer)
    {
        stAlumno aux;
        stAlumno mayor;
        fread(&mayor, sizeof(stAlumno), 1, buffer);
        while (fread(&aux, sizeof(stAlumno), 1, buffer) == 1)
        {
            if (aux.edad>mayor.edad)
            {
                mayor = aux;
            }
        }
        fclose(buffer);
        printf("\nEl mayor es: \n");
        mostrarAlumno(mayor);
    }
    else
    {
        printf("no se pudo abrir el archivo\n");
    }
}

///11. Crear una función que retorne la cantidad de alumnos que cursan un determinado año. El año buscado se pasa por parámetro.

int mostrarAlumnosSegunAnio(char nombreArchivoAlumnos[], int anio)
{
    FILE* buffer = fopen(nombreArchivoAlumnos, "rb");
    if (buffer)
    {
        stAlumno aux;
        int cantidadAlumnos = 0;
        while (fread(&aux, sizeof(stAlumno), 1, buffer) == 1)
        {
            if (anio == aux.anio)
            {
                mostrarAlumno(aux);
                cantidadAlumnos++;
            }
        }
        fclose(buffer);
        return cantidadAlumnos;
    }
    else
    {
        printf("no se pudo abrir el archivo\n");
        return 0;
    }
}

///12. Crear una función que reciba como parámetro un arreglo de tipo alumno y lo copie en el archivo.
///Asimismo, realice otra función que pase los elementos del archivo a un arreglo de alumnos, filtrando los estudiantes de un año en particular.

void copiarArreglo(stAlumno alumnosArreglo2[],char nombreArchivoAlumnos2[], int cantidad2)
{
    FILE* buffer = fopen(nombreArchivoAlumnos2, "wb");
    if (buffer)
    {
        for (int i = 0; i < cantidad2 ; i++)
        {
            fwrite(&alumnosArreglo2[i], sizeof(stAlumno), 1, buffer);
        }
        fclose(buffer);
    }
    else
    {
        printf("no se pudo abrir el archivo \n");
    }
}

void pasarArregloAnio (stAlumno alumnmosArreglo2[], char nombreArchivoAlumnos[], int cantidad)
{
    int anioFiltro, j = 0;
    printf("\n ingrese el anio que desea filtrar para copiar al arreglo\n");
    scanf("%d", &anioFiltro);

    FILE* buffer = fopen(nombreArchivoAlumnos, "rb");
    if (buffer)
    {
        stAlumno aux;
        while (fread(&aux, sizeof(stAlumno), 1, buffer) == 1)
        {
            if (anioFiltro == aux.anio)
            {
                alumnmosArreglo2[j] = aux;
                j++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("no se pudo abrir el archivo\n");
    }

    for(int i = 0; i < j; i++){
        printf("\n");
        mostrarAlumno(alumnmosArreglo2[i]);
    }

}

///13. Crear una función que retorne la cantidad de registros que tiene el archivo. Usar fseek y
///ftell. Puede pensar la función para uso genérico, que sirva para averiguar la cantidad de registros de cualquier archivo.

int cantidadRegistrosArchivo(char nombreArchivoAlumnos[]){
int cantidadRegistros = 0;
FILE* buffer = fopen(nombreArchivoAlumnos, "rb");
if (buffer){
    long pos = 0;
    fseek(buffer,0,SEEK_END);
    pos = ftell(buffer);
    cantidadRegistros = pos / sizeof(stAlumno);
    fclose(buffer);
    return cantidadRegistros;
}
else {
    printf("No se pudo abrir el archivo \n");
    return -1;
}
}

///14. Dado un archivo de alumnos, que tenga al menos 10 registros, hacer una función que
///muestre el contenido de un registro, cuyo número (entre 0 y 9) se pase por parámetro. Controlar no sobrepasar los límites del archivo.

void buscarXNumeroEnArchivo(char nombreArchivoAlumnos2[],int cantidad3,int numElegido){
FILE* buffer = fopen(nombreArchivoAlumnos2,"rb");
if (buffer){
    fseek(buffer, (numElegido-1)* sizeof(stAlumno), SEEK_SET);
    stAlumno aux;
    fread(&aux, sizeof(stAlumno),1, buffer);
    fclose(buffer);
    mostrarAlumno(aux);
}
else {
    printf("no se pudo abrir el archivo\n");
}
}
