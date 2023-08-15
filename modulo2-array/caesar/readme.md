OBJETIVO: Criptografia Simples (Caesar).

    CONTEXTO: O algoritmo de César (isto é, cifra) criptografa mensagens “girando” cada letra em k posições. Mais formalmente, se p é algum texto simples (ou seja, uma mensagem não criptografada), pi é o i-ésimo caractere em p , e k é uma chave secreta (ou seja, um inteiro não negativo), então cada letra, c i , em o texto cifrado, c , é calculado como

                    c i = (pi + k)% 26

    em que %26 aqui significa "resto ao dividir por 26." Essa fórmula talvez faça a cifra parecer mais complicada do que é, mas na verdade é apenas uma maneira concisa de expressar o algoritmo com precisão. De fato, para fins de discussão, pense em A (ou a) como 0, B (ou b) como 1, ..., H (ou h) como 7, I (ou i) como 8, ... e Z (ou z) como 25. Suponha que César apenas queira dizer Oi para alguém confidencialmente usando, desta vez, uma chave, k , de 3. E então seu texto simples, p , é Hi, em cujo caso o primeiro caractere de seu texto simples, p 0 , é H (também conhecido como 7), e o segundo caractere de seu texto simples, p 1 , é i (também conhecido como 8). O primeiro caractere de seu texto cifrado, c 0 , é portanto K, e o segundo caractere de seu texto cifrado, c 1 , é assim L.

    Este programa chamado permite criptografar mensagens usando a cifra de César. No momento em que o usuário executa o programa, ele deve decidir, fornecendo um argumento de linha de comando, qual deve ser a chave na mensagem secreta que fornecerá no tempo de execução. Não devemos necessariamente presumir que a chave do usuário será um número; embora você possa assumir que, se for um número, será um inteiro positivo.

INPUT: Um numero (N) inteiro positivo.
OUTPUT: Um texto criptografado.

COMPILAÇÃO: cc caesar.c -o caesar -lcs50
EXECUÇÃO: $ ./caesar N

ex:

$ ./caesar 1
plaintext:  HELLO
ciphertext: IFMMP

$ ./caesar 13
plaintext:  be sure to drink your Ovaltine
ciphertext: or fher gb qevax lbhe Binygvar