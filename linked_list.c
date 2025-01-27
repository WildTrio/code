#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void creation() {
    struct node *newnode, *temp;
    int choice = 1;

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        
        if(newnode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to add another node? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    }
}

void print() {
    struct node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insert_begin(){
    struct node *newnode;
    newnode=(struct node*) malloc(sizeof(struct node));
    printf("Enter the data");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}
void insert_end(){
    struct node *newnode;
    newnode=(struct node*) malloc(sizeof(struct node));
    printf("Enter the data");
    scanf("%d",&newnode->data);
    newnode->next=0;
    struct node *temp=head;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=newnode;

}
void insert_pos(){
    struct node *newnode;
    struct node *temp=head;
    int pos,i=1;
    printf("enter the position");
    scanf("%d",&pos);
    while(i<pos-1){
        temp=temp->next;
        i++;
    }

    newnode=(struct node*) malloc(sizeof(struct node));
    printf("enter the data");
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    temp->next=newnode;
}
void del_beg(){
    struct node *temp;
    temp=head;
    head=temp->next;
    free(temp);
}
void del_end(){
    struct node *temp;
    struct node *prevnode;
    temp=head;
    while(temp->next!=0){
        prevnode=temp;
       temp=temp->next;
    }
    if(temp==head){
     free(temp);
     head=0;
    }  
    else{
    prevnode->next=0;
    free(temp);
}
}
void del_pos(){
    struct node *temp;
    struct node *prevnode;
    int pos,i=1;
    scanf("%d",&pos);
    temp=head;
    while(i<pos){
        prevnode=temp;
        temp=temp->next;
        i++;
    }
    if(temp==head){
        head=0;
        free(temp);
    }
    else{
         prevnode->next=temp->next;
        free(temp);
    }
   

}
void length(){
    struct node *temp;
    temp=head;
    int count=0;
    while(temp->next!=0){
        temp=temp->next;
        count++;
    }
    printf("%d",count);
}
void reverse(){
    struct node *prevnode,*temp,*nextnode;
    prevnode=0;
    temp=head;
    nextnode=head;
    while(nextnode!=0){
        nextnode=temp->next;
        temp->next=prevnode;
        prevnode=temp;
        temp=nextnode;
    }
    head=prevnode;

}

int main() {
    creation();
    print();
    reverse();
    print();

    return 0;
}
