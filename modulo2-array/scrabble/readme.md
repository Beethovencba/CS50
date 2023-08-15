OBJETIVO: Reproduzir o jogo Scrabble.

        CONTEXTO: No jogo Scrabble, os jogadores criam palavras para marcar pontos, e o número de pontos é a soma dos valores dos pontos de cada letra da palavra.

        A	B	C	D	E	F	G	H	I	J	K	L	M	N	O	P	Q	R	
        1	3	3	2	1	4	2	4	1	8	5	1	3	1	1	3	10	1	

        S	T	U	V	W	X	Y	Z
        1	1	1	4	4	8	4	10

        Por exemplo, se quiséssemos pontuar a palavra Code, observaríamos que, nas regras gerais do Scrabble, o C vale 3 pontos, o o vale 1 ponto, o d vale 2 pontos e e vale 1 ponto. Somando isso, obtemos que Code vale 3 + 1 + 2 + 1 = 7 pontos.

INPUT: Uma palavra qualquer para ambos os players.
OUTPUT: Imprime o vencedor.

COMPILAÇÃO: cc scrabble.c -o $ scrabble -lcs50
EXECUÇÃO: ./scrabble


ex:

$ ./scrabble
Player 1: Question?
Player 2: Question!
Tie!

$ ./scrabble
Player 1: Oh,
Player 2: hai!
Player 2 wins!

$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!