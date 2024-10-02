#include <stdio.h>
// add your structure here
typedef struct {
    int x;
    int y;
} point;


// add your function prototypes here
int displayPoint(point p){
    printf("(%d, %d)",p.x, p.y);
}

point createPoint(int x, int y){
    point where;
    where.x = x;
    where.y = y;
    
    return where;
}

int identifyPoint(point p){
    if(p.x == 0 && p.y == 0){
        return 0;
    } else if(p.x > 0 && p.y > 0){
        return 1;
    } else if(p.x > 0 && p.y < 0){
        return 4;
    } else if(p.x < 0 && p.y > 0){
        return 2;
    } else if(p.x < 0 && p.y < 0){
        return 3;
    } else if(p.x > 0 && p.y == 0 || p.x < 0 && p.y == 0){
        return 5;
    } else if(p.x == 0 && p.y > 0 || p.x == 0 && p.y < 0){
        return 6;
    }
}

void main() {
    point p;
    int x, y;

    printf("Enter x - coordinate: ");
    scanf("%d", &x);
    printf("Enter y - coordinate: ");
    scanf("%d", &y);

   p = createPoint(x,y);
   int quadrant = identifyPoint(p);
   printf("The point ");
   if(quadrant == 0){
       displayPoint(p);
       printf(" is in Origin.");
   } else if(quadrant == 5){
       displayPoint(p);
       printf(" is in x-axis.");
   } else if(quadrant == 6){
       displayPoint(p);
       printf(" is in y-axis.");
       
   } else {
       displayPoint(p);
       printf(" is in Q%d.", quadrant);
   }

}