#ifndef rico_h
#define rico_h

#include "head.h"

void buatArrayKualifikasi(Isi_Team Q, int Jml_Tim, char namaTimArr[100]);

void Create_tree(Isi_Tree X, int Jml_Node, infotype nilai, char namaArr[]);

void PrintTree(Isi_Tree P, char* treeString);

void printTree(Isi_Tree P, int posisi, int level, char* str);

void cariDaun(Isi_Tree P, int posisi, int* indeksDaun, int* hitungDaun);

void assignDaunTree(Isi_Tree P, int* indeksDaun, int *hitungDaun, char timPemenang[][500]);

void updateParent(Isi_Tree P, int* indeksDaun, int* hitungDaun,char timPemenangTree[][500]);

void inputSkorTree(Isi_Tree P, int* indeksDaun, int* hitungDaun, char* treeString, char timPemenangTree[][500]);

#endif