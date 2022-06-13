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
    while (fread(buffer, sizeof(buffer), 1, input) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpg_found == 1)
            {
                fclose(output);
            }
            else
            {
                jpg_found = 1;
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", jpegs);
            output = fopen(filename, "w");
            jpegs++;
        }
        if (jpg_found == 1)//once new JPEGS are found
        {
            fwrite(buffer, 512, 1, output);
        }
    }
    fclose(output);
    fclose(input);
    return 0;
}
