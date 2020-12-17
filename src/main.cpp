/*

            Robert Protocol Algorithm - DIALLO Fatoumata et TORRES Lyam

 */

#include <iostream>
#include <random>
#include <ctime> 
#include "main.h"

using namespace std;

int main() {
    srand(time(0));
    
    const int seuil = 4;

    Telephone premierTelephone;
    premierTelephone = initialiserTelephone(5);
    afficherListe(premierTelephone);
    supprimerPseudoFin(premierTelephone);
    supprimerPseudoFin(premierTelephone);
    afficherListe(premierTelephone);
    rechargerListe(premierTelephone, seuil);
    afficherListe(premierTelephone);
    
    return 0;
}

Telephone initialiserTelephone(int memoire) {
    const int seuil = 4;
    Telephone nouveauTelephone;
    
    nouveauTelephone.capacite = memoire;
    nouveauTelephone.espaceOccupe = 0;
    for (int i = 0; i < nouveauTelephone.capacite; i++) {
        insererPseudoFin(nouveauTelephone);
    }

    return nouveauTelephone;
}

void afficherListe(Telephone tel) {
    Pseudo *actuel = tel.tete;

    cout << "Tête -> ";
    while (actuel != nullptr) {
        cout << actuel->valeur << " -> ";
        actuel = actuel->suivant;
    }
    cout << "NULL" << endl;
}

void rechargerListe(Telephone &tel, int seuil) {
    if (tel.espaceOccupe < seuil) {
        while (tel.espaceOccupe != tel.capacite) {
            insererPseudoFin(tel);
        }
    }
}

// Complexité temporelle : Constante = O(1)
void insererPseudoAvant(Telephone &tel) {
    Pseudo *nouveauPseudo = new Pseudo;

    nouveauPseudo->valeur = donnerPseudonyme();
    nouveauPseudo->suivant = nullptr;
    if (tel.espaceOccupe == 0) {
        tel.tete = nouveauPseudo;
        tel.queue = nouveauPseudo;
    } else {
        nouveauPseudo->suivant = tel.tete;
        tel.tete = nouveauPseudo;
    }   
    tel.espaceOccupe++;
}

// Complexité temporelle : Constante = O(1)
void insererPseudoFin(Telephone &tel) {
    Pseudo *nouveauPseudo = new Pseudo;

    nouveauPseudo->valeur = donnerPseudonyme();
    nouveauPseudo->suivant = nullptr;
    if (tel.espaceOccupe == 0) {
        tel.tete = nouveauPseudo;
        tel.queue = nouveauPseudo;
    } else {
        tel.queue->suivant = nouveauPseudo;
        tel.queue = nouveauPseudo;
    }
    tel.espaceOccupe++;
}

// Complexité temporelle : Constante = O(1)
void supprimerPseudoDebut(Telephone &tel) {
    Pseudo *aSupprimer = tel.tete;

    tel.tete = tel.tete->suivant;
    delete aSupprimer;
    tel.espaceOccupe--;
}

// Complexité temporelle : Lineaire = O(n)
void supprimerPseudoFin(Telephone &tel) {
    Pseudo *actuel = tel.tete;
    Pseudo *aSupprimer = tel.queue;

    while (actuel->suivant != tel.queue) {
        actuel = actuel->suivant;
    }
    tel.queue = actuel;
    actuel->suivant = nullptr;
    delete aSupprimer;
    tel.espaceOccupe--;
}

string donnerPseudonyme() {
  string pseudonyme = "";
  char consonne[20] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
  char voyelle[6] = {'a','e','i','o','u','y'};

  for (int i = 0; i < 2; i++){                    
    pseudonyme = pseudonyme + consonne[rand() % 20];    
    pseudonyme = pseudonyme + voyelle[rand() % 6];      
  }
  for (int i = 0; i < 2; i++){                   
    pseudonyme = pseudonyme + to_string(rand() % 9);      
  }
  return pseudonyme;
}
