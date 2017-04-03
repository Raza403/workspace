#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // Ensure proper usage
    if (argc != 4)
    {
        printf("Usage: resize factor infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    
    int n = atoi(argv[1]);
    
    if (n < 1 || n > 100)
    {
        printf("Factor must be in range 1 to 100!\n");
        return 1;
    }

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bfnew;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, binew;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    bfnew = bf;
    binew = bi;
    // Determine the new dimensions
    binew.biWidth  = bi.biWidth * n;
    binew.biHeight = bi.biHeight * n;
    
    // Determine the old and new paddings
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) %4) % 4;
    int newpadding = (4 - (binew.biWidth * sizeof(RGBTRIPLE)) %4) % 4;
    
    // Determine new image sizes
    bfnew.bfSize = (binew.biWidth * sizeof(RGBTRIPLE) + newpadding) * abs(binew.biHeight);
    binew.biSizeImage = ((((binew.biWidth * binew.biBitCount)+31)& ~31)/8)* abs (binew.biHeight);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bfnew, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&binew, sizeof(BITMAPINFOHEADER), 1, outptr);
    long int p = -(bi.biWidth * 3 + padding);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Read each scanline factor times
        for (int j = 0; j < n; j++)
        {  
            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile, multiplied by factor
                for (int l = 0; l < n; l++)
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);    
            }
            
            // Add a new padding
            for (int l = 0; l < newpadding; l++)
                fputc(0x00, outptr);
            
            // Return to the beginning of a scanline
            if (j < n - 1)
            
                fseek(inptr,p, SEEK_CUR);
        }

        // Skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}