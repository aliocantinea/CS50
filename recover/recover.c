#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    //check for argc > 1
    if (argc != 2)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }

    //check to see file can be opened
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    //var for FAT blocksize
    int blocksize = 512;

    //create buffer
    uint8_t buffer[blocksize];

    //assigns pointer for filename and returns in NULL
    char *filename = malloc(8 * sizeof(char));
    if (filename == NULL)
    {
        printf("Not enough memory for filename.\n");
        fclose(file);
        return 3;
    }

    //counter for files recovered
    int images = 0;

    //create output file globally
    FILE *recovered = NULL;

    //read file looking for jpg header '0xff 0xd8 oxff 0xe...'
    while (fread(buffer, sizeof(uint8_t), blocksize, file) != 0)
    {
        //if jpg header found open file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if file opened already
            if (images > 0)
            {
                fclose(recovered);
            }
            //set filename
            sprintf(filename, "%03i.jpg", images);
            //open filename
            recovered = fopen(filename, "w");
            if (recovered == NULL)
            {
                printf("Not enough memory for recovered file.\n");
                free(filename);
                fclose(recovered);
                fclose(file);
                return 4;
            }
            //add to image counter
            ++images;
        }
        //if file is open to write to
        if (recovered != NULL)
        {
            //write to file
            fwrite(buffer, sizeof(uint8_t), blocksize, recovered);
        }
    }

    //free pointers
    free(filename);
    //close files
    fclose(recovered);
    fclose(file);
    return 0;
}