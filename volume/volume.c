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

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // assigning dynamic memory to heap for copy var
    uint8_t *header = malloc(sizeof(uint8_t) * HEADER_SIZE);
    // check to make sure memory was allocated
    if (header == NULL)
    {
        printf("Out of memory.\n");
        fclose(input);
        fclose(output);
        return 2;
    }
    // reads and writes HEADER_SIZE amount of uint8_t at one time
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);
    // freeing heap var
    free(header);

    // TODO: Read samples from input file and write updated data to output file
    // dynamic heap memory that will release after finished
    int16_t *sample = malloc(sizeof(int16_t));
    // check to make sure memory was allocated
    if (sample == NULL)
    {
        printf("Out of memory.\n");
        fclose(input);
        fclose(output);
        return 2;
    }
    //remembers in order the last position of the read file, so starts after HEADER_SIZE
    // loop to read and write each int16_t
    while (fread(sample, sizeof(int16_t), 1, input))
    {
        *sample *= factor;
        fwrite(sample, sizeof(int16_t), 1, output);
    }
    // freeing dynamic var
    free(sample);
    // Close files
    fclose(input);
    fclose(output);
}
