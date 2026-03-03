# TP4 - Arreglos Paralelos en C

Trabajo práctico desarrollado en C para la materia Programación I  
Tecnicatura en Programación - UTN

Este proyecto implementa un sistema básico de gestión de alumnos utilizando arreglos paralelos para almacenar:

- Nombres
- Legajos
- Años

El programa funciona mediante un menú interactivo por consola que permite cargar, buscar y ordenar alumnos.

---

## Funcionalidades implementadas

### Carga de alumnos
Permite ingresar múltiples alumnos con:
- Nombre
- Año
- Legajo

La función retorna la cantidad de elementos válidos cargados.

---

️### Búsqueda por legajo
Busca un legajo específico dentro del arreglo y devuelve su posición.

---

### Búsqueda de alumno por legajo
Utiliza la función de búsqueda para:
- Encontrar el legajo
- Mostrar el nombre correspondiente

---

### ️ Ordenamiento por nombre
Ordena los alumnos alfabéticamente utilizando el método de selección, manteniendo sincronizados:

- Arreglo de nombres
- Arreglo de legajos
- Arreglo de años

Esto garantiza la integridad de los datos en los arreglos paralelos.

---

##  Conceptos aplicados

- Arreglos paralelos
- Manejo de válidos
- Strings en C (`strcpy`, `strcmpi`)
- Búsqueda secuencial
- Ordenamiento por selección
- Intercambio de elementos
- Modularización
- Separación de responsabilidades

---

##  Estructura del proyecto


tp5-arreglos-paralelos/
└── main.c


---

##  Compilación

Desde la terminal:

```bash
gcc main.c -o programa
./programa
 Objetivo académico

El objetivo del trabajo es comprender:

Cómo modelar datos relacionados mediante arreglos paralelos

Cómo mantener coherencia entre estructuras al ordenar

Cómo aplicar algoritmos clásicos adaptados a múltiples arreglos

Organización modular del código

 Autor

Lisandro Inzulsa
Estudiante de Tecnicatura en Programación - UTN
