// SAURYANSHU KHANAL, 15th March 2022

// Included Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CHAR_BITS 8
unsigned char rightEncrypt(unsigned char ch, unsigned int keyVal)
{
    return (char)(ch >> keyVal) | (ch << (CHAR_BITS - keyVal));
}
unsigned char leftDecrypt(unsigned char ch, unsigned int keyVal)
{
    return (char)(ch << keyVal) | (ch >> (CHAR_BITS - keyVal));
}
void encryptFile(char *infile_path, char *progName, unsigned int keyVal)
{
    FILE *pFILE;
    FILE *p_enFILE;
    pFILE = fopen(infile_path, "rb");
    bool fileValidity = true;
    bool encryption_check = false;

    if (pFILE == NULL)
    {
        fileValidity = false;
        printf("Error in reading the File. %s doesn't either exist, is corrupt, or is not .txt file.\n", infile_path);
    }
    p_enFILE = fopen("outfile.txt", "w");
    while (fileValidity == true)
    {
        char ch = fgetc(pFILE);
        if (ch == EOF)
        {
            fileValidity = false;
        }
        char en_ch = rightEncrypt(ch, keyVal);
        fputc(en_ch, p_enFILE);
        encryption_check = true;
    }
    if (encryption_check == true)
    {
        printf("Usage: %s %s [encrypt %s %d | decrypt outfile.txt %d] \n", progName, infile_path, infile_path, keyVal, keyVal);
    }
    if (encryption_check == false)
    {
        printf("Encryption failed\n");
    }
    fclose(pFILE);
    fclose(p_enFILE);
}
void decryptFile(char *infile_path, char *progName, unsigned int keyVal)
{
    FILE *p_enFILE;
    FILE *p_FILE;
    p_enFILE = fopen(infile_path, "rb");
    bool fileValidity = true;
    bool decryption_check = false;

    if (p_enFILE == NULL)
    {
        fileValidity = false;
        printf("Error in reading the File. %s doesn't either exist, is corrupt, or is not .txt file.\n", infile_path);
    }
    p_FILE = fopen("unencrypted.txt", "w");
    while (fileValidity == true)
    {
        char en_ch = fgetc(p_enFILE);
        if (en_ch == EOF)
        {
            fileValidity = false;
        }
        char ch = leftDecrypt(en_ch, keyVal);
        fputc(ch, p_FILE);
        decryption_check = true;
    }
    if (decryption_check == true)
    {
        printf("Usage: %s %s [encrypt %s %d | decrypt unencrypted.txt %d] \n", progName, infile_path, infile_path, keyVal, keyVal);
    }
    if (decryption_check == false)
    {
        printf("Encryption failed\n");
    }
    fclose(p_FILE);
    fclose(p_enFILE);
}
void showPreview(char *infile_path, int prevNum)
{
    FILE *pFILE;
    pFILE = fopen(infile_path, "rb");
    for (int i = 0; i <= 7; i++)
    {
        printf("key = %d: ", i);
        for (int j = 0; j <= prevNum; j++)
        {
            char encrypted_char = fgetc(pFILE);
            char decrypted_char = rightEncrypt(encrypted_char, i);
            printf("%c", decrypted_char);
        }
        printf("\n");
    }
    fclose(pFILE);
}
bool checkArgs(int argNum, char *command)
{
    if (strcmp(command, "preview") == 0)
    {
        if (argNum == 4)
        {
            return true;
        }
        printf("Invalid number of arguments AND/OR invalid commands for: %s\n", command);
        return false;
    }
    if (argNum == 3)
    {
        return true;
    }
    printf("Invalid number of arguments AND/OR invalid commands for: %s\n", command);
    return false;
}
// MAIN FUNCTION
void main(int argc, char *argv[])
{
    // Variable Declarations
    char *progName = argv[0];
    char *infile_path = argv[1];
    char *command = argv[2];
    int argNum = argc;
    unsigned int keyVal = 7;
    int prevNum;
    if (argNum == 4)
    {
        char *prevNum_char = argv[3];
        prevNum = atoi(prevNum_char);
    }
    if (checkArgs(argNum, command))
    {
        if (strcmp(command, "preview") == 0)
        {
            showPreview(infile_path, prevNum);
        }
        if (strcmp(command, "encrypt") == 0)
        {
            encryptFile(infile_path, progName, keyVal);
        }
        if (strcmp(command, "decrypt") == 0)
        {
            decryptFile(infile_path, progName, keyVal);
        }
        if (!((strcmp(command, "encrypt") == 0) || (strcmp(command, "decrypt") == 0) || (strcmp(command, "preview") == 0)))
        {
            printf("Invalid command: %s\n", command);
        }
    }
}

// 1: key 3??
