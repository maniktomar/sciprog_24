#include <stdio.h>
#include <math.h>

double trapezoidal_rule(int N, double a, double b) {
    double h = (b - a) / N;  // Width of each interval
    double sum = tan(a) + tan(b);  // Start with tan(0) + tan(pi/3)

    // Calculate sum of 2 * tan(x_i) for i = 1 to N-1
    for (int i = 1; i < N; i++) {
        double x_i = a + i * h;
        sum += 2 * tan(x_i);
    }

    // Final result for the integral
    double integral = (h / 2) * sum;
    return integral;
}

int main() {
    int N = 12;                // Number of intervals
    double a = 0.0;            // Start point
    double b = M_PI / 3;       // End point (π/3)

    double result = trapezoidal_rule(N, a, b);
    printf("Approximate integral of tan(x) from 0 to π/3: %f\n", result);
    printf("Actual value (log(2)): %f\n", log(2.0));
    printf("Error: %f\n", fabs(log(2.0) - result));

    return 0;
}