#include "scalanie.hh"

/*FUNKCJA SCALAJACA TABLICE W JEDNA*/
template <typename typ>
void scal(typ *tab, int lewy, int prawy, int srodek)
{
	int i, j, k;
	typ * temp = new typ[prawy-lewy+1];
	i = lewy;
	k = 0;
	j = srodek + 1;

	while (i <= srodek && j <= prawy)
	{
		if (tab[i] < tab[j])
		{
			temp[k] = tab[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = tab[j];
			k++;
			j++;
		}
	}

	while (i <= srodek)
	{
		temp[k] = tab[i];
		k++;
		i++;
	}
	while (j <= prawy)
	{
		temp[k] = tab[j];
		k++;
		j++;
	}


	for (i = lewy; i <= prawy; i++)
	{
		tab[i] = temp[i-lewy];
	}
        delete [] temp;
}
/*FUNKCJA WYKONUJACA SORTOWANIE PRZEZ SCALANIE*/
template <typename typ>
void sortowanie_scalanie(int *tab, int lewy, int prawy)
{
	int srodek;
	if (lewy < prawy)
	{
		srodek=(lewy+prawy)/2;
		sortowanie_scalanie<typ>(tab, lewy, srodek);
		sortowanie_scalanie<typ>(tab, srodek+1, prawy);

		scal<typ>(tab, lewy, prawy, srodek);
	}
}
