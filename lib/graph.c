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
   rge->xmin = -5;
   rge->xmax = 5;
   rge->ymin = -5;
   rge->ymax = 5;
}

void init_graph_ecran(Graph_ecran *ecran) {
    ecran->xminEcran = 100;
    ecran->xmaxEcran = 700;
    ecran->yminEcran = 100;
    ecran->ymaxEcran = 500;
}


void window_trace_courbe(sfVideoMode mode, sfVertexArray* vertex_array, Polynome *poly, Range *rng, Graph_ecran *ecran) {
    
    // mettre en place une structure pour les valeurs min max du repère ==> done 28/05/23
    // prevoir un calcul de min et max du polynome?

    float x = rng->xmin;
    float y = rng->ymin;
    int xecran, yecran;
    float nb = 5000;
    sfVertex vertex;

    for (int i=0; i<=nb; i++) {
        xecran = (int)map(x,rng->xmin,rng->xmax,ecran->xminEcran,ecran->xmaxEcran);
        yecran = (int)map((float)eval_polynome(poly,x),-rng->ymin,-rng->ymax,ecran->yminEcran,ecran->ymaxEcran); 
        
        if (test_ecran(xecran,yecran,ecran)==1) {
            vertex.position.x = xecran;
            vertex.position.y = yecran;
            vertex.color = sfWhite;
            sfVertexArray_append(vertex_array, vertex);
        }
        x = x+ (rng->xmax-rng->xmin)/nb;
    }

    window_trace_repere(vertex_array,rng,ecran);

}


void window_trace_repere(sfVertexArray* vertex_array, Range *rng, Graph_ecran *ecran) {


    // attente de modification pour implémenter cette fonction
    float x = rng->xmin;
    float y = rng->ymin;
    int xecran, yecran;
    float nb = 5000;
    sfVertex vertex;
    
    for (int i=0; i<=nb; i++) {
        xecran = (int)map(x,rng->xmin,rng->xmax,ecran->xminEcran,ecran->xmaxEcran);
        yecran = (int)map(0,-rng->ymin,-rng->ymax,ecran->yminEcran,ecran->ymaxEcran); 
        if (test_ecran(xecran,yecran,ecran)==1) {
            vertex.position.x = xecran;
            vertex.position.y = yecran;
            vertex.color = sfWhite;
            sfVertexArray_append(vertex_array, vertex);
        }

        x =  x + (rng->xmax-rng->xmin)/nb;
    }

    for (int i=0; i<=nb; i++) {
        xecran = (int)map(0,rng->xmin,rng->xmax,ecran->xminEcran,ecran->xmaxEcran);
        yecran = (int)map(y,-rng->ymin,-rng->ymax,ecran->yminEcran,ecran->ymaxEcran); 
        if (test_ecran(xecran,yecran,ecran)==1) {
            vertex.position.x = xecran;
            vertex.position.y = yecran;
            vertex.color = sfWhite;
            sfVertexArray_append(vertex_array, vertex);
        }

        y = y + (rng->ymax-rng->ymin)/nb;
    }
   

}


int test_ecran(int xecran, int yecran, Graph_ecran *ecran) {
    int result=0;

    if(xecran>=ecran->xminEcran && xecran<=ecran->xmaxEcran && yecran>=ecran->yminEcran && yecran<=ecran->ymaxEcran)
        result = 1;

    return result;
    
}

void destroy_range(Range *rge) {
    //
    free(rge);
}

void destroy_Graph_ecran(Graph_ecran *ecran) {
    //
    free(ecran);
}