#include <iostream>
#include <windows.h>

using namespace std;

int v( const std::string &pWorld )
{
    //stworzenie przykladowej mapy za pomoca tablicy dwuwymiarowej wielkosci 9x9
    string mapa[9][9] =
    {

        {"[0,0]", "", "[0,2]", "", "[0,4]", "", "[0,6]", "", "[0,8]"},
        {"", "[1,1]", "", "[1,3]", "", "[1,5]", "", "[1,7]",""},
        {"[2,0]", "", "[2,2]", "", "[2,4]", "", "[2,6]", "", "[2,8]"},
        {"", "[3,1]", "", "[3,3]", "", "[3,5]", "", "[3,7]",""},
        {"[4,0]", "", "[4,2]", "", "[4,4]", "", "[4,6]", "", "[4,8]"},
        {"", "[5,1]", "", "[5,3]", "", "[5,5]", "", "[5,7]",""},
        {"[6,0]", "", "[6,2]", "", "[6,4]", "", "[6,6]", "", "[6,8]"},
        {"", "[7,1]", "", "[7,3]", "", "[7,5]", "", "[7,7]",""},
        {"[8,0]", "", "[8,2]", "", "[8,4]", "", "[8,6]", "", "[8,8]"}
    };

    //oznaczenie srodka kolumny pierwszej przez S (Start)
    mapa[4][0] = "S";
    cout << "Obecna pozycja: " << mapa[4][0] << endl;
    cout << endl;

    //wyswietlenie mapy
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; ++col)
            cout << mapa[row][col] << "     ";
        cout << endl;
        cout << endl;
        cout << endl;
    }

    Sleep(3000);
    system("cls");

    int N; // numer kolumny w ktorej znajdzie sie pierwszy skarb

    //obecna pozycja poczatkowa
    int y = 4;
    int x = 0;

    //petla for umozliwiacaja poruszanie sie po mapie
    char znak; //zmienna pobierajaca kazdy znak zmiennej referencyjnej pWorld
    for(int i = 0; i < pWorld.size(); i++)
    {
        system("cls");

        znak = pWorld[i];
        if(znak == '(')
        {
            y += 1;
            x += 1;
        }
        else if(znak == ')')
        {
            y -= 1;
            x += 1;
        }
        else if(znak == '*')
        {
            cout << "Obecna pozycja: " << mapa[y][x] << endl;
            cout << endl;
            for (int row = 0; row < 9; row++)
            {
                for (int col = 0; col < 9; ++col)
                    cout << mapa[row][col] << "     ";
                cout << endl;
                cout << endl;
                cout << endl;
            }

            cout << "Znaleziono skarb w kolumnie: " << x << "!" << endl;
            N = x;
            Sleep(5000);
            break;
        }

        cout << "Obecna pozycja: " << mapa[y][x] << endl;
        cout << endl;

        //wyswietlenie mapy
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; ++col)
                cout << mapa[row][col] << "     ";
            cout << endl;
            cout << endl;
            cout << endl;
        }
        Sleep(4000);
    }
    cout << "Pozycja koncowa: " << mapa[y][x] << endl;
    cout << "Pierwszy znaleziony skarb dla N = " << N << endl;
}

int main()
{
    string droga;
    cout << "Podaj droge: ";
    cin >> droga;
    cout << endl;
    v(droga);

    return 0;
}
