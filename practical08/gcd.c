#include <stdio.h>

// Iterative function to calculate GCD
int gcd_iterative(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Recursive function to calculate GCD
int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd_recursive(b, a % b);
    }
}

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Calculate and print GCD using the iterative function
    printf("GCD (Iterative): %d\n", gcd_iterative(num1, num2));

    // Calculate and print GCD using the recursive function
    printf("GCD (Recursive): %d\n", gcd_recursive(num1, num2));

    return 0;
}
