#ifndef ENIGMA_C_
#define ENIGMA_C_

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "enigma.h"

// encryption rotor_functions

int length(char array[]) {
    return strlen(array);
}

int findIndex(char array[], char value) {
    for (int i = 0; i < length(array); i++) {
        if (array[i] == value) {
            return i;
        }
    }

    return -1;
}

char encryptChar(char plainChar) {
    // most tedious part of the program.

    if (plainChar == ' ') { return ' '; } // don't encrypt whitespace

    char upperChar = toupper(plainChar);
    int index = findIndex(plugboard, upperChar);

    if (index == -1) { return plainChar; } // character is not a regular letter so just ignore it

    // find alphabet letter with that index, then find the new index on the rotor
    char currentChar = alphabet[index];
    index = findIndex(fastRotor, currentChar);

    // find alphabet letter with that index, then find the new index on the rotor
    currentChar = alphabet[index];
    index = findIndex(semiRotor, currentChar);

    // find alphabet letter with that index, then find the new index on the rotor
    currentChar = alphabet[index];
    index = findIndex(slowRotor, currentChar);

    // now find that letter in the alphabet, then reflector
    currentChar = alphabet[index];
    index = findIndex(reflector, currentChar);

    // now pass back!

    currentChar = slowRotor[index];
    index = findIndex(alphabet, currentChar);

    currentChar = semiRotor[index];
    index = findIndex(alphabet, currentChar);

    currentChar = fastRotor[index];
    index = findIndex(alphabet, currentChar);

    currentChar = plugboard[index];

    return currentChar;

}

#endif
