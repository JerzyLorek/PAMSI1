#include "Testy.hh"


template <typename typ>
void wyswietl_tablice(typ *tablica, int dlugosc)
{
  for(int i =0; i< dlugosc; i++)
    cout << tablica[i] << endl;
}

/*FUNKCJA POSORTOWANA MALEJACO*/
/*WYKORZYSTANO GOTOWA FUNKCJE SORT Z BIBLIOTEKI 'ALGORITHM'*/
template <typename typ>
void Odwrotnie_posortowana(typ *tablica, int dlugosc)
{
  sort(tablica,tablica+dlugosc,greater<int>());
}

template <typename typ>
void Posortowana(typ *tablica, int dlugosc)
{
      sort(tablica,tablica+dlugosc);
}

/*FUNKCJA SORTUJACA PEWIEN PROCENT PIERWSZYCH ELEMENTOW TABLICY*/
/*WYKORZYSTANO GOTOWA FUNKCJE SORT Z BIBLIOTEKI 'ALGORITHM'*/
template <typename typ>
void Czesciowo_posortowana(typ *tablica, const int dlugosc, double procent)
{
  sort(tablica,tablica+(int)((dlugosc*procent)/100));
}

/*FUNKCJA WYPELNIAJACA TABLICE LOSOWYMI LICZBAMI*/
template <typename typ>
void Losowa(typ *tablica, int dlugosc)
{
  srand(time(NULL));
  
  for(int i=0; i<dlugosc; i++)
    tablica[i] = rand()%10000+1;
        
}

template <typename typ>
bool Sprawdz_czy_posortowano(typ *tablica, int dlugosc)
{
    for(int i=0; i<dlugosc-1; i++)
        if(tablica[i+1] < tablica[i])
            return false;
    return true;
}

/*FUNKCJA TESTUJACA DZIALANIA ALGORYTMOW SORTOWANIA*/
template <typename typ>
void Test(typ *tablica, int dlugosc, double &scalanie, double &szybkie, double &introspektywne)
{
  clock_t start, stop;
  double roznica;
  typ* pom=new typ [dlugosc];
  
  for(int i=0; i<dlugosc; i++)
    tablica[i] = pom[i];
  
  start=clock();
  sortowanie_scalanie<typ>(pom, 0, dlugosc-1);		//liczenie czasu sortowania szybkiego
  stop=clock();
  if(!Sprawdz_czy_posortowano(pom, dlugosc))
    {
      cout<<"ERROR!";
      return;
    }
  roznica=(stop-start)/(double)CLOCKS_PER_SEC;		//roznica czasu przed startem sortowania i po jego ukonczeniu
  scalanie=scalanie+roznica;						//obliczenie faktycznego czasu dzialania algorytmu
  
  for(int i=0; i<dlugosc; i++)
    tablica[i] = pom[i];
  
  start=clock();
  sortowanie_szybkie<typ>(pom, 0, dlugosc-1);
  if(!Sprawdz_czy_posortowano(pom, dlugosc))
    {
      cout<<"ERROR!";
      return;
    }
  stop=clock();
  roznica=(stop-start)/(double)CLOCKS_PER_SEC;
  szybkie=szybkie+roznica;
  
  
  for(int i=0; i<dlugosc; i++)
    tablica[i] = pom[i];
  
  start=clock();
  sortowanie_introspektywne<typ>(pom,pom,pom+dlugosc, dlugosc);
  if(!Sprawdz_czy_posortowano(pom, dlugosc))
    {
      cout<<"ERROR!";
      return;
    }
  stop=clock();
  roznica=(stop-start)/(double)CLOCKS_PER_SEC;
  introspektywne=introspektywne+roznica;
  
  delete [] pom;
  
}



/*FUNKCJA ZACZYNAJACA PROGRAM*/
template<typename typ>
void start()
{
  int i, j, ilosc_testow=100;
  double scalanie=0, szybkie=0, introspektywne=0;
  int ILOSC[5]={10000, 50000, 100000, 500000,1000000};
  
  ofstream plik;
  plik.open("Wyniki.txt", ios::out | ios::app);

  plik.precision(6);			//ustawienie ilosci miejsc jakie maja sie wyswietlac po przecinku
  plik.setf(ios::fixed);		//notacja zwykla
  plik.setf(ios::showpoint);	//wypisuje nieznaczace zera
  
 
  for(j=0; j<5; j++)
    {
    
      typ* tablica=new int [ILOSC[j]];
      
      plik<<endl<<"SORTOWANIE "<<ILOSC[j]<<" ELEMENTOW"<<endl;
      plik<<endl<<"LOSOWA"<<endl;
      
      for(i=0; i<ilosc_testow; i++)
      {
	Losowa<int>(tablica, ILOSC[j]);
	Test<int>(tablica, ILOSC[j], scalanie,szybkie, introspektywne);
      }
    
    plik<<"SCALANIE: "<<scalanie<<endl;
    plik<<"SZYBKIE: "<<szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<<introspektywne<<endl;
    scalanie=0, szybkie=0,   introspektywne=0;

    plik<<endl<<"ODWROTNA"<<endl;
    for(i=0; i<ilosc_testow; i++)
      {
	Odwrotnie_posortowana<int>(tablica, ILOSC[j]);
	Test<int>(tablica, ILOSC[j], scalanie, szybkie, introspektywne);
      }
    
    plik<<"SCALANIE: "<<scalanie<<endl;
    plik<<"SZYBKIE: "<<szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<<introspektywne<<endl;
    scalanie=0, szybkie=0,   introspektywne=0;

    plik<<endl<<"25% POSORTOWANA"<<endl;
    for(i=0; i<ilosc_testow; i++)
      {
	Czesciowo_posortowana<int>(tablica, ILOSC[j],25);
	Test<int>(tablica, ILOSC[j], scalanie, szybkie, introspektywne);
      }
    
    plik<<"SCALANIE: "<<scalanie<<endl;
    plik<<"SZYBKIE: "<<szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<<introspektywne<<endl;
    scalanie=0, szybkie=0,   introspektywne=0;

    plik<<endl<<"50% POSORTOWANA"<<endl;
    for(i=0; i<ilosc_testow; i++)
      {
	Czesciowo_posortowana<int>(tablica, ILOSC[j],50);
	Test<int>(tablica, ILOSC[j], scalanie, szybkie, introspektywne);
      }
    
    plik<<"SCALANIE: "<< scalanie<<endl;
    plik<<"SZYBKIE: "<< szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<< introspektywne<<endl;
    scalanie=0, szybkie=0,   introspektywne=0;

    plik<<endl<<"75% POSORTOWANA"<<endl;
    for(i=0; i<ilosc_testow; i++)
      {
	Czesciowo_posortowana<int>(tablica, ILOSC[j],75);
	Test<int>(tablica, ILOSC[j], scalanie, szybkie, introspektywne);
      }
    
    plik<<"SCALANIE: "<< scalanie<<endl;
    plik<<"SZYBKIE: "<< szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<< introspektywne<<endl;
    scalanie=0, szybkie=0,   introspektywne=0;

    plik<<endl<<"95% POSORTOWANA"<<endl;
    for(i=0; i<ilosc_testow; i++)
      {
	Czesciowo_posortowana<int>(tablica, ILOSC[j],95);
	Test<int>(tablica, ILOSC[j], scalanie, szybkie, introspektywne);
      }
    
    plik<<"SCALANIE: "<< scalanie<<endl;
    plik<<"SZYBKIE: "<< szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<< introspektywne<<endl;
    scalanie=0, szybkie=0,   introspektywne=0;
    
    plik<<endl<<"99% POSORTOWANA"<<endl;
    for(i=0; i<ilosc_testow; i++)
      {
	Czesciowo_posortowana<int>(tablica, ILOSC[j],99);
	Test<int>(tablica, ILOSC[j], scalanie, szybkie, introspektywne);
      }
    
    plik<<"SCALANIE: "<< scalanie<<endl;
    plik<<"SZYBKIE: "<< szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<< introspektywne<<endl;
    scalanie=0, szybkie=0,   introspektywne=0;
    
    plik<<endl<<"99,7% POSORTOWANA"<<endl;
    for(i=0; i<ilosc_testow; i++)
      {
	Czesciowo_posortowana<int>(tablica, ILOSC[j],99.7);
	Test<int>(tablica, ILOSC[j], scalanie, szybkie, introspektywne);
      }
    
    plik<<"SCALANIE: "<< scalanie<<endl;
    plik<<"SZYBKIE: "<< szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<< introspektywne<<endl;
    scalanie=0, szybkie=0,introspektywne=0;

    
    cout << "SORTOWANIE TABLIC Z " << ILOSC[j] << " ELEMENTOW ZAKONCZONE" << endl;
    delete [] tablica;
    };
  
  plik << endl <<"----------------" << endl << "KONIEC" <<endl;
  plik.close();
}

