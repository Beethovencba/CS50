OBJETIVO: Determinar o nível de alfabetização com base no texto fornecido.
    
    Contexto: De acordo com a Scholastic , “Charlotte's Web” de EB White está entre o nível de leitura da segunda e quarta séries, e “The Giver” de Lois Lowry está entre um nível de leitura da oitava série e um nível de leitura da décima segunda série. No entanto, o que significa um livro estar no “nível de leitura da quarta série”?

    Bem, em muitos casos, um especialista humano pode ler um livro e tomar uma decisão sobre a série para a qual acha que o livro é mais apropriado. Mas você também pode imaginar um algoritmo tentando descobrir qual é o nível de leitura de um texto.

    Então, que tipo de características são características de níveis de leitura mais altos? Bem, palavras mais longas provavelmente se correlacionam com níveis de leitura mais altos. Da mesma forma, frases mais longas provavelmente se correlacionam com níveis mais altos de leitura também. Vários “testes de legibilidade” foram desenvolvidos ao longo dos anos, para fornecer um processo estereotipado para calcular o nível de leitura de um texto.

    Um desses testes de legibilidade é o índice Coleman-Liau. O índice Coleman-Liau de um texto é projetado para mostrar qual nível escolar (EUA) é necessário para entender o texto. A fórmula é:

    índice = 0,0588 * L - 0,296 * S - 15,8
    Aqui, L é o número médio de letras por 100 palavras no texto e S é o número médio de sentenças por 100 palavras no texto.

    Vamos escrever um programa chamado readability que pega um texto e determina seu nível de leitura.

INPUT: Texto ou paragrafo de sua preferencia.
OUTPUT: O nível de escolaridade.

COMPILAÇÃO: cc reabability.c -o reabability -lcs50
EXECUÇÃO: ./readability

EX:

$ ./readability
Text: As the average number of letters and words per sentence increases, the Coleman-Liau index gives the text a higher reading level. If you were to take this paragraph, for instance, which has longer words and sentences than either of the prior two examples, the formula would give the text an eleventh grade reading level.
Grade 11