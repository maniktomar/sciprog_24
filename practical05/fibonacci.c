#include <stdio.h>
#include <math.h>

// Function to compute the next Fibonacci number
void compute_next_fib(int *fn1, int *fn2) {
    int next = *fn1 + *fn2;
    *fn1 = *fn2;
    *fn2 = next;
}

// Function to calculate arctanh(x) using Maclaurin series
double artanh1(double x, double delta) {
    double sum = 0.0;
    double term = x;
    int n = 0;

    while (fabs(term) >= delta) {
        sum += term;
        n++;
        term = pow(x, 2 * n + 1) / (2 * n + 1);
    }

    return sum;
}

// Function to calculate arctanh(x) using natural logarithms
double artanh2(double x) {
    return 0.5 * (log(1 + x) - log(1 - x));
}

int main() {
    // Exercise 1: Fibonacci Series
    int n;
    printf("Enter the value of n for the Fibonacci series: ");
    scanf("%d", &n);

    int fn1 = 0, fn2 = 1;
    printf("Fibonacci series up to %d:\n", n);
    printf("%d ", fn1);

    for (int i = 1; i < n; i++) {
        printf("%d ", fn2);
        compute_next_fib(&fn1, &fn2);
    }
    printf("\n");

    // Exercise 2: Inverse Hyperbolic Tangent (arctanh)
    double delta;
    printf("\nEnter a positive real number delta for Maclaurin series precision: ");
    scanf("%lf", &delta);

    double results_maclaurin[181];
    double results_log[181];

    // Calculate arctanh(x) for x in [-0.9, 0.9] with step of 0.01
    printf("\nCalculating arctanh(x) using both methods for x in [-0.9, 0.9]:\n");
    for (int i = 0; i <= 180; i++) {
        double x = -0.9 + i * 0.01;
        results_maclaurin[i] = artanh1(x, delta);
        results_log[i] = artanh2(x);

        printf("x = %.2f, artanh1 (Maclaurin) = %.10f, artanh2 (Logarithmic) = %.10f\n", 
                x, results_maclaurin[i], results_log[i]);
    }

    return 0;
}