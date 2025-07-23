#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int low,int mid,int high){
   
    int n1=mid-low+1;
    int n2=high-mid;

    int *L=malloc(n1*sizeof(int));
    int *R=malloc(n2*sizeof(int));
    for (int i = 0; i < n1; i++)
    {
       L[i]=arr[low+i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i]=arr[mid+i+1];
    }
    int i=0,j=0,k=low;
    while (i<n1&&j<n2)
    {
        if (L[i]<R[j])
        {
            arr[k++]=L[i++];
        }
        else arr[k++]=R[j++];
        
    }
    while (i<n1)
    {
        arr[k++]=L[i++];
    }
    while (j<n2)
    {
        arr[k++]=R[j++];
    }
    free(L);
    free(R);
}
void mergeSort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main()
{
   int arr[]={5,7,10,8,1,9};
   int n=sizeof(arr)/sizeof(arr[0]);
   mergeSort(arr,0,n-1);
   printf("after merge sort : ");
   for (int  i = 0; i < n; i++)
   {
    printf("%d ",arr[i]);
   }
   
    return 0;
}
