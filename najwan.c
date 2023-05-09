#include <stdio.h>
#include "najwan.h"
#include "head.h"



void tampilan() {
	printf("\t\t\t\t  _______  ___   _______  ___      _______    ______   __   __  __    _  ___   _______  \n");
	printf("\t\t\t\t |       ||   | |   _   ||   |    |   _   |  |      | |  | |  ||  |  | ||   | |   _   | \n");
	printf("\t\t\t\t |    _  ||   | |  |_|  ||   |    |  |_|  |  |  _    ||  | |  ||   |_| ||   | |  |_|  | \n");
	printf("\t\t\t\t |   |_| ||   | |       ||   |    |       |  | | |   ||  |_|  ||       ||   | |       | \n");
	printf("\t\t\t\t |    ___||   | |       ||   |___ |       |  | |_|   ||       ||  _    ||   | |       | \n");
	printf("\t\t\t\t |   |    |   | |   _   ||       ||   _   |  |       ||       || | |   ||   | |   _   | \n");
	printf("\t\t\t\t |___|    |___| |__| |__||_______||__| |__|  |______| |_______||_|  |__||___| |__| |__| \n");
	printf("\n\n\n");
	printf("\t\t\t\t                      _____      ____      __       ____     \n");
	printf("\t\t\t\t                     / ___ `.  .'    '.   /  |    .' __ '.   \n");
	printf("\t\t\t\t                    |_/___) | |  .--.  |  `| |    | (__) |   \n");
	printf("\t\t\t\t                     .'____.' | |    | |   | |    .`____'.   \n");
	printf("\t\t\t\t                    / /_____  |  `--'  |  _| |_  | (____) |  \n");
	printf("\t\t\t\t                    |_______|  '.____.'  |_____| `.______.'  \n\n\n");
}

void swapScore(Isi_Team R, int Jml_Tim) {
	int i,j,k;
	int temp;
	team temp2;
	for(k = 0; k < Jml_Tim/4; k++) {
		for(i = 1 + k*4; i <= 4 + k*4; i++) {
			for(j = i+1; j <= 4 + k*4; j++) {
				if(score[i] < score[j]) {
					temp = score[i];
					score[i] = score[j];
					score[j] = temp;

					temp2.name = R[i].name;
					R[i].name = R[j].name;
					R[j].name = temp2.name;
				}
			}
		}
	}
}

void sortByScore(Isi_Team R, int Jml_Tim) {
	int i,k;
	for( k=0; k<Jml_Tim/4; k++) {
		printf("\nGrup %c\n", 'A' + k);
		printf("\nHasil akhir babak penyisihan:\n");
		printf("Tim\t\tScore\n");
		printf("--------------------\n");
		for(i=1; i<=Jml_Tim; i++) {
			printf("%s\t\t%d\n", R[i].name, score[i]);
		}
	}
}

void cekPemenang(Isi_Team Q, int Jml_Tim, Isi_Team R, char timPemenang[][500]) {
	int i, j, k, l;
	int x = 0, grup;
	char ulang;
	int index = 0;
	for(l = 0; l < Jml_Tim/4; l++) {
		printf("\nGrup %c\n", 'A' + l);
		printf("Tim yang masuk ke babak Gugur: \n");
		printf("--------------------\n");
		for (i = 1 + l*4; i <= 4 + l*4; i++) {
			for(j = i+1; j <= 4 + l*4; j++) {
				for(k = j+1; k <= 4 + l*4; k++) {
					if(Q[i].score == Q[j].score && Q[i].score == Q[k].score && Q[j].score == Q[k].score) {
							for (i = 1 + l*4; i <= 2 + l*4; i++) {
								printf("%s\n", R[i].name);
								strcpy(timPemenang[index], R[i].name);
								index++;
								x = 1;
							}
						}
					}
				}
			}
		}

		if( x != 1) {
			getPemenang(Q,Jml_Tim,timPemenang);
		}
	}


void inputSkor(Isi_Team Q, int Jml_Tim) {
	int i, j, k;
	int scoreI, scoreJ;
	char namaGrup = 'A';
	for(k = 0; k < Jml_Tim/4; k++) {
		system("cls");
		printf("Grup %c\n", namaGrup + k);
		for(i = 1 + k*4; i <= 4 + k*4; i++) {
			for(j = i+1; j <= 4 + k*4; j++) {
				printf("Masukkan skor %s vs %s : ", Q[i].name, Q[j].name);
				scanf("%d-%d", &scoreI, &scoreJ);

				score[i] = scoreI + score[i];
				score[j] = scoreJ + score[j];

				if(scoreI > scoreJ) {
					Q[i].score = Q[i].score + 3;
				} else if(scoreJ > scoreI) {
					Q[j].score = Q[j].score + 3;
				} else {
					Q[i].score = Q[i].score + 1;
					Q[j].score = Q[j].score + 1;
				}
			}
		}
	}
}



