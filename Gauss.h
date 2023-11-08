// La moyenne
float moyenne(float x[][7], int colonne, int taille){
    float som=0, n=0;
    for(int i=0;i<taille;i++){
        som += x[i][0]*x[i][colonne];
        n += x[i][colonne];
    }
    return som/n;
}
//L'écart type
float ecart_type(float x[][7], int colonne, int taille, float moyenne){
    float som=0, n=0;
    for(int i=0;i<taille;i++){
        som += x[i][colonne]*pow(x[i][0] - moyenne,2);
        n += x[i][colonne];
    }
    return sqrt(som/n);
}
//Fonction pour ajouter les temps à la matrice
void ajouter(float t[][7] , int ligne , int colonne , float val){
    t[ligne][colonne] = val;
}
//Fonction pour créer des copies pour chaque tableau
void copierTableau(int t[], int nvt[], int taille){
    for(int i=0;i<taille;i++){
        nvt[i] = t[i];
    }
}
