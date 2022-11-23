#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack new_stack(void){
    return NULL;
}

bool is_empty(Stack sta){
    if(sta==NULL)
        return true;
    
    return false;

}

Stack push_stack(Stack sta,int *x){
    StackElement *element=malloc(sizeof(*element));
    if(element==NULL){
        fprintf(stderr,"erreur d'allocation dynamique\n");
        exit(EXIT_FAILURE);
    }
    element->valeur=x;
    element->next=sta;

    return element;
}

// Stack clear_stack(Stack sta){
//     StackElement *element;
//     if(is_empty(sta))
//         return new_stack();
        
//     element=sta->next;
//     free(sta);
//     return clear_stack(element);
// }

Stack clear_stack(Stack sta){
    
    while(!is_empty(sta)){        
       sta = pop_stack(sta);
    }
    return new_stack();
}

void status(Stack st){
    if(is_empty(st)){
        printf("la pile est vide\n");
        exit(1);
    }
    while(!is_empty(st)){
        for (int i = 0; i <3 ; i++)
        {
             printf("[%d]\t",st->valeur[i]);
        }
    printf("\n");
     st=st->next;   
    }
}


Stack pop_stack(Stack sta){
    if(is_empty(sta)){
        return new_stack();
    }
    Stack element=sta->next;
    free(sta);
    return element;
}

int *top_stack(Stack sta){
    if(is_empty(sta)){
        printf("aucun sommet");
    }
    return sta->valeur;
}

int stack_length(Stack sta){
    int length=0;
    while(sta!=NULL){
        length++;
        sta=sta->next;
    }
    return length;
}