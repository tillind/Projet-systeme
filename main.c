#include <stdio.h>
/* Pour les constantes EXIT_SUCCESS et EXIT_FAILURE */
#include <stdlib.h>
/* Pour fprintf() */
#include <stdio.h>
/* Pour fork() */
#include <unistd.h>
/* Pour perror() et errno */
#include <errno.h>
/* Pour le type pid_t */
#include <sys/types.h>
#include <sys/prctl.h>
#include <string.h>
#include <sys/wait.h>

/*
 *
 */
int main(int argc, char** argv) {
    struct document
    {   
        char titre[20];
        char *text;
        char proprio[8];
        char connecte[10][8];
    };
    void write (FILE* fichier,struct document mastruct)/*w,r,a+,...*/
        {   
            fichier = fopen("./test.txt", "r+");
            if (fichier != NULL)
            {
                printf ("fichier existant \n");
                fputs(mastruct.text,fichier);
                fclose(fichier);
            }
        }
        void read (FILE* fichier, struct document str)
        {
            
        };
    struct document mesDoc[5];
    /*test écriture*/
    mesDoc[5].text="test";
    FILE* fichier = NULL;
    fichier = fopen("./test.txt", "a+");
    if (fichier != NULL)
    {
        printf ("fichier existant \n");
        write(fichier,mesDoc[5]);
        fclose(fichier);
    }

    return (EXIT_SUCCESS);
}
