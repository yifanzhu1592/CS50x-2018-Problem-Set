//Implement a program that encrypts messages using Caesar’s cipher, per the below.

//$ ./caesar 13
//plaintext:  HELLO
//ciphertext: URYYB


#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string p;

    if (argc != 2)
    {
        printf("Error.\n");
        return 1;
    }
    else
    {
        int k = atoi(argv[1]); // get the key
        printf("Plaintext: ");
        p = get_string(); // get the plaintext
        //encipher
        for (int i = 0; i < strlen(p); i++)
            if (isalpha(p[i]))
            {
                if (isupper(p[i]))
                    p[i] = (p[i] - 'A' + k) % 26 + 'A';
                else
                    p[i] = (p[i] - 'a' + k) % 26 + 'a';
            }
    }
    printf("ciphertext: ");
    for (int i = 0; i < strlen(p); i++)
        printf("%c", p[i]);
    printf("\n");
}
