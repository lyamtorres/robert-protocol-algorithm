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

// Précondition : memoire > 0
Telephone initialiserTelephone(int memoire);

void afficherListe(Telephone tel);

// Précondition : tel.espaceOccupe < tel.capacite
void rechargerListe(Telephone &tel, int seuil);

// Précondition : Le chaînage doit être initialisé
void insererPseudoAvant(Telephone &tel);

// Précondition : Le chaînage doit être initialisé
void insererPseudoFin(Telephone &tel);

// Précondition : Le chaînage doit contenir au moins deux Pseudos
void supprimerPseudoDebut(Telephone &tel);

// Précondition : Le chaînage doit contenir au moins deux Pseudos
void supprimerPseudoFin(Telephone &tel);

std::string donnerPseudonyme();

