/*
** JMS PROJECT, 2022
** 
** File description:
** Header Window
*/
#include <polynome.h>


#ifndef my_window
    void window_title(sfText* text, sfFont* font);
    void window_rectangle(sfRectangleShape* rectangle);
    //void window_trace_courbe(sfVideoMode mode, sfVertex vertex, sfVertexArray* vertex_array);
    void window_trace_courbe(sfVideoMode mode, sfVertexArray* vertex_array, Polynome *poly);
    void window_event(sfRenderWindow* window);
    void window_display(sfRenderWindow* window, sfText* text,sfRectangleShape* rectangle, sfVertexArray* vertex_array);
#endif