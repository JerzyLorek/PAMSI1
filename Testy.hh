#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
#include "scalanie.cpp"
#include "szybkie.cpp"
#include "introspektywne.cpp"



using namespace std;


template <typename typ>
void Czesciowo_posortowana(typ *tablica, int dlugosc, double procent);

template <typename typ>
void Posortowana(typ *tablica, int dlugosc);

template <typename typ>
void Odwrotnie_posortowana(typ *tablica, int dlugosc);

template <typename typ>
void wyswietl_tablice(typ *tablica, int dlugosc);

template <typename typ>
void Losowa(typ *tablica, int dlugosc);


template <typename typ>
void Test(typ *tablica, int dlugosc, double &scalanie, double &szybkie, double &introspektywne);

template <typename typ>
bool Sprawdz_czy_posortowano(typ *tablica, int dlugosc);

