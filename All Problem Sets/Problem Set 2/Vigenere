//Implement a program that encrypts messages using Vigenère’s cipher, per the below.

//$ ./vigenere ABC
//plaintext:  HELLO
//ciphertext: HFNLP


#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string k = argv[1]; // get the key
    string p;
    int counter = 0;

    if (argc != 2)
    {
        printf("Error.\n");
        return 1;
    }
    else
    {
        for (int j = 0; j < strlen(k); j++)
        {
            if (isalpha(k[j]))
                continue;
            else
            {
                printf("Error.\n");
                return 1;
            }
        }
        printf("Plaintext: ");
        p = get_string(); // get the plaintext
        //encipher
        for (int i = 0; i < strlen(p); i++)
        {
            if (isalpha(p[i]))
            {
                if (isupper(k[(i - counter) % strlen(k)]))
                {
                    if (isupper(p[i]))
                        p[i] = (p[i] + k[(i - counter) % strlen(k)] - 'A' - 'A') % 26 + 'A';
                    else
                        p[i] = (p[i] + k[(i - counter) % strlen(k)] - 'A' - 'a') % 26 + 'a';
                }
                else
                {
                    if (isupper(p[i]))
                        p[i] = (p[i] + k[(i - counter) % strlen(k)] - 'a' - 'A') % 26 + 'A';
                    else
                        p[i] = (p[i] + k[(i - counter) % strlen(k)] - 'a' - 'a') % 26 + 'a';
                }
            }
            else
                counter++;
        }
    }
    printf("ciphertext: ");
    for (int i = 0; i < strlen(p); i++)
        printf("%c", p[i]);
    printf("\n");
}
