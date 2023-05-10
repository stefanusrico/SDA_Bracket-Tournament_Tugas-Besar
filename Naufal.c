#include "Naufal.h"

void tandingGrup(Isi_Team Q, int Jml_Tim) {
	int i, j, k;
	char namaGrup = 'A';
	for(k = 0; k < Jml_Tim/4; k++) {
		printf("Grup %c\n", namaGrup + k);
		for(i = 1 + k*4; i <= 4 + k*4; i++) {
			for(j = i+1; j <= 4 + k*4; j++) {
				printf("%s vs %s\n", Q[i].name, Q[j].name);
			}
		}
	}
}

void swapHasil(Isi_Team Q, int Jml_Tim) {
	int i,j,k;
	team temp;
	for(k = 0; k < Jml_Tim/4; k++) {
		for(i = 1 + k*4; i <= 4 + k*4; i++) {
			for(j = i+1; j <= 4 + k*4; j++) {
				if(Q[i].score < Q[j].score) {
					temp = Q[i];
					Q[i] = Q[j];
					Q[j] = temp;
				}
			}
		}
	}
}

void sortHasil(Isi_Team Q, int Jml_Tim) {
	int i,k;
	for(k = 0; k < Jml_Tim/4; k++) {
		printf("\nGrup %c\n", 'A' + k);
		printf("\nHasil akhir babak penyisihan:\n");
		printf("Tim\t\tPoin\n");
		printf("--------------------\n");
		for (i = 1 + k*4; i <= 4 + k*4; i++) {
			printf("%s\t\t%d\n", Q[i].name, Q[i].score);	
		}
	}
}

void getPemenang(Isi_Team Q, int Jml_Tim, char timPemenang[][500]){
	int i,k;
	int index = 0;
	for(k = 0; k < Jml_Tim/4; k++) {
		printf("\nGrup %c\n", 'A' + k);
		printf("Tim yang masuk ke babak Gugur: \n");
		printf("--------------------\n");
		for (i = 1 + k*4; i <= 2 + k*4; i++) {
			printf("%s\n", Q[i].name);
			strcpy(timPemenang[index], Q[i].name);
			index++;
		}
	}
}
