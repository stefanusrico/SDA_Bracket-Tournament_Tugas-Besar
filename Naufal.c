#include "Naufal.h"

void tandingGrup(Isi_Team Q, int Jml_Tim) { //Fungsi tandingGrup menerima masukan array Q yang berisi informasi tentang tim-tim yang akan berkompetisi dan jumlah tim Jml_Tim
	int i, j, k; //Mendeklasikan variabel lokal i, j, dan k.
	char namaGrup = 'A';
	for(k = 0; k < Jml_Tim/4; k++) { //Memulai loop dengan variabel k untuk membagi tim-tim menjadi grup-grup.
		printf("Grup %c\n", namaGrup + k); //Menampilkan output berupa informasi grup yang sedang diproses.
		for(i = 1 + k*4; i <= 4 + k*4; i++) {
			for(j = i+1; j <= 4 + k*4; j++) {
				printf("%s vs %s\n", Q[i].name, Q[j].name); //Menampilkan output pertandingan antara tim Q[i] dan tim Q[j].
			}
		}
	}
}

void swapHasil(Isi_Team Q, int Jml_Tim) { //bertujuan untuk menukar posisi tim berdasarkan skor yang mereka peroleh dalam pertandingan
	int i,j,k;
	team temp;
	for(k = 0; k < Jml_Tim/4; k++) { //Memulai loop dengan variabel k untuk membagi tim-tim menjadi grup-grup
		for(i = 1 + k*4; i <= 4 + k*4; i++) { //Memulai loop dengan variabel i untuk memilih tim pertama dalam pertukaran.
			for(j = i+1; j <= 4 + k*4; j++) { //Memulai loop dengan variabel j untuk memilih tim kedua dalam pertukaran, yang akan dibandingkan dengan tim pertama.
				if(Q[i].score < Q[j].score) { //Memeriksa apakah skor tim Q[i] lebih kecil dari skor tim Q[j].
					temp = Q[i]; //Jika kondisi di atas terpenuhi, maka dilakukan pertukaran posisi tim Q[i] dengan Q[j] 
					Q[i] = Q[j];
					Q[j] = temp;
				}
			}
		}
	}
}

void sortHasil(Isi_Team Q, int Jml_Tim) { //Tujuan nya mengurutkan dan menampilkan hasil akhir babak penyisihan tim dalam grup berdasarkan skor yang mereka peroleh.
	int i,k;
	for(k = 0; k < Jml_Tim/4; k++) {
		printf("\nGrup %c\n", 'A' + k);
<<<<<<< HEAD
		printf("\nHasil akhir babak penyisihan:\n"); //Menampilkan output berupa string yang memberikan informasi bahwa ini adalah hasil akhir babak penyisihan
		printf("Tim\t\tSkor\n"); //Menampilkan output berupa header tabel untuk nama tim dan skor.
=======
		printf("\nHasil akhir babak penyisihan:\n");
		printf("Tim\t\tPoin\n");
>>>>>>> a27d6de90d905c86bbe466d51fd9e4e9ffe940c8
		printf("--------------------\n");
		for (i = 1 + k*4; i <= 4 + k*4; i++) {
			printf("%s\t\t%d\n", Q[i].name, Q[i].score);	
		}
	}
}

void getPemenang(Isi_Team Q, int Jml_Tim, char timPemenang[][500]){ //Tujuan modul di atas adalah untuk mendapatkan tim pemenang dari setiap grup berdasarkan posisi mereka setelah babak penyisihan. 
	int i,k;
	int index = 0;
	for(k = 0; k < Jml_Tim/4; k++) {
		printf("\nGrup %c\n", 'A' + k);
		printf("Tim yang masuk ke babak Gugur: \n"); //Menampilkan output berupa string yang memberikan informasi bahwa ini adalah tim yang masuk ke babak gugur.
		printf("--------------------\n");
		for (i = 1 + k*4; i <= 2 + k*4; i++) {
			printf("%s\n", Q[i].name); //Menampilkan output berupa nama tim Q[i] yang masuk ke babak gugur.
			strcpy(timPemenang[index], Q[i].name); //Menggunakan fungsi strcpy untuk menyalin nama tim Q[i] ke dalam elemen timPemenang pada indeks index
			index++;
		}
	}
}
