This encryption program can do 2 different types of cyphers, a caeser cypher and a Vigenère cypher.

The caeser cypher:
This cypher shift each letter by a certain amount, 3 in this case so A becomes D and c becomes f and so on.
use by writing the following into the terminal:
encrypt:
./main caesar encrypt (message)
decrypt:
./main caesar decrypt (message)

The Vigenère cypher:
This cypher uses a passkey to encrypt a message based on the letters in the passkey.
use by writing the following into the terminal:
encrypt:
./main vigenere encrypt (message) (passkey)
decrypt:
./main vigenere decrypt (message) (passkey)