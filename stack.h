#ifndef __FILE_H__
#define __FILE_H__

typedef enum
{
    false,
    true
    
}Bool;

typedef struct StackElement
{
    int *valeur;
    struct StackElement *next;

}StackElement,*Stack;

Stack new_stack(void);
Bool is_empty(Stack sta);
Stack push_stack(Stack sta,int *x);
Stack clear_stack(Stack sta);
Stack pop_stack(Stack sta);
void status(Stack st);
int *top_stack(Stack sta);
int stack_length(Stack sta);

#endif