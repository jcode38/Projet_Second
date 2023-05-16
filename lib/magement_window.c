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
#include <my_courbe.h>




void window_title(sfText* text, sfFont* font) {

    sfText_setString(text, "Fonction Sinus");
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
    float x = -3.14;
    float nb;

    nb=500;

    for (i=0; i<nb; i++)
    {
        x = x+ 6.28/nb;
        vertex.position.x = map(x,-3.14,3.14,100,700);
        vertex.position.y = map(sin(x),-1,1,100,500);
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
}



void management_window(sfVideoMode mode,sfRenderWindow* window) {
    
    
    window = sfRenderWindow_create(mode, "SFML window", sfDefaultStyle, NULL);
    sfFont* font = sfFont_createFromFile("arial.ttf");;
    sfText* text = sfText_create();
    sfRectangleShape* rectangle = sfRectangleShape_create();
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