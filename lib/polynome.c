/*
** JMS PROJECT, 2022
** 
** File description:
** Projet Second degré avec gestion fenetre
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <polynome.h>


void init_second(Polynome *poly) {
    poly->degre = 2;
    poly->nb_racine = 2;
    poly->p = (float *)malloc((poly->degre+1)  * sizeof(float));
    poly->zero = (float *)malloc(poly->degre  * sizeof(float));
}

void destroy_second(Polynome *poly) {
    free(poly->p);
    free(poly->zero);
    free(poly);
}

void input_data(Polynome *poly) {
    printf("Valeur a = ");
    scanf("%f",&poly->p[0]);
    printf("Valeur b = ");
    scanf("%f",&poly->p[1]);
    printf("Valeur c = ");
    scanf("%f",&poly->p[2]);   
}

float calcul_delta(Polynome *poly) {
    return pow(poly->p[1],2)-4*poly->p[2]*poly->p[0];
}

void calcul_racine(Polynome *poly) {
    float delta = calcul_delta(poly);


    if(delta>0)
        {
            poly->zero[0] = (-poly->p[1]-sqrt(delta))/(2*poly->p[2]);
            poly->zero[1] = (-poly->p[1]+sqrt(delta))/(2*poly->p[2]);
            poly->nb_racine = 2;
        }
    else if(delta == 0)
        {
            poly->zero[0] = (-poly->p[1])/(2*poly->p[2]);
            poly->nb_racine = 1;
        }

    else
        poly->nb_racine = 0;

}


void affiche_result(Polynome *poly) {
    printf("le polynome du second degré a %d solution(s) \n",poly->nb_racine);
    
    for(int i=1;i<=poly->nb_racine; i++) {
        printf("Solution x%d = %f \n",i,poly->zero[i-1]);
    }
    
}

float eval_polynome(Polynome *poly, float x) {
    float val=0;
    for(int i=0;i<=poly->degre;i++) {
        val = val + poly->p[i]*pow(x,i);
    }
    return val;
}