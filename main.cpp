/*

            Robert Protocol Algorithm - DIALLO Fatoumata et TORRES Lyam

 */

#include <iostream>
#include "main.h"

using namespace std;

int main() {
    ListeChainee liste;

    liste = initialiser('A');
    afficherListe(liste);
    insererEnQueue(liste, 'B');
    afficherListe(liste);

    return 0;
}

ListeChainee initialiser(char d) {
    ListeChainee nouvelleListe;
    Maillon *premierMaillon = new Maillon;

    premierMaillon->donnees = d;
    premierMaillon->suivant = nullptr;

    nouvelleListe.tete = premierMaillon;
    nouvelleListe.queue = premierMaillon;
    nouvelleListe.nombreElements = 1;

    return nouvelleListe;
}

void afficherListe(ListeChainee l) {
    Maillon *actuel = l.tete;

    cout << "Tête -> ";
    while (actuel != nullptr) {
        cout << actuel->donnees << " -> ";
        actuel = actuel->suivant;
    }
    cout << "NULL" << endl;
}

void insererEnTete(ListeChainee &l, char d) {
    Maillon *nouveauMaillon = new Maillon;

    nouveauMaillon->donnees = d;
    nouveauMaillon->suivant = l.tete;

    l.tete = nouveauMaillon;
    l.nombreElements += 1;
}

void insererEnQueue(ListeChainee &l, char d) {
    Maillon *nouveauMaillon = new Maillon;

    nouveauMaillon->donnees = d;
    nouveauMaillon->suivant = nullptr;
    if(l.nombreElements = 0) {
        l.tete = nouveauMaillon;
    } else {
        l.queue->suivant = nouveauMaillon;
    }
}

void supprimerEnTete(ListeChainee &l) {
    Maillon *aSupprimer = l.tete;

    l.tete = l.tete->suivant;
    delete aSupprimer;
    l.nombreElements -= 1;
}

void supprimerEnQueue(ListeChainee &l) {
    
}