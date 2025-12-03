#include "cypher.h" 
#include <ctype.h>  
#include <string.h>  

void caesarEncrypt(char text[]){
  for (int i = 0; text[i] != '\0'; i++) {
    char character = text[i];            
    if (isalpha(character)) {
      int shift = 3;         
      if (isupper(character))
        character = ((character - 'A' + shift) % 26) + 'A';
      else 
        character = ((character - 'a' + shift) % 26) + 'a';
    }

    text[i] = character; 
  }
}

void caesarDecrypt(char text[]){
  for (int i = 0; text[i] != '\0'; i++){ 
    char character = text[i];             
    if (isalpha(character)) { 
      int shift = 3;       
      if (isupper(character)) 
        character = ((character - 'A' - shift + 26) % 26) + 'A';
      else 
        character = ((character - 'a' - shift + 26) % 26) + 'a';
    }
    text[i] = character;
  }
}

void vigenereEncrypt(char text[], char key[]){
  int keyLength = strlen(key);

  for (int i = 0, j = 0; text[i] != '\0'; i++){
    char character = text[i];

    if (isalpha(character)) {
      int shift = tolower(key[j % keyLength]) - 'a';

      if (isupper(character))
        character = ((character - 'A' + shift) % 26) + 'A';
      else
        character = ((character - 'a' + shift) % 26) + 'a';

      j++;
    }
    text[i] = character; 
  }
}

void vigenereDecrypt(char text[], char key[]){
  int keyLength = strlen(key);

  for (int i = 0, j = 0; text[i] != '\0'; i++){
    char character = text[i];

    if (isalpha(character)) {
      int shift = tolower(key[j % keyLength]) - 'a';

      if (isupper(character))
        character = ((character - 'A' - shift + 26) % 26) + 'A';
      else
        character = ((character - 'a' - shift + 26) % 26) + 'a';
      j++;
    }

    text[i] = character; 
  }
}