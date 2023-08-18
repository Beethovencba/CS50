OBJETIVO: Calcular, aleatoriamente, o tipo sanguíneo dos filhos com base nos alelos (genes) dos pais. O programa deve aderir às regras descritas em segundo plano. A criança deve ter dois alelos, um de cada pai. Cada um dos pais deve ter dois alelos, um de cada um de seus pais, assim por diante.

    CONTEXTO: O tipo sanguíneo de uma pessoa é determinado por dois alelos (isto é, diferentes formas de um gene). Os três alelos possíveis são A, B e O, dos quais cada pessoa tem dois (possivelmente iguais, possivelmente diferentes). Cada um dos pais de uma criança passa aleatoriamente um de seus dois alelos de tipo sanguíneo para o filho. As combinações possíveis de tipo sanguíneo, então, são: OO, OA, OB, AO, AA, AB, BO, BA e BB.

    Por exemplo, se um dos pais tem o tipo sanguíneo AO e o outro tem o tipo sanguíneo BB, os possíveis tipos sanguíneos da criança seriam AB e OB, dependendo de qual alelo é recebido de cada pai. Da mesma forma, se um dos pais tem tipo de sangue AO e o outro OB, os possíveis tipos de sangue da criança seriam AO, OB, AB e OO.

COMPILAÇÃO: cc inheritance.c -o inheritance
EXECUÇÃO: ./inheritance

INPUT: Numero de gerações(alterar numero de gerações);
OUTPUT: Geração e o tipo sanguíneo;

ex:

$ ./inheritance
Generation 0, blood type OO
   Generation 1, blood type AO
      Generation 2, blood type OA
      Generation 2, blood type BO
   Generation 1, blood type OB
      Generation 2, blood type AO
      Generation 2, blood type BO
