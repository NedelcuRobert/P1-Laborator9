#include "matrice.h"

int main()
{
    int ch = 0;
    ifstream fin;
    ofstream fout;

    mat<CComplex> m1, m2, m3;
    do
    {
        cout << "\n***MENIU***\n1-Creare\n2-Afisare\n3-Restaurare\n4-Adunare\n5-Scadere\n6-Inmultire\n7-Ridicare putere\n8-Salvare\n9-Iesire\nOptiunea dvs.: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Creare matrice\n";
            cout << "Prima matrice:\n";
            m1.creare();
            cout << "A doua matrice:\n";
            m2.creare();
            break;

        case 2:
            cout << "Afisare\n";
            m1.afisare();
            m2.afisare();
            break;
        case 3:
            cout << "Restaurare\n";
            m1.restaurare(fin);
            break;
        case 4:
            cout << "Adunare\n";
            m3 = m1 + m2;
            m3.afisare();
            break;

        case 5:
            cout << "Scadere\n";
            m3 = m1 - m2;
            m3.afisare();
            break;
        case 6:
            cout << "Inmultire\n";
            m3 = m1 * m2;
            m3.afisare();
            break;
        case 7:
            cout << "Ridicare putere\n";
            int dim;
            cout << "La a cata putere:";
            cin >> dim;
            m3 = m2 ^ dim;
            m3.afisare();  
        case 8:
            cout << "Salvare\n";
            m1.salvare(fout);
            break;
        case 9:
            break;
        default:
            cout << "Optiunea dvs.:\n";
        }
    } while (ch != 9);
    return 0;
}