/** @file */
#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

#ifndef List_H
#define List_H

/**Glowna czesc gry
@param bufor Poczatek listy
@param health zawiera liczbe zdrowia
@param pointsinrank zawiera liczbe punktow
*/
void PickOne(listtyp* bufor, int health, int pointsinrank);

/**Glowna czesc obslugujaca ranking
@param bufrank Poczatek listy
*/
void PickThree(prank* bufrank);

/**Obsluguje menu gry i akcje z nim zwiazane
*/
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

/**Dodaje punkty i inforumje uzytkownika o dobej odpowiedzi
@param pointsinrank liczba punktow w rankingu
@param distancegiven dystans z pliku
@param distanceguess dystans ktory wpisal uzytkownik
*/
void correct(int* pointsinrank, float distancegiven, float distanceguess);

/**Odejmuje zycie i informuje uzytkownika o zlej odpowiedzi
@param pointsinrank liczba punktow w rankingu
@param distancegiven dystans z pliku
@param distanceguess dystans ktory wpisal uzytkownik
@param health ilosc zyc uzytkownika
*/
void wrong(int* pointsinrank, float distanceguess, float distancegiven, int* health);

/**Wpisuje do pliku miasto uzytkownika
*/
void SavetoFile();

/**Funkcja dealokuje pamiec w liscie 
@param head poczatek listy
*/
void DeleteList(listtyp** head);

#endif
