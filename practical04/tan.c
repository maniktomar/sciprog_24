#include <stdio.h>
#include <math.h>

#define NUM_POINTS 13  // Number of points from 0 to 60 degrees, every 5 degrees
#define DEG_TO_RAD (M_PI / 180.0)  // Conversion factor from degrees to radians

// Global array to store tan(x) values
double tan_values[NUM_POINTS];

// Function to convert degrees to radians
double degrees_to_radians(double degrees) {
    return degrees * DEG_TO_RAD;
}

// Function to compute tan(x) values for every 5 degrees from 0 to 60
void compute_tan_values() {
    for (int i = 0; i < NUM_POINTS; i++) {
        double degrees = i * 5.0;  // 0, 5, 10, ..., 60
        double radians = degrees_to_radians(degrees);  // Convert to radians
        tan_values[i] = tan(radians);  // Compute tan(x) and store in array
        printf("tan(%3.0f degrees) = %f\n", degrees, tan_values[i]);
    }
}

// Function to calculate the area using the trapezoidal rule
double trapezoidal_rule(double values[], int n, double h) {
    double sum = values[0] + values[n - 1];  // Start with first and last terms

    // Sum 2 * tan(x_i) for the inner points
    for (int i = 1; i < n - 1; i++) {
        sum += 2 * values[i];
    }

    // Final area result
    return (h / 2) * sum;
}

int main() {
    // Step 1: Compute tan(x) values and store them in the global array
    compute_tan_values();

    // Step 2: Calculate the area under tan(x) from 0 to 60 degrees using the trapezoidal rule
    double h = degrees_to_radians(5.0);  // Interval width in radians (5 degrees)
    double area = trapezoidal_rule(tan_values, NUM_POINTS, h);

    printf("\nApproximate area under tan(x) from 0 to 60 degrees: %f\n", area);

    return 0;
}