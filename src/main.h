struct Maillon {
    char donnee;
    Maillon *suivant;
};

struct ListeChainee {
    int nombreElements;
    Maillon *tete;
    Maillon *queue;
};

// Utilisé une seule fois pour initialiser une liste chaînée avec un maillon
ListeChainee initialiser(char d);

void afficherListe(ListeChainee liste);

// Précondition: Le chaînage doit être initialisé
void insererAvant(ListeChainee &liste, char d);

// Précondition: Le chaînage doit être initialisé
void insererFin(ListeChainee &liste, char d);

// Précondition: Le chaînage doit contenir au moins deux maillons
void supprimerDebut(ListeChainee &liste);

// Précondition: Le chaînage doit contenir au moins deux maillons
void supprimerFin(ListeChainee &liste);

