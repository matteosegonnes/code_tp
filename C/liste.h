#ifndef __ListeH__
#define __ListeH__

/*
definition des types 
*/


typedef struct List
{
    int val;
    struct List *next;
}List;


/*
definition des prototypes
*/

List* initialize_list(int x);
void print(List *list);
List* push_front(List *list, int x);
List* push_back(List * list, int x);
List * fusion( List * liste1, List * liste2);
List * tri_fusion( List * list);
List * deepcopy( List * list);


#endif