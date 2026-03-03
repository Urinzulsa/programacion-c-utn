#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXPALABRAS 10
#define MAXLONGITUD 30
void cargarMatriz (int filas,int columnas,int matriz[filas][columnas]);
void mostrarMatriz (int filas,int columnas,int matriz[filas][columnas]);
void cargarMatrizRandom(int filas,int columnas,int matriz[filas][columnas]);
void sumaMatriz(int filas, int columnas, int matriz[filas][columnas], int *suma, int *cant);
float promMatriz(int filas, int columnas, int matriz[filas][columnas]);
void buscarNumero(int filas,int columnas,int matriz[filas][columnas],int numBuscado);
int cargaPalabras(char matriz[MAXPALABRAS][MAXLONGITUD]);
void mostrarPalabras (char matrizPalabras[][MAXLONGITUD], int cantidadPalabras);
int buscarPalabra (char matrizPalabras[][MAXLONGITUD], int cantidadPalabras,char palabraBuscada[]);
void ordenarAlfabeticamente(int *cantidadPalabras, char matrizPalabras[][MAXLONGITUD]);
void buscarMenor(int *cantidadPalabras, char matrizPalabras[][MAXLONGITUD], char aux []);

int main()
{
 int filas=2;
 int columnas=3;
 int matriz[filas][columnas];
 char matrizPalabras[MAXPALABRAS][MAXLONGITUD];
 char palabraBuscada [MAXLONGITUD];
 int numBuscado = 0;
 int cantidadPalabras = 0;
 int indice = 0;
 float promedio=0;
 srand(time(NULL));
 
   ///Hacer una función que reciba como parámetro una matriz de números enteros y permita
///que el usuario ingrese valores al mismo por teclado.
///La función debe cargar la matriz por completo

 cargarMatriz (filas,columnas,matriz);
 ///Hacer una función que reciba como parámetro una matriz de números enteros
///y la muestre por pantalla (en formato matricial).

 mostrarMatriz (filas,columnas,matriz);

  ///Hacer una función que reciba como parámetro una matriz de números enteros y que cargue la misma con números aleatorios
///(sin intervención del usuario). La función debe cargar la matriz por completo.

 cargarMatrizRandom(filas,columnas,matriz);
 mostrarMatriz (filas,columnas,matriz);

 ///Hacer una función tipo int que sume el contenido total de una matriz de números enteros

 sumaMatriz(filas, columnas, matriz);

 ///Hacer una función tipo float que calcule el promedio de una matriz de números enteros
 promedio = promMatriz(filas, columnas, matriz);
 printf("promedio = %.2f\n", promedio);

 ///Hacer una función que determine si un elemento se encuentra dentro de una matriz de números enteros.
///La función recibe la matriz y el dato a buscar
printf("ingrese el numero que desea buscar \n");
scanf("%d", &numBuscado);
buscarNumero(filas,columnas,matriz,numBuscado);

 ///Hacer una función que cargue un arreglo de palabras (strings).
///La función debe retornar cuantas palabras se cargaron.
///(puede ser a través del parámetro como puntero).

cantidadPalabras = cargaPalabras(matrizPalabras);
printf("cantidad de palabras cargadas %d\n", cantidadPalabras);

 ///Hacer una función que muestre un arreglo de palabras.

mostrarPalabras (matrizPalabras, cantidadPalabras);

///Hacer una función que determine si un string se encuentra dentro de un arreglo de strings.
///La función recibe el arreglo, la cantidad de palabras que contiene y la palabra a buscar.
///devuelve el índice de la fila en que se encuentra, de lo contrario retorna -1
printf("ingrese la palabra que desea buscar \n");
scanf("%s", palabraBuscada);
indice = buscarPalabra (matrizPalabras, cantidadPalabras, palabraBuscada);
if (indice == -1) {
        printf("no se encontro la palabra");
} else printf("se encuentra en la pos: %d\n", indice);

///Hacer una función que determine si un string se encuentra dentro de un arreglo de strings ordenado alfabéticamente.
///La función recibe el arreglo, la cantidad de palabras que contiene y el string a buscar.
///devuelve el índice de la fila en que se encuentra, de lo contrario retorna -1
ordenarAlfabeticamente(&cantidadPalabras, matrizPalabras);

printf("ingrese la palabra que desea buscar \n");
scanf("%s", palabraBuscada);
indice = buscarPalabra (matrizPalabras, cantidadPalabras, palabraBuscada);
if (indice == -1) {
        printf("no se encontro la palabra");
} else printf("se encuentra en la pos: %d\n", indice);

}

void cargarMatriz (int filas,int columnas,int matriz[filas][columnas]){
for (int i = 0; i < filas ; i++){
    for (int j = 0; j < columnas ; j++){
        printf("ingrese un valor a la matriz\n");
        scanf("%d", &matriz[i][j]);
    }
}
}

void mostrarMatriz (int filas,int columnas,int matriz[filas][columnas]){
for (int i = 0; i < filas ; i++){
    for (int j = 0; j < columnas ; j++){
        printf("%d", matriz[i][j]);
        printf(" ");
    }
    printf("\n");
}
}

void cargarMatrizRandom(int filas,int columnas,int matriz[filas][columnas]){
for (int i = 0; i < filas ; i++){
    for (int j = 0; j < columnas ; j++){
        matriz[i][j] = rand() % 101;
        }
    }
}

void sumaMatriz(int filas, int columnas, int matriz[filas][columnas], int *suma, int *cant){
 for (int i = 0; i < filas ; i++){
    for (int j = 0; j < columnas ; j++){
      *suma = *suma + matriz[i][j];
      (*cant) ++;
        }
    }

    printf("resultado total = %d\n", *suma);
}

float promMatriz(int filas, int columnas, int matriz[filas][columnas]){
 int suma = 0;
 int cant =  0;
 float prom = 0;
 sumaMatriz(filas, columnas, matriz, &suma, &cant);
 if (cant != 0){
 prom = (float)suma/cant;
 }
 else prom =-1;
 return prom;
}

void buscarNumero(int filas,int columnas,int matriz[filas][columnas],int numBuscado){
    for (int i = 0; i < filas ; i++){
        for (int j = 0; j < columnas ; j++){
          if (numBuscado == matriz[i][j]){
            printf("Numero encontrado\n");
            return;
          }
            }
    }
    printf("numero no encontrado \n");
    return;
}

int cargaPalabras(char matriz[MAXPALABRAS][MAXLONGITUD]){
int i = 0;
char opcion = 's';
while (opcion == 's' && i < MAXPALABRAS){
    printf("ingrese la palabra que desea agregar \n");
    scanf("%s", matriz[i]);
    i++;
    if (i< MAXPALABRAS){
        printf("desea seguir cargando palabras? \n");
        scanf(" %c", &opcion);
    }
}
return i;
}

void mostrarPalabras (char matrizPalabras[][MAXLONGITUD], int cantidadPalabras){
for (int i = 0; i < cantidadPalabras ; i++){
    printf("%s\n", matrizPalabras[i]);
}
}

int buscarPalabra (char matrizPalabras[][MAXLONGITUD], int cantidadPalabras,char palabraBuscada[]){
for (int i = 0; i < cantidadPalabras ; i++){
    if (strcmp(matrizPalabras[i], palabraBuscada) == 0){
        return i;
        }
}
return -1;
}

void buscarMenor(int *cantidadPalabras, char matrizPalabras[][MAXLONGITUD], char aux []){
    int indiceAux = 0;
    strcpy(aux,matrizPalabras[0]);

    for (int i = 1; i< *cantidadPalabras ; i++){
        if (strcmp(aux,matrizPalabras[i])> 0){
            strcpy(aux, matrizPalabras[i]);
            indiceAux = i;
        }
    }

    for (int j = indiceAux ; j < *cantidadPalabras -1 ; j++){
        strcpy(matrizPalabras[j], matrizPalabras[j+1]);
    }
    (*cantidadPalabras)--;
}

void ordenarAlfabeticamente(int *cantidadPalabras, char matrizPalabras[][MAXLONGITUD]){
    char matrizOrdenado[MAXPALABRAS][MAXLONGITUD];
    char aux [MAXLONGITUD];
    int cantidadOriginal = *cantidadPalabras;
    int i = 0;
    while (*cantidadPalabras != 0) {
    buscarMenor(cantidadPalabras, matrizPalabras, aux);
    strcpy(matrizOrdenado[i], aux);
    i++;

    }
        for (int j = 0; j < cantidadOriginal; j++) {
        strcpy(matrizPalabras[j], matrizOrdenado[j]);
    }

    *cantidadPalabras = cantidadOriginal;

    mostrarPalabras (matrizPalabras, *cantidadPalabras);
}
