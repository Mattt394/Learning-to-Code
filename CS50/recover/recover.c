//Implement a program that recovers JPEGs from a forensic image

//Alright, let's go
//It worked, what stumped me was I was initially declaring filename as a constant string literal
//then I malloc()ed it and sprintf worked
//my logic with the jpegs was fine, thankfully
//but it still took me like 3 hours to fix sprintf
//lolololololololololol

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    //check for correct usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover card.raw\n");
        return 1;
    }

    //infile
    char *infile = argv[1];

    //open card.raw
    FILE *card_raw = fopen(infile, "r");
    if (card_raw == NULL)
    {
        fprintf(stderr, "Could not open %s, are you sure it's a file?\n", infile);
        return 2;
    }
    // start jpeg count
    int jnum =-1;


    //name the jpeg
    char *filename = malloc(1024);

    sprintf(filename, "%03i.jpg", jnum+1);



    //initialise file
    FILE *img;
    //I used to open file here
    img = fopen(filename, "w");

    //buffer


    //until end of file
    while (1)
    {
        //read the card
        unsigned char* buffer = malloc(512);
        int test = fread(buffer, sizeof(buffer), 1, card_raw);
        if (test != 1)
        {
            free(filename);
            free(buffer);
            break;
        }



        //test for jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //found a jpeg
            if (jnum == -1)
            {
                jnum++;

                //open file
                img = fopen(filename, "w");

                //write to the file
                fwrite(buffer, sizeof(buffer), 1, img);
                free(buffer);
            }
            else
            {
                //found new jpeg

                //close img
                fclose(img);


                jnum++;



                //name the jpeg


                sprintf(filename, "%03i.jpg", jnum);





                //open the file, I didn't make a new FILE * variable here, let's see what happens
                img = fopen(filename, "w");

                //write to the file
                fwrite(buffer, sizeof(buffer), 1, img);
                free(buffer);
            }

        }
        else
        {
            //if not start of a jpeg
            if (jnum == -1)
            {
                //repeat the loop
                free(buffer);
            }
            else
            {
                //write to jpeg
                fwrite(buffer, sizeof(buffer), 1, img);
                free(buffer);

            }

        }
    }



}
