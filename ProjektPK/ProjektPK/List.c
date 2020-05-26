#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

#include "List.h"

void push_back_cities(listtyp** pHead, double cubbe2, char *cubbe)
{
    if (*pHead == NULL)
    {
        *pHead = (listtyp*)malloc(sizeof(listtyp));
        (*pHead)->distance = cubbe2;
        (*pHead)->cities = cubbe;
        (*pHead)->pNext = NULL;
    }
    else
    {
        listtyp* p = *pHead;
        while (p->pNext != NULL)
        {
            p = p->pNext;
        }
        p->pNext = (listtyp*)malloc(sizeof(listtyp));
        p->pNext->distance = cubbe2;
        p->pNext->cities = cubbe;
        p->pNext->pNext = NULL;
    }
}
void readFileWithTags(char* bufor, listtyp** start)
{
    FILE* file;
    char* cubby;
    char* cubby2;
    float a;
    char correction[] = " ";
    if (fopen_s(&file, "Miasta.txt", "r") == 0)
    {
        while (fgets(bufor, 300000, file) != NULL) {
            cubby = strtok_s(NULL, correction, &bufor);
            cubby2 = strtok_s(NULL, correction, &bufor);
            // printf("%s", cubby);
            // printf("%s", cubby2);
            a = strtod(cubby2, NULL);
            push_back_cities(start, a, cubby);
        }
    }
    fclose(file);
}
void show(listtyp* head)
{
    printf("\n");
    if (head == NULL) printf("List is empty");
    else
    {
        listtyp* current = head;
        do {
            printf("%.1f", current->distance);
            printf("\n");
            current = current->pNext;
        } while (current != NULL);
    }
}
void showcities(listtyp* head)
{
    printf("\n");
    if (head == NULL) printf("List is empty");
    else
    {
        listtyp* current = head;
        while (current != NULL)
        {
            printf("%s", current->cities);
            printf("\n");
            current = current->pNext;
        }
    }
}
int CountList(listtyp* head)
{
    listtyp* current = head;
    if (current)
    {
        return 1 + CountList(current->pNext);
    }
}
int Rand(int a)
{
    int NumberDrawn = 1 + rand() % a;
    //printf("%i", NumberDrawn);
    return NumberDrawn;
}
void ShowCitiesToGuess(listtyp* head, int RandNumber)
{
    listtyp* current = head;
    int i = 1;
    while (i < RandNumber)
    {
        current = current->pNext;
        i++;
    }
    printf("%s", current->cities);
}
void CheckPoint(listtyp* head, float distanceguess, int RandNumber, int* pointsinrank, int* health)
{
    listtyp* current = head;
    int i = 1;
    while (i < RandNumber)
    {
        current = current->pNext;
        i++;
    }
    float distancegiven;
    distancegiven = current->distance;
    //printf("W pliku: ");
    //printf("%.1f", distancegiven);
    //printf("\n");
    if (distancegiven == distanceguess || distanceguess <= ((distancegiven)+((distancegiven) * 0.10)) && distanceguess >= ((distancegiven)-((distancegiven) * 0.10)))
    {
        printf("Dobrze!");
        printf("\n");
        (*pointsinrank) = (*pointsinrank) + 10;
        if (distancegiven != distanceguess)
        {
            (*pointsinrank) = (*pointsinrank) - 5;
            printf("Zmiesciles sie w granicy bledu! ");
            float true1;
            true1 = distancegiven - distanceguess;
            if (true1 < 0)
            {
                true1 = true1 * (-1);
            }
            printf("Ale pomyliles sie o %0.1f km", true1);
            printf("\n");
            printf("Prawidlowa odpowiedz to: %0.1f km\n", distancegiven);

        }
    }
    else
    {
        (*health)--;
        printf("Zle!");
        printf("\n");
        printf("Prawidlowa odpowiedz to: %0.1f km", distancegiven);
        float true2;
        true2 = distancegiven - distanceguess;
        if (true2 < 0)
        {
            true2 = true2 * (-1);
        }
        printf("\n");
        printf("Pomyliles sie o: %0.1f km", true2);
        printf("\n");
        if ((*health) == 0)
        {
            printf("Przegrales! Twoja liczba punktow: %i\n", *pointsinrank);
            printf("Wpisac do rankingu?\n");
            printf("1.Tak\n");
            printf("2.Nie, wyjdz do menu\n");
            char choice;
            choice = _getche();
            switch (choice)
            {
            case'1': {system("cls"); SavetoToRank((*pointsinrank)); system("cls"); main(); }
                   break;
            case'2': {system("cls"); main(); }
                   break;
            default: {system("cls"); main(); }
                   break;
            }
        }
    }
}
void SavetoFile()
{
    FILE* file2;
    if (fopen_s(&file2, "Miasta.txt", "a") == 0)
    {
        char choice3;
        system("cls");
        char input[300];
        printf("Wprowadz nowe miasto w formacie (miasto-miasto dystans): ");
        gets_s(input, 300);
        char newline[300] = "\n";
        strcat_s(newline, 300, input);
        fprintf_s(file2, "%s", newline);
        printf("Chcesz wprowadzic wiecej miast?\n");
        printf("1.Tak\n");
        printf("2.Nie, wroc do menu!\n");
        choice3 = _getche();
        switch (choice3)
        {
        case'1': SavetoFile();
            break;
        case'2': {system("cls"); fclose(file2); main(); }
               break;
        default: {system("cls"); fclose(file2); main(); }
               break;
        }

    }
    fclose(file2);
}
void DeleteList(listtyp** head)
{
    listtyp* current = *head;
    listtyp* next;

    while (current != NULL)
    {
        next = current->pNext;
        free(current);
        current = next;
    }
    *head = NULL;
}