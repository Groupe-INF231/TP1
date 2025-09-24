#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Affiche une matrice allouée dynamiquement
void afficher_matrice(int rows, int cols, float **tab) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%6.1f ", tab[i][j]);
        }
        printf("\n");
    }
}

// Trie un tableau avec le tri par insertion
void trie_insertion(float *tab, int n) {
    for (int i = 1; i < n; i++) {
        float temp = tab[i];
        int j = i;
        while (j > 0 && tab[j - 1] > temp) {
            tab[j] = tab[j - 1];
            j--;
        }
        tab[j] = temp;
    }
}

// Somme de deux matrices dynamiques
void somme_matrice(int rows, int cols, float **tab1, float **tab2) {
    float **resultat = malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++) {
        resultat[i] = malloc(cols * sizeof(float));
        for (int j = 0; j < cols; j++) {
            resultat[i][j] = tab1[i][j] + tab2[i][j];
        }
    }
    afficher_matrice(rows, cols, resultat);
    for (int i = 0; i < rows; i++) free(resultat[i]);
    free(resultat);
}

// Produit de deux matrices dynamiques
void produit_matrice(int inter, int rows, int cols, float **tab1, float **tab2) {
    float **resultat = malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++) {
        resultat[i] = malloc(cols * sizeof(float));
        for (int j = 0; j < cols; j++) {
            float somme = 0;
            for (int k = 0; k < inter; k++) {
                somme += tab1[i][k] * tab2[k][j];
            }
            resultat[i][j] = somme;
        }
    }
    afficher_matrice(rows, cols, resultat);
    for (int i = 0; i < rows; i++) free(resultat[i]);
    free(resultat);
}

// Recherche séquentielle dans un tableau
bool recherche_sequentiel(float *tab, float valeur, int taille) {
    for (int i = 0; i < taille; i++) {
        if (tab[i] == valeur) return true;
    }
    return false;
}

// Produit de deux entiers via additions
int produit(int a, int b) {
    int resultat = 0;
    for (int i = 0; i < b; i++) {
        resultat += a;
    }
    return resultat;
}

// Vérifie si un tableau est trié
bool test_trie(float *tab, int taille) {
    for (int i = 0; i < taille - 1; i++) {
        if (tab[i] > tab[i + 1]) return false;
    }
    return true;
}

// Calcule la médiane
float median(float *tab, int taille) {
    float *clone = malloc(taille * sizeof(float));
    for (int i = 0; i < taille; i++) {
        clone[i] = tab[i];
    }
    trie_insertion(clone, taille);
    float m;
    if (taille % 2 == 0)
        m = (clone[taille/2 - 1] + clone[taille/2]) / 2;
    else
        m = clone[taille/2];
    free(clone);
    return m;
}

// Inverse un tableau
void inverser_tableau(float *tab, int taille) {
    for (int i = 0; i < taille / 2; i++) {
        float temp = tab[i];
        tab[i] = tab[taille - i - 1];
        tab[taille - i - 1] = temp;
    }
}

// Produit vectoriel de deux vecteurs
float produit_vectorielle(float *tab1, float *tab2, int dimension) {
    float produit = 0;
    for (int i = 0; i < dimension; i++) {
        produit += tab1[i] * tab2[i];
    }
    return produit;
}

// Produit d’un vecteur ligne et d’une matrice
void produit_vecteur_matrice(int rows, int cols, float *vecteur, float **matrice) {
    float *res = malloc(rows * sizeof(float));
    for (int i = 0; i < rows; i++) {
        float somme = 0;
        for (int j = 0; j < cols; j++) {
            somme += vecteur[j] * matrice[i][j];
        }
        res[i] = somme;
    }
    for (int i = 0; i < rows; i++) {
        printf("%6.1f ", res[i]);
    }
    printf("\n");
    free(res);
}

// MAIN : tests de toutes les fonctions
int main() {
    // Matrices dynamiques
    int rows = 3, cols = 3;
    float **A = malloc(rows * sizeof(float *));
    float **B = malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++) {
        A[i] = malloc(cols * sizeof(float));
        B[i] = malloc(cols * sizeof(float));
        for (int j = 0; j < cols; j++) {
            A[i][j] = i + j + 1;
            B[i][j] = (i + 1) * (j + 1);
        }
    }

    printf("Matrice A:\n");
    afficher_matrice(rows, cols, A);
    printf("Matrice B:\n");
    afficher_matrice(rows, cols, B);

    printf("Somme A + B:\n");
    somme_matrice(rows, cols, A, B);

    printf("Produit A * B:\n");
    produit_matrice(cols, rows, cols, A, B);

    float vecteur[3] = {1, 2, 3};
    printf("Produit vecteur * matrice A:\n");
    produit_vecteur_matrice(rows, cols, vecteur, A);

    float tab[5] = {7, 2, 4, 9, 1};

    printf("Recherche 4 dans le tableau : %s\n", recherche_sequentiel(tab, 4, 5) ? "Trouvé" : "Non trouvé");

    printf("Médiane du tableau : %.1f\n", median(tab, 5));

    inverser_tableau(tab, 5);
    printf("Tableau inversé : ");
    for (int i = 0; i < 5; i++) printf("%.1f ", tab[i]);
    printf("\n");

    float v1[3] = {1, 2, 3}, v2[3] = {4, 5, 6};
    printf("Produit vectoriel : %.1f\n", produit_vectorielle(v1, v2, 3));

    printf("Produit par additions : 4 * 5 = %d\n", produit(4, 5));

    // Libération mémoire
    for (int i = 0; i < rows; i++) {
        free(A[i]);
        free(B[i]);
    }
    free(A);
    free(B);

    return 0;
}