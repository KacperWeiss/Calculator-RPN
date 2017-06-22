#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Kalkulator.h"

/* Funkcja PUSH (umieszcza element na szczycie stosu) */
void push(T_stos **stos, int liczba)
{
  T_stos *element = (T_stos*) malloc (sizeof (T_stos));
  element->dana=liczba;
  element->nast=*stos;
  *stos=element;
}

/* Funkcja POP (zdejmuje element ze szczytu stosu) */
int pop(T_stos **stos)
{
  T_stos *element;
  int dana_tymczasowa;
  if(*stos != NULL)
  {
    dana_tymczasowa = (*stos)->dana;
    element = *stos;
    *stos = element->nast;
    free(element);
  }
  else
  {
    fprintf(stderr, "Blad braku danych\n");
    return 0;
  }
  return dana_tymczasowa;
}

/* Funkcja EMPTY (nie użyta w programie, ponieważ nie było takiej potrzeby - funkcja PRINT wykonuje to samo zadanie, w lepszy sposób)*/ 
void empty(T_stos *stos)
{
  if(stos==NULL)
  {
    printf("Stos jest pusty\n");
  } 
  else 
  {
    printf("Stos nie jest pusty\n");
  }
}

/* Funkcja PRINT (Wyświetla zawartość stosu, a jeśli jest on pusty informuje o braku danych w stosie)*/
void print(T_stos *stos)
{
  if(stos!=NULL)
  {
    while(stos!=NULL)
    {
      printf("%d\n", stos->dana);
      stos=stos->nast;
    }
  }
  else 
  {
    printf("Stos jest pusty\n");
  }
}

/* Funkcja USUN (funkcja usuwająca stos)*/

void usun(T_stos **stos)
{
  T_stos *element;
  while(*stos != NULL)
    {
      element=*stos;
      *stos=element->nast;
      free(element);
    }
}

/* Wyświetla instrukcje kalkulatora */
void instrukcja()
{
printf("Instrukcja użytkowania kalkulatora RNP (Odwrotnej notacji Polskiej)\n");
printf("Wpisz: + w celu dodawania\n");
printf("Wpisz: - w celu odejmowania\n");
printf("Wpisz: * w celu mnożenia\n");
printf("Wpisz: / w celu dzielenia\n");
printf("Wpisz: ^ w celu potęgowania\n");
printf("Wpisz: v w celu pierwiastkowania kwadratowego ostatniej liczby\n");
printf("Wpisz: # w celu usunięcia ostatnio dodanej danej\n");
printf("Wpisz: $ w celu zamiana miejsc dwoch ostatnio dodanych do stosu danych\n");
printf("Wpisz: & w celu ponownego dodania tej samej danej do stosu\n");
printf("Wpisz: ? w celu wyświetlenia danych ze stosu\n");
printf("Wpisz: = w celu wyświetlenia ostatniego wyniku\n");
printf("Wpisz: d w celu usunięcia całości stosu danych\n");
printf("Wpisz: q w celu zakończenia dzialania programu (automatycznie usuwa stos)\n");
}


