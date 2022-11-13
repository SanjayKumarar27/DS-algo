#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data ;
    struct node*next;
};
// case 1 deleting the first node 0(1)
struct node  * deletefirst(struct node *head){
    struct  node* ptr = head;
    head = head->next;
    free(ptr);
return head;
  }
// case 2 deleting the  node in between
struct node* deleteinbetween(struct node *head, int index){
    struct node * p = head;
    int i =0;
    while (i < index-1)
    {
        p = p->next;
        i++;
    }
    struct node * q = p->next;

    p->next=q->next;
    free(q);
    return head;

    
}
// case 2.1
struct node*deleteinbetween2(struct node * head, int index){
    struct node *p= head;
    struct node *q= head->next;
    for (int i = 0; i <index -1; i++)       
    {
        p=p->next;
        q=q->next;

    }
    p->next=q->next;
    free(q);
    return head;
    
    
}

// case 3 deleting the last  node
struct node * deletelast(struct node*head){
    struct node *p = head ;
    struct node *q= head->next;
    while (q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    
    
    p->next=NULL;
   
    free(q);
    return head;
}
// case 4 deleting the node with given data
struct node*deleteatvalue(struct node * head, int value){
    struct node *p= head;
    struct node *q= head->next;
    for (int i = 0; q->data!=value && q->next!=NULL; i++)       
    {
        p=p->next;
        q=q->next;

    }
    if(q->data == value)
    {
        p->next=q->next;
    }
    else{
        printf("Invalid Value");
        exit (0);
    }
    free(q);
    return head;
    
    
}
void display(struct node * ptr){
    while(ptr != NULL){
    printf("Element : %d \n ", ptr->data);
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
  third -> next = fourth;
     // terminate list at third node 
    fourth -> data = 7;
    fourth -> next = NULL;
  printf("The list before deleting\n");
    display(head);
 //case1 head = deletefirst(head);
  printf("The list after deleting\n");
  //head = deleteinbetween(head,3);
  //head = deletelast(head);
  head = deleteatvalue(head,7);
    display(head);
    return 0;
}