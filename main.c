#include "enigma.h"

char *readFile(char *fileName);

int main() {

    // initialize rotors
    // for each rotor, shift it however many times its initial position is
    for ( int i = 0; i <= r1init; i++ ) {
        shiftRotor(fastRotor);
    }
    for ( int i = 0; i <= r2init; i++ ) {
        shiftRotor(semiRotor);
    }
    for ( int i = 0; i <= r3init; i++ ) {
        shiftRotor(slowRotor);
    }

    // now get what to output
    FILE *output = fopen("output", "w");
    FILE *input  = fopen("input", "r");

    // now read from the input, encrypt, and put the encrypted character into the output file

    char plainChar;
    while((plainChar = fgetc(input)) != EOF) {
        char encrypted = encryptChar(plainChar);
        fputc(encrypted, output);
        printf("Encrypting: %c -> %c\n", plainChar, encrypted);
        shiftRotors();
    }

    // close files
    fclose(output);
}
