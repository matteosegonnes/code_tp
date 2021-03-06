#ifndef __ListeH__
#define __ListeH__

/*
definition des types 
*/


typedef struct List
{
    float val;
    struct List *next;
}List;


/*
definition des prototypes
*/

List* initialize_list();
void print(List *list);
List* push_front(List *list, float x); // change adress memory
List* push_back(List * list, float x); // keep same adress memory
List * fusion( List * liste1, List * liste2); 
List * tri_fusion( List * list); 
List * deepcopy( List * list);
void clear(List * list); // free list


#endif