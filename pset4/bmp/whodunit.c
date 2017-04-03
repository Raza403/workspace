/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: Enter clue file also\n");
        return 1;
    }


    // open input file 
    FILE* clue_ptr = fopen(argv[1], "r");
    if (clue_ptr == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    // open output file
    FILE* convict_ptr = fopen("convict.bmp", "w");
    if (convict_ptr == NULL)
    {
        fclose(clue_ptr);
        fprintf(stderr, "Could not create %s.\n", "convict.bmp");
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, clue_ptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, clue_ptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(convict_ptr);
        fclose(clue_ptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, convict_ptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, convict_ptr);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, clue_ptr);

            // write RGB triple to outfile
            
            if (triple.rgbtRed==255)
            {
                triple.rgbtRed=255;
                triple.rgbtBlue=0;
                triple.rgbtGreen=255;
            }
            
            fwrite(&triple, sizeof(RGBTRIPLE), 1, convict_ptr);
            
        }

        // skip over padding, if any
        fseek(clue_ptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, convict_ptr);
        }
    }

    // close infile
    fclose(clue_ptr);

    // close outfile
    fclose(convict_ptr);

    // that's all folks
    return 0;
}
