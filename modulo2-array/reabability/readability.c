#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int segundo_calculo(int letra, int palavras, int sentencas)
{
    float l = (float) letra / palavras * 100;
    float s = (float) sentencas / palavras * 100;
    float n1 = 0.0588 * l;
    float n2 = 0.296 * s;
    float grade = n1 - n2;
    int indice = grade + 0.5 - 15.8;
    return indice;
}

int primeiro_calculo()
{
    string texto = get_string("texto: ");
    int letra = 0;
    int palavras = 1;
    int sentencas = 0;
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        if (isalpha(texto[i]))
        {
            letra++;
        }
        else if (isblank(texto[i]))
        {
            palavras++;
        }
        else if (texto[i] == '!' || texto[i] == '?' || texto[i] == '.')
        {
            sentencas++;
        }
    }
    int retorno = segundo_calculo(letra, palavras, sentencas);
    return retorno;
}

void print_resultado()
{
    int grade = primeiro_calculo();
    if (grade <= 1)
    {
        printf("Before Grade 1");
    }
    else if (grade > 1 && grade < 16)
    {
        printf("Grade %i", grade);
    }
    else
    {
        printf("Grade 16+");
    }
    printf("\n");
}

int main(void)
{
    print_resultado();
    return 0;
}