#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifndef Kalkulator_h
#define Kalkulator_h

/* Struktura */
typedef struct stos
{
  int dana;
  struct stos *nast;
} T_stos;

/* Prototypy funkcji */
void push(T_stos **stos, int liczba);
int pop(T_stos **stos);
void empty(T_stos *stos);
void print(T_stos *stos);
void usun(T_stos **stos);
void instrukcja();

#endif
