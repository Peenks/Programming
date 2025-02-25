#include <math.h>
#include <stdio.h>

typedef struct points{
    int x;
    int y;
}myPoint;

int getPosition(myPoint point){
     if(point.x == 0 && point.y == 0){
        return 0;
    }  else if(point.x == 0 && point.y > 0 || point.x == 0 && point.y < 0){
        return 5;
    } else if(point.y == 0 && point.x > 0 || point.y == 0 && point.x < 0){
        return 6;
    } else if(point.x > 0 && point.y > 0){
        return 1;
    } else if(point.x > 0 && point.y < 0){
        return 2;
    } else if(point.x < 0 && point.y < 0){
        return 3;
    } else if(point.x < 0 && point.y > 0){
        return 4;
    } 
    
    
    return 0;
}

myPoint createPoint(int x, int y){
   myPoint point;
   
   point.x = x;
   point.y = y;
    
    return point;
}

void displayPoint(myPoint point){
    int quadrant = getPosition(point);
    
    printf("The point ");
    if(quadrant == 0){
        printf("is in origin\n");
    } else if(quadrant == 5){
        printf("is in Y-AXIS\n");
    } else if(quadrant == 6){
        printf("is in X-AXIS\n");
    } else {
        printf("is in Quadrant %d\n", quadrant);
    }

}
double getDistance(myPoint point, myPoint point2){
    int par1 = (point.x - point2.x) * (point.x - point2.x);
    int par2 = (point.y - point2.y) * (point.y - point2.y);
    
    double added = par1 + par2;
    
    double result = sqrt(added);
    
    return result;
}

int main() {
    
    
    myPoint point;
    myPoint point2;
    
    
    int x;
    int y;
    int x1;
    int y1;
    
    printf("Enter point x: ");
    scanf("%d", &x);
    
    printf("Enter point y: ");
    scanf("%d", &y);
    
    point = createPoint(x,y);
    getPosition(point);
    displayPoint(point);
    
    
    printf("Enter point k: ");
    scanf("%d", &x1);
    
    printf("Enter point j: ");
    scanf("%d", &y1);
    
    point2 = createPoint(x1,y1);
    getPosition(point2);
    displayPoint(point2);
  
    double result = getDistance(point,point2);
    
    printf("The distance is %.2lf", result);
    
    

    return 0;
}