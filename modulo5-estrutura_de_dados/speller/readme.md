OBJETIVO: Verificar a ortografia de um arquivo, como mostrado a seguir, usando uma tabela de hash. Calcular o desempenho do programa.

    CONTEXTO: Teoricamente, na entrada de tamanho n , um algoritmo com um tempo de execução de n é “assintoticamente equivalente,” em termos de O , a um algoritmo com um tempo de execução de 2n . Na verdade, ao descrever o tempo de execução de um algoritmo, normalmente nos concentramos no termo dominante (ou seja, mais impactante) (ou seja, n neste caso, uma vez que n pode ser muito maior do que 2). No mundo real, porém, o fato é que 2n parece duas vezes mais lento que n .

    O desafio à sua frente é implementar o corretor ortográfico mais rápido possível! Por "mais rápido", porém, estamos falando de um "relógio de parede" real, não assintótico, tempo.

COMPILAÇÃO: make speller
EXECUÇÃO: ./speller dictionaries/small texts/FILE.txt

INPUT: Numero de gerações(alterar numero de gerações);
OUTPUT: Geração e o tipo sanguíneo;

ex:

./speller text/lalaland.txt
MISSPELLED WORDS

[...]
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
[...]
Shangri
[...]
fianc
[...]
Sebastian's
[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL: