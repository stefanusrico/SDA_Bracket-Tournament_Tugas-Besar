#ifndef rico_h
#define rico_h

#include "head.h"

void buatArrayKualifikasi(Isi_Team Q, int Jml_Tim);

void inputSkor(Isi_Team Q, int Jml_Tim);

void Create_tree(Isi_Tree X, int Jml_Node, infotype nilai, char namaArr[]);

void PrintTree(Isi_Tree P, char* treeString);

void printTree(Isi_Tree P, int posisi, int level, char* str);

void cariDaun(Isi_Tree P, int posisi, int* indeksDaun, int* hitungDaun);

void assignDaunTree(Isi_Tree P, int* indeksDaun, int *hitungDaun, char timPemenang[][500]);

void tampilPemenangTree(Isi_Tree P, int* indeksDaun, int* hitungDaun, char timPemenangTree[][500]);

void updateParent4(Isi_Tree P, int* indeksDaun, int* hitungDaun,char timPemenangTree[][500]);

void updateParent3(Isi_Tree P, int index, char timPemenangTree[][500]);

void updateParent2(Isi_Tree P, int index, char timPemenangTree[][500]);

void updateParent1(Isi_Tree P, int index, char timPemenangTree[][500]);

void inputSkorTree4(Isi_Tree P, int* indeksDaun, int* hitungDaun, char* treeString, char timPemenangTree[][500]);

void inputSkorTree3(Isi_Tree P, char timPemenangTree[][500], int index);

void inputSkorTree2(Isi_Tree P, char timPemenangTree[][500], int index);

void inputSkorTree1(Isi_Tree P, char timPemenangTree[][500], int index);

#endif