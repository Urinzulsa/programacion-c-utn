TP - Archivos Binarios y Struct en C

Trabajo práctico desarrollado en C para la materia Programación I
Tecnicatura en Programación - UTN

Este proyecto implementa múltiples ejercicios enfocados en el manejo de archivos binarios, estructuras (struct), lectura y escritura de registros, posicionamiento dentro de archivos y filtrado de datos.

El programa funciona mediante un menú interactivo por consola que permite ejecutar cada ejercicio relacionado con manipulación de archivos.

Funcionalidades implementadas
Operaciones básicas con archivos

Agregar un elemento al final de un archivo

Mostrar el contenido completo de un archivo

Contar la cantidad de registros recorriendo el archivo

Gestión de archivo de alumnos

Crear archivo de alumnos si no existe

Cargar alumnos desde teclado

Mostrar todos los alumnos almacenados

Agregar nuevos alumnos al final del archivo

Mostrar un alumno específico

Búsqueda y filtrado sobre archivo

Pasar a una pila los legajos de alumnos mayores de edad

Contar alumnos mayores a una edad determinada

Mostrar alumnos dentro de un rango de edades

Mostrar el alumno de mayor edad

Mostrar alumnos según año

Buscar alumno por número de registro

Manipulación avanzada de registros

Copiar un arreglo de estructuras a un archivo

Copiar desde archivo a arreglo filtrando por año

Obtener cantidad de registros usando fseek y ftell

Acceder directamente a un registro específico mediante posicionamiento

Conceptos aplicados

Archivos binarios (rb, wb, ab)

Lectura y escritura con fread y fwrite

Posicionamiento con fseek y ftell

Estructuras (struct)

Arreglos de estructuras

Búsqueda secuencial

Filtrado de datos

Modularización

Integración con estructura Pila

Persistencia de información en disco

Estructura del proyecto
tp-archivos/
├── main.c
└── pila.h
Compilación


gcc main.c pila.c -o programa
./programa


Objetivo académico

El objetivo del trabajo es reforzar:

Manipulación de archivos binarios

Persistencia de estructuras en disco

Posicionamiento directo en archivos

Filtrado y procesamiento de registros

Diseño modular en programas de mayor complejidad

Autor

Lisandro Inzulsa
Estudiante de Tecnicatura en Programación - UTN

Integrar estructuras dinámicas (Pila) con datos persistidos.

Reforzar diseño modular en programas de mayor tamaño.

Autor

Lisandro Inzulsa
Estudiante de Tecnicatura en Programación - UTN
