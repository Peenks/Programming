#include <stdio.h>
#include <math.h>
#define PI M_PI 

// Use M_PI for PI
typedef struct{
    float radius;
} Circle;

int main(void) {
    Circle circle1;
    float Circ;
    float Area;
    
    printf("Enter radius: ");
    scanf("%f", &circle1.radius);
    
    Circ = 2 * PI * circle1.radius;
    Area = PI * circle1.radius * circle1.radius;
    
    printf("Circumference: %.2f\n", Circ);
    printf("Area: %.2f\n", Area);
    
    return 0;
}