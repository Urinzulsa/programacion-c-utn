 #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define MAXALUMNOS 30

    typedef struct {
    int matricula;
    char nombre[30];
    char genero; //m, f, o
    } stAlumno;

    int cargarAlumnos(stAlumno alumnos[]);
    void mostrarAlumnos (int cantidadAlumnos, stAlumno alumnos[]);
    int buscarMatricula (stAlumno alumnos[], int cantidadAlumnos);
    void mostrarAlumno(stAlumno alumnos[], int i);
    int hardcodearAlumnos(stAlumno alumnos[]);
    void ordenarAlumnosMatricula(int cantidadAlumnos,stAlumno alumnos[]);
    void mostrarPorGenero(int cantidadAlumnos, stAlumno alumnos[]);
    int ingresarEnOrden(int cantidadAlumnos, stAlumno alumnos[], stAlumno nuevoAlumno);
    stAlumno cargarAlumno();
    int buscarGenero(alumnos, cantidadAlumnos, genero);
    int main()
    {
        int cantidadAlumnos = 0;
        int buscado, cantidadGenero;
        char genero;
        stAlumno alumnos [MAXALUMNOS];
        cantidadAlumnos = hardcodearAlumnos(alumnos);
        mostrarAlumnos (cantidadAlumnos, alumnos);
        buscado = buscarMatricula(alumnos, cantidadAlumnos);
        if (buscado == -1){
            printf("alumno no encontrado \n");
        } else {
            mostrarAlumno(alumnos, buscado);
        }
        ordenarAlumnosMatricula(cantidadAlumnos, alumnos);
        mostrarPorGenero(cantidadAlumnos, alumnos);
        stAlumno nuevoAlumno;
        nuevoAlumno = cargarAlumno();
        cantidadAlumnos = ingresarEnOrden(cantidadAlumnos, alumnos,nuevoAlumno);
        mostrarAlumnos(cantidadAlumnos, alumnos);
        printf("\n ingrese el genero a buscar \n");
        scanf(" %c", genero);
        cantidadGenero = buscarGenero(alumnos, cantidadAlumnos, genero);
    }

    int cargarAlumnos(stAlumno alumnos[]){
    char opcion = 's';
    int i = 0;
    do {
        alumnos[i] = cargarAlumno(alumnos[i]);
        printf("desea seguir cargando alumnos s/n\n");
        fflush(stdin);
        scanf(" %c", &opcion);
        i++;
    } while (i<MAXALUMNOS && opcion == 's');
    return i;
    }

    stAlumno cargarAlumno(){
        stAlumno alumno;
        printf("ingrese el numero de matricula del alumno\n");
        scanf("%d", &alumno.matricula);
        printf("ingrese el nombre del alumno\n");
        fflush(stdin);
        scanf("%s", alumno.nombre);
        fflush(stdin);
        printf("ingrese el genero del alumno\n");
        scanf(" %c", &alumno.genero);
        return alumno;
    }

    void mostrarAlumnos (int cantidadAlumnos, stAlumno alumnos[]){
    for (int i = 0; i < cantidadAlumnos ; i++){
        mostrarAlumno(alumnos, i);
    }
    }

    void mostrarAlumno(stAlumno alumnos[], int i){
        printf("\n");
        printf("legajo: %d\n", alumnos[i].matricula );
        printf("nombre: %s\n", alumnos[i].nombre );
        printf("genero: %c\n", alumnos[i].genero );
        printf("\n");
    }

    int hardcodearAlumnos(stAlumno alumnos[])
{
    int i = 0;

    alumnos[i].matricula = 1005;
    strcpy(alumnos[i].nombre, "Juan Perez");
    alumnos[i].genero = 'm';
    i++;

    alumnos[i].matricula = 1002;
    strcpy(alumnos[i].nombre, "Maria Lopez");
    alumnos[i].genero = 'f';
    i++;

    alumnos[i].matricula = 1006;
    strcpy(alumnos[i].nombre, "Sofia Martinez");
    alumnos[i].genero = 'f';
    i++;

    alumnos[i].matricula = 1004;
    strcpy(alumnos[i].nombre, "Lucas Gomez");
    alumnos[i].genero = 'm';
    i++;

    return i;
}

int buscarMatricula (stAlumno alumnos[], int cantidadAlumnos){
int aux;
printf("ingrese la matricula del alumno que desea buscar \n");
scanf("%d", &aux);
for (int i = 0 ; i<cantidadAlumnos ; i++){
    if (aux == alumnos[i].matricula){
        return i;
    }
    return -1;
}
}

void ordenarAlumnosMatricula(int cantidadAlumnos,stAlumno alumnos[]){
int menor;
stAlumno aux;
for (int i = 0; i< cantidadAlumnos-1 ; i++){
    menor = i;
    for (int j = i+1 ; j < cantidadAlumnos ; j++){
        if(alumnos[j].matricula < alumnos[menor].matricula){
            menor = j;
        }
    }
    aux = alumnos[i];
    alumnos [i] = alumnos[menor];
    alumnos[menor] = aux;
}

printf("\n\n------------------\n\n");
printf("alumnos mostrados por orden de matricula\n\n");
mostrarAlumnos(cantidadAlumnos, alumnos);
printf("\n\n------------------\n\n");
}

void mostrarPorGenero(int cantidadAlumnos, stAlumno alumnos[]){
char genero;
printf("ingrese el genero que desea buscar \n");
fflush(stdin);
scanf(" %c", &genero);
for (int i = 0; i< cantidadAlumnos ; i++){
    if (alumnos[i].genero == genero){
        mostrarAlumno(alumnos, i);
    }
}
}

int ingresarEnOrden(int cantidadAlumnos, stAlumno alumnos[], stAlumno nuevoAlumno){
    stAlumno aux;
    int i = 0;
    while (i < cantidadAlumnos && alumnos[i].matricula < nuevoAlumno.matricula){
        i++;
    }

    for (int j = cantidadAlumnos ; j > i; j--){
       alumnos[j] = alumnos[j-1];
    }
    alumnos [i] = nuevoAlumno;

    return cantidadAlumnos +1;
}

int buscarGenero(stAlumno alumnos[],int cantidadAlumnos,char genero){
    int contador = 0;
    for (int i = 0 ; i < cantidadAlumnos ; i++){
        if (alumnos[i].genero == genero){
            contador++;
        }
    }
    return contador;
}
