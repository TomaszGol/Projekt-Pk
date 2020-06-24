/** @file */
#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

#ifndef List_H
#define List_H

/**Przechowuje miasta i dystans pomiêdzy nimi, oraz wskaznik na nastepny element */
typedef struct list
{

    double distance; ///< Dystans miedzy miastami
    char* cities; ///< Miasta
    struct list* pNext; ///< Wskaznik na nastepny element
}listtyp;

void startmenu();

/**Wysyla dystans do listy
@param pHead wskaznik na poczatek listy
@param cubbe2 zawiera dystans
@param cubbe zawiera miasta
*/
void push_back_cities(listtyp** pHead, double cubbe2, char *cubbe);

/**Czyta z pliku do tablicy
@param bufor tablica na zapis
@param start  poczatek listy
*/
void readFileWithTags(char* bufor, listtyp** start);

/**Wyswietla liste miast
@param head wskaznik na poczatek listy
*/
void showcities(listtyp* head);

/**Wyswietla liste dystans
@param head wskaznik na poczatek listy
*/
void show(listtyp* head);

/**Liczy ile elementow jest w liscie
@param head wskaznik na poczatek listy
@return Zwraca liczbe elementow w liscie
*/
int CountList(listtyp* head);

/**Czyta z pliku do tablicy
@param a Gorna granica z ktorej losuje liczbe(liczba elementow w liscie)
@return Zwraca wylosowana liczbe
*/
int Rand(int a);

/**Pokazuje miasto z losty ktore uzytkownik musi zgadnac
@param head wskaznik na poczatek listy
@param RandNumber wylosowana liczba
*/
void ShowCitiesToGuess(listtyp* head, int RandNumber);

/**Sprawdza czy uzytkownik zgadl odleglosc z pliku
@param head wskaznik na poczatek listy
@param distanceguess dystans ktory wpisal uzytkownik
@param RandNumber wylosowana liczba
@param pointsinrank wskaznik na licznik punktow
@param health wskaznik na liczbe zdrowia
*/
void CheckPoint(listtyp* head, float distanceguess, int RandNumber, int *pointsinrank, int *health);

/**Wpisuje do pliku miasto uzytkownika
*/
void SavetoFile();

/**Funkcja dealokuje pamiec w liscie 
@param head poczatek listy
*/
void DeleteList(listtyp** head);

#endif
