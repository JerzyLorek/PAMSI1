#include"introspektywne.hh"


   


/*SORTOWANIE SZYBKIE*/
template <typename typ >
void szybkie(typ *tablica, int lewy, int prawy)
{
  for (int i = lewy +1; i <=prawy; i++)
    {
    int pomoc = tablica[i];
    int j=i;

    while(j>lewy && tablica[j-1]>pomoc)
      {
	tablica[j]=tablica[j-1];
	j--;
      }
    tablica[j]=pomoc;
    }
  
}

/*SORTOWANIE PRZEZ KOPCOWANIE*/
template<typename typ>
void sortowanie_kopcowanie(typ *lewy, typ *prawy)
{
  make_heap(lewy,prawy);
  sort_heap(lewy,prawy);
}

template<typename typ>
int partycja(typ *tablica, int lewy, int prawy)
{
    int x = tablica[(lewy + prawy) / 2], i = lewy, j = prawy;

    while (true)
    {
        while (tablica[j] > x) j--;

        while (tablica[i] < x) i++;

        if (i < j)
	  swap(tablica[i++], tablica[j--]);

        else
            return j;
    }
}
/*FUNKCJA WYKONUJACA SORTOWANIE INTROSPEKTYWNE*/
template <typename typ>
void sortowanie_introspektywne(typ *tablica, int *lewy, int *prawy, int dlugosc)
{
  if ((prawy-lewy)<16)
        szybkie(tablica,lewy-tablica,prawy-tablica);
    else if (dlugosc == 0)
        sortowanie_kopcowanie(lewy,prawy+1);
    else
      {
	int x=partycja(tablica,lewy-tablica,prawy-tablica);
	sortowanie_introspektywne(tablica,lewy,tablica+x,dlugosc-1);
	sortowanie_introspektywne(tablica,tablica+x+1,prawy,dlugosc-1);
      }
}
