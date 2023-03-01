#ifndef BANNER
#define BANNER
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void banner_vertical(char *thong){
    int n=strlen(thong);
    printf("+---+\n");
    for(int i=0;i<n;i++){
        printf("| %c |\n",thong[i]);
    }
    printf("+---+\n");
}
void banner_horizintal(char *thong){
    int n=strlen(thong);
    printf("+-");
    for(int i=0;i<n;i++){
        printf("-");
    }
    printf("-+\n| %s |\n+-",thong);
    for(int i=0;i<n;i++){
        printf("-");
    }
    printf("-+\n");
}
#endif