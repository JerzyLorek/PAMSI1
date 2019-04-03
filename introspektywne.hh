#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;


template <typename typ >
void szybkie(typ *tablica, int lewy, int prawy);

template<typename typ>
void kopcowanie(typ *lewy, typ *prawy);

template<typename typ>
int partycja(typ *tablica, int lewy, int prawy);

template <typename typ>
void sortowanie_introspektywne(typ *tablica, int *lewy, int *prawy, int dlugosc);
