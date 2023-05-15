#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void criptografia(int key)
{
    string texto = get_string("plaintext: ");
    int calculo;

    for (int i = 0, c = strlen(texto); i < c; i++)
    {

        if (isalpha(texto[i]) && isupper(texto[i]))
        {
            int criptografia = (int)texto[i] - 65 + key;
            calculo = criptografia % 26 + 65;
        }
        else if (isalpha(texto[i]) && islower(texto[i]))
        {
            int criptografia = (int)texto[i] - 97 + key;
            calculo = criptografia % 26 + 97;
        }
        else
        {
            calculo = texto[i];
        }
        texto[i] = (char)calculo;
    }
    printf("ciphertext: %s\n", texto);
    exit(0);
}

int main(int argc, string argv[])
{
    int key = atoi(argv[1]);

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (argc == 2 && key >= 1)
    {
        for (int i = 0, c = strlen(argv[1]); i < c; i++)
        {
            if (isdigit(argv[1][i]))
            {
                if(i == c - 1)
                {
                    criptografia(key);
                }
            }
        }
    }
    printf("Usage: ./caesar key\n");
    return 1;
}

