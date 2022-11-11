
#include<stdio.h>
struct array
{
    int total_size;
    int used_size;
    int *ptr;
} ;
void createarr(struct array*a,int tsize,int usize){
    // declaration of array
    a->total_size=tsize;
    a->used_size=usize;
    a->ptr =(int *)malloc(tsize*sizeof(int));

}
void show(struct array*a){
    // prints the array
    printf("The array is ");
    for (int i = 0; i < a->used_size; i++)     
    {
        printf("%d ",(a->ptr)[i]);
    }
}
void setvalue(struct array *a){
    // enter the elements of the array
 
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the element no %d ",i);
        scanf("%d",&(a->ptr)[i]);
        }
}
int insert(struct array*a){
    // code for inserstion of the array
    int index,i,element;
    printf("Enter the position at which the element should be inserted; ");
    scanf("%d",&index);
    printf("Enter the element to be inserted ");
    scanf("%d",&element);
    if( index > (a->used_size)){
        return -1;
    }
    for (int i = ((a->used_size)-1); i >= index; i--)
    {
        (a->ptr)[i+1]=(a->ptr)[i];
    }
    (a->ptr)[index]=element;
    (a->used_size) += 1;
    return 1;
    

}
void delete(struct array*a)
{
    // code for Deletion
    int index;
    printf("Enter the position at which the element should be deleted; ");
    scanf("%d",&index);
    for (int i = index; i < (a->used_size)-1; i++)
    {
        (a->ptr)[i] = (a->ptr)[i + 1];
    }  
    (a->used_size) -= 1;
}
int main()

{
    
    int arr[12];
    struct arr;
    createarr(&arr,10,5);
    setvalue(&arr);
    show(&arr);
   
    insert(&arr);
     show(&arr);
    delete(&arr);
     show(&arr);
        return 0;
}