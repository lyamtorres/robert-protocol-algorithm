/*

            Robert Protocol Algorithm - DIALLO Fatoumata et TORRES Lyam

 */

#include <iostream>
#include "main.h"

using namespace std;

int main() {
    ListeChainee premiereliste;

// Test pour insererAvant
    premiereliste = initialiser('C');
    insererAvant(premiereliste, 'B');
    insererAvant(premiereliste, 'A');
    afficherListe(premiereliste);

    supprimerFin(premiereliste);
    afficherListe(premiereliste);
    

    return 0;
}

ListeChainee initialiser(char d) {
    ListeChainee nouvelleListe;
    Maillon *premierMaillon = new Maillon;

    premierMaillon->donnee = d;
    premierMaillon->suivant = nullptr;

    nouvelleListe.tete = premierMaillon;
    nouvelleListe.queue = premierMaillon;
    nouvelleListe.nombreElements = 1;

    return nouvelleListe;
}

void afficherListe(ListeChainee liste) {
    Maillon *actuel = liste.tete;

    cout << "Tête -> ";
    while (actuel != nullptr) {
        cout << actuel->donnee << " -> ";
        actuel = actuel->suivant;
    }
    cout << "NULL" << endl;
}

// Complexité temporelle : Constante = O(1)
void insererAvant(ListeChainee &liste, char d) {
    Maillon *nouveauMaillon = new Maillon; // +2

    nouveauMaillon->donnee = d; // +2
    nouveauMaillon->suivant = liste.tete; // +3

    liste.tete = nouveauMaillon; // +2
    liste.nombreElements++;
}

// Complexité temporelle : Constante = O(1)
void insererFin(ListeChainee &liste, char d) {
    Maillon *nouveauMaillon = new Maillon;

    nouveauMaillon->donnee = d;
    nouveauMaillon->suivant = nullptr;
    liste.queue->suivant = nouveauMaillon;
    liste.queue = nouveauMaillon;
    liste.nombreElements++;
}

// Complexité temporelle : Constante = O(1)
void supprimerDebut(ListeChainee &liste) {
    Maillon *aSupprimer = liste.tete;

    liste.tete = liste.tete->suivant;
    delete aSupprimer;
    liste.nombreElements--;
}

// Complexité temporelle : Lineaire = O(n)
void supprimerFin(ListeChainee &liste) {
    Maillon *actuel = liste.tete;
    Maillon *aSupprimer = liste.queue;

    while (actuel->suivant != liste.queue) {
        actuel = actuel->suivant;
    }
    liste.queue = actuel;
    actuel->suivant = nullptr;
    delete aSupprimer;
    liste.nombreElements--;
}