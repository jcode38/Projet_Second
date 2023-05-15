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
#include <math.h>




void window_title(sfText* text, sfFont* font) {

    sfText_setString(text, "Polynome du second degre");
    printf("Coucou");
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
    sfRectangleShape_setOutlineThickness(rectangle, 2.f);
    sfRectangleShape_setOutlineColor(rectangle, sfWhite);
}

void window_trace_courbe(sfVideoMode mode, sfVertex vertex, sfVertexArray* vertex_array) {
    
    int i;

    for (i = 0; i < (int)mode.width; i++)
    {
        float x = (float)i / mode.width* 2 * M_PI;
        float y = sinf(x) * mode.height / 2 + mode.height / 2;

        vertex.position.x = (float)i;
        vertex.position.y = y;
        vertex.color = sfWhite;
        sfVertexArray_append(vertex_array, vertex);
    }
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
}float map(float a, float E1min,float E1max, float E2min, float E2max)
{
    return (a-E1min)*((E2max-E2min)/(E1max-E1min))+E2min;
}
Shape_create();
    sfVertexArray* vertex_array = sfVertexArray_create();
    sfVertex vertex;
    
    if(window !=NULL)
    {
        /* Start the game loop */
        window_title(text,font);
        window_rectangle(rectangle);
        window_trace_courbe(mode,vertex,vertex_array);

        while (sfRenderWindow_isOpen(window)) {

            window_event(window);
            window_display(window,text,rectangle,vertex_array);   

            }            

    }

    sfText_destroy(text);
    sfFont_destroy(font);
    sfRectangleShape_destroy(rectangle);
    sfVertexArray_destroy(vertex_array);
    sfRenderWindow_destroy(window);
}