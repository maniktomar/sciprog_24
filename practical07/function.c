#include <stdio.h>

// Iterative function to find GCD using Euclidean algorithm
int gcd_iterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Recursive function to find GCD using Euclidean algorithm
int gcd_recursive(int a, int b) {
    if (b == 0)
        return a;
    return gcd_recursive(b, a % b);
}

int main() {
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int gcd_iter = gcd_iterative(a, b);
    int gcd_rec = gcd_recursive(a, b);

    printf("GCD (Iterative) of %d and %d: %d\n", a, b, gcd_iter);
    printf("GCD (Recursive) of %d and %d: %d\n", a, b, gcd_rec);

    return 0;
}
