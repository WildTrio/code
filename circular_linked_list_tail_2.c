#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *tail=0;
void creation(){
    struct node *newnode;
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d",&newnode->data);
        if(tail==0){
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("choice");
        scanf("%d",&choice);
    }
}

void display(){
    struct node *temp;
    if(tail==0){
        printf("list is empty");
    }
    else{
        temp=tail->next;
    while(temp->next!=tail->next){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d->",temp->data);
    printf("NULL\n");
    }
    
}
int length(){
    struct node *temp;
    int count=0;
    temp=tail->next;
    if(tail==0){
        return 0;
    }
    else{
        while(temp!=tail){
        temp=temp->next;
        count++;
        }
        return count+1;
    }
}
void insert_beg(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(tail==0){
        tail=newnode;
        newnode->next=tail;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
    }
}
void insert_end(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(tail==0){
        tail=newnode;
        newnode->next=tail;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}
void insert_pos(){
    struct node *newnode,*temp;
    int pos,i=1,l;
    printf("enter position\n");
    scanf("%d",&pos);
    l=length();
    if(pos<0||pos>l+1){
        printf("invalid position");
    }
    else if(pos==1) {
        insert_beg();
    }
    else if(pos==l+1){
        insert_end();
    }
    
    else{
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d",&newnode->data);
        newnode->next=0;
        temp=tail->next;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void del_beg(){
    struct node *temp;
    if(tail==0){
        printf("empty");
    }
    else if(tail==tail->next){
        free(tail);
        tail=0;
    }
    else{
        temp=tail->next;
        tail->next=temp->next;
        free(temp);
    }
}
void del_end(){
    struct node *prevnode,*temp;
    prevnode=0;
    if(tail==0){
        printf("empty");
    }
    else if(tail==tail->next){
        free(tail);
        tail=0;
    }
    else{
        temp=tail->next;
        while(temp!=tail){
            prevnode=temp;
            temp=temp->next;
        }
        prevnode->next=temp->next;
        tail=prevnode;
        free(temp);
    }
}
void del_pos(){
    struct node *prevnode,*temp;
    prevnode=0;
    if(tail==0){
        printf("empty");
    }
    
    int pos,i=1;
    printf("enter position");
    scanf("%d",&pos);
    if(pos==1){
        del_beg();
        return;
    }
    else if(pos==length()){
        del_end();
         return;
    }
    else if(pos<0||pos>length()){
        printf("invalid position");
         return;
    }
    
    else{
        temp=tail->next;
        while(i<pos){
        prevnode=temp;
        temp=temp->next;
        i++;
        }
        prevnode->next=temp->next;
        free(temp);
    }
}
void reverse(){
    struct node *prevnode,*temp,*nextnode;
    prevnode=tail;
    temp=tail->next;
   
        if(tail==0){
           printf("list is empty"); 
           return;
        }
        else if(tail==tail->next){
            return;
        }
        else{
            while(temp!=tail){
                nextnode=temp->next;
                temp->next=prevnode;
                prevnode=temp;
                temp=nextnode;
            }
            nextnode=tail->next;
            temp->next=prevnode;
            tail=nextnode;
        }
}
int main(){
    creation();
    display();
    // printf("%d",length());
    // insert_pos();
    // display();
    reverse();
    display();
    return 0;
}