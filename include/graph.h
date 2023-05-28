/*
** JMS PROJECT, 2022
** 
** File description:
** Projet Second degré avec gestion fenetre : Graph.h
*/

typedef struct Range
{
    /* data */
    float xmin;
    float xmax;
    float ymin;
    float ymax;
} Range;

typedef struct Graph_ecran
{
    /* data */
    float xminEcran;
    float xmaxEcran;
    float yminEcran;
    float ymaxEcran;
} Graph_ecran;

#ifndef graph
    void init_range(Range *rnge);
    void init_graph_ecran(Graph_ecran *ecran);
    void destroy_Graph_ecran(Graph_ecran *ecran);
    int test_ecran(int xecran, int yecran, Graph_ecran *ecran);
#endif