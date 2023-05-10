#include <stdio.h>
#include "najwan.h"
#include "naufal.h"
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


//modul ini bertujuan untuk menentukan score yang paling besar itu di paling atas
void swapScore(Isi_Team R, int Jml_Tim) {
	int i,j,k;
	int temp;
	team temp2;
	for(k = 0; k < Jml_Tim/4; k++) { //perulangan dengan syarat berikut bertujuan untuk membagi setiap grup terdiri dari 4 tim
		for(i = 1 + k*4; i <= 4 + k*4; i++) { //variabel i pada perulangan berikut berguna untuk menjadi indeks pertama yang akan dibandingkan. nilai awal k adalah 0, jadi batasan pertamanya adalah 4
			for(j = i+1; j <= 4 + k*4; j++) { //variabel j pada perulangan berikut berguna untuk menjadi indeks kedua yang akan dibandingkan dengan indeks pertama. 
				if(score[i] < score[j]) { //jika indeks variabel i lebih kecil dari indeks variabel j, maka akan melakukan swap/penukaran
					temp = score[i];      //melakukan penukaran posisi score. score pertama (i) akan disimpan sementara pada temp
					score[i] = score[j];  //score kedua (j) ditempatkan ke posisi pertama
					score[j] = temp;	  //score pertama (i) yang tadi disimpan di temp, kemudian di pindahkan di posisi kedua

					temp2.name = R[i].name; //melakukan penukaran posisi nama tim, untuk mekanisme penukaran sama dengan penukaran score
					R[i].name = R[j].name;
					R[j].name = temp2.name;
				}
			}
		}
	}
}

void sortByScore(Isi_Team R, int Jml_Tim) {
	int i,x;                      //variabel x berguna untuk menjadi batasan agar 1 grup terdiri dari 4 tim
	for( x=0; x<Jml_Tim/4; x++) { //dilakukan perulangan dengan batasan x<jumlah tim dibagi 4, agar terbentuk grup yang masing-masing nya terdiri dari 4 tim saja
		printf("\nGrup %c\n", 'A' + x); //grup dimulai dari A, kemudian untuk selanjutnya akan ditambah dengan indeks x, sehingga selanjutnya menjadi B, C, dan seterusnya
		printf("\nHasil akhir babak penyisihan:\n");
		printf("Tim\t\tScore\n");
		printf("--------------------\n");
		for(i=1 + x*4; i<=4 + x*4; i++) { //melakukan perulangan dengan syarat berikut, agar ketika di print ke layar, hanya 4 tim per grup yang ditampilkan, dengan indeks 1-4 = grup A, 5-8 Grup B,dan seterusnya.karena x pertamanya adalah 0, maka batasan pertama adalah 4, dst.
			printf("%s\t\t%d\n", R[i].name, score[i]); //melakukan print ke layar berdasarkan indeks yang telah melakukan swap di modul swapScore
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
					if(Q[i].score == Q[j].score == Q[k].score && Q[i].score == Q[k].score != Q[j].score || Q[i].score != Q[k].score == Q[j].score) {
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
			getPemenang(Q, Jml_Tim, timPemenang);
		}
	}


void inputSkor(Isi_Team Q, int Jml_Tim, int scoreI, int scoreJ) {
	int i, j, k;
//	int scoreI, scoreJ;
	char namaGrup = 'A';
	for(k = 0; k < Jml_Tim/4; k++) {
		system("cls");
		printf("Grup %c\n", namaGrup + k);
		for(i = 1 + k*4; i <= 4 + k*4; i++) {
			for(j = i+1; j <= 4 + k*4; j++) {
//				printf("Masukkan skor %s vs %s : ", Q[i].name, Q[j].name);
//				scanf("%d-%d", &scoreI, &scoreJ);

				score[i] = scoreI + score[i];
				score[j] = scoreJ + score[j];
				
				if(scoreI < 0 || scoreJ < 0){
					printf("Invalid input");
					j--;
					continue;	
				}
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

void aduPenalti(Isi_Tree P, int i, int index, char timPemenangTree[][500]){
	int scoreI,scoreJ;
	printf("\n ADU PENALTI ANTARA %s DAN %s", P[i].nama, P[i+1].nama);
	for(int kicker=1; kicker<=5; kicker++){
		printf("Tendangan ke: %d\n", kicker);
		do {
			printf("%s: ", P[i].nama);
			scanf("%d", &scoreI);
			printf("%s: ", P[i+1].nama);
			scanf("%d", &scoreJ);
			
			if ((scoreI != 0 && scoreI != 1) || (scoreJ != 0 && scoreJ != 1)){
				printf("Invalid input! skor harus 0 atau 1.\n");
			}
			else {
				break;
			}
		} while (1);

		scorePenalti[i] += scoreI;
		scorePenalti[i+1] += scoreJ;
	}
	
	if(scorePenalti[i] == scorePenalti[i+1]){
		aduPenalti(P, i, index, timPemenangTree);
	}else if(scorePenalti[i] < scorePenalti[i+1]){
		strcpy(timPemenangTree[index], P[i+1].nama);
	}else if(scorePenalti[i] > scorePenalti[i+1]){
		strcpy(timPemenangTree[index], P[i].nama);
	}
}




