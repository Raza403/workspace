/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Infile pointer
    FILE* infile;
    infile = fopen ("card.raw", "r");
    // Check for errors
    if (infile == NULL)
    {
        printf ("Error opening infile");
        return 1;
    }
    // Buffer memory
    char buff[512] = {0};
    // First check
    char jpeg [4] = {0xff,0xd8,0xff,0xe0};
    // 2nd check
    char jpeg1 [4] ={0xff,0xd8,0xff,0xe1};
    char filename[10];
    // Count for jpegs numbering
    int count = 0;
    // Out file pointer
    FILE* outfile;
    // Checking if outfile is already open
    int indicator = 0;
    
    fread (buff,512, 1, infile);
    // if there is memory to be read
    while (fread (buff,512, 1, infile) > 0)
    {
        // If it complies with the checks
        if (memcmp (buff, jpeg, 4) == 0 || memcmp (buff, jpeg1, 4) == 0)
        {
            // file name
            sprintf (filename, "%03d.jpg", count);
            
            //if file is already not open then open the file to write
            if (indicator == 0)
            {
                
                outfile = fopen (filename , "w");
                fwrite (buff , 512, 1, outfile);
                indicator = 1;
            }
            // If file already open then close previous as it is indication of new file, So open new.
            if (indicator == 1)
            {
                fclose (outfile);
                // count++ for jpeg numbering
                count++;
                outfile = fopen (filename , "w");
                fwrite (buff , 512, 1, outfile);
                indicator = 1;
            }
        }
        
        else {
            if (indicator == 1)
                    {
                            fwrite (buff , 512, 1, outfile);
                    }
            }
    }
    
    
    
    if (outfile)
    {
        fclose (outfile);
    }
    
    fclose (infile);
    
    
    return 0;
}
