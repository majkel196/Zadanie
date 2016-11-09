#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int v(const std::string &pWorld)
{
    //WYZNACZAMY LICZBE NAWIASOW '(' ABY OKRESLIC MAKSYMALNA GLEBOKOSC TZN. NAJNIZSZY POZIOM
    int licz_nawiasy = 0;
    char znak_nawias;
    for (int i = 0; i < pWorld.size(); i++)
    {
        znak_nawias = pWorld[i];
        if (znak_nawias == '(')
        {
            licz_nawiasy++;
        }
    }

    const int N = pWorld.size();  //okresla dlugosc ciagu pWorld

    char znak_poziomu;      //okresla znak w stringu czyli '(', ')', '*'
    int numer_indeksu = -1; //okresla polozenie na osi poziomej, zaczynamy od -1
    int poziom = 0;         //okresla poziom na ktorym obecnie sie znajduje poszukiwacz, zaczynamy od 0
    int skarby = 0;         //okresla ilosc skarbow, poczatkowo wynosi 0

    //W TYM MIEJSCU TWORZYMY DWA KONTENERY TABLIC VECTOR TYPU INT
    vector <int> pod_jakim_indeksem_jaki_poziom(N); //indeksow jest tyle, co znakow w pWorld
    vector <int> liczba_skarbow_na_konkretnym_poziomie(licz_nawiasy+1); //zlicza ilosc skarbow na kazdym z poziomow

    //ROZMIESZCZAMY DANE ZE STRINGU pWorld DO KONTENEROW
    for(int i = 0; i < pWorld.size(); i++)
    {
        znak_poziomu = pWorld[i];
        if(znak_poziomu == '(')
        {
            poziom--;
            numer_indeksu++;
        }
        else if(znak_poziomu == ')')
        {
            poziom++;
            numer_indeksu++;
        }
        else if(znak_poziomu == '*')
        {
            numer_indeksu++;
            pod_jakim_indeksem_jaki_poziom[numer_indeksu] = poziom;
            liczba_skarbow_na_konkretnym_poziomie[abs(poziom)]++;
        }
    }

//----------------------------------------------------------------------------
    //KODY NA WYSWIETLENIE TABLIC WEKTOROWYCH PO PRZYPORZADKOWANIU IM LICZB
    /*
    cout << "----------------------" << endl;
    //wyswietla pierwsza tablice
    cout << "Pierwsza tablica: " << endl;
    for( int i = 0; i < pod_jakim_indeksem_jaki_poziom.size(); i++ )
    {
        cout << pod_jakim_indeksem_jaki_poziom[i] << endl;
    }

    //wyswietla druga tablice
    cout << "Druga tablica: " << endl;
    for( int i = 0; i < liczba_skarbow_na_konkretnym_poziomie.size(); i++ )
    {
        cout << liczba_skarbow_na_konkretnym_poziomie[i] << endl;
    }
    cout << "----------------------" << endl;
    */
//----------------------------------------------------------------------------


    //ZNAJDUJEMY POZIOM NA KTORYM ZNAJDUJE SIE NAJWIECEJ SKARBOW
    cout << endl;
    cout << endl;
    cout << "Znajdujemy poziom, na ktorym znajduje sie najwiecej skarbow: " << endl;
    int pMax = 0;   //przechowuje najwieksza ilosc skarbow z danego poziomu
    int poziom_max; //przechowuje informacje o tym na ktorym poziomie jest najwiecej skarbow
    for( int i = 0; i < liczba_skarbow_na_konkretnym_poziomie.size(); i++ )
    {
        if(liczba_skarbow_na_konkretnym_poziomie[i] > pMax)
        {
            pMax = liczba_skarbow_na_konkretnym_poziomie[i];
            poziom_max = i;
            cout << "obecna maksymalna: " << pMax << " poziom: " << i << endl;
        }
        else if(liczba_skarbow_na_konkretnym_poziomie[i] == pMax) // 2 = 2
        {
            int przeciwna_liczba_pierwsza = -1 * poziom_max; // = -2
            int przeciwna_liczba_druga = -1 * i; // -3
            int zwrocony_najmniejszy_indeks_1;
            int zwrocony_najmniejszy_indeks_2;

            //ZNAJDUJEMY NAJMNIEJSZY INDEKS PIERWSZEGO Z POZIOMOW
            for( int j = 0; j < pod_jakim_indeksem_jaki_poziom.size(); j++ )
            {
                if(pod_jakim_indeksem_jaki_poziom[j] == przeciwna_liczba_pierwsza) // -2 = -2
                {
                    cout << "Najmniejszy indeks pierwszego z poziomow: " << j << endl;
                    zwrocony_najmniejszy_indeks_1 = j;
                    break;
                }
            }

            //ZNAJDUJEMY NAJMNIEJSZY INDEKS DRUGIEGO Z POZIOMOW
            for( int k = 0; k < pod_jakim_indeksem_jaki_poziom.size(); k++ )
            {
                if(pod_jakim_indeksem_jaki_poziom[k] == przeciwna_liczba_druga)
                {
                    cout << "Najmniejszy indeks drugiego z poziomow: " <<k << endl;
                    zwrocony_najmniejszy_indeks_2 = k;
                    break;
                }
            }

            //SPRAWDZAMY NA KTORYM Z POZIOMOW JEST MNIEJSZY INDEKS
            if(zwrocony_najmniejszy_indeks_1 > zwrocony_najmniejszy_indeks_2)
            {
                cout << "zamiana ";
                pMax = liczba_skarbow_na_konkretnym_poziomie[i];
                poziom_max = i;
            }
        }
    }
    cout << "Najwiecej skarbow jest na poziomie: -" << poziom_max << endl;

    int przeciwna_liczba = -1 * poziom_max;

    //ZNAJDUJEMY NAJMNIEJSZY INDEKS
    cout << "Wyswietla indeksy liczb z poziomu na ktorym jest najwiecej liczb: " << endl;
    for( int i = 0; i < pod_jakim_indeksem_jaki_poziom.size(); i++ )
    {
        if(pod_jakim_indeksem_jaki_poziom[i] == przeciwna_liczba)
        {
            cout << "indeks = : " << i << endl;
            cout << "indeks = : " << i << endl;
            return i;
            break;
        }
    }
}

int main()
{
    string droga;
    cout << "Podaj droge: ";
    cin >> droga;
    cout << "indeks wynosi: " << v(droga) << endl;
    cout << endl;
    cout << "***KONIEC***" << endl;

    return 0;
}
