/* Kacper Weiss
Kalkulator RPN
24.01.2017 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Kalkulator.h"

int main()
{
  int end=0; 
  int a,b,i,wynik;
  char buffor[64];
  T_stos *stos=NULL; /* Inicjuje pusty stos (uznałem za bezsensowne tworzenie funkcji INICJUJ, która zajmuje jedną linijkę programu, 
                                                                            skoro mogę zainicjować stos bezpośrednio w funkcji main) */
  printf("Zostal uruchomiony kalkulator RPN\nAby wyświetlić instrukcje wpisz - help\n"); /* Teks powitalny programu */
  while(end==0) /* Warunek zakończenia działania programu */
  {
    scanf("%s",buffor);
    if(buffor[0]=='h' && buffor[1]=='e' && buffor[2]=='l' && buffor[3]=='p' && buffor[4]==NULL) /* Wykrywanie wpisania do programu opcji help */
    {
      instrukcja();
    }

    else if(sscanf(buffor,"%d",&i)>0) /* sscanf zwroci 0 dla wszystkiego poza liczbami i EOF (End-of-file) dla liczb, */
    {                               /* (ewentualnie poprzedzonych znakami '-' lub '+') */
      push(&stos,i);
    }
    else
    {
      switch(buffor[0])
      {
	case '+': /* Dodaje do siebie dwie ostatnio dodane do stosu liczby */
	{
	  a=pop(&stos); /* Nadaje zmiennej a wartość z góry stosu, jednocześnie usuwając tą daną ze stosu */
	  b=pop(&stos); /* Nadaje zmiennej b wartość z góry stosu, jednocześnie usuwając kolejną daną ze stosu */
	  wynik=b+a; /* Nadaje zmiennej "wynik" wynik działania b+a */
	  push(&stos,wynik); /* Dodaje wynik na góre stosu - kolejne funkcje działają analogicznie do tej */
	  break;
	}
	case '-': /* Odejmuje od przedostatniej dodanej liczby ostatnią liczbę */
	{
	  a=pop(&stos);
	  b=pop(&stos);
	  wynik=b-a;
	  push(&stos,wynik);
	  break;
	}
	case '*': /* Mnoży dwie ostatnio dodane liczby */
	{
	  a=pop(&stos);
	  b=pop(&stos);
	  wynik=b*a;
	  push(&stos,wynik);
	  break;
	}
	case '/': /* Dzieli przedostatnią dodaną liczbę przez ostatnią */
	{
	  a=pop(&stos);
	  b=pop(&stos);
	  wynik=b/a;
	  push(&stos,wynik);
	  break;
	}
	case '^': /* Podnosi przed ostatnią dodaną danę do potęgi liczby dodanej ostatnio */
	{
	  a=pop(&stos);
	  b=pop(&stos);
	  wynik=pow(b,a);
	  push(&stos,wynik);
	  break;
	}
	case 'v': /* Pierwiastkuje ostatnią podaną liczbę */
	{
	  a=pop(&stos);
	  wynik=sqrt(a);
	  push(&stos,wynik);
	  break;
	}
	case '#': /* Usuwa ostanią dodaną daną */
	{
	  pop(&stos);
	  break;
	}
	case '$': /* Zamienia miejscami na stosie dwie ostanie dane */
	{
	  a=pop(&stos);
	  b=pop(&stos);
	  push(&stos,a);
	  push(&stos,b);
	  break;
	}
	case '&': /* Kopiuje ostatnio dodaną daną i umieszcza na szczycie stosu */
	{
	  a=pop(&stos);
	  push(&stos,a);
	  push(&stos,a);
	  break;
	}
	case '?': /* Wyświetla całą zawartość stosu, od ostatniej dodanej danej, do pierwszej */
	{
	  print(stos);
	  break;
	}
	case '=': /* Wyświetla ostanią daną ze stosu (najpewniej wynik) */
	{
	  printf("%d\n",wynik);
	  break;
	}
	case 'd': /* Usuwa cały stos */
	{
	  usun(&stos);
	  break;
	}
	case 'q': /* Kończy działanie programu, jednocześnie usuwając stos */
	{
	  end++; /* Zmienia wartość end kończąc pętle i kończąc program */
	  usun(&stos);
	  break;
	}
      }
    }
  } return 0; 
}


/*
+++++++++++++++++++++++++++++++++++++++++++++++++
+                                               +
+                 SPRAWOZDANIE                  +
+                                               +
+++++++++++++++++++++++++++++++++++++++++++++++++
*/

/*
1. TESTY NA KOMPUTERZE OSOBISTYM
a) Sprawdzenie działania wyświetlenia istrukcji, a następnie działania podstawowych funkcji matematycznych (+,-,*,/):
Dane wejściowe: help
Dane wyjściowe: kompletna instrukcja obsługi kalkulatora RPN
Dane wejściowe: 1 1 + 5 * 6 * 5 - 5 / = q
Dane wyjściowe: 11
Rezultat: Program wykonał obliczenia poprawnie.
b) Sprawdzenie działania zaawansowanych funkcji matematycznych (^,v), oraz funkcji programu (#,$,&,?,d,=):
Dane wejściowe: 2 5 ^ ?
Dane wyjściowe: 32
Dane wejściowe: 2 * v ?
Dane wyjściowe: 8
Dane wejściowe: 4 # 8 & 4 ?
Dane wyjściowe: 4 8 8 8
Dane wejściowe: $ ?
Dane wyjściowe: 8 4 8 8
Dane wejściowe: * =
Dane wyjściowe: 32
Dane wejściowe: d
Dane wyjściowe: Stos jest pusty
Rezultat: Wszystkie funkcje matematyczne i funkcje programu działają prawidłowo, # usuwa ostatnią daną ze stosu, $ zamienia miejscami dwie ostatnio dodane dane ze stosu, & klonuje ostatnią daną na stosie, ? wyświetla dane ze stosu od ostatnio dodanych, do tych najstarszych, a = wyświetla tylko ostatnią daną ze stosu która jest wynikiem ostatniego działania, natomiast funkcja d usuwa cały stos.

WYNIKI TESTÓW NA KOMPUTERZE OSOBISTYM:
POZYTYWNY

2. TESTY NA SERWERZE DIABLO
a) Sprawdzenie działania wyświetlenia istrukcji, a następnie działania podstawowych funkcji matematycznych (+,-,*,/):
Dane wejściowe: help
Dane wyjściowe: kompletna instrukcja obsługi kalkulatora RPN
Dane wejściowe: 1 1 + 10 * 5 * 1 - 9 / = q
Dane wyjściowe: 11
Rezultat: Program wykonał obliczenia poprawnie.
b) Sprawdzenie działania zaawansowanych funkcji matematycznych (^,v), oraz funkcji programu (#,$,&,?,d,=):
Dane wejściowe: 2 4 ^ ?
Dane wyjściowe: 16
Dane wejściowe: 4 * v ?
Dane wyjściowe: 8
Dane wejściowe: 4 # 2 & 4 ?
Dane wyjściowe: 4 2 2 8
Dane wejściowe: $ ?
Dane wyjściowe: 2 4 2 8
Dane wejściowe: * =
Dane wyjściowe: 8
Dane wejściowe: d
Dane wyjściowe: Stos jest pusty
Rezultat: Wszystkie funkcje matematyczne i funkcje programu działają prawidłowo, # usuwa ostatnią daną ze stosu, $ zamienia miejscami dwie ostatnio dodane dane ze stosu, & klonuje ostatnią daną na stosie, ? wyświetla dane ze stosu od ostatnio dodanych, do tych najstarszych, a = wyświetla tylko ostatnią daną ze stosu która jest wynikiem ostatniego działania, natomiast funkcja d usuwa cały stos.

WYNIKI TESTÓW NA SERWERZE DIABLO:
POZYTYWNY
*/
