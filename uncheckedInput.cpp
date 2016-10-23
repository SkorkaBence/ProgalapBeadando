/*
GitHub: http://github.com/SkorkaBence/ProgalapBeadando
*/
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

    cin >> tanulokSzama;

    for (int i = 0; i < tanulokSzama; i++) {
        atment[i] = false;
    }

    cin >> versenyekSzama;

    for (int i = 0; i < versenyekSzama; i++) {
        cin >> minimumPontszamok[i];
    }

    for (int i = 0; i < versenyekSzama; i++) {
        int indultTanulokSzama;
        cin >> indultTanulokSzama;
        for (int j = 0; j < indultTanulokSzama; j++) {
            int tanuloid;
            int pontszam;
            cin >> tanuloid;
            cin >> pontszam;

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
    }
    cout << num;
    for (int i = 0; i < tanulokSzama; i++) {
        if (!atment[i]) {
            cout << " " << (i+1);
        }
    }

    return 0;
}
