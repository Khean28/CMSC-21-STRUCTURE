#include <stdio.h>
#include <math.h>

//following the same code in the assignment guide for declaring the line struct
struct line {
    struct point{
        float x;
        float y;
    }
    // declare point1 and point2 w/c are also structs as they store 2 values (float x and float y)
    point1, // point1 will have (x1, y1)
    point2; // point2 will have (x2, y2)
    float *midpoint; // midpoint is a pointer since it is an array storing 2 values
    float slope;
    float distance;
};

// following the same code in the assignment guide for declaring the functions
float solveSlope(struct line line1);
float *solveMidpoint(struct line line1);
float solveDistance(struct line line1);
void getSlopeInterceptForm(struct line line1);

int main() {
    struct line line1;
    
    printf("Enter x and y for point1: ");
    scanf("%f %f", &line1.point1.x, &line1.point1.y);
    // assigns the values of x and y for point1 by using the dot address of the struct (i.e. line1.point1.x for x1, line1.point1.y for y1)

    printf("Enter x and y for point2: ");
    scanf("%f %f", &line1.point2.x, &line1.point2.y);
    // same as above (i.e. line1.point2.x for x2, line1.point2.y for y2)


    // assign struct values to the results of the functions
    line1.slope = solveSlope(line1); // value to be used for slope-intercept form
    line1.midpoint = solveMidpoint(line1);
    line1.distance = solveDistance(line1);
    
    // printing the results
    printf("Slope: %.6f\n", line1.slope);
    printf("Midpoint: %.6f %.6f\n", line1.midpoint[0], line1.midpoint[1]);
    printf("Distance between 2 points: %.6f\n", line1.distance);
    getSlopeInterceptForm(line1);
    
    return 0;
}

// solveSlope based on the formula:
// m = (y1 - y2) / (x1 - x2)
float solveSlope(struct line line1) {
    return (line1.point1.y - line1.point2.y) / (line1.point1.x - line1.point2.x);
}

// midpoint based on the formula:
// midpoint = ((x1 + x2) / 2, (y1 + y2) / 2)
float *solveMidpoint(struct line line1) {
    static float midpoint[2]; // declare midpoint as a static array of size 2
    
    midpoint[0] = (line1.point1.x + line1.point2.x) / 2; // (x1 + x2) / 2 = midpoint[0]
    midpoint[1] = (line1.point1.y + line1.point2.y) / 2; // (y1 + y2) / 2 = midpoint[1]
    return midpoint;
}

// distance based on the formula:
// d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
float solveDistance(struct line line1) {
    return sqrt(pow(line1.point2.x - line1.point1.x, 2) + pow(line1.point2.y - line1.point1.y, 2));
}

// slope intercept form based on the formula:
// y = mx + b
void getSlopeInterceptForm(struct line line1) {
    float b = line1.point1.y - line1.slope * line1.point1.x;
    printf("y = %.5fx + (%.6f)\n", line1.slope, b);
}
