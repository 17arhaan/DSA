#include<stdio.h>

// 1D array

/*

int main()
{
    int n;
    int array1[99];
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for (int i = 0 ; i < n ; i++)
    {
        scanf("%d",&array1[i]);
    }
    printf("the array is: \n ");
    for (int i = 0 ; i < n ; i++)
    {
        printf("%d",array1[i]);
        printf("\n");
    }
    return 0;
}

*/

// 2D array

int main(){
    int arr[99][99];
    int r,c;

    printf("Enter the no. rows : ");
    scanf("%d",&r);
    printf("Enter the no. columns : ");
    scanf("%d",&c);

    for (int i = 1 ; i <= r ; i++)
    {
        for (int j = 1 ; j <= c ; j++)
        {
            printf("Enter the element(%d,%d) : ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
        printf("\n    || Array ||\n");
        for (int i = 1 ; i <= r ; i++)
    {
        printf("\n");
        for (int j = 1 ; j <= c ; j++)
        {
            printf("%d \t",arr[i][j]);
        }
    }
}