#include "szybkie.hh"


/*FUNKCJA WYKONUJACA SORTOWANIE SZYBKIE*/
template <typename typ>
void sortowanie_szybkie(typ *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while (tablica[i]<v)
            i++;
        while (tablica[j]>v)
            j--;
        if (i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while (i<=j);
    if (j>lewy)
        sortowanie_szybkie<typ>(tablica,lewy, j);
    if (i<prawy)
        sortowanie_szybkie<typ>(tablica, i, prawy);
}
