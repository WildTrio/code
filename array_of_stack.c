#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Stack{
    int *items;
    int capacity;
    int top;
}Stack;
typedef struct{
    char name[10];
    int key;
}hash_;
void initialize(Stack* stack,int capacity){
    stack->capacity=capacity;
    stack->top=-1;
    stack->items=(int*)malloc(capacity*sizeof(int));
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
int main(){
 int t;
 scanf("%d",&t);
 while(t--){
    int s,q,c;
    scanf("%d %d %d",&s,&q,&c);
    Stack stack[s];
    hash_ hashmap[s];
    
    for(int i=0;i<s;i++){
        scanf("%s",hashmap[i].name);
        hashmap[i].key=i;     
    }
    for(int i=0;i<s;i++){
        initialize(&stack[i],c);
    }
    while(q--){
        char query[10];
        char nameof[10];
        scanf("%s",query);
        if(strcmp(query,"push")==0){
            scanf("%s",nameof);
            for(int i=0;i<s;i++){
               if(strcmp(nameof,hashmap[i].name)==0){
                  int value;
                  scanf("%d",&value);
                  push(&stack[i],value);
               }
            }
        }
        if(strcmp(query,"pop")==0){
            scanf("%s",nameof);
            for(int i=0;i<s;i++){
               if(strcmp(nameof,hashmap[i].name)==0){
                  pop(&stack[i]);
               }
            }
        }
        if(strcmp(query,"top")==0){
            scanf("%s",nameof);
            for(int i=0;i<s;i++){
               if(strcmp(nameof,hashmap[i].name)==0){
                  top(&stack[i]);
               }
            }
        }
        
    }
    for(int i=0;i<s;i++){
        free_(&stack[i]);
    }
 }
    
    return 0;
}
