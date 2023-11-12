// quadratic_client.c
#include <stdio.h>
#include <rpc/rpc.h>
#include "quadratic.h"

int main(int argc, char *argv[]) {
    CLIENT *cl;
    double *result;
    coefficients coeffs;

    if (argc != 5) {
        printf("Usage: %s server_host a b c\n", argv[0]);
        exit(1);
    }

    cl = clnt_create(argv[1], QUADRATIC_PROG, QUADRATIC_VERS, "tcp");
    if (cl == NULL) {
        clnt_pcreateerror(argv[1]);
        exit(1);
    }

    coeffs.a = atof(argv[2]);
    coeffs.b = atof(argv[3]);
    coeffs.c = atof(argv[4]);

    result = solvequadratic_1(&coeffs, cl);

    printf("Root 1: %.2lf\n", result[0]);
    printf("Root 2: %.2lf\n", result[1]);

    clnt_destroy(cl);

    return 0;
}
