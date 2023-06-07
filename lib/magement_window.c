/*
** JMS PROJECT, 2022
** 
** File description:
** Projet Second degré avec gestion fenetre
*/


#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <my_courbe.h>
#include <polynome.h>


void window_title(sfText* text, sfFont* font) {

    sfText_setString(text, "Polynome du second degre");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 24);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f){250, 30});
}


void window_rectangle(sfRectangleShape* rectangle) {
    // Crée le rectangle
    
    sfRectangleShape_setSize(rectangle, (sfVector2f){600.f, 400.f});
    sfRectangleShape_setPosition(rectangle, (sfVector2f){100.f, 100.f});
    sfRectangleShape_setFillColor(rectangle, sfBlack);
    sfRectangleShape_setOutlineThickness(rectangle, 1.f);
    sfRectangleShape_setOutlineColor(rectangle, sfWhite);
}


void window_event(sfRenderWindow* window) {

    sfEvent event;
    /* Process events */
    while (sfRenderWindow_pollEvent(window, &event)) {
        /* Close window : exit */
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);

        /* Close window : ESC */
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);    
    }
}

void window_display(sfRenderWindow* window, sfText* text,sfRectangleShape* rectangle, sfVertexArray* vertex_array) {
       
            /* Clear the screen */
        sfRenderWindow_clear(window, sfBlack);

        // Dessiner le texte
        sfRenderWindow_drawText(window, text, NULL);

        // Dessine le rectangle
        sfRenderWindow_drawRectangleShape(window, rectangle, NULL);

        // Tracer courbe
        sfRenderWindow_drawVertexArray(window, vertex_array, NULL);

        
        // Afficher le résultat
        sfRenderWindow_display(window);
}