#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long cartao = get_long("insira o numero do cartão: ");
    int digito = (int)log10(cartao) + 1; //o operador log10 devolve o numero total de digitos. //O operador pow me devolve o divisor em forma de potencia (10 elevado à x pontencia).//onde o x representa o expoente e 10 a base. ex: base 10 elevado ao expoente 16-2 = 100000000000000 ou 1 seguido de 14 zeros.
    long divisor = (long)pow(10, digito - 2);// o floor é utilizado para pegar apenas a parte "inteira" da divisao, descartando o resto.//ex: floor = carta / divisor = 123456789 / 10000000 = 12.345678 = 12
    int primeiro_dois_digitos = (int)floor(cartao / divisor);
    int n1;
    int n2;
    int soma;
    int resultado = 0;

    do
    {
        n1 = cartao % 10;
        cartao = cartao / 10;
        n2 = cartao % 10 * 2;
        if (n2 > 9)
        {
            int n3;
            n3 = n2 % 10;
            n2 = n2 / 10;
            n2 = n2 + n3;
        }
        soma = n1 + n2;
        cartao = cartao / 10;
        resultado = resultado + soma;

    }
    while (cartao > 0);

    resultado = resultado % 10;

    if (resultado == 0)
    {
        if (primeiro_dois_digitos == 34 || primeiro_dois_digitos == 37)
        {
            printf("AMEX\n");
        }
        else if (primeiro_dois_digitos > 50 && primeiro_dois_digitos < 56)
        {
            printf("MASTERCARD\n");
        }
        else if (primeiro_dois_digitos / 10 == 4 && digito > 12)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
