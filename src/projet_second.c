/*
** JMS PROJECT, 2022
** 
** File description:
** Projet Second degré avec gestion fenetre
*/



#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <polynome.h>
#include <graph.h>

#define WIDTH 800
#define HEIGHT 600


int main() {
    
    sfRenderWindow* window;
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfVertexArray* vertex_array = sfVertexArray_create();
    Polynome *poly = malloc(sizeof(Polynome));
    Range *rge = malloc(sizeof(Range));

    init_second(poly);
    input_data(poly);
    calcul_racine(poly);
    affiche_result(poly);

    init_range(rge);
    window_trace_courbe(mode,vertex_array,poly,R);
    window_affiche(mode,window, vertex_array);

    destroy_second(poly);
    destroy_range(rge);
 
    return 0;
}