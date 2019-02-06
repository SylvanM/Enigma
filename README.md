# Enigma
## How to run
### Installation
This step is pretty easy. Just download the repository and put the folder somewhere.
Note: Do not put the folder in a directory where its file path has a space in it. This confuses the compiler because instead of escaping the space, it considers it two different commands.

### Running/Compilation
If you have a UNIX system, this step is easy. In the downloaded folder there is a file called "run_on_mac". Run it. This runs a shell script that will compile the program and then run it. After running "run_on_mac", just check the output file and there should be the encrypted/decrypted text.

If you have a Windows computer, you will have to compile it and run it yourself because I don't have much experience with Windows. I will work on adding a .exe file for Windows that will do the same as the "run_on_mac" file.

## Usage
If you are unfamiliar with what the machine is or its basic operation, please read [this wikipedia paragraph](https://en.wikipedia.org/wiki/Enigma_machine#Basic_operation).

To set the rotor positions for the enigma, open the hardware.h file. It should look like this:
```c
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
```
For each to set the position of the first rotor, change the value of r1init, and so on.
Changing the plugboard is a matter of having a jumbled-up version of the alphabet. 

Note: If you are editing the plugboard, the new plugboard **must** have **every** letter of the alphabet once **in capital letters**.

If for some reason your heart desires to change the rotors/reflector of the enigma, those are edited the same way the plugboard is.

### Configuration example
The following configuration sets the rotors to 4, 2, and 26, and sets the plugboard to "QWERTZUIOASDFGHJKPYXCVBNML":
```c
/* ----------- CONFIG ------------- */

// this is where you set the "key" to the enigma machine

// Rotor positions are 0-25

// initial position of rotor 1
int r1init = 3;

// initial position of rotor 2
int r2init = 1;

// initial position of rotor 3
int r3init = 5;

// plugboard
char plugboard[26] = "QWERTZUIOASDFGHJKPYXCVBNML";

/* --------- END CONFIG ---------- */
```

### Input and Output
This part is pretty simple. Just open the input file in the folder and type whatever you want to encrypt. Run the program. The program will create an output file and encrypt to it. When the program finishes, open the output file to see your encrypted message.
