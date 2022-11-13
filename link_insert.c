#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data ;
    struct node*next;
};
// case 1
struct node  * addfirst(struct node *head, int data){
    struct  node* ptr =( struct node*) malloc(sizeof(struct node));
    ptr ->next = head;
    ptr ->data = data;
  // ptr = head;
    return ptr;
}
// case 2
struct node * insertatindex(struct node*head,int data,int index){
        struct  node* ptr =( struct node*) malloc(sizeof(struct node));
        struct  node* p = head;

    int i=0;
    while (i != index-1)  
    {
        p=p ->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next=ptr;
    return head;
    
}
// case 3
struct node * insertatend(struct node*head,int data){
        struct  node* ptr =( struct node*) malloc(sizeof(struct node));
        struct  node* p = head;
        ptr->data = data;
   
    while( (ptr->next) != NULL )  
    {
        p=p->next;
    }
    
    p->next=ptr;
    ptr ->next = NULL;
    return head;
    
}
// case 4
struct node *insertafternode(struct node*head,struct node * prenode,int data){
        struct  node* ptr =( struct node*) malloc(sizeof(struct node));
    ptr ->data=data;
    ptr->next =prenode->next;
    prenode->next = ptr;
    return head;
    
}
void display(struct node * ptr){
    while(ptr != NULL){
    printf("Element ; %d \n ", ptr->data);
    ptr = ptr->next;
    }
}

int main(){
      struct node *head ;
    struct node *secound ;
    struct node *third ;
    struct node *fourth ;

    // allocates memory for nodes in the linked list in heap
    head = (struct node *)malloc(sizeof(struct node));
    secound = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // Link the head node and the second node 
    head -> data = 3;
    head -> next = secound;
     // Link the secound node and the third node 
    secound -> data = 5;
    secound -> next = third;
    // Link the third node and the forth node 
   third -> data = 25;
   third-> next = fourth;
     // terminate list at third node 
    fourth -> data = 7;
    fourth -> next = NULL;
    printf("Linked list before inserstion");
   display(head);
  //head= addfirst(head,69);
  //  head=insertatindex(head,69,1);
 // head = insertatend(head,69);
 head = insertafternode(head,secound,69);
    printf("Linked list after inserstion");
    
    display(head);
   // display(head);
    
    return 0;
}