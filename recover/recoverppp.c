#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE* input = fopen(argv[1], "r");
    if (argv[1] == NULL)
    {
        printf("Unable to open: %s\n", argv[1]);
        return 1;
    }
    BYTE buffer[512];
    int jpegs = 0;
    FILE *output = NULL;
    int jpg_found = 0; //False
    //Read through the whole block, repeat for all files
    while (fread(buffer, sizeof(buffer), 1, input) == 1)
    {
        //if start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if JPEG has been found
            if (jpg_found == 1)
            {
                // Start of an image has been found, so close current image
                fclose(output);
            }
            //if first JPEG, create a new first file and write in it
            else
            {
                //new JPEG discovered and we can write on file
                jpg_found = 1;
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", jpegs);
            output = fopen(filename, "w");
            jpegs++;
        }
        if (jpg_found == 1)//once new JPEGS are found
        {
            //copy over the blocks from buffer into new file
            fwrite(buffer, 512, 1, output);
        }
    }
        fclose(output);
        fclose(input);
        return 0;
}





#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    FILE* input = fopen(argv[1], "r");
    if (argv[1] == NULL)
    {
        printf("Unable to open: %s\n", argv[1]);
        return 1;
    }
    BYTE buffer[512];
    int jpegs = 0;
    FILE *out = NULL;
    int jpeg_start = 0;
    while (fread(buffer, sizeof(buffer), 1, input) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpeg_start == 1)
            {
                fclose(out);
            }
            else
            {
                jpeg_start = 1;
            }
            char filename[8];
            sprintf(filename, "%03i.jpeg", jpegs);
            out = fopen(filename, "w");
            jpegs++;
        }
        if (jpeg_start == 1)
        {
            fwrite(buffer, 512, 1, out);
        }
    }
    fclose(out);
    fclose(input);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./something");
    }

    fopen(argv[1], "r");

    if (argv[1] == NULL)
    {
        printf("Unable to open %s", argv[1])
    }

    BYTE buffer[512];
    char filename[8];
    int foundjpg = 0;
    FILE *output = NULL;
    while (fread(buffer, sizeof(buffer), 1, input) == 1)
    {
        if (buffer[0] = 0xff && buffer[1] = 0xd8 && buffer[2] = 0xff && (buffer[3] & 0xf0) = 0xe0)
        {
            if (foundjpg > 0)
            {
                fclose(output);
            }
            else if (foundjpg = 0)
            {
                sprintf(filename, "%.3i", output);
                fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, output);
                foundjpg++;
            }
        }
        else if (foundjpg > 0)
        {
            fwrite(buffer, sizeof(buffer), 1, output);
        }
        fclose(output);
        fclose(input);
        return 0;
    }
}


