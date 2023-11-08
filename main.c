#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdlib.h>
#include "algorithmes.h"
#include "time_spent.h"
#include <math.h>
#include "Gauss.h"

int main() {
    int menu;
    do{
        printf("saiser un choix :");
        scanf("%d",&menu);
    }while((menu<1) || (menu>2));
    if(menu == 1){
        FILE *datafile = fopen("data.txt", "w");
        if (datafile == NULL) {
            perror("Erreur lors de l'ouverture du fichier de données");
            return 1;
        }
        int n = 6;
        float tab[91][n+1],temps;
        int k=0,i=0;
        for(int taille=1000 ; taille<=10000 ; taille=taille+100){
            fprintf(datafile, "%d\t", taille);
            ajouter(tab,k,0,taille);
            int *t = (int*) calloc(taille,sizeof(int));
            int *nvt = (int*) calloc(taille,sizeof(int));
            for (i = 0; i < taille; i++) {
                t[i] = (rand()%10)+1;
            }
            copierTableau(t,nvt,taille);
            temps = time_spent(&triInsertion , t , taille);
            fprintf(datafile, "%f\t", temps);
            ajouter(tab,k,1,temps);
            copierTableau(nvt,t,taille);
            temps = time_spent(&triSelection , nvt , taille);
            fprintf(datafile, "%f\t", temps);
            ajouter(tab,k,2,temps);
            copierTableau(t,nvt,taille);
            temps = time_spent(&triTas , t , taille);
            fprintf(datafile, "%f\t", temps);
            ajouter(tab,k,3,temps);
            copierTableau(nvt,t,taille);
            temps = time_spent(&quicksort , nvt , taille);
            fprintf(datafile, "%f\t", temps);
            ajouter(tab,k,4,temps);
            copierTableau(t,nvt,taille);
            temps = time_spent(&triFusion , t , taille);
            fprintf(datafile, "%f\t", temps);
            ajouter(tab,k,5,temps);
            copierTableau(nvt,t,taille);
            temps = time_spent(&triBulle , nvt , taille);
            fprintf(datafile, "%f\n", temps);
            ajouter(tab,k,6,temps);
            free(t);
            free(nvt);
            k++;
        }
        fclose(datafile);
        float moy[n], e_type[n], coef[n];
        for(i=0;i<n;i++){
            moy[i] = moyenne(tab,i+1,k);
            printf("%f\t",moy[i]);
        }
        printf("\n");
        for(i=0;i<n;i++){
            e_type[i] = ecart_type(tab,i+1,k,moy[i]);
            printf("%f\t",e_type[i]);
        }
        for(i=0;i<n;i++){
            coef[i] = 1/e_type[i]*sqrt(2*M_PI);
        }
        const char *mots[] = {"par Insertion", "par Selection", "par Tas", "Rapide", "Fusion", "Bulle"};

        //Créer un fichier pour les commandes GNUPLOT
        FILE *gnuplotScript = fopen("plot_script1.plt", "w");
        if (gnuplotScript == NULL) {
            perror("Erreur lors de l'ouverture du script Gnuplot");
            return 1;
        }
        fprintf(gnuplotScript, "set title 'Graphe des algorithmes de tri par la fonction de Gauss'\n");
        fprintf(gnuplotScript,"plot [1000:15000]");
        for(i=0;i<n;i++){
            if(i!=n-1) fprintf(gnuplotScript, "%f*exp(-(((x-%f)/%f)**2)/2) title 'Tri %s',",coef[i],moy[i],e_type[i],mots[i]);
            else fprintf(gnuplotScript, "%f*exp(-(((x-%f)/%f)**2)/2) title 'Tri %s'",coef[n-1],moy[n-1],e_type[n-1],mots[n-1]);
        }
        fclose(gnuplotScript);
        //Créer un fichier pour les commandes GNUPLOT
        FILE *gnuplotScript1 = fopen("plot_script.plt", "w");
        if (gnuplotScript1 == NULL) {
            perror("Erreur lors de l'ouverture du script Gnuplot");
            return 1;
        }
        fprintf(gnuplotScript1, "set title 'Graphe : Algorithmes de Tri'\n");
        fprintf(gnuplotScript1,"plot [1000:10000][0:300]'data.txt' using 1:2 with lines title 'Tri par Insertion',");
        fprintf(gnuplotScript1,"'data.txt' using 1:3 with lines title 'Tri par Selection',");
        fprintf(gnuplotScript1,"'data.txt' using 1:4 with lines title 'Tri par Tas',");
        fprintf(gnuplotScript1,"'data.txt' using 1:5 with lines title 'Tri Rapide',");
        fprintf(gnuplotScript1,"'data.txt' using 1:6 with lines title 'Tri Fusion',");
        fprintf(gnuplotScript1,"'data.txt' using 1:7 with lines title 'Tri Bulle'");
        fclose(gnuplotScript1);

        // Exécuter Gnuplot en utilisant popen()
        FILE *gnuplot = popen("gnuplot -persist", "w");
        if (gnuplot == NULL) {
            perror("Erreur lors de l'ouverture de Gnuplot");
            return 1;
        }
        fprintf(gnuplot, "load 'plot_script.plt'\n");
        pclose(gnuplot);
        FILE *gnuplot1 = popen("gnuplot -persist", "w");
        if (gnuplot1 == NULL) {
            perror("Erreur lors de l'ouverture de Gnuplot");
            return 1;
        }
        fprintf(gnuplot1, "load 'plot_script1.plt'\n");
        pclose(gnuplot1);
    }
    return 0;
}
