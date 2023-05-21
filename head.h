#ifndef head_h
#define head_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define jml_maks 100
#define NIL 0
#define MAX_STRING_LENGTH 100
#define MAX_ELM 100

#define FILE_NAME1 "Babak Kualifikasi (Array).txt"
#define FILE_NAME2 "Babak Gugur (Tree).txt"

typedef char* infotype;
typedef int address;

typedef struct Node {
    int skor;
    infotype nama;
    address left;
    address right;
} Node;

typedef struct team{
	infotype name;
	int score;
}team;

typedef Node Isi_Tree[jml_maks+1];
typedef team Isi_Team[jml_maks+1];

int score[jml_maks+1];
int scorePenalti[jml_maks+1];
#endif