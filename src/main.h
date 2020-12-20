struct Pseudo {
    std::string valeur;
    Pseudo *suivant;
};

struct Telephone {
    int capacite;
    int espaceOccupe;
    Pseudo *tete;
    Pseudo *queue;
};

struct Date {
    int jour;
    int mois;
    int an;
};

struct Contact {
    std::string pseudo1;
    std::string pseudo2;
    Date date;
};

struct MaillonContact {
    Contact contact;
    MaillonContact *suivant;
};

struct ListeDeContacts {
    MaillonContact *tete;
};

            // QUESTION 1

// Précondition : memoire > 0
Telephone initialiserTelephone(int memoire);

void afficherListe(Telephone tel);

// Précondition : tel.espaceOccupe < tel.capacite et tel.espaceOccupe < seuil 
void rechargerListe(Telephone &tel);

// Précondition : Le chaînage doit être initialisé
void insererPseudoAvant(Telephone &tel);

// Précondition : Le chaînage doit être initialisé
void insererPseudoFin(Telephone &tel);

// Précondition : Le chaînage doit contenir au moins deux Pseudos
void supprimerPseudoDebut(Telephone &tel);

// Précondition : Le chaînage doit contenir au moins deux Pseudos
void supprimerPseudoFin(Telephone &tel);

std::string donnerPseudonyme();


            // QUESTION 2

// Rôle : Ajoute les nouveaux contacts du jour dans la liste de contacts de l'utilisateur 
void integrerContacts(ListeDeContacts &liste, Date dateDuJour);

// Rôle : Crée un pointeur de type MaillonContact à partir d'un type Contact
void genererMaillonContact(ListeDeContacts &liste, Contact cont);
 
void insererMaillonContact(ListeDeContacts &liste, MaillonContact *maille);

// Rôle : Supprime tous les contacts avec plus de 14 jours d'avoir été enregistrés
// Précondition: La liste des contacts doit commencer par les contacts moins récents
void supprimerContacts(ListeDeContacts &liste, Date dateDuJour);

// Rôle : Calcule le nombre de jours totals entre 2 dates données
int calculerDifference(Date date1, Date date2);

// Rôle : Verifie si l'année actuelle doit être considérée comme année binaire
int nombrerAnneeBinaire(Date date);

void afficherContacts(ListeDeContacts liste);

