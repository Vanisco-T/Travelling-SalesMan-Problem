#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



int main(){


    int tab[5]={12,13,1,5,6};
    Stack sta=new_stack();
    sta=push_stack(sta,tab);
    status(sta);
    printf("la longueur est : %d",stack_length(sta));
    sta=pop_stack(sta);
    printf("\nnouve lle pile\n");
    status(sta);
    sta=clear_stack(sta);
    status(sta);

    return 0;
}

