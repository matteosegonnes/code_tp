#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include <stdbool.h>

int main()
{

List * my_list = initialize_list(5); //we do not initialize empty list in order to create memory access at the beginning!!
my_list = push_front(my_list, 15);
my_list = push_front(my_list, 1);
my_list = push_front(my_list, 999);
my_list = push_front(my_list, 555);

print(my_list);


my_list = tri_fusion(my_list);
print(my_list);
    

}
