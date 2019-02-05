#ifndef HARDWARE_H_
#define HARDWARE_H_

/* ----------- CONFIG ------------- */

// this is where you set the "key" to the enigma machine

// Rotor positions are 0-25

// initial position of rotor 1
int r1init = 0;

// initial position of rotor 2
int r2init = 0;

// initial position of rotor 3
int r3init = 0;

// plugboard
char plugboard[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/* --------- END CONFIG ---------- */


// Rotors and Hardware setup

char alphabet[26]  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char fastRotor[26] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
char semiRotor[26] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
char slowRotor[26] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";

char reflector[26] = "EJMZALYXVBWFCRQUONTSPIKHGD";

int fastRotorHasShifted = 0; // keeps track of how many times the fastRotor has been shifted
int semiRotorHasShifted = 0; // keeps track of how many times the semiRotor has been shifted

#endif
