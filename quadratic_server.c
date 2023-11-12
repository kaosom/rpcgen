// quadratic_server.c
#include <stdio.h>
#include <math.h>
#include "quadratic.h"

double* solvequadratic_1_svc(coefficients *coeffs, struct svc_req *rqstp) {
    static double result[2];
    double a = coeffs->a;
    double b = coeffs->b;
    double c = coeffs->c;

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("No real roots\n");
        result[0] = result[1] = 0.0;
    } else if (discriminant == 0) {
        result[0] = result[1] = -b / (2 * a);
        printf("One real root: %.2lf\n", result[0]);
    } else {
        result[0] = (-b + sqrt(discriminant)) / (2 * a);
        result[1] = (-b - sqrt(discriminant)) / (2 * a);
        printf("Two real roots: %.2lf and %.2lf\n", result[0], result[1]);
    }

    return result;
}
