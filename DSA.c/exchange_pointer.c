#include<stdio.h>
void exchange (int*ptr , int*qtr){
    int temp;
     temp = *ptr;
     *ptr = *qtr;
     *qtr = temp;
}
int main(){
    int a,b;
    printf("enter the numbers to exchange: ");
    scanf("%d",&a);
    scanf("%d",&b);
    exchange(&a,&b);
    printf("exchanged numbers: %d %d ",a,b);
    return 0;
}