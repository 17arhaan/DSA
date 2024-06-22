#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct shapes
{
    int length;
    int width;
    int radius;
};

void isArea(float areaR , float areaT , float areaC){
    printf("Area of Rectangle is %f.\n",areaR);
    printf("Area of Triangle is %f.\n",areaT);
    printf("Area of Circle is %f.\n",areaC);
}

int main(){
    struct shapes Triangle;
    struct shapes Rectangle;
    struct shapes Circle;
    float area_rect , area_tri , area_cir;

    printf("Enter the length & width of rectangle: ");
    scanf("%d",&Rectangle.length);
    scanf("%d",&Rectangle.width);
    
    printf("Enter the length & width of triangle: ");
    scanf("%d",&Triangle.length);
    scanf("%d",&Triangle.width);

    printf("Enter the radius of circle: ");
    scanf("%d",&Circle.radius);
    
    area_rect = Rectangle.length * Rectangle.width;
    area_tri = 0.5 * Triangle.length * Triangle.width;
    area_cir = 3.14 * Circle.radius;

    isArea(area_rect,area_tri,area_cir);

    return 0;

}

