#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

#include "Rank.h"

void push_back_rank(prank** pHead, double point, char *names)
{
    if (*pHead == NULL)
    {
        *pHead = (prank*)malloc(sizeof(prank));
        (*pHead)->points = point;
        (*pHead)->name = names;
        (*pHead)->pNext = NULL;
    }
    else
    {
        prank* p = *pHead;
        while (p->pNext != NULL)
        {
            p = p->pNext;
        }
        p->pNext = (prank*)malloc(sizeof(prank));
        p->pNext->points = point;
        p->pNext->name = names;
        p->pNext->pNext = NULL;
    }
}
void readFilerank(char* bufrank, prank** start)
{
    FILE* file3;
    char* name;
    char* point;
    float a;
    char correction[] = " ";
    if (fopen_s(&file3, "rank.txt", "r") == 0)
    {
        while (fgets(bufrank, 1000, file3) != NULL) {
            name = strtok_s(NULL, correction, &bufrank);
            point = strtok_s(NULL, correction, &bufrank);
            //printf("%s", name);
            //printf("%s", point);
            a = strtod(point, NULL);
            push_back_rank(start, a, name);
        }
    }
    fclose(file3);
}
void showpoints(prank* head)
{
    if (head == NULL) printf("");
    else
    {
       prank* current2 = head;
       printf("%i", current2->points);
       printf("\n");
    }
}
void showname(prank* head)
{
    if (head == NULL) printf("No one is in the ranking");
    else
    {
        prank* current2 = head;
        printf("%s ", current2->name);
    }
}
void SavetoToRank(int pointsinrank)
{
    FILE* file3;
    if (fopen_s(&file3, "rank.txt", "a") == 0)
    {
        system("cls");
        char inputname[300];
        printf("Wpisz nazwe(bez spacji): ");
        gets_s(inputname, 300);
        char pointname[300];
        sprintf_s(pointname, 300, " %d", pointsinrank);
        strcat_s(inputname, 300, pointname);
        char newline2[300] = "\n";
        strcat_s(newline2, 300, inputname);
        fprintf_s(file3, "%s", newline2);
    }
    fclose(file3);
}
void sortrank(prank** head, prank* newel)
{
      prank* current;
    if (*head == NULL || (*head)->points <= newel->points)
    {
        newel->pNext = *head;
        *head = newel;
    }
    else
    {
        current = *head;
        while (current->pNext != NULL && current->pNext->points > newel->points)
        {
            current = current->pNext;
        }
        newel->pNext = current->pNext;
        current->pNext = newel;
    }
}
void insertionSort(prank** head)
{
    prank* sorted = NULL;
    prank* current = *head;
    while (current != NULL)
    {
        struct Node* next = current->pNext;
        sortrank(&sorted, current);
        current = next;
    }
    *head = sorted;
}
void DeleteRank(prank** head)
{
    prank* current = *head;
    prank* next;

    while (current != NULL)
    {
        next = current->pNext;
        free(current);
        current = next;
    }
    *head = NULL;
}
