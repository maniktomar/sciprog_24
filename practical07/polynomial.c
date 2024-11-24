#include <stdio.h>
#include <stdlib.h>

// Function to calculate factorial
double factorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to estimate the value of e using a polynomial
double estimate_e(int order) {
    double *terms = (double*) malloc((order + 1) * sizeof(double));
    if (terms == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    double estimate = 0.0;
    for (int i = 0; i <= order; i++) {
        terms[i] = 1.0 / factorial(i); // Each term x^i / i! with x=1
        estimate += terms[i];
    }

    // Display each term
    printf("Estimate for order %d: %lf\n", order, estimate);

    // Free allocated memory
    free(terms);
    return estimate;
}

int main() {
    int order;
    printf("Enter the order of the polynomial: ");
    scanf("%d", &order);

    double actual_e = 2.71828; // Known approximate value of e
    double estimate = estimate_e(order);

    printf("Actual value of e: %lf\n", actual_e);
    printf("Difference: %lf\n", actual_e - estimate);

    return 0;
}
