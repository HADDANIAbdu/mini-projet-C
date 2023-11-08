double time_spent(int (*pf)(int[] , int), int tab[] , int taille){
    clock_t begin = clock();
    (*pf)(tab , taille);
    clock_t end = clock();
    unsigned long millis = (double)(end -  begin) * 1000.0 / CLOCKS_PER_SEC;
    return millis;
}
