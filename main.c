/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: alexandre
 *
 * Created on 15 décembre 2016, 15:54
 */

/ Pour les constantes EXIT_SUCCESS et EXIT_FAILURE /
#include <stdlib.h>
/ Pour fprintf() /
#include <stdio.h>
/ Pour fork() /
#include <unistd.h>
/ Pour perror() et errno /
#include <errno.h>
/ Pour le type pid_t /
#include <sys/prctl.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#define CLEF 123456 
#include <sys/shm.h>
#define PERMS 777
int docs;
struct document
{
char titre[20];
char text[1000];
char proprio[8];
char connecte[10][8];
};
typedef struct
