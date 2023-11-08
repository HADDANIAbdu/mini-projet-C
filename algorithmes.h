//Fonction pour échanger les valeurs de deux variables
void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Tri par Insertion
void triInsertion(int tableau[], int taille) {
    for (int i = 1; i < taille; i++) {
        int cle = tableau[i];
        int j = i - 1;

        while (j >= 0 && tableau[j] > cle) {
            tableau[j + 1] = tableau[j];
            j--;
        }

        tableau[j + 1] = cle;
    }
}
//Tri par Selection
void triSelection(int tableau[], int taille) {
    int i, j, min;
    for (i = 0; i < taille - 1; i++) {
        min = i;
        for (j = i + 1; j < taille; j++) {
            if (tableau[j] < tableau[min]) {
                min = j;
            }
        }
        // Échanger les éléments min et i
        echanger(&tableau[i],&tableau[min]);
    }
}
//Tri par Tas
void tamiser(int tableau[], int taille, int racine) {
    int plus_grand = racine;
    int gauche = 2 * racine + 1;
    int droite = 2 * racine + 2;

    if (gauche < taille && tableau[gauche] > tableau[plus_grand]) {
        plus_grand = gauche;
    }

    if (droite < taille && tableau[droite] > tableau[plus_grand]) {
        plus_grand = droite;
    }

    if (plus_grand != racine) {
        echanger(&tableau[racine], &tableau[plus_grand]);
        tamiser(tableau, taille, plus_grand);
    }
}
// Fonction pour trier un tableau en utilisant le tri par tas
void triTas(int tableau[], int taille) {
    // Construire le tas max
    for (int i = taille / 2 - 1; i >= 0; i--) {
        tamiser(tableau, taille, i);
    }
    // Extraire les éléments un par un du tas
    for (int i = taille - 1; i > 0; i--) {
        echanger(&tableau[0], &tableau[i]);
        tamiser(tableau, i, 0);
    }
}
//Tri Rapide
void quicksort(int array[], int length){
    srand(time(NULL));
    quicksort_recursion(array, 0, length - 1);
}
void quicksort_recursion(int array[], int low, int high){
    if (low < high){
        int pivot_index = partition(array, low, high);
        quicksort_recursion(array, low, pivot_index - 1);
        quicksort_recursion(array, pivot_index + 1, high);
    }
}
int partition(int array[], int low, int high){
    int pivot_index = low + (rand() % (high - low));
    if (pivot_index != high) echanger(&array[pivot_index], &array[high]);
    int pivot_value = array[high];
    int i = low;
    for (int j = low; j < high; j++){
        if (array[j] <= pivot_value){
            echanger(&array[i], &array[j]);
            i++;
        }
     }
     echanger(&array[i], &array[high]);
     return i;
}
//Tri Fusion
void fusion(int tableau[], int debut, int milieu, int fin) {
    int n1 = milieu - debut + 1 , n2 = fin - milieu;
    int tableauGauche[n1], tableauDroite[n2];
    for (int i = 0; i < n1; i++) tableauGauche[i] = tableau[debut + i];
    for (int j = 0; j < n2; j++) tableauDroite[j] = tableau[milieu + 1 + j];
    int i = 0, j = 0, k = debut;
    while (i < n1 && j < n2) {
        if (tableauGauche[i] <= tableauDroite[j]) {
            tableau[k] = tableauGauche[i];
            i++;
        } else {
            tableau[k] = tableauDroite[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        tableau[k] = tableauGauche[i];
        i++;
        k++;
    }
    while (j < n2) {
        tableau[k] = tableauDroite[j];
        j++;
        k++;
    }
}
void triFusionRecursif(int tableau[], int debut, int fin) {
    if (debut < fin) {
        int milieu = debut + (fin - debut) / 2;
        triFusionRecursif(tableau, debut, milieu);
        triFusionRecursif(tableau, milieu + 1, fin);
        fusion(tableau, debut, milieu, fin);
    }
}
void triFusion(int tableau[], int taille) {
    triFusionRecursif(tableau, 0, taille - 1);
}
//Tri Bulle
void triBulle(int tableau[], int taille) {
    int i, j;
    int temp;
    for (i = 0; i < taille - 1; i++) {
        for (j = 0; j < taille - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                // Échange les éléments si ils sont dans le mauvais ordre
                echanger(&tableau[j],&tableau[j+1]);
            }
        }
    }
}



