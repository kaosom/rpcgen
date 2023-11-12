// quadratic.c
#include <stdio.h>
#include <math.h>

void solveQuadratic(double a, double b, double c, double *root1, double *root2) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("No real roots\n");
    } else if (discriminant == 0) {
        *root1 = *root2 = -b / (2 * a);
        printf("One real root: %.2lf\n", *root1);
    } else {
        *root1 = (-b + sqrt(discriminant)) / (2 * a);
        *root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Two real roots: %.2lf and %.2lf\n", *root1, *root2);
    }
}

int main() {
    double a, b, c;
    printf("Enter coefficients (a, b, c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double root1, root2;
    solveQuadratic(a, b, c, &root1, &root2);

    return 0;
}
