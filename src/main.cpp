/*

            Robert Protocol Algorithm - DIALLO Fatoumata et TORRES Lyam

*/

#include <iostream>
#include <random>
#include <ctime> 
#include "main.h"

using namespace std;

const int joursDuMois[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 

int main() {
            // QUESTION 4 - PROGRAMME PRINCIPAL


    Utilisateur charles, alice;

    charles.monTel = initialiserTelephone(5);
    alice.monTel = initialiserTelephone(5);

    cout << "Pseudos Charles : ";
    afficherListe(charles.monTel);
    cout << "Pseudos Alice : ";
    afficherListe(alice.monTel);

    alice.maListe.tete = nullptr;
    integrerContacts(alice.maListe, 2, 11, 2020);
    integrerContacts(alice.maListe, 7, 11, 2020);
    cout << "Contacts Alice : ";
    afficherContacts(alice.maListe);

    ListeDeContacts listeGlobale;

    listeGlobale.tete = nullptr;
    fusionnerListes(listeGlobale, alice.maListe, false);
    cout << "Application centrale: ";
    afficherContacts(listeGlobale);

    return 0;
}

ListeChainee initialiser() {
    ListeChainee nouvelleListe;
    Maillon *nouveauMaillon = new Maillon;

    nouveauMaillon->valeur = 'A';
    nouveauMaillon->suivant = nullptr;
    nouvelleListe.tete = nouveauMaillon;
    nouvelleListe.queue = nouveauMaillon;

    return nouvelleListe;
}

void afficher(ListeChainee liste) {
    Maillon *actuel = liste.tete;

    cout << "Tête -> ";
    while (actuel != nullptr) {
        cout << actuel->valeur << " -> ";
        actuel = actuel->suivant;
    }
    cout << "NULL" << endl;
}

void insererDebut(ListeChainee &liste) {
    Maillon *nouveauMaillon = new Maillon;

    nouveauMaillon->valeur = 'B';
    nouveauMaillon->suivant = liste.tete;
    liste.tete = nouveauMaillon;
}

void insererFin(ListeChainee &liste) {
    Maillon *nouveauMaillon = new Maillon;

    nouveauMaillon->valeur = 'B';
    nouveauMaillon->suivant = nullptr;
    liste.queue->suivant = nouveauMaillon;
    liste.queue = nouveauMaillon;
}

void supprimerDebut(ListeChainee &liste) {
    Maillon *aSupprimer = liste.tete;

    liste.tete = liste.tete->suivant;
    delete aSupprimer;
}

void supprimerFin(ListeChainee &liste) {
    Maillon *actuel = liste.tete;
    Maillon *aSupprimer = liste.queue;

    while (actuel->suivant != liste.queue) {
        actuel = actuel->suivant;
    }
    liste.queue = actuel;
    actuel->suivant = nullptr;
    delete aSupprimer;
}

Telephone initialiserTelephone(int memoire) {
    Telephone nouveauTelephone;
    
    nouveauTelephone.capacite = memoire;
    nouveauTelephone.espaceOccupe = 0;
    for (int i = 0; i < nouveauTelephone.capacite; i++) {
        insererPseudo(nouveauTelephone);
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
            insererPseudo(tel);
        }
    }
}

void insererPseudo(Telephone &tel) {
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

void supprimerPseudo(Telephone &tel) {
    Pseudo *aSupprimer = tel.tete;

    tel.tete = tel.tete->suivant;
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

void integrerContacts(ListeDeContacts &liste, int jour, int mois, int annee) {
    Contact nouveauContact;
    int contactsDuJour = rand() % 20;

    for (int i = 0; i < contactsDuJour; i++) {
        nouveauContact.pseudo1 = donnerPseudonyme();
        nouveauContact.pseudo2 = donnerPseudonyme();
        nouveauContact.date.jour = jour;
        nouveauContact.date.mois = mois;
        nouveauContact.date.an = annee;
        genererContact(liste, nouveauContact);
    }
}

void genererContact(ListeDeContacts &liste, Contact cont) {
    MaillonContact *nouveauMaillon;
    
    nouveauMaillon = new MaillonContact;
    nouveauMaillon->contact = cont;
    nouveauMaillon->suivant = nullptr;
    insererContact(liste, nouveauMaillon);
}

void insererContact(ListeDeContacts &liste, MaillonContact *maille) {
    MaillonContact *actuel; // actuel correspond à l'élément où l'on est positionés dans la liste

    if (liste.tete == nullptr) {
        liste.tete = maille;
    } else {
        actuel = liste.tete;
        while (actuel->suivant != nullptr) {
            actuel = actuel->suivant;
        }
        actuel->suivant = maille;
    }
}

void supprimerContacts(ListeDeContacts &liste, Date date) {
    MaillonContact *aSupprimer;
    int nombreJours = calculerDifference(liste.tete->contact.date, date);
    
    do {
        aSupprimer = liste.tete;
        liste.tete = liste.tete->suivant;
        delete aSupprimer;
        nombreJours = calculerDifference(liste.tete->contact.date, date);
    } while (nombreJours > 14);

}

int calculerDifference(Date date1, Date date2) {
    long int n1 = date1.an * 365 + date1.jour;

    for (int i = 0; i < date1.mois - 1; i++)
        n1 += joursDuMois[i];
    n1 += nombrerAnneeBinaire(date1);
 
    long int n2 = date2.an * 365 + date2.jour;

    for (int i = 0; i < date2.mois - 1; i++)
        n2 += joursDuMois[i];
    n2 += nombrerAnneeBinaire(date2);
 
    return (n2 - n1);
}

int nombrerAnneeBinaire(Date date) {
    int annee = date.an;
 
    if (date.mois <= 2)
        annee--;

    return annee / 4 - annee / 100 + annee / 400;
}

void afficherContacts(ListeDeContacts liste) {
    MaillonContact *actuel = liste.tete;

    cout << "Tête -> ";
    while (actuel != nullptr) {
        cout << actuel->contact.pseudo1 << " -> ";
        actuel = actuel->suivant;
    }
    cout << "NULL" << endl;
}

void fusionnerListes(ListeDeContacts &listeAppli, ListeDeContacts listeContacts, bool estMalade) {
    MaillonContact *actuel;

    if (listeAppli.tete == nullptr) {
        listeAppli.tete = listeContacts.tete; 
    } else {
        actuel = listeAppli.tete;
        while (actuel->suivant != nullptr) {
            actuel = actuel->suivant;
        }
        actuel->suivant = listeContacts.tete;
    }
}
