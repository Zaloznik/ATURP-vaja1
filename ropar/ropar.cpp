// ropar.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Jaka Zaloznik

#include <iostream>;
#include <fstream>;
#include <string>;

using namespace std;

int main(int argc, char* argv[])
{
    bool resitvaNajdena = false;
    int stPalc = 0, stPalcNaZacetku = 0, stPalcVmes = 0;
    int stRoparjev = 0, stKorakov = 0;
    ifstream file(argv[1]);
    string str;
    while (getline(file, str))
    {
        stPalcNaZacetku = stoi(str);
        if (stPalcNaZacetku == -1)
        {
            break;
        }
        resitvaNajdena = false;
        //i = st roparjev
        for (int i = stPalcNaZacetku/8; i > 1; i--)
        {
            stPalc = stPalcNaZacetku;
            stKorakov = 0;
            stRoparjev = i;
            while (stPalc % i == 1)
            {
                stPalc = stPalc - (stPalc / stRoparjev + 1);
                stKorakov++;
            }
            if (stPalc % i == 0 && stKorakov == stRoparjev)
            {
                resitvaNajdena = true;
                cout << "st. zlatih palic: " << stPalcNaZacetku << " - st. roparjev: " << stRoparjev << endl;
                break;
            }
        }
        if (!resitvaNajdena)
        {
            cout << "st. zlatih palic: " << stPalcNaZacetku << " - ni resitve!" << endl;
        }
    }
}