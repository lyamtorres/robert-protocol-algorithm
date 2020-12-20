/*

            Robert Protocol Algorithm - DIALLO Fatoumata et TORRES Lyam

 */

#include <iostream>
#include <random>
#include <ctime> 
#include "main.h"

using namespace std;

const int joursDuMois[12]
    = { 31, 28, 31, 30, 31, 30, 
       31, 31, 30, 31, 30, 31 };

int main() {
    srand(time(0));

/*     Telephone samsungAlice = initialiserTelephone(5);
    Telephone iphoneCharles = initialiserTelephone(5);

    afficherListe(samsungAlice);
    afficherListe(iphoneCharles); */

    ListeDeContacts contactsAlice;
    Date maDate;
    Date maDate2;
    Date maDate3;
    Date maDate4;

    maDate.jour = 1;
    maDate.mois = 1;
    maDate.an = 2021;

    maDate2.jour = 3;
    maDate2.mois = 1;
    maDate2.an = 2021;

    maDate3.jour = 28;
    maDate3.mois = 1;
    maDate3.an = 2021;

    maDate4.jour = 29;
    maDate4.mois = 1;
    maDate4.an = 2021;


    contactsAlice.tete = nullptr;

    integrerContacts(contactsAlice, maDate);
    integrerContacts(contactsAlice, maDate2);
    integrerContacts(contactsAlice, maDate3);

    afficherContacts(contactsAlice);

    supprimerContact(contactsAlice, maDate4);

    afficherContacts(contactsAlice);

/*     supprimerPlusieurs(contactsAlice, maDate4);
    supprimerPlusieurs(contactsAlice, maDate4);
    supprimerPlusieurs(contactsAlice, maDate4);
    supprimerPlusieurs(contactsAlice, maDate4);

    supprimerPlusieurs(contactsAlice, maDate4);
    supprimerPlusieurs(contactsAlice, maDate4); */


/*     supprimerContact(contactsAlice);
    afficherContacts(contactsAlice); */

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

void integrerContacts(ListeDeContacts &liste, Date dateDuJour) {
    Contact nouveauContact;
    //int contactsDuJour = rand() % 20;

    for (int i = 0; i < 2; i++) {
        nouveauContact.pseudo1 = donnerPseudonyme();
        nouveauContact.pseudo2 = donnerPseudonyme();
        nouveauContact.date = dateDuJour;
        genererMaillonContact(liste, nouveauContact);
    }
}

void genererMaillonContact(ListeDeContacts &liste, Contact cont) {
    MaillonContact *nouveauMaillon;
    
    nouveauMaillon = new MaillonContact;
    nouveauMaillon->contact = cont;
    nouveauMaillon->suivant = nullptr;
    insererMaillonContact(liste, nouveauMaillon);
}

void insererMaillonContact(ListeDeContacts &liste, MaillonContact *maille) {
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

void supprimerContacts(ListeDeContacts &liste, Date dateDuJour) {
    MaillonContact *aSupprimer;
    int nombreJours = calculerDifference(liste.tete->contact.date, dateDuJour);
    
    do {
        aSupprimer = liste.tete;
        liste.tete = liste.tete->suivant;
        delete aSupprimer;
        nombreJours = calculerDifference(liste.tete->contact.date, dateDuJour);
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


// Commande pour compiler : g++ main.cpp -o main.exe