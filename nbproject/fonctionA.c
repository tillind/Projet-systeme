/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
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

void write (FILE* fichier,char type, char texte)/*w,r,a+,...*/
{
    fichier = fopen("./test.txt", "a+");
    if (fichier != NULL)
    {
        printf ("fichier existant \n");
        fprintf(fichier,texte);
        fclose(fichier);
    }
}
char readInput()
{
   char saisie1[30]="";
   fgets(saisie1, sizeof(saisie1), stdin);
   return saisie1;
}

