/** @file */
#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

#ifndef Rank_H
#define Rank_H


/**Przechowuje punkty i nazwe uzytkownika, oraz wskaznik na nastepny element */
typedef struct rank
{
    int points;///< Punkty
    char* name;///< Nazwa uzytkownika 
    struct rank* pNext;///< Wskaznik na nastepny element
}prank;

/**Wysyla punkty do listy
@param pHead poczatek listy
@param point zawiera punkty
@param names zawiera nazwe
*/
void push_back_rank(prank** pHead, double point, char *names);

/**Czyta z pliku do tablicy
@param bufrank tablica na zapis
@param start wskaznik na poczatek listy
*/
void readFilerank(char* bufrank, prank** start);

/**Wyswietla liste points
@param head poczatek listy
*/
void showpoints(prank* head);

/**Wyswietla liste nazwy uzytkownika
@param head poczatek listy
*/
void showname(prank* head);

/**Wpisuje do pliku punkty i nazwe uzykownika
@param pointsinrank punkty rankingu
*/
void SavetoToRank(int pointsinrank);

/**Sortuje ranking wzgledem ilosci punktow
@param head poczatek listy
@param newel wskaznik na nastepny element
*/
void sortrank(prank** head, prank* newel);

/**Wysyla kolejne elemetny do funkcji sortrank
@param head poczatek listy
*/
void insertionSort(prank** head);

/**Funkcja dealokuje pamiec w liscie
@param head poczatek listy 
*/
void DeleteRank(prank** head);

#endif