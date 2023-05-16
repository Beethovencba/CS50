#include <cs50.h>
#include <stdio.h>

int recebe_numero(void)
{

    int altura;
    //get heigth
    do
    {
        altura = get_int("Digite um numero de 1 á 8!");
    }
    while (altura <= 0 || altura > 8);
    return altura;
}

void    imprime_hash(void)
{
    int altura = recebe_numero();
    int largura = altura--;
    int i = 0;
    //print hash
    while (i <= altura)
    {
        largura--;
        for (int c = 0; c < largura; c++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
        i++;
    }
}

int main(void)
{

    imprime_hash();
    return 0;

}