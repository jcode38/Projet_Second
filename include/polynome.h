/*
** JMS PROJECT, 2022
** 
** File description:
** Header second degré
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct Polynome
{
    /* data */
    int degre;
    int nb_racine;
    float *p;
    float *zero;
} Polynome;


#ifndef polynome
    void init_second(Polynome *poly);
    void destroy_second(Polynome *poly);
    void input_data(Polynome *poly);
    float calcul_delta(Polynome *poly);
    void calcul_racine(Polynome *poly);
    void affiche_result(Polynome *poly);
    float eval_polynome(Polynome *poly, float x);
#endif