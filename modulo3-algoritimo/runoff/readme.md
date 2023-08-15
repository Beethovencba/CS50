OBJETIVO: Executar uma eleição de segundo turno; Votação por escolha ranqueada;

    contexto: Um sistema de votação por classificação é o sistema de runoff instantâneo (ou uma eleição com turnos). Em uma eleição de runoff instantâneo, os eleitores podem rankear quantos candidatos quiserem. Se algum candidato tiver a maioria (mais de 50%) dos votos da primeira preferência, esse candidato é declarado vencedor da eleição.

INPUT: Numero de eleitores (MAX 100) e o nome dos candidatos (MAX 9);
OUTPUT: nome do ou dos vencedores.


COMPILAÇÃO: cc runoff.c -o runoff -lcs50
EXECUÇÃO: ./runoff candidato1 candidato2 candidato3...

EX:

./runoff Alice Bob Charlie
Número de eleitores: 5
Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Alice
Rank 3: Charlie

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Alice