#include<stdio.h>
void isSmall(int*ptr,int*qtr,int*rtr){
    if ( *ptr < *qtr && *ptr < *rtr){
        printf("%d is the smallest number amongst.\n",*ptr);
    }
    else if ( *qtr < *ptr && *qtr < *rtr){
        printf("%d is the smallest number amongst.\n",*qtr);
    }
    else {
        printf("%d is the smallest number amongst.\n",*rtr);
    }
}
int main(){
    int a,b,c;
    printf("\nenter the first number to compare: ");
    scanf("%d",&a);
    printf("\nenter the second number to compare: ");
    scanf("%d",&b);
    printf("\nenter the third number to compare: ");
    scanf("%d",&c);
    isSmall(&a,&b,&c);
    return 0;
}