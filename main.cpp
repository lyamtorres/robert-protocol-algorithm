/*

            Robert Protocol Algorithm - DIALLO Fatoumata et TORRES Lyam

 */

#include <iostream>
#include "main.h"

using namespace std;

int main() {
    ListeChainee liste;

    liste = initialiser();

    return 0;
}

ListeChainee initialiser() {
    ListeChainee nouvelleListe;
    Maillon *nouveauMaillon = new Maillon;

    nouveauMaillon->data = "";
    nouveauMaillon->suivant = nullptr;

    nouvelleListe.tete->data;
    nouvelleListe.queue->data;
    nouvelleListe.nombreElements = 1;

    return nouvelleListe;
}

void afficherListe(ListeChainee l) {
    Maillon *actuel = l.tete;

    while (actuel != nullptr) {
        cout << actuel->data << " -> ";
        actuel = actuel->suivant;
    }
    cout << "NULL" << endl;
}

void insererEnTete(ListeChainee &l) {
    Maillon *nouveauMaillon = new Maillon;

    nouveauMaillon->data = "";
    nouveauMaillon->suivant = nullptr;

    l.tete = nouveauMaillon;
    l.nombreElements += 1;
}

void supprimerEnTete(ListeChainee &l) {
    Maillon *aSupprimer = l.tete;

    l.tete = l.tete->suivant;
    delete aSupprimer;
    l.nombreElements -= 1;
}