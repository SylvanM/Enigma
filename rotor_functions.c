#ifndef ROTOR_FUNCTIONS_C_
#define ROTOR_FUNCTIONS_C_

#include "rotor_functions.h"

// shift a specific rotor
void shiftRotor(char *rotor) {
    char temp = rotor[25];

    for (int i = 25; i > 0; i--) {
        rotor[i] = rotor[i-1];
    }

    rotor[0] = temp;
}

// shift all rotors
void shiftRotors() {
    shiftRotor(fastRotor);
    fastRotorHasShifted++;

    if (fastRotorHasShifted == 26) {
        fastRotorHasShifted = 0;

        // shift next rotor
        shiftRotor(semiRotor);
        semiRotorHasShifted++;

        if(semiRotorHasShifted == 26) {
            semiRotorHasShifted = 0;

            // shift slow rotor
            shiftRotor(slowRotor);
        }
    }
}

#endif
