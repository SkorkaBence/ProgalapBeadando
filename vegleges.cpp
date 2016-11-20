/*
GitHub: http://github.com/SkorkaBence/ProgalapBeadando
*/
#include <iostream>
#include <string>

using namespace std;

const int maxN = 256;

struct Tanulo {
public:
    bool sikerultEgyVerseny = false;
};

struct Verseny {
public:
    int minimumPontszam;
};

int main()
{
    // adatokat tároló változók
    int versenyekSzama;
    int tanulokSzama;
    Verseny versenyek[maxN];
    Tanulo tanulok[maxN];
    // egyéb változók
    int minimumPontszam;
    int indultTanulokSzama;
    int tanuloid;
    int pontszam;
    int szamolas;

    // tanulók számának bekérdezése, és a változókat tároló tömb előkészítése
    cin >> tanulokSzama;
    for (int i = 0; i < tanulokSzama; i++) {
        tanulok[i] = Tanulo();
    }

    // versenyek számának bekérdezése, és a versenyeket tároló tömb előkészítése, majd feltöltése a minimum pontszámokkal
    cin >> versenyekSzama;
    for (int i = 0; i < versenyekSzama; i++) {
        cin >> minimumPontszam;
        versenyek[i] = Verseny();
        versenyek[i].minimumPontszam = minimumPontszam;
    }

    // a versenyek adatainak bekérdezése
    for (int i = 0; i < versenyekSzama; i++) {
        // hányan indultak a versenyen
        cin >> indultTanulokSzama;
        for (int j = 0; j < indultTanulokSzama; j++) {
            // a versenyen induló pontszámainak bekérdezése
            cin >> tanuloid;
            cin >> pontszam;

            if (pontszam >= versenyek[i].minimumPontszam) { // elérte a minimum pontszámot?
                // sikerült neki!
                tanulok[tanuloid-1].sikerultEgyVerseny = true;
            }
        }
    }

    szamolas = 0;
    // hány tanuló nem érte el a minimum pontot?
    for (int i = 0; i < tanulokSzama; i++) {
        if (!tanulok[i].sikerultEgyVerseny) {
            szamolas++;
        }
    }

    // eredmény kiírása
    cout << szamolas;
    for (int i = 0; i < tanulokSzama; i++) {
        if (!tanulok[i].sikerultEgyVerseny) {
            cout << " " << i + 1;
        }
    }

    return 0;
}
