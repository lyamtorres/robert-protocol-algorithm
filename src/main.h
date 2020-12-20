            // QUESTION 0 - PRÉLIMINAIRE


struct Maillon {
    char valeur;
    Maillon *suivant;
};

struct ListeChainee {
    Maillon *tete;
    Maillon *queue;
};

ListeChainee initialiser();

void afficher(ListeChainee liste);

// Précondition : Le chaînage doit être initialisé.
void insererDebut(ListeChainee &liste);

// Précondition : Le chaînage doit être initialisé.
void insererFin(ListeChainee &liste);

// Précondition : Le chaînage doit contenir au moins 2 maillons.
void supprimerDebut(ListeChainee &liste);

// Précondition : Le chaînage doit contenir au moins 2 maillons.
void supprimerFin(ListeChainee &liste);


            // QUESTION 1 - GESTION DE LA LISTE DE PSEUDONYMES D'UN UTILISATEUR


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

// Précondition : La memoire passée en paramètre doit être supérieur à 0.
Telephone initialiserTelephone(int memoire);

void afficherListe(Telephone tel);

// Précondition : Le chaînage doit être initialisé.
void insererPseudo(Telephone &tel);

// Précondition : Le chaînage doit contenir au moins 2 pseudos.
void supprimerPseudo(Telephone &tel);

// Précondition : L'espace occupé doit être inférieur à la capacité et au seuil.
void rechargerListe(Telephone &tel, int seuil);

std::string donnerPseudonyme();


            // QUESTION 2 - GESTION DE LA LISTE DE CONTACTS MÉMORISÉS SUR LE TÉLÉPHONE


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

// Rôle : Ajoute les nouveaux contacts du jour dans la liste de contacts de l'utilisateur.
// Précondition: La tête doit être un pointeur vers null.
void integrerContacts(ListeDeContacts &liste, int jour, int mois, int annee);

void afficherContacts(ListeDeContacts liste);

// Rôle : Crée un pointeur de type MaillonContact à partir d'un type Contact
void genererContact(ListeDeContacts &liste, Contact cont);

void insererContact(ListeDeContacts &liste, MaillonContact *maille);

// Rôle : Supprime tous les contacts avec plus de 14 jours d'avoir été enregistrés.
// Précondition: La liste des contacts doit commencer par les contacts moins récents.
void supprimerContacts(ListeDeContacts &liste, Date date);

// Rôle : Calcule le nombre de jours passés entre 2 dates données.
int calculerDifference(Date date1, Date date2);

// Rôle : Verifie si l'année actuelle doit être considérée comme année binaire.
int nombrerAnneeBinaire(Date date);


            // QUESTION 3 - GESTION DE LA LISTE DE CONTACTS MÉMORISÉS PAR L'APPLICATION CENTRALE


struct Utilisateur {
    Telephone monTel;
    ListeDeContacts maListe;
};

// Rôle : Insère une liste dans une autre liste.
// Précondition: La tête de la liste de l'application doit être un pointeur vers null.
void fusionnerListes(ListeDeContacts &listeAppli, ListeDeContacts listeContacts, bool estMalade);