#ifndef RSA_PROGRAM
#define RSA_PROGRAM

long int modExp(unsigned long int base, unsigned int exp, unsigned int mod);
unsigned int gcd(unsigned int a, unsigned int b);
unsigned int modInverse(unsigned int a, unsigned int m);
unsigned char isPrime(unsigned int n);
void generateKeys(unsigned int *e, unsigned int *d, unsigned int *phi);

#endif //RSA_PROGRAM