#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi (argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
    if (n<=0||n>100)
    {
        printf("n must be between 1 and 100");
        return 5;
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
    BITMAPFILEHEADER bf,new_bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, new_bi;
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
    new_bf=bf;
    new_bi=bi;
    new_bi.biWidth=bi.biWidth*n;
    new_bi.biHeight=bi.biHeight*n;
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding = (4-(new_bi.biWidth * sizeof(RGBTRIPLE))%4)%4;
    //size of new image.
    new_bi.biSizeImage = (bi.biWidth* sizeof (RGBTRIPLE) + new_padding) * (abs(new_bi.biHeight));
    new_bf.bfSize = (bf.bfSize - bi.biSizeImage + new_bi.biSizeImage);

    // write outfile's BITMAPFILEHEADER
    fwrite(&new_bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    
    // write outfile's BITMAPINFOHEADER
    fwrite(&new_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    
    // iterate over infile's scanlines
   
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
         //iterate n times.
         for (int m=0;m<n;m++)
         {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
            {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
        for (int f=0;f<n;f++)
            {
            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
            // then add it back (to demonstrate how)
            for (int k = 0; k < new_padding; k++)
            {
            fputc(0x00, outptr);
            //start from scale line again
            if (m<n-1)
            {
                fseek(inptr, -(long int)-bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
            }
            }
             

            
            }
            fseek(inptr, padding, SEEK_CUR);
            
         } 
         
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
