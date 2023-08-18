// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <wchar.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    wchar_t word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
#define N 27
unsigned int size_library;

// Hash table
node *table[N];
//Função para remover acentos dp primeiro caractere da string
// char remove_acento(char c)
// {
//     setlocale(LC_ALL, "");

//     char str[2] = {c, '\0'}; // Criar um array de caracteres com o caractere c e um terminador nulo
//     wchar_t letra;

//     size_t len = mbstowcs(&letra, str, sizeof(letra) / sizeof(wchar_t));

//     if (len != (size_t)-1) {
//         // Verificar as conversões só é necessário se a conversão foi bem-sucedida
//         if (letra == L'á' || letra == L'â' || letra == L'à' || letra == L'ã') {
//             return 'a';
//         }
//         else if (letra == L'é' || letra == L'ê' || letra == L'è')
//         {
//             return 'e';
//         }
//         else if (letra == L'í' || letra == L'î' || letra == L'ì')
//         {
//             return 'i';
//         }
//         else if (letra == L'ó' || letra == L'ô' || letra == L'ò' || letra == L'õ')
//         {
//             return 'o';
//         }
//         else if (letra == L'ú' || letra == L'û' || letra == L'ù')
//         {
//             return 'u';
//         }
//         else if (letra == L'ç')
//         {
//             return 'c';
//         }
//         else
//         {
//             return c;
//         }
//     }
//     else
//     {
//         printf("Failed to convert multibyte string.\n");
//         return c;
//     }
// }

// Returns true if word is in dictionary, else false
bool check(const wchar_t *word)
{
    int i;
    i = hash(word);
    printf("%i-", i);
	if (i > 25)
    {
        i = 26;
    }
    //printf("%i ", i);

    for (node *tmp = table[i]; tmp != NULL; tmp = tmp->next)
    {
        if (wcscmp(word, tmp->word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const wchar_t *word)
{
    wchar_t   palavra[LENGTH + 1];
    int  hash;
    
	wcscpy(palavra, word);
	hash = tolower(palavra[0]) - 97;
	if (hash > 25)
	{
		return 26;
	}

    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dicionario = NULL;
    dicionario = fopen(dictionary, "r");

    if (dicionario == NULL)
    {
        printf("falha ao abrir dicionario!");
    }
    else
    {
        printf("dicionario aberto com sucesso!");
    }

    int     idx, i = 1, x = 0;
    wchar_t    palavra[LENGTH + 1];

    while (fwscanf(dicionario, L"%ls", palavra) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Falha na alocação de memória.\n");
            return false;
        }

        wcscpy(n->word, palavra);
        n->next = NULL;

        idx = hash(n->word);
       // printf("%i, ", idx);
        if (idx == i)
        {
            table[idx] = NULL;
            table[idx] = n;
            i++;
        }
        else
        {
            n->next = table[idx];
            table[idx] = n;
        }
        x++;
    }
    printf("\n\n");
    fclose(dicionario);

    // printf("\n");
    // for (node *tmp = table[0]; tmp != NULL; tmp = tmp->next)
    // {
    //     printf("%s ", tmp->word);
    // }
    // printf("\n");

    size_library = size();
    printf("x: %i, size_library: %i \n", x, size_library);
    if (x == size_library)
    {
        return true;
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int x = 0, i = 0;

    while (i < 26)
    {
        for (node *tmp = table[i]; tmp != NULL; tmp = tmp->next)
        {
            x++;
        }
        i++;
    }

    if (x > 0)
    {
      return x;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    int i = 0;

    // Liberar memória alocada
    for (int j = 0; j < 26; j++)
    {
        while (table[j] != NULL)
        {
            node *temp = table[j];
            table[j] = table[j]->next;
            free(temp);
            i++;
        }
    }

    if (i == size_library)
    {
        return true;
    }

    return false;
}
