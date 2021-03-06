#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include <stdbool.h>



List* initialize_list()
{
    return NULL;
}

void print(List *list)
{
    printf("------------------------\n");
    if(list == NULL)
    {
        printf("List is empty\n");
    }

    List *temp = (List *)malloc(sizeof(List));
    temp = list;
    while(temp != NULL)
    {
        printf("%f\n", (*temp).val);
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

List * push_front(List *list, float x)
{
    List * temp = (List *)malloc(sizeof(List));

    temp -> val = x;
    temp -> next = list;
    return temp;

}

List * push_back(List * list, float x)
{

    List *temp = (List *)malloc(sizeof(List));

    

    if (list == NULL)
    {
        temp -> val = x;
        temp -> next = NULL;
    }
    else
    {
        temp = list;
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
    //liste1 and liste2 already sorted by recursion in tri_fusion
    
    List * liste_fusion = initialize_list();

    while( liste1 != NULL && liste2 != NULL)
    {
       
        float x = liste1 -> val;
        float y = liste2 -> val;
        if(x <= y)
        {
            liste_fusion = push_back(liste_fusion, x);
            liste1 = liste1 -> next;
            
        }
        else 
        {
            liste_fusion = push_back(liste_fusion, y);
            liste2 = liste2 -> next;
        }
    
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

    
    List * liste1 = initialize_list();
    List * liste2 = initialize_list();
  
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


void clear(List * list)
{
    while(list != NULL)
    {
        list = list -> next;
    }
}
