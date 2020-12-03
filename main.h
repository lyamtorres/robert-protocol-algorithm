struct Maillon {
    char donnees;
    Maillon *suivant;
};

struct ListeChainee {
    int nombreElements;
    Maillon *tete;
    Maillon *queue;
};

// Utilisé une seule fois pour initialiser une liste chaînée avec un maillon
ListeChainee initialiser(char d);

void afficherListe(ListeChainee l);

// Précondition: Le chaînage doit être initialisé
void insererEnTete(ListeChainee &l, char d);

// Précondition: Le chaînage doit être initialisé
void insererEnQueue(ListeChainee &l, char d);

// Précondition: Le chaînage doit contenir au moins un maillon
void supprimerEnTete(ListeChainee &l);

// Précondition: Le chaînage doit contenir au moins un maillon
void supprimerEnQueue(ListeChainee &l);

