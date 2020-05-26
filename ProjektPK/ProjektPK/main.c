#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

#include "List.h"
#include "Rank.h"

int main() {
    char choice;
    char choice2 = 4;
    char choice3 = 2;
    char **bufor = (char*)malloc(300000*sizeof(char*));
    char **bufrank = (char*)malloc(1000 * sizeof(char*));
    int pointsinrank = 0;
    int health = 3;
    printf("1. Graj\n");
    printf("2. Wprowadz swoje miasto\n");
    printf("3. Ranking\n");
    printf("4. Wyjscie\n");
    choice = _getche();
       switch (choice)
       { case '1':
          {
            system("cls");
             do
             {
                 system("cls");
                 printf("Twoje punkty: %i", pointsinrank);
                 printf("\n");
                 srand(time(NULL));
                 listtyp* start;
                 start = (listtyp*)malloc(sizeof(listtyp));
                 start = NULL;
                 readFileWithTags(bufor, &start);
                 int a;
                 a = CountList(start);
                 int RandomNumber;
                 RandomNumber = Rand(a);
                 printf("Zgadnij odleglosc miedzy miastami: ");
                 ShowCitiesToGuess(start, RandomNumber);
                 printf("\n");
                 float distance;
                 printf("Wpisz odleglosc w km(mozesz sie pomylic o 10%%): ");
                 scanf_s("%f", &distance);
                 while ((getchar()) != '\n');
                 CheckPoint(start, distance, RandomNumber, &pointsinrank, &health);
                 printf("Zostalo Ci zyc: %i \n", health);
                 printf("Czy chcesz grac dalej: \n");
                 printf("1.Tak\n");
                 printf("2.Nie, zapisz mnie do rankingu.\n");
                 printf("3.Nie, wyjdz do menu.\n");
                 choice2 = _getche();
                 switch (choice2)
                 {
                  case'1': choice2 = 1;
                     break;
                  case'2': {free(bufor); DeleteList(&start);  system("cls"); SavetoToRank(pointsinrank); system("cls"); main(); }
                     break;
                  default: {free(bufor); DeleteList(&start); system("cls"); main(); }
                     break;
                 }
             } while (choice2 == 1);
          }
          break;
        case '2':
            {
            SavetoFile();
            }
        break; 
        case '3':
            {
                system("cls");
                prank* start2;
                start2 = (prank*)malloc(sizeof(prank));
                start2 = NULL;
                readFilerank(bufrank, &start2);
                insertionSort(&start2);
                prank* current = start2;
                while (current != NULL)
                {
                   showname(current);
                   showpoints(current);
                   current = current->pNext;
                }
                printf("\n");
                printf("1.Wroc do menu! \n");
                choice3 = _getche();
                switch (choice3)
                {
                default: {system("cls"); free(bufrank); DeleteRank(&start2); main(); }
                 break;
                }
            }
        break;
        case '4':
            {
            free(bufor); exit(0);
            }
        break;
        default: 
            {
            system("cls");
            main();
            }
       }
       return 0;
}