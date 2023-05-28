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
    float xminEcran;
    float xmaxEcran;
    float yminEcran;
    float ymaxEcran;
} Range;


#ifndef graph
    void init_range(Range*R);
#endif