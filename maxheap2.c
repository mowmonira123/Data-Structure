#include<stdio.h>
#include<math.h>
int parent(int i)
{
    return (i-1)/2;
}
int left(int i)
{
    return 2*i+1;
}
int right(int i)
{
    return 2*i+2;
}
void maxheapify(int arr[], int n, int i)
{
    int l, r,largest,temp;
    l = left(i);
    r = right(i);
    if(l<n && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if(r<n && arr[r] > arr[largest])
        largest = r;
    //printf("\ni=%d  l=%d  r=%d largest=%d",i,l,r,largest);
    if(largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxheapify(arr,n,largest);
    }
}

void main()
{
    int arr[20];
    int i=0,n;
    printf("Enter the number of element in array : ");
    scanf("%d",&n);
    printf("\nEnter the elements : ");
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);

    printf("\nArray before max heap \n\n");
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);

   for(int x=(n-1)/2;x>=0;x--)
        for(i=0; i<n; i++)
        maxheapify(arr,n,i);


    printf("\nArray after Maxheap \n\n");

    for(i=0; i<n; i++)
        printf("%d ",arr[i]);

    getch();
    return 0;
}
