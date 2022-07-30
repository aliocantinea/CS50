#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    //check for argc > 1
    if (argc != 1)
    {
        printf ("Usage: ./recover file\n");
        return 1;
    }

    //check to see file can be opened
    FILE *file = fopen (argv[1], "r");
    if (file == NULL)
    {
        printf ("Could not open %s.\n", argv[1]);
        return 1;
    }
    //var for FAT
    int blocksize = 512;

    //create buffer
    int *buffer = malloc(blocksize * sizeof(uint8_t));
    if (buffer == NULL)
    {
        printf("Not enough memory for buffer.\n");
        fclose(file);
        return 2;
    }

    //read fole looking for jpeg header '0xff 0xd8 oxff 0xe...'
    while (fread(buffer, 1, blocksize, file) == blocksize)
    {
        //counter for files recovered
        int i = 0;

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
        (buffer[3] & 0xf0) == 0xe0)
        {
            ++i;
            sprintf(filename, "%03i.jpg", i);
            FILE *img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Not enough memory for recovered file.\n")
                free(buffer);
                fclose(file);
                return 3;
            }
        }



    //open new file

    //when found copy block size of 512 bytes under new jpeg header found
    }

    //close file
    free(buffer);
    fclose(file);
    return 0;
}