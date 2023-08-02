#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    uint8_t buffer[512]; //esta variavel reserva 1 byte sendo possivel armazenar apenas nº 0 à 255. atenção: risco de ouverflow.
    int imagem, i = 0, gravando = 0;
    char img[10] = "000.jpg";


    FILE *file  = fopen(argv[1], "rb");
    FILE *image = NULL; //inicializa o ponteiro.

    if (file != NULL)
    {
        printf("arquivo aberto com sucesso!\n");
    }
    else
    {
        printf("falha ao abrir o arquivo!");
        return (1);
    }

    //a função fread retorna o valor do bloco lido (512) retornando 0 quando chega ao fim do arquivo.
    while ((imagem = fread(buffer, 1, sizeof(buffer), file)) > 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (gravando == 1)
            {
                fclose(image);
            }
            sprintf(img, "%03i.jpg", i);
            image = fopen(img, "wb");
            i++;
            gravando = 1;

        }

        if (gravando == 1)
        {
            fwrite(buffer, 1, imagem, image);
        }
    }

    fclose(image);
    fclose(file);

    return (0);
}