#ifndef najwan_h
#define najwan_h
#include "head.h"

void tampilan();

void swapScore(Isi_Team R, int Jml_Tim);

void sortByScore(Isi_Team R, int Jml_Tim);

void cekPemenang(Isi_Team Q, int Jml_Tim, Isi_Team R, char timPemenang[][500]);

void inputSkor(Isi_Team Q, int Jml_Tim);

void aduPenalti(Isi_Tree P,int i,int index,char timPemenangTree[][500]);

//int isAngka(char p);
#endif