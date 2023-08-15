OBJETIVO: Criptografia (Simples) por substituição.


        CONTEXTO: Em uma cifra de substituição, “criptografamos” (ou seja, ocultamos de forma reversível) uma mensagem substituindo cada letra por outra. Para isso, usamos uma chave : neste caso, um mapeamento de cada uma das letras do alfabeto à letra correspondente quando criptografada. Para “decifrar” a mensagem, o receptor da mensagem precisaria saber a chave, para que pudesse reverter o processo: traduzir o texto criptografado (geralmente chamado de texto cifrado ) de volta na mensagem original (geralmente chamado de texto simples ).

        Uma chave, por exemplo, pode ser a sequencia NQXPOMAFTRHLZGECYJIUWSKDVB. Esta chave de 26 caracteres significa que A (a primeira letra do alfabeto) deve ser convertido em N (o primeiro caractere da chave), B (a segunda letra do alfabeto) deve ser convertido em Q (o segundo caractere do chave), e assim por diante.

        Uma mensagem como HELLO , então, seria criptografada como FOLLE , substituindo cada uma das letras de acordo com o mapeamento determinado pela chave.



INPUT: uma chave (alfabeto em ordem aleatória) e um texto simples.
OUTPUT: texto cifrado.


COMPILAÇÃO: cc substitution.c -o substitution -lcs50
EXECUÇÃO: ./substitution CHAVE

ex: 

$ ./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO
texto simples: HELLO
texto cifrado: EHBBQ

$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
texto simples: hello, world
texto cifrado: jrssb, ybwsp