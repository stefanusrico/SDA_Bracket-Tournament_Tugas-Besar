#include <stdio.h>
#include "najwan.h"
#include "head.h"



void tampilan(){
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
	printf("\t\t\t\t                    |_______|  '.____.'  |_____| `.______.'  \n");
}

void swapScore(Isi_Team Q, int Jml_Tim) {
	int i,j,k;
	int temp;
	Isi_Team R;
	team temp2;
	for(k = 0; k < Jml_Tim/4; k++) {
		for(i = 1 + k*4; i <= 4 + k*4; i++) {
			for(j = i+1; j <= 4 + k*4; j++) {
				if(score[i] < score[j]) {
					temp = score[i];
					score[i] = score[j];
					score[j] = temp;
					
					temp2.name = Q[i].name;
					Q[i].name = Q[j].name;
					Q[j].name = temp2.name;
				}
			}
		}
	}
}

void sortByScore(Isi_Team Q, int Jml_Tim){
	int i,k;
	for( k=0; k<Jml_Tim/4; k++){
		printf("\nGrup %c\n", 'A' + k);
		printf("\nHasil akhir babak penyisihan:\n");
		printf("Tim\t\tScore\n");
		printf("--------------------\n");
		for(i=1; i<=Jml_Tim; i++){
			printf("%s\t\t%d\n", Q[i].name, score[i]);
		}
	}
}

void ulangPertandingan(Isi_Team Q, int Jml_Tim){
	int i, j, k;
	char ulang;
	for(k = 0; k < Jml_Tim/4; k++) {
		printf("\n");
        printf("Rematch:\n");
        printf("--------\n");
        for (i = 1 + k*4; i <= 4 + k*4; i++) {
            for(j = i+1; j <= 4 + k*4; j++) {
                if(Q[i].score == Q[j].score){
                    printf("Rematch %s dan %s (y/n)?\n", Q[i].name, Q[j].name);
                    getchar();
                    scanf("%c", &ulang);
                    if(ulang == 'Y' || ulang == 'y'){
                    	
					}
                }
            }
		}
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
