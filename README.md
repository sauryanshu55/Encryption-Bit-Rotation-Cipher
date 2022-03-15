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

If gcc is not installed:<br>
```
$> gcc sudo apt install
```
<b> ERROR RETURNS </b>
```
$> ./bitrot <filepath> ENCRYPT
Invalid Command

$> ./bitrot <Non-existent, corrupt, incorrect, or incorrect extension filepath> decrypt
Error in reading file <> Doesn't either Exist, is corrupt, or is not a .txt file.

$> ./bitort
Invalid number of arguments

$> ./bitrot <filepath> decrypt
Encryption failed
```
<i> By Sauryanshu Khanal (Chhetri) </i>
