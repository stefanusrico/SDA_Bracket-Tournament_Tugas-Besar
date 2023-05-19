#ifndef rico_h
#define rico_h

#include "head.h"

void mainmenu();

void buatArrayKualifikasi(Isi_Tree P, Isi_Team Q, Isi_Team R, char namaTimArr[MAX_STRING_LENGTH], char* treeString, int Jml_Tim, int tahun);

void Create_tree(Isi_Tree X, int Jml_Node, infotype nilai, char namaArr[]);

//void PrintTree(Isi_Tree P, char* treeString);

void PrintTree(Isi_Tree P, Isi_Team Q, Isi_Team R, int Jml_Node, char* treeString, char namaTimArr[], char timPemenang[][500], int tahun);

void printTree(Isi_Tree P, int posisi, int level, char* str);

void cariDaun(Isi_Tree P, int posisi, int* indeksDaun, int* hitungDaun);

void shuffleArray(char arr[][500], int size);

void assignDaunTree(Isi_Tree P, int* indeksDaun, int *hitungDaun, char timPemenang[][500]);

void updateParent(Isi_Tree P, int index, int* indeksDaun, int* hitungDaun, char timPemenangTree[][500]);

void inputSkorTree(Isi_Tree P, Isi_Team Q, Isi_Team R, int* indeksDaun, int* hitungDaun, char* treeString, char timPemenang[][500], char timPemenangTree[][500], char namaTimArr[], int tahun);

//void saveData(Isi_Tree P, Isi_Team Q, Isi_Team R, char* treeString, char namaTimArr[], char timPemenang[][500], int Jml_Node, int i);

void operasiFileTimPemenang(Isi_Tree P, char* filename, char* treeString, char timPemenang[][500], int Jml_Tim, int tahun);
//
//void loadData(Isi_Tree *P, Isi_Team *Q, Isi_Team *R);

#endif