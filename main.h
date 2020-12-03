struct Maillon {
    std::string data;
    Maillon *suivant;
};

struct ListeChainee {
    int nombreElements;
    Maillon *tete;
    Maillon *queue;
};

// Retourne une liste chaînée avec un seul élément
ListeChainee initialiser();

void afficherListe(ListeChainee l);

void insererEnTete(ListeChainee &l);

void supprimerEnTete(ListeChainee &l);

