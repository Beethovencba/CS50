#include <cs50.h>
#include <math.h>
#include <stdio.h>

float recebe_troco(void)
{
    float troco;
    do
    {
        troco = get_float("Insira o troco a receber: R$ ");
    }
    while (troco <= 0.00);
    return troco;
}

void conta_troco(void)
{
    float reais = recebe_troco();
    // adiciona 0.5 para arredondar corretamente
    int troco = (reais * 100) + 0.5;
    int i = 0;
    while (troco >= 25)
    {
        troco = troco - 25;
        i++;
    }
    while (troco >= 10)
    {
        troco = troco - 10;
        i++;
    }
    while (troco >= 5)
    {
        troco = troco - 5;
        i++;
    }
    while (troco >= 1)
    {
        troco = troco - 1;
        i++;
    }

    printf("%.i\n", i);
}

int main(void)
{
    conta_troco();
    return 0;
}