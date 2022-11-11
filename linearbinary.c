#include<stdio.h>
int linear(int arr[],int size,int elements){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==elements)       
        {
           return i;
        }
        
    }
    return -1;
    
}
int binary(int arr[],int size,int elements){
    int low,high,mid;
    low = 0;
    high= size-1;
    // start
    while (low <= high)
    {
  
    mid =(low+high)/2;
    if(arr[mid] == elements ){

    return mid;
    }
    if(arr[mid] < elements){
        low = mid + 1;
        
    }
    else{
        high = mid - 1;
    }
    
    }
return -1;
}
int main(){
    // unsorted arary for linear search
    // int arr[]={1,3,5,21,34,8,9,12,45,67,39};
    // int size =sizeof(arr)/sizeof(int);
    // sorted arary for binary search
    int arr[]={1,3,5,21,34,67,444,556};
    int size =sizeof(arr)/sizeof(int);

    int elments = 556;
    int indexsearch =binary(arr,size,elments);
    printf("The elements %d was found as index %d \n ",elments,indexsearch);


    return 0;

}