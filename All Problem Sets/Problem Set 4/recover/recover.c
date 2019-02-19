#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: filename\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    char filename[8];
    FILE *img = fopen(filename, "w");

    BYTE buffer[512];
    int number = 0;
    // read until the end
    while (fread(buffer, 512, 1, inptr) == 1)
    {
        // if it's the beginning of a JPG
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // if it's not the first JPG
            if (number != 0)
            {
                fclose(img);
            }
            // write to outfile
            sprintf(filename, "%03i.jpg", number);
            img = fopen(filename, "w");
            number++;
            fwrite(buffer, 512, 1, img);
        }
        // if it's not the beginning of a JPG
        else
        {
            // if a JPG is open
            if (number != 0)
            {
                fwrite (buffer, 512, 1, img);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(img);

    return 0;
}
