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

int main(int argc, char *argv[])
{
    struct document mesDoc[5];
    /*test écriture*/
    FILE* fichier = NULL;
    fichier = fopen("./test.txt", "a+");
    if (fichier != NULL)
    {
        printf ("fichier existant \n");
        fclose(fichier);
    }

    return (EXIT_SUCCESS);
}


    int argv0size = strlen(argv[0]);
    int pid1 = fork();

    if(pid1<0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if(pid1==0)
    {
        FILE* fichier = NULL;
        fichier = fopen("./test.txt", "a+");
        printf("je vais écrire");
        strncpy(argv[0],"un",argv0size);
        char saisie1[30]="";
        fgets(saisie1, sizeof(saisie1), stdin);
        fprintf(fichier,saisie1);
        fclose(fichier);
        sleep(1000);
        exit(EXIT_SUCCESS);
    }
    else
    {
        int pid2 = fork();
        if(pid2<0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if(pid2==0)
        {
            FILE* fichier = NULL;
            fichier = fopen("./test.txt", "a+");
            strncpy(argv[0],"deux",argv0size);
            char saisie2[30]="";
            fgets(saisie2, sizeof(saisie2), stdin);
            fprintf(fichier,saisie2);
            fclose(fichier);
            sleep(1000);
            exit(EXIT_SUCCESS);
        }
        else
        {
            int status;
            int rpid2 = waitpid(pid2,&status,0);
            int rpid = waitpid(pid1,&status,0);
        }
    }
    return EXIT_SUCCESS;
} 
