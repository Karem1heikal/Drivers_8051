#include <reg52.h>
#include <stdlib.h>
#include "config.h"
#include "UART.h"
#include "program.h"

// Optimized Modular Exponentiation: (base^exp) % mod
long int modExp(unsigned long int base, unsigned int exp, unsigned int mod) {
    long int result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp & 1) { // If exp is odd
            result = ((long)result * base) % mod;
        }
        exp = exp >> 1; // Divide exp by 2
        base = ((long)base * base) % mod; // Square the base
    }
	
	while (result < 0) result += mod;
	while (result >= mod) result -= mod;

    return result;
}

// Compute GCD (Greatest Common Divisor)
unsigned int gcd(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Compute Modular Inverse using Extended Euclidean Algorithm
unsigned int modInverse(unsigned int a, unsigned int m) {
    unsigned int m0 = m, t, q;
    unsigned int x0 = 0;
	int x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    while (x1 < 0) x1 += m0;
	
	while (x1 >= m0) x1 -= m0;

    return x1;
}

// Fermat's Primality Test
unsigned char isPrime(unsigned int n) {
	unsigned int i;
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (i = 0; i < SECURITY_LEVEL; i++) {
        unsigned int a = (rand() % (n - 4)) + 2;
        if (modExp(a, n - 1, n) != 1) return 0;
    }
    return 1;
}

// Generate RSA Keys
void generateKeys(unsigned int *e, unsigned int *d, unsigned int *phi) {
    *e = 3;
    while (gcd(*e, *phi) != 1 && *e < *phi) {
        (*e)++;
    }
	if(*e >= *phi) {
		UART_SendString("e can't be calculated\r\n");
	}
    *d = modInverse(*e, *phi);
    //return 0;
}
