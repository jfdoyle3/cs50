// Copies a BMP file
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy resize infile outfile\n");
        return 1;
    }

    // remember filenames
    char* size = argv[1];
    char* infile = argv[2];
    char* outfile = argv[3];
    // Size has to be 100 or less
    if (*size>100){
        fprintf(stderr, "The %c is to large enter less than 100\n",*size);
        return 2;
    }
    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
   // BITMAPFILEHEADER inbf=bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

   // BITMAPINFOHEADER inbiw=bi.biWidth;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    int factor=atoi(size);
     int inpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
   // int inwidth=bi.biWidth*size;
   // int inHeight=abs(bi.biHeight)

    printf("\ninpadding= %i inWidth= %i    inHeight= %i   size=%i\n",inpadding,bi.biWidth,bi.biHeight,factor);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
  //  bi.biHeight=abs(bi.biHeight)*size;
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
     int outWidth = bi.biWidth*factor;
     int outpadding = (4 - (outWidth * sizeof(RGBTRIPLE)) % 4) % 4;


    int outHeight=abs(bi.biHeight)*factor;
    printf("outpadding= %i  outwidth= %i  outhieght=%i\n",outpadding,outWidth,outHeight);
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;


            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);



            // write RGB triple to outfile
        for (int r=0; r<outWidth; r++)
        {

        }
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, inpadding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < outpadding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}