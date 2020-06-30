/** @file */
#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

#ifndef Struct_H
#define Struct_H

/**Przechowuje miasta i dystans pomiêdzy nimi, oraz wskaznik na nastepny element */
typedef struct list
{

    double distance; ///< Dystans miedzy miastami
    char* cities; ///< Miasta
    struct list* pNext; ///< Wskaznik na nastepny element
}listtyp;

/**Przechowuje punkty i nazwe uzytkownika, oraz wskaznik na nastepny element */
typedef struct rank
{
    int points;///< Punkty
    char* name;///< Nazwa uzytkownika 
    struct rank* pNext;///< Wskaznik na nastepny element
}prank;
#endif