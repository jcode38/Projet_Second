/*
** JMS PROJECT, 2022
** 
** File description:
** Projet Second degré avec gestion fenetre
*/


float map(float a,float val_min, float val_max, float Ecran_min, float Ecran_max) {
    return (a - val_min) * (Ecran_max - Ecran_min) / (val_max-val_min) + Ecran_min;
}
