#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Uso: ./ chave de substituição\n");
    }
    else if(strlen(argv[1]) == 26)
    {
        int somaChar = 0;
        for (int i = 0, c = strlen(argv[1]); i < c; i++)
        {
            //Soma todas num da posicoes das letras maiusculas da tab. ascii.
            //caso retorne 2015 significa que nao à letras repetidas. obs: não é a solução mais adequada.
            somaChar = somaChar + toupper((int)argv[1][i]);
        }
        if(somaChar == 2015)
        {
            string texto = get_string("plaintext: ");
            int x;
            for (int i = 0, c = strlen(texto); i < c; i++)
            {
                if (isupper(texto[i]))
                {
                    x = texto[i] - 65;
                    texto[i] = toupper(argv[1][x]);
                }
                else if (isalpha(texto[i]) && islower(texto[i]))
                {
                    x = texto[i] - 97;
                    texto[i] = tolower(argv[1][x]);
                }

            }
            printf("ciphertext: %s\n", texto);
            return 0;
        }
    }
    else
    {
        printf("A chave deve conter 26 caracteres.");
    }


    return 1;
}