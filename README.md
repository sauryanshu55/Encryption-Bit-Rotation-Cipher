# Encryption-Bit-Rotation-Cipher
Encrypts a text file using bit-rotation method around a block of 1 byte (8 bits), the size of the char-type in C. Decrypts the same file when appropriate command is used in the command line.

<b> ENCRYPTION </b> <br>
```
$> gcc bitrot.c -o bitrot 
$> ./bitrot <FILEPATH FOR FILE TO BE ENCRYPTED> encrypt 
```
This command will create a file called outfile.txt in the local folder where the infile is located.<br>

<b> DECRYPTION </b><br>
```
$> gcc bitrot.c -o bitrot
$> ./bitrot <FILEPATH OF THE FILE TO BE DECRYPTED FROM THE PREV ENC KEY> decrypt
```
This command will create a file called unencrypted.txt in the local folder where the encrypted file with the same encryption key was located. <br>

<i> By Sauryanshu Khanal (Chhetri) </i>
