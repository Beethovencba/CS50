// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float   factor = atof(argv[3]);
    uint8_t buffer_header[HEADER_SIZE];
    int16_t buffer_body;
    int     contador;

    // TODO: Copy header from input file to output file
    fread(buffer_header, 1, sizeof(buffer_header), input);
    fwrite(buffer_header, 1, sizeof(buffer_header), output);


    while (fread(&buffer_body, sizeof(buffer_body), 1, input) > 0)
    {
        buffer_body = (int16_t)(buffer_body * factor); // Convertendo o resultado da multiplicação para int16_t
        fwrite(&buffer_body, sizeof(int16_t), 1, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}