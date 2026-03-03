TP5 - Gestión de Alumnos con Struct en C

Trabajo práctico desarrollado en C para la materia Programación I
Tecnicatura en Programación - UTN

Este proyecto implementa un sistema básico de gestión de alumnos utilizando estructuras (struct) para modelar los datos.

Cada alumno está representado mediante una estructura stAlumno que contiene:

Matrícula

Nombre

Género

El programa permite realizar distintas operaciones como búsqueda, ordenamiento e inserción ordenada.

Estructura de datos
typedef struct {
    int matricula;
    char nombre[30];
    char genero; // m, f, o
} stAlumno;

Se trabaja con un arreglo de estructuras con un máximo definido por:

#define MAXALUMNOS 30
Funcionalidades implementadas
1. Carga de alumnos

Carga manual de alumnos por teclado.

Función de carga individual (cargarAlumno).

Opción de carga automática mediante hardcodeo para pruebas.

2. Mostrar alumnos

Mostrar todos los alumnos.

Mostrar un alumno específico por posición.

3. Búsqueda por matrícula

Búsqueda secuencial dentro del arreglo.

Devuelve la posición del alumno o -1 si no existe.

4. Ordenamiento por matrícula

Ordenamiento mediante método de selección.

Reorganiza el arreglo completo de estructuras.

5. Mostrar por género

Filtrado de alumnos según género ingresado.

Muestra únicamente los alumnos que coinciden.

6. Inserción ordenada

Inserta un nuevo alumno manteniendo el orden por matrícula.

Desplaza los elementos necesarios dentro del arreglo.

7. Conteo por género

Cuenta la cantidad de alumnos de un género determinado.

Conceptos aplicados

Uso de estructuras (struct)

Arreglos de estructuras

Búsqueda secuencial

Ordenamiento por selección

Inserción ordenada en arreglo

Modularización

Manejo de memoria estática

Separación de lógica en funciones

Estructura del proyecto
tp5-struct-alumnos/
└── main.c
Compilación

Desde la terminal:

gcc main.c -o programa
./programa
Objetivo académico

El objetivo del trabajo es:

Modelar datos utilizando estructuras.

Reemplazar arreglos paralelos por una estructura más organizada.

Aplicar algoritmos clásicos (búsqueda y ordenamiento) sobre estructuras.

Comprender inserción ordenada en arreglos.

Autor

Lisandro Inzulsa
Estudiante de Tecnicatura en Programación - UTN
