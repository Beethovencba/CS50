OBJETIVO: sistema de votação por escolha ranqueada. 
    
    CONTEXTO: Em um sistema de escolha ranqueada, os eleitores podem votar em mais de um candidato. Em vez de apenas votar na primeira escolha, eles podem classificar os candidatos em ordem de preferência. De modo geral, o método Tideman funciona construindo um “gráfico” de candidatos, onde uma seta (isto é, aresta) do candidato A ao candidato B indica que o candidato A vence o candidato B em um confronto direto. Sendo assim, o candidato que não receber nenhuma seta (arestas) é o vencedor. Tindeman ao contrario dos outros sistemas não tem empate.

INPUT: Numero de eleitores e o nome dos candidatos (MAX 9);
OUTPUT: nome do vencedor.


COMPILAÇÃO: cc tideman.c -o tideman -lcs50
EXECUÇÃO: ./tideman candidato1 candidato2 candidato3...

EX:

./tideman Alice Bob Charlie
Número de eleitores: 5
Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Charlie