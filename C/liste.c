#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include <stdbool.h>



List* initialize_list(int x)
{

    List * temp = (List *)malloc(sizeof(List));
    temp -> val = x;
    temp -> next = NULL;
    return temp;
}

void print(List *list)
{
    printf("------------------------\n");
    if(list == NULL)
    {
        printf("NULL\n");
    }

    List *temp = (List *)malloc(sizeof(List));
    temp = list;
    while(temp != NULL)
    {
        printf("%d\n", (*temp).val);
        temp = (*temp).next;
    }
    printf("-------------------------\n");

}

List * deepcopy(List * list)
{
    List * copy = (List *)malloc(sizeof(List));
    List * copycopy = copy;
    copy -> val = list -> val;
    copy -> next = NULL;

    list = list -> next;

    while(list != NULL)
    {
        List *copy2 = (List *)malloc(sizeof(List));
        copy2 -> val = list -> val;
        copy2 -> next = NULL;
        copycopy -> next = copy2;
        list = list -> next;
        copycopy = copycopy -> next;
    }
    return copy;
}

List * push_front(List *list, int x)
{
    List * temp = (List *)malloc(sizeof(List));

    List * list2 = deepcopy(list); // chaque sous pointeur a une adresse différente : deepcopy

    temp = list; // le pointeur lui est différent mais l'objet pointé est le meme : celui qu'on renvoie

    temp -> val = x;

    while(list -> next!= NULL)
    {
        list = list -> next;
        list -> val = list2 -> val;
        list2 = list2 -> next;
    }
    List * final = (List *)malloc(sizeof(List));

    final -> val = list2 -> val;
    final -> next = NULL;
    list -> next = final;
    
    
    return temp;

}

List * push_back(List * list, int x)
{

    List *temp = (List *)malloc(sizeof(List));

    temp = list;

    if (list == NULL)
    {
        temp -> val = x;
        temp -> next = NULL;
    }
    else
    {
        while( list -> next != NULL)
        {
            list = list -> next;  
        }

        List * final = (List *)malloc(sizeof(List));
        final -> val = x;
        final -> next = NULL;
        list -> next = final;
    }
    return temp;

}

List * fusion(List * liste1, List * liste2)
{
    //liste1 et liste2 déja triée et liste_fusion

    
    //liste1 = liste1 -> next;

    int x1 = liste1 -> val;
    int x2 = liste2 -> val;
    int X;
    if(x1 <= x2)
    {
        X = x1;
        liste1 = liste1 -> next;
    }
    else
    {
        X = x2;
        liste2 = liste2 -> next;
    }


    List * liste_fusion = initialize_list(X);
    while( liste1 != NULL && liste2 != NULL)
    {
        int x = liste1 -> val;
        int y = liste2 -> val;
        if(x<= y)
        {
            liste_fusion = push_back(liste_fusion, x);
            liste_fusion = push_back(liste_fusion, y);
        }
        else 
        {
            liste_fusion = push_back(liste_fusion, y);
            liste_fusion = push_back(liste_fusion, x);
        }
        liste1 = liste1 -> next;
        liste2 = liste2 -> next;

    }
    if (liste1 == NULL && liste2 == NULL)
        return liste_fusion;

    if(liste1 == NULL)
    {
        while(liste2 != NULL)
        {
            liste_fusion = push_back(liste_fusion, liste2 -> val);
            liste2 = liste2 -> next;
        }
    }

    if(liste2 == NULL)
    {
        while(liste1 != NULL)
        {
            liste_fusion = push_back(liste_fusion, liste1 -> val);
            liste1 = liste1 -> next;
        }
    }
    
    return liste_fusion;
    
}



List * tri_fusion(List * list)
{
    
    if(list == NULL)
    {
        return list;
    }
    if(list -> next == NULL)
    {
        return list;
    }

    
    List * liste1 = initialize_list(list->val);
    List * liste2 = initialize_list((list -> next) -> val);
 
    list = list -> next -> next;
  
    while(list != NULL)
    {
        liste1 = push_front(liste1, list -> val);
        if(list -> next != NULL)
        {
            list = list -> next;
            liste2 = push_front(liste2, list -> val);
        }
        list = list -> next;

    }
    
    return fusion(tri_fusion(liste1), tri_fusion(liste2));


}
