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
    void write (FILE* fichier,char *chemin,struct document mastruct)/*w,r,a+,...*/
        {   
            fichier = fopen(chemin, "a+");
            fputs(mastruct.text,fichier);
            fputs("\n",fichier);
            fclose(fichier);
        }
        void read (FILE* fichier, char *chemin, struct document str)
        {
            #define TAILLE_MAX 1000 // Tableau de taille 1000
            char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
            fichier = fopen(chemin, "r");
            while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
            {
                strcat(str.text,chaine); // On insère ce qu'on vient de lire
            }
            fclose(fichier);
        }
    struct document mesDoc[5];
    /*test écriture*/
    mesDoc[5].text="bonjour tout le monde \n";
    FILE* fichier = NULL;
    write(fichier,"./test.txt",mesDoc[5]);
    read(fichier,"./test.txt",mesDoc[5]);
    printf("%s",mesDoc[5].text);
    return (EXIT_SUCCESS);
}
