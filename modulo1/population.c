#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int pop_atual;
    int pop_final;
    int i = 0;

    do
    {
        pop_atual = get_int("populção atual: ");
    }
    while (pop_atual < 9);
    do
    {
        pop_final = get_int("populção final: ");
    }
    while (pop_final < pop_atual);
    while (pop_atual < pop_final)
    {
        int natalidade = pop_atual / 3;
        int mortalidade = pop_atual / 4;
        pop_atual = natalidade - mortalidade + pop_atual;
        i++;
    }
    printf("Years: %i\n", i);
}