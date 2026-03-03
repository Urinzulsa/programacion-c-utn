# TP7 - Arreglos Dinámicos y Punteros Dobles en C

Trabajo práctico desarrollado en C para la materia Programación I  
Tecnicatura en Programación - UTN

Este proyecto implementa ejercicios enfocados en el uso de punteros, punteros dobles y memoria dinámica utilizando `malloc`.

El programa funciona mediante un menú interactivo por consola que permite ejecutar distintos ejercicios relacionados con direcciones de memoria y arreglos dinámicos.

---

## Funcionalidades implementadas

### Punteros y punteros dobles

- Declaración de variable `int`
- Uso de puntero simple (`int *`)
- Uso de puntero doble (`int **`)
- Visualización de direcciones de memoria con `%p`
- Modificación del valor de una variable usando:
  - Puntero simple
  - Puntero doble

---

### Arreglos dinámicos con malloc

- Conteo de números pares en un arreglo
- Reserva dinámica de memoria con `malloc`
- Creación de arreglo dinámico del tamaño justo
- Traspaso de números pares desde un arreglo original a uno dinámico
- Recorrido e impresión del arreglo dinámico

---

## Conceptos aplicados

- Punteros
- Punteros dobles
- Direcciones de memoria
- Operador de indirección (`*`)
- Operador de dirección (`&`)
- Arreglos
- Funciones con parámetros tipo arreglo
- Modularización
- Memoria dinámica con `malloc`
- Reserva de memoria proporcional a cantidad necesaria (`sizeof`)
- Separación de responsabilidades en funciones

---

## Estructura del proyecto

```
tp8-arreglos-dinamicos/
└── main.c
```

---

## Compilación

```
gcc main.c -o programa
./programa
```

---

## Objetivo académico

El objetivo del trabajo es reforzar:

- Comprensión del funcionamiento interno de los punteros
- Diferencia entre variable, puntero y puntero doble
- Manejo correcto de memoria dinámica
- Uso de funciones para dividir responsabilidades
- Pensamiento lógico aplicado a manipulación de arreglos

---

## Autor

Lisandro Inzulsa  
Estudiante de Tecnicatura en Programación - UTN
