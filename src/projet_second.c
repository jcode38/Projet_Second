/*
** JMS PROJECT, 2022
** 
** File description:
** Projet Second degré avec gestion fenetre
*/



#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <my_window.h>

#define WIDTH 800
#define HEIGHT 600


int main() {
    
    sfRenderWindow* window;
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    management_window(mode,window);

    return 0;
}