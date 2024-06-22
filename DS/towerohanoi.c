#include<stdio.h>
#include<math.h>

static int count = 0;
void isMove ( int x , char a , char c , char b ){
    if(x==1){
        printf("moved ring %d from %c to %c\n",x,a,c);
        count ++;
        return;
    }
    isMove(x-1,a,b,c) ;
    printf("moved ring %d from %c to %c\n",x,a,c);
    count ++;
    isMove(x-1,b,c,a);
}

int main(){
    int ch;
    int d;
    printf("enter the number of disks: ");
    scanf("%d",&d);
    printf("\n");
    isMove(d,'A','C','B');
    printf("\ntotal moves: %d",count);
    return 0;
}