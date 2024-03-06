#include <stdio.h>
#include <stdlib.h>

int search(int *arr, int key, int n) {
    for(int *p=arr; p<arr+n; p++) {
        if((*p)==key)
            return p-arr;
    }
    return -1;
}

int main()
{
    int n, ch, key, pos;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    printf("Enter elements : \n");
    for(int *p=arr; p<arr+n; p++) 
        scanf("%d",p);
    do {
        printf("1-Add 2-Delete 3-Modify 4-Display 5-Exit : ");
        scanf("%d", &ch);
        switch(ch) 
        {
            case 1: arr = realloc(arr,sizeof(int)*(++n));
                    printf("Enter data to append : ");
                    scanf("%d", &arr[n-1]);
                    break;
            case 2: printf("Enter data to delete : ");
                    scanf("%d", &key);
                    pos = search(arr,key,n);
                    if(pos!=-1) {
                        for(int i=pos; i<n-1; i++)
                            arr[i] = arr[i+1];
                        arr = realloc(arr, sizeof(int)*(--n));
                    }
                    else 
                        printf("Element not found\n");
                    break;
            case 3: printf("Enter data which has to be modified : ");
                    scanf("%d",&key);
                    pos = search(arr,key,n);
                    if(pos!=-1) {
                        printf("Enter new data : ");
                        scanf("%d",&key);
                        arr[pos] = key;
                    }
                    else 
                        printf("Element not found\n");
                    break;
            case 4: for(int *p=arr; p<arr+n; p++)
                        printf("%d ",*p);
                    printf("\n");
                    break;
            case 5: break;
        }
    }while(ch!=5);
    return 0;
}