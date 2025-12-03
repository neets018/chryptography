#include "include/cypher.h" // Include Vigenère cipher function declarations
#include <stdio.h>            // For input/output (printf)
#include <string.h>           // For string functions like strcmp and strncpy

int main(int argc, char *argv[]) { // Program entry point; argc = argument
                                   // count, argv = argument values
  if (argc < 4) {                  // If too few arguments were givendn
    printf("Usage:\n");            // Print usage instructions
    printf("  %s caesar   <encrypt|decrypt> <message>\n",
           argv[0]); // Example for Caesar
    printf("  %s vigenere <encrypt|decrypt> <message> <key>\n",
           argv[0]); // Example for Vigenère
    return 1;        // Exit with error code 1
  }

  char *cipher = argv[1];  // The first argument after the program name (which cipher to use)
  char *mode = argv[2];    // The second argument (encrypt or decrypt)
  char *message = argv[3]; // The third argument (the text to process)
  char msgRam[150];        // Buffer to store a copy of the message

  strncpy(msgRam, message, sizeof(msgRam)); // Copy message safely into buffer
  msgRam[sizeof(msgRam) - 1] = '\0';        // Ensure string ends properly

  if (strcmp(cipher, "caesar") == 0) { // If the chosen cipher is "caesar"
    if (argc != 4) { // Check correct number of arguments for Caesar
      printf("Please use specified format: <caesar> <encrypt/decrypt> "
             "<message>\n");
      return 1; // Exit if incorrect usage
    }

    if (strcmp(mode, "encrypt") == 0) { // If user chose encryption
      caesarEncrypt(msgRam);           // Call Caesar encryption function
      printf("Encrypted message: %s\n", msgRam); // Print the result
      return 0;                                  // Exit successfully

    } else if (strcmp(mode, "decrypt") == 0) { // If user chose decryption
      caesarDecrypt(msgRam); // Call Caesar decryption function
      printf("Decrypted message: %s\n", msgRam); // Print the result
      return 0;                                  // Exit successfully

    } else { // If mode is neither encrypt nor decrypt
      printf("Please select encrypt or decrypt\n"); // Error message
      return 1;                                     // Exit with error
    }

  } else if (strcmp(cipher, "vigenere") ==
             0) {    // If chosen cipher is "vigenere"
    if (argc != 5) { // Must include key argument
      printf("Please use specified format: <vigenere> <encrypt/decrypt> "
             "<message> <key>\n");
      return 1; // Exit if incorrect usage
    }

    char *key = argv[4]; // Store the encryption key

    if (strcmp(mode, "encrypt") == 0) { // If encrypt mode
      vigenereEncrypt(msgRam, key);    // Call Vigenère encryption function
      printf("Encrypted message: %s\n", msgRam); // Print encrypted text
      return 0;                                  // Exit successfully

    } else if (strcmp(mode, "decrypt") == 0) { // If decrypt mode
      vigenereDecrypt(msgRam, key); // Call Vigenère decryption function
      printf("Decrypted message: %s\n", msgRam); // Print decrypted text
      return 0;                                  // Exit successfully

    } else {                                        // Invalid mode
      printf("Please select encrypt or decrypt\n"); // Error message
      return 1;                                     // Exit with error
    }

  } else { 
    printf("Invalid cipher (use 'caesar' or 'vigenere')\n"); // error message
    return 1;                                                
  }
}