/*
GitHub: http://github.com/SkorkaBence/ProgalapBeadando
*/
#include <iostream>

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

// beolvasó algoritmusok
void integerBeolvasas(int &N);
void integerBeolvasas_Min(int &N, int minimum);
void integerBeolvasas_MinMax(int &N, int minimum, int maximum);

// feladatmegoldás lépéseit tartalmazó algoritmusok
void beolvasas(Verseny versenyek[], Tanulo tanulok[maxN], int &versenyekSzama, int &tanulokSzama);
void eredmeny(const Verseny versenyek[], const Tanulo tanulok[maxN], int versenyekSzama, int tanulokSzama);

int main()
{
    // adatokat tároló változók
    int versenyekSzama;
    int tanulokSzama;
    Verseny versenyek[maxN];
    Tanulo tanulok[maxN];

    beolvasas(versenyek, tanulok, versenyekSzama, tanulokSzama);
    eredmeny(versenyek, tanulok, versenyekSzama, tanulokSzama);

    return 0;
}

void integerBeolvasas(int &N) {
    bool hiba = false;
    do {
        cin >> N;
        hiba = cin.fail();
        if (hiba) {
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Hibas bemenet, egesz szám szukseges!" << endl;
        }
    } while (hiba);
}

void integerBeolvasas_Min(int &N, int minimum) {
    bool hiba = false;
    do {
        cin >> N;
        hiba = cin.fail();
        if (!hiba) {
            if (N < minimum) {
                hiba = true;
            }
        }
        if (hiba) {
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Hibas bemenet, egesz szam szukseges, amely minimum " << minimum << "!" << endl;
        }
    } while (hiba);
}

void integerBeolvasas_MinMax(int &N, int minimum, int maximum) {
    bool hiba = false;
    do {
        cin >> N;
        hiba = cin.fail();
        if (!hiba) {
            if ((N < minimum) || (N > maximum)) {
                hiba = true;
            }
        }
        if (hiba) {
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Hibas bemenet, egesz szam szukseges, amely minimum " << minimum << " es maximum " << maximum << "!" << endl;
        }
    } while (hiba);
}

void beolvasas(Verseny versenyek[], Tanulo tanulok[maxN], int &versenyekSzama, int &tanulokSzama) {
    // egyéb változók
    int minimumPontszam;
    int indultTanulokSzama;
    int tanuloid;
    int pontszam;

    // tanulók számának bekérdezése, és a változókat tároló tömb előkészítése
    cerr << "Tanulok szama: ";
    integerBeolvasas_MinMax(tanulokSzama, 0, maxN);
    for (int i = 0; i < tanulokSzama; i++) {
        tanulok[i] = Tanulo();
    }

    // versenyek számának bekérdezése, és a versenyeket tároló tömb előkészítése, majd feltöltése a minimum pontszámokkal
    cerr << "Versenyek szama: ";
    integerBeolvasas_MinMax(versenyekSzama, 0, maxN);
    for (int i = 0; i < versenyekSzama; i++) {
        cerr << (i+1) << ". verseny minimum pontszama: ";
        integerBeolvasas_Min(minimumPontszam, 0);
        versenyek[i] = Verseny();
        versenyek[i].minimumPontszam = minimumPontszam;
    }

    // a versenyek adatainak bekérdezése
    for (int i = 0; i < versenyekSzama; i++) {
        // hányan indultak a versenyen
        cerr << "Hanyan indultak az " << (i+1) << ". versenyen? ";
        integerBeolvasas_MinMax(indultTanulokSzama, 0, tanulokSzama);
        for (int j = 0; j < indultTanulokSzama; j++) {
            // a versenyen induló pontszámainak bekérdezése
            cerr << (i+1) << ". verseny " << (j+1) << ". indulojanak azonositoja: ";
            integerBeolvasas_MinMax(tanuloid, 1, tanulokSzama + 1);
            cerr << "Es pontszama: ";
            integerBeolvasas_Min(pontszam, 0);

            if (pontszam >= versenyek[i].minimumPontszam) { // elérte a minimum pontszámot?
                // sikerült neki!
                tanulok[tanuloid-1].sikerultEgyVerseny = true;
            }
        }
    }
}

void eredmeny(const Verseny versenyek[], const Tanulo tanulok[maxN], int versenyekSzama, int tanulokSzama) {
    int szamolas = 0;
    // hány tanuló nem érte el a minimum pontot?
    for (int i = 0; i < tanulokSzama; i++) {
        if (!tanulok[i].sikerultEgyVerseny) {
            szamolas++;
        }
    }

    // eredmény kiírása
    cerr << endl << "Minimum pontszamot sehol el nem erok szama: ";
    cout << szamolas;
    cerr << endl << "Es az azonositoik:";
    for (int i = 0; i < tanulokSzama; i++) {
        if (!tanulok[i].sikerultEgyVerseny) {
            cout << " " << i + 1;
        }
    }
}
