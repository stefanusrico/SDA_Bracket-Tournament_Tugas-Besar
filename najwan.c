#include <stdio.h>
#include "najwan.h"
#include "naufal.h"
#include "head.h"


//menggunakan ASCII GENERATOR, web :https://ascii-generator.site/t/
void tampilan() {
	puts("\t\t\t\t 88888888888  .d88888b.  888     888 8888888b.  888b    888        d8888 888b     d888 8888888888 888b    888 88888888888");
	puts("\t\t\t\t     888     888     888 888     888 888    888 88888b  888      d88P888 88888b.d88888 888        88888b  888     888    ");
	puts("\t\t\t\t     888     888     888 888     888 888    d88P888Y88b 888     d88P 888 888Y88888P888 8888888    888Y88b 888     888    ");
	puts("\t\t\t\t     888     888     888 888     888 888   d88P 888Y88b 888     d88P 888 888Y88888P888 8888888    888Y88b 888     888    ");
	puts("\t\t\t\t     888     888     888 888     888 8888888P   888 Y88b888    d88P  888 888 Y888P 888 888        888 Y88b888     888    ");
	puts("\t\t\t\t     888     888     888 888     888 888 T88b   888  Y88888   d88P   888 888  Y8P  888 888        888  Y88888     888    ");
	puts("\t\t\t\t     888     Y88b. .d88P Y88b. .d88P 888  T88b  888   Y8888  d8888888888 888       888 888        888   Y8888     888    ");
	puts("\t\t\t\t     888       Y88888P     Y88888P   888   T88b 888    Y888 d88P     888 888       888 8888888888 888    Y888     888    \n\n");
	puts("\t\t\t\t\t\t 888888b.   8888888b.         d8888  .d8888b.  888    d8P  8888888888 88888888888 ");
	puts("\t\t\t\t\t\t 888   88b  888   Y88b       d88888 d88P  Y88b 888   d8P   888            888     ");
	puts("\t\t\t\t\t\t 888  .88P  888    888      d88P888 888    888 888  d8P    888            888     ");
	puts("\t\t\t\t\t\t 8888888K.  888   d88P     d88P 888 888        888d88K     8888888        888     ");
	puts("\t\t\t\t\t\t 888    888 888 T88b     d88P   888 888    888 888  Y88b   888            888     ");
	puts("\t\t\t\t\t\t 888   d88P 888  T88b   d8888888888 Y88b  d88P 888   Y88b  888            888     ");
	puts("\t\t\t\t\t\t 8888888P   888   T88b d88P     888   Y8888P   888    Y88b 8888888888     888     ");
	puts("\t\t\t\t============================================================================================================================\n\n");
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
	int i = 1, j = 2, k = 3, l = 4;
	int x = 0, grup;
	char ulang;
	int index = 0;
	for(x = 0; x < Jml_Tim/4; x++) {
		printf("\nGrup %c\n", 'A' + x);
		printf("Tim yang masuk ke babak Gugur: \n");
		printf("--------------------\n");
		i = 1 + x*4;
		j = 2 + x*4;
		k = 3 + x*4;
		l = 4 + x*4;

		//untuk kondisi : 1 1 1 1
		if((Q[i].score == Q[j].score) && (Q[i].score == Q[k].score) && (Q[i].score == Q[l].score) && (Q[j].score == Q[l].score) && (Q[j].score == Q[k].score) && (Q[k].score == Q[l].score) ) {
			printf("%s\n", Q[i].name);
			printf("%s", Q[i+1].name);
			strcpy(timPemenang[index],Q[i].name);
			index++;
			strcpy(timPemenang[index],Q[i+1].name);
			index++;
		} /*untuk kondisi : 1 1 1 0*/else if((Q[i].score == Q[j].score == Q[k].score) && (Q[k].score != Q[l].score)) {

			printf("%s\n", R[i].name);
			printf("%s\n", R[i+1].name);
			strcpy(timPemenang[index],R[i].name);
			index++;
			strcpy(timPemenang[index],R[i+1].name);
			index++;

		} /*untuk kondisi : 2 1 1 1 */else if((Q[j].score == Q[k].score) && (Q[k].score == Q[l].score) && (Q[i].score!= Q[j].score) && (Q[i].score!= Q[k].score) && (Q[i].score!= Q[l].score) ) {
			printf("%s\n", Q[i].name);
			printf("%s", Q[i+1].name);
			strcpy(timPemenang[index],Q[i].name);
			index++;
			strcpy(timPemenang[index],Q[i+1].name);
			index++;
		} /*untuk kondisi : 4 3 2 1*/else if(Q[i].score != Q[j].score && Q[i].score!= Q[k].score && Q[i].score!= Q[l].score && Q[j].score!= Q[k].score && Q[j].score!= Q[l].score && Q[l].score!= Q[k].score || Q[l].score== Q[k].score) {
			printf("%s\n", Q[i].name);
			printf("%s", Q[i+1].name);
			strcpy(timPemenang[index],Q[i].name);
			index++;
			strcpy(timPemenang[index],Q[i+1].name);
			index++;
		} /*untuk kondisi : */   else  {
			printf("%s\n", Q[i].name);
			printf("%s", Q[i+1].name);
			strcpy(timPemenang[index],Q[i].name);
			index++;
			strcpy(timPemenang[index],Q[i+1].name);
			index++;
		}
	}


}


void inputSkor(Isi_Team Q, int Jml_Tim) {
	int i, j, k;
	char scoreI, scoreJ;
	char namaGrup = 'A';
	for(k = 0; k < Jml_Tim/4; k++) {
		system("cls");
		printf("\t\t*cara penulisannya 'skor-skor'\n\t\t*jika tim tidak hadir, maka diberi tanda '-' dan yang hadir 'o'\n");
		printf("Grup %c\n", namaGrup + k);
		for(i = 1 + k*4; i <= 4 + k*4; i++) {
			for(j = i+1; j <= 4 + k*4; j++) {
				printf("Masukkan skor %s vs %s : ", Q[i].name, Q[j].name);
				scanf("%c-%c",&scoreI,&scoreJ);
				getchar();
			
				if((scoreI == 'o' && scoreJ == '-') || (scoreI == '-' && scoreJ == 'o')) {
					if(scoreI == 'o' && scoreJ == '-') {
						Q[i].score = Q[i].score + 3;
						scoreI = '3';
						scoreJ = '0';
						score[i] = (scoreI - '0') + score[i];
						score[j] = (scoreJ - '0') + score[j];
						
					} else {
						Q[j].score = Q[j].score + 3;
						scoreI = '0';
						scoreJ = '3';
						score[i] = (scoreI - '0') + score[i];
						score[j] = (scoreJ - '0') + score[j];
						
					}
				} else if(isdigit(scoreJ) && isdigit(scoreI)) {

					scoreI = scoreI - '0';
					scoreJ = scoreJ - '0';
					
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

				} else {
					printf("Invalid input\n");
					j--;
					continue;
				}
			}
		}
	}
}





void aduPenalti(Isi_Tree P, int i, int index, char timPemenangTree[][500]) {
	int scoreI,scoreJ;
	printf("\n ADU PENALTI ANTARA %s DAN %s", P[i].nama, P[i+1].nama);
	for(int kicker=1; kicker<=5; kicker++) {
		printf("Tendangan ke: %d\n", kicker);
		do {
			printf("%s: ", P[i].nama);
			scanf("%d", &scoreI);
			printf("%s: ", P[i+1].nama);
			scanf("%d", &scoreJ);

			if ((scoreI != 0 && scoreI != 1) || (scoreJ != 0 && scoreJ != 1)) {
				printf("Invalid input! skor harus 0 atau 1.\n");
			} else {
				break;
			}
		} while (1);

		scorePenalti[i] += scoreI;
		scorePenalti[i+1] += scoreJ;
	}

	if(scorePenalti[i] == scorePenalti[i+1]) {
		aduPenalti(P, i, index, timPemenangTree);
	} else if(scorePenalti[i] < scorePenalti[i+1]) {
		strcpy(timPemenangTree[index], P[i+1].nama);
	} else if(scorePenalti[i] > scorePenalti[i+1]) {
		strcpy(timPemenangTree[index], P[i].nama);
	}
}

//int isAngka(char p) {
//	if (p[100] >= '0' && p[100] <= '100') {
////		|| scoreJ >= '0' && scoreJ <= '2147483647' || scoreI == 'o' && scoreJ == '-' ||scoreI == '-' && scoreJ == 'o'
//		return 1;  // pernyataannya benar, dikirim 0 karena yang dikembalikan tuh kebalikannya
//	} else {
//		return 0;  // Karakter bukan angka
//	}
//}
//

