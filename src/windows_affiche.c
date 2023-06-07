
/*
** JMS PROJECT, 2022
** 
** File description:
** Projet Second degré avec gestion fenetre
*/


#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <my_window.h>
//#include <polynome.h>

void window_affiche(sfVideoMode mode,sfRenderWindow* window, sfVertexArray* vertex_array) {
    
    // [23/05/23] penser à rendre indépendant le tracer de courbe en passant vertex_array en parametre ==> done 01/06/23
    
    window = sfRenderWindow_create(mode, "Tracer graph", sfDefaultStyle, NULL);
    sfFont* font = sfFont_createFromFile("arial.ttf");
    sfText* text = sfText_create();
    sfRectangleShape* rectangle = sfRectangleShape_create();


    if(window !=NULL)
    {
        /* Start the game loop */
        window_title(text,font);
        window_rectangle(rectangle);

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