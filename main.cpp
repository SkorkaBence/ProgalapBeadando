#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int maxN = 256;
    int versenyekSzama = 0;
    int tanulokSzama = 0;
    int minimumPontszamok[maxN] = {};
    bool atment[maxN] = {};

    bool hiba = false;
    do {
        //cerr << "Add meg a tanulok szamat!" << endl;
        cin >> tanulokSzama;
        hiba = cin.fail();
        if (!hiba) {
            if ((tanulokSzama < 0) || (tanulokSzama > maxN)) {
                hiba = true;
            }
        }
        if (hiba) {
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Hibas!" << endl;
        }
    } while (hiba);

    for (int i = 0; i < tanulokSzama; i++) {
        atment[i] = false;
    }

    do {
        //cerr << "Add meg a versenyek szamat!" << endl;
        cin >> versenyekSzama;
        hiba = cin.fail();
        if (!hiba) {
            if ((versenyekSzama < 0) || (versenyekSzama > maxN)) {
                hiba = true;
            }
        }
        if (hiba) {
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Hibas!" << endl;
        }
    } while (hiba);

    for (int i = 0; i < versenyekSzama; i++) {
        do {
            //cerr << "Add meg a " << (i+1) << ". verseny minimum pontszamat!" << endl;
            cin >> minimumPontszamok[i];
            hiba = cin.fail();
            if (!hiba) {
                if (minimumPontszamok[i] < 0) {
                    hiba = true;
                }
            }
            if (hiba) {
                cin.clear();
                cin.ignore(1000, '\n');
                cerr << "Hibas!" << endl;
            }
        } while (hiba);
    }

    for (int i = 0; i < versenyekSzama; i++) {
        int indultTanulokSzama;
        do {
            //cerr << "Add meg az indult tanulok szamat!" << endl;
            cin >> indultTanulokSzama;
            hiba = cin.fail();
            if (!hiba) {
                if ((indultTanulokSzama < 0) || (indultTanulokSzama > tanulokSzama)) {
                    hiba = true;
                }
            }
            if (hiba) {
                cin.clear();
                cin.ignore(1000, '\n');
                cerr << "Hibas!" << endl;
            }
        } while (hiba);
        for (int j = 0; j < indultTanulokSzama; j++) {
            int tanuloid;
            int pontszam;

            do {
                //cerr << "Add meg a tanulo azonositot!" << endl;
                cin >> tanuloid;
                hiba = cin.fail();
                if (!hiba) {
                    if ((tanuloid < 1) || (tanuloid > tanulokSzama)) {
                        hiba = true;
                    }
                }
                if (hiba) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cerr << "Hibas!" << endl;
                }
            } while (hiba);

            do {
                //cerr << "Add meg az elert pontot!" << endl;
                cin >> pontszam;
                hiba = cin.fail();
                if (!hiba) {
                    if (pontszam < 0) {
                        hiba = true;
                    }
                }
                if (hiba) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cerr << "Hibas!" << endl;
                }
            } while (hiba);

            if (minimumPontszamok[i] <= pontszam) {
                atment[tanuloid-1] = true;
            }
        }
    }

    int num = 0;
    for (int i = 0; i < tanulokSzama; i++) {
        if (!atment[i]) {
            num++;

    }
    cout << num;
    for (int i = 0; i < tanulokSzama; i++) {
        if (!atment[i]) {
            cout << " " << (i+1);
        }
    }

    return 0;
}
