#include <reg52.h>
#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "UART.h"
#include "program.h"

// Global Variables
unsigned int publicKey, privateKey, modulus;
unsigned int i; // Iterator for loops

// Main Function
void main() {
    unsigned int plaintext, ciphertext, decrypted, p, q, phi;
    char buffer[MAX_BUFFER];
    char mode;

    UART_Init();
    UART_SendString("Enhanced RSA on 8052 Initialized\r\n");

    while (1) {
        UART_SendString("Choose mode: (e)ncrypt or (d)ecrypt: ");
        mode = UART_ReceiveChar();
        UART_SendChar(mode);
        UART_SendString("\r\n");

        if (mode == 'e') {
            UART_SendString("Enter plaintext: ");
        } else if (mode == 'd') {
            UART_SendString("Enter ciphertext: ");
        } else {
            UART_SendString("Invalid mode.\r\n");
            continue;
        }

        // Input plaintext or ciphertext
        for (i = 0; i < MAX_BUFFER; i++) buffer[i] = 0; // Clear buffer
        for (i = 0; i < MAX_BUFFER - 1; i++) {
            buffer[i] = UART_ReceiveChar();
            if (buffer[i] == '\r' || buffer[i] == '\n') break; // End on carriage return
            UART_SendChar(buffer[i]); // Echo back
        }
		UART_SendString("\r\n");
        plaintext = atoi(buffer);

        // Input primes p and q
        while (1) {
            UART_SendString("Enter prime p: ");
            for (i = 0; i < MAX_BUFFER; i++) buffer[i] = 0;
            for (i = 0; i < MAX_BUFFER - 1; i++) {
                buffer[i] = UART_ReceiveChar();
                if (buffer[i] == '\r' || buffer[i] == '\n') break;
                UART_SendChar(buffer[i]);
            }
            p = atoi(buffer);

            if (isPrime(p)) {
                UART_SendString(" -> p is prime.\r\n");
                break;
            } else {
                UART_SendString(" -> p is not prime. Try again.\r\n");
            }
        }

        while (1) {
            UART_SendString("Enter prime q: ");
            for (i = 0; i < MAX_BUFFER; i++) buffer[i] = 0;
            for (i = 0; i < MAX_BUFFER - 1; i++) {
                buffer[i] = UART_ReceiveChar();
                if (buffer[i] == '\r' || buffer[i] == '\n') break;
                UART_SendChar(buffer[i]);
            }
            q = atoi(buffer);

            if (isPrime(q)) {
                UART_SendString(" -> q is prime.\r\n");
                break;
            } else {
                UART_SendString(" -> q is not prime. Try again.\r\n");
            }
        }

        // Generate keys
        modulus = p * q;
		sprintf(buffer, "modulus = %u\r\n", modulus);
		UART_SendString(buffer);
		phi = (p - 1) * (q - 1);
		sprintf(buffer, "phi = %u\r\n", phi);
		UART_SendString(buffer);
		
        generateKeys(&publicKey, &privateKey, &phi);
		
		sprintf(buffer, "e = %u\r\n", publicKey);
		UART_SendString(buffer);
		sprintf(buffer, "d = %u\r\n", privateKey);
		UART_SendString(buffer);

		// Encrypt or decrypt
        if (mode == 'e') {
            ciphertext = modExp(plaintext, publicKey, modulus);
            sprintf(buffer, "Ciphertext: %u\r\n", ciphertext);
            UART_SendString(buffer);
			UART_SendString("\r\n");
        } else if (mode == 'd') {
            decrypted = modExp(plaintext, privateKey, modulus);
            sprintf(buffer, "Decrypted text: %u\r\n", decrypted);
            UART_SendString(buffer);
			UART_SendString("\r\n");
        }
    }
}
