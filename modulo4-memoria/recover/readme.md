Objetivo: Recuperar JPEGs de uma imagem forense, conforme a seguir.



        Contexto: Prevendo esse problema, passamos os últimos dias tirando fotos de pessoas que conhecemos, todas as quais foram salvas em uma câmera digital como JPEG em um cartão de memória. (Ok, é possível que, em vez disso, tenhamos passado os últimos dias no Facebook.) Infelizmente, de alguma forma excluímos todos eles! Felizmente, no mundo da informática, "excluído" tende a não significar "excluído", mas sim "esquecido". Mesmo que a câmera insista que o cartão agora está em branco, temos certeza de que isso não é bem verdade. Na verdade, estamos torcendo (er, esperando!) Que você possa escrever um programa que recupere as fotos para nós!

        Mesmo que JPEGs sejam mais complicados do que BMPs, JPEGs têm “assinaturas”, padrões de bytes que podem distingui-los de outros formatos de arquivo. Especificamente, os primeiros três bytes de JPEGs são "0xff 0xd8 0xff" do primeiro para o terceiro byte, da esquerda para a direita. O quarto byte, entretanto, é 0xe0 , 0xe1 , 0xe2 , 0xe3 , 0xe4 , 0xe5 , 0xe6 , 0xe7 , 0xe8 , 0xe9 , 0xea , 0xeb , 0xec , 0xed , 0xee ou 0xef . Dito de outra forma, os primeiros quatro bits do quarto byte são 1110 .

        As probabilidades são de que, se você encontrar esse padrão de quatro bytes na mídia conhecida por armazenar fotos (por exemplo, meu cartão de memória), eles demarcam o início de um JPEG. Para ser justo, você pode encontrar esses padrões em algum disco puramente por acaso, então a recuperação de dados não é uma ciência exata.

        Felizmente, as câmeras digitais tendem a armazenar fotos de forma contígua em cartões de memória, sendo que cada foto é armazenada imediatamente após a foto anterior. Da mesma forma, o início de um JPEG geralmente marca o final de outro. No entanto, as câmeras digitais geralmente inicializam os cartões com um sistema de arquivos FAT cujo “tamanho de bloco” é de 512 bytes (B). A implicação é que essas câmeras só gravam nesses cartões em unidades de 512 B. Uma foto com 1 MB (ou seja, 1.048.576 B) ocupa 1048576 ÷ 512 = 2048 “blocos” em um cartão de memória. Mas o mesmo acontece com uma foto que é, digamos, um byte menor (ou seja, 1.048.575 B)! O espaço desperdiçado em disco é chamado de "espaço livre". Os investigadores forenses costumam olhar para a folga em busca de resquícios de dados suspeitos.

        A implicação de todos esses detalhes é que você, o investigador, provavelmente pode escrever um programa que itera sobre uma cópia do meu cartão de memória, procurando assinaturas de JPEGs. Cada vez que encontrar uma assinatura, você pode abrir um novo arquivo para escrever e começar a preencher esse arquivo com bytes do meu cartão de memória, fechando esse arquivo apenas quando encontrar outra assinatura. Além disso, em vez de ler os bytes do meu cartão de memória um de cada vez, você pode ler 512 deles por vez em um buffer para fins de eficiência. Graças ao FAT, você pode confiar que as assinaturas de JPEGs serão "alinhadas em bloco". Ou seja, você só precisa procurar essas assinaturas nos primeiros quatro bytes de um bloco.


compilação: cc recover.c -o recover

execução: ./recover card.raw