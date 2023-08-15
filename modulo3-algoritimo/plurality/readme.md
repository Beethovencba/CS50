Objetivo: Contabilizar votos (eleição). Candidato que tiver maioria vence.

input: numero de candidatos(<= 9) e o nome dos candidatos;
output: nome do ou dos vencedores.


compilação: cc plurality.c -o plurality -lcs50
execução: ./plurality candidato1 candidato2 candidato3...

ex:
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: Alice
Alice

$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Charlie
Invalid vote.
Vote: Alice
Alice

$ ./plurality Alice Bob Charlie
Number of voters: 5
Vote: Alice
Vote: Charlie
Vote: Bob
Vote: Bob
Vote: Alice
Alice
Bob