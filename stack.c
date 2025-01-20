#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Stack{
    int *items;
    int top;
    int capacity;
} Stack;
void initialize(Stack* stack, int capacity) {
    stack->capacity=capacity;
    stack->top=-1;
    stack->items=(int *)malloc(capacity * sizeof(int));
    }
void push(Stack* stack,int value){
    if(stack->top==stack->capacity-1){
        printf("stack overflow\n");
    }
    else{
        stack->top++;
        stack->items[stack->top]=value;
        printf("%d\n",stack->items[stack->top]);
    }
}
void pop(Stack* stack){
    if(stack->top==-1){
        printf("stack underflow\n");
    }
    else{
        
        printf("%d\n",stack->items[stack->top]);
        stack->top--;
    }
}
void top(Stack* stack){
    if(stack->top==-1){
        printf("stack underflow\n");
    }
    else{
       printf("%d\n",stack->items[stack->top]);
    }
 }

 void free_(Stack* stack){
     free(stack->items);
 }
int main() {

    int t;
    scanf("%d",&t);
    while(t--){
        int q,n;
        scanf("%d %d",&q,&n);
        Stack stack;
        initialize(&stack,n);
        while(q--){
            char query[10];
            scanf("%s",query);
            if(strcmp(query,"push")==0){
                int value;
                scanf("%d",&value);
                push(&stack,value);
            }
            else if(strcmp(query,"pop")==0){
                pop(&stack);
            }
            else if(strcmp(query,"top")==0){
                top(&stack);
            }
        }
        free_(&stack);
    }
    return 0;
}
