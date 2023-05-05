//
// Created by Lucian Cojocaru on 05.05.2023.
//
// O agenție de turism gestionează N trasee turistice, numerotate de la 1 la N. Pentru a determina cel mai popular traseu au fost analizate ultimele K excursii de pe fiecare traseu. Cel mai popular este considerat traseul, pentru care numărul total de turiști în aceste K excursii este maximal. Datele despre turiști sunt stocate în tabloul T cu N linii și K coloane. Elementul T[i,j] reprezintă numărul de turiști de pe traseul i și excursia j.

//Sarcină: Elaborați un program care determină cel mai popular traseu turistic. Programul va conține un subprogram cu numele NT, care va primi în calitate de parametru un număr întreg i – indicele traseului și va întoarce numărul total de turiști în K excursii pe traseul i.

//Intrare: Fișierul text turist.in conține în prima linie două numere întregi - numărul de trasee turistice N(1≤N≤8) și numărul de excursii K(1≤K≤10). Fiecare din următoarele N linii conțin câte K numere întregi separate prin spațiu – elementele tabloului T. Numărul cu indicile j din linia i+1 este valoare elementului T[i,j].

//Ieșire: Fișierul text turist.out conține într-o linie două numere întregi separate prin spațiuindicele celui mai popular traseu turistic și numărul total de turiști în K excursii pe traseul dat.

//Notă. Nu sunt două trasee turistice cu același număr total de turiști în ultimele K excursii.

#include <iostream>
#include <fstream>

using namespace std;

int n, k;
int T[8][10];

int nt(int i) {
    int sum = 0;
    for (int j = 0; j < k; j++) {
        sum += T[i][j];
    }
    return sum;
}

int main() {
    ifstream in("turist.in");
    ofstream out("turist.out");

    in >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            in >> T[i][j];
        }
    }

    int rutaPopulară = 0;
    int maxTuriști = nt(0);

    for (int i = 1; i < n; i++) {
        int turiști = nt(i);
        if (turiști > maxTuriști) {
            maxTuriști = turiști;
            rutaPopulară = i;
        }
    }

    out << rutaPopulară + 1 << " " << maxTuriști << endl;

    in.close();
    out.close();

    return 0;
}

