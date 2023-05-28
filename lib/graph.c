/*
** JMS PROJECT, 2022
** 
** File description:
** Projet Second degré avec gestion fenetre : graph
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <my_courbe.h>
#include <polynome.h>
#include <graph.h>


void init_range(Range *rge) {
    //
    
}



void window_trace_courbe(sfVideoMode mode, sfVertexArray* vertex_array, Polynome *poly, Range *R) {
    
    // mettre en place une structure pour les valeurs min max du repère
    // prevoir un calcul de min et max du polynome?
    int i;
    float x = -10;
    float nb;
    sfVertex vertex;


    nb=500;

    for (i=0; i<=nb; i++)
    {
        vertex.position.x = (int)map(x,-20,20,100,700);
        vertex.position.y = (int)map((float)eval_polynome(poly,x),120,-90,100,500); 
        vertex.color = sfWhite;
        sfVertexArray_append(vertex_array, vertex);
        x = x+ 20/nb;
    }
}

void destroy_range(Range *rge) {
    //
    free(rge);
}