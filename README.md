## Liste des membres

| Nom complet                     | Matricule |
| ------------------------------- | --------- |
| David Bacré Noubao              | 24G2910   |
| Ngon-Assna Régis                | 24H2322   |
| Bagoulong Beteïgué Maxime       | 2025003   |
| Djidjose Kangrang Jean-Baptiste | 24Xxxxx   |
| Ngah Franc Le Roy               | 24Xxxxx   |
| Gormon Moïse                    | 24Xxxxx   |

# 🧮 Opérations sur matrices et vecteurs en C (version dynamique)

Ce programme en langage **C** réalise différentes opérations mathématiques sur des **matrices** et **vecteurs**, en utilisant l’**allocation dynamique** de mémoire.

Deux fonctions utilitaires (`afficher_matrice` et `trie_insertion`) sont incluses pour faciliter les traitements, mais **ne font pas partie des fonctionnalités évaluées** dans l’exercice.

---

## ✅ Fonctionnalités principales (exigées par l’exercice)

Les fonctions suivantes sont celles que le programme met en œuvre dans le cadre de l'exercice :

- ➕ `somme_matrice` — Calcule la somme de deux matrices
- ✖️ `produit_matrice` — Produit de deux matrices
- 🔍 `recherche_sequentiel` — Recherche une valeur dans un tableau
- 🎯 `median` — Calcule la médiane d’un tableau
- ↩️ `inverser_tableau` — Inverse les éléments d’un tableau
- 📐 `produit_vectorielle` — Produit scalaire entre deux vecteurs
- 🔄 `produit_vecteur_matrice` — Produit d’un vecteur ligne avec une matrice
- 🔢 `produit` — Multiplie deux entiers via des additions répétées

---

## 🛠️ Fonctions utilitaires (hors exercice)

Les fonctions suivantes sont **utilisées en interne** dans certaines des fonctions ci-dessus mais **ne font pas partie de l'exercice** :

- 🖨️ `afficher_matrice(int rows, int cols, float **matrice)`  
  Affiche proprement une matrice allouée dynamiquement.

- 📊 `trie_insertion(float *tab, int taille)`  
  Trie un tableau de flottants. Utilisée dans `median()`.

---

## 📁 Structure des fichiers

    .
├── programme.c ← Fichier source principal avec toutes les fonctions et le main()
├── README.md ← Documentation du projet (ce fichier)
└── doc/ ← Dossier contenant les cahiers de suivi de chaque membre du groupe


---

## ⚙️ Compilation et exécution

```bash
gcc -o programme programme.c
./programme