#include "include/cypher.h" 
#include <stdio.h>         
#include <string.h>         

int main(int argc, char *argv[]){ 
  if (argc < 4) {              
    printf("Usage:\n");     
    printf("  %s caesar   <encrypt|decrypt> <message>\n",
           argv[0]); 
    printf("  %s vigenere <encrypt|decrypt> <message> <key>\n",
           argv[0]); 
    return 1;  
  }
  char *cypher = argv[1];  
  char *type = argv[2];  
  char *message = argv[3];
  char msgRam[150];     

  strncpy(msgRam, message, sizeof(msgRam));  
  msgRam[sizeof(msgRam) - 1] = '\0';        

  if (strcmp(cypher, "caesar") == 0){ 
    if (argc != 4) {
      printf("ERROR use format: <caesar> <encrypt/decrypt> "
             "<message>\n"); 
      return 1;
    }
    if (strcmp(type, "encrypt") == 0){ 
      caesarEncrypt(msgRam);   
      printf("Encrypted message: %s\n", msgRam);
      return 0;             

    } else if (strcmp(type, "decrypt") == 0){
      caesarDecrypt(msgRam);
      printf("Decrypted message: %s\n", msgRam);
      return 0;                            

    } else {
      printf("Select encrypt or decrypt\n");
      return 1;                               
    }

  } else if (strcmp(cypher, "vigenere") ==0){   
    if (argc != 5) { 
      printf("Please use specified format: <vigenere> <encrypt/decrypt> "
             "<message> <key>\n");
      return 1;
    }

    char *key = argv[4]; 

    if (strcmp(type, "encrypt") == 0){
      vigenereEncrypt(msgRam, key); 
      printf("Encrypted message: %s\n", msgRam); 
      return 0;

    } else if (strcmp(type, "decrypt") == 0){
      vigenereDecrypt(msgRam, key);
      printf("Decrypted message: %s\n", msgRam);
      return 0;

    } else {
      printf("select encrypt or decrypt\n");
      return 1;
    }

  } else { 
    printf("Invalid cypher use 'caesar' or 'vigenere'\n");
    return 1;                                                
  }
}