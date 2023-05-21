#include "rico.h"
#include "head.h"
#include "najwan.h"

void buatArrayKualifikasi(Isi_Tree P, Isi_Team Q, Isi_Team R, char namaTimArr[MAX_STRING_LENGTH], char* treeString, int Jml_Tim, int tahun) {
	int i;
	char namaGrup = 'A'; // Variabel untuk menyimpan nama grup, dimulai dari A
	int jumlahTimGrup = 4; // Jumlah tim dalam satu grup
	char timPemenang[100][500]; // Array untuk menyimpan nama tim pemenang
	int indeksTim = 0; // Indeks untuk mengakses array namaTimArr

	for(i = 1; i <= Jml_Tim; i++) { // Loop untuk memasukkan data tim
		if(indeksTim == 0) {
			printf("Grup %c\n", namaGrup); // Menampilkan nama grup saat indeksTim bernilai 0
		}
		printf("Masukkan nama tim %d : ", indeksTim+1); // Meminta input nama tim
		fflush(stdin);
		fgets(namaTimArr, MAX_STRING_LENGTH, stdin); // Membaca input nama tim
		strtok(namaTimArr, "\n"); // Menghapus karakter newline (\n) dari input nama tim
		Q[i].name = strdup(namaTimArr); // Menyalin nama tim ke struktur Q
		Q[i].score = 0; // Menginisialisasi skor tim dengan 0

		indeksTim++; // Menaikkan indeksTim
		if(indeksTim == jumlahTimGrup) { // Jika indeksTim sudah mencapai jumlahTimGrup
			indeksTim = 0; // Set indeksTim kembali ke 0
			namaGrup++; // Pindah ke grup berikutnya dengan menaikkan karakter namaGrup
		}
	}
	operasiFileTimPemenang(P, "timPemenangKualifikasi.txt", treeString, timPemenang,Jml_Tim, tahun); // Memanggil fungsi operasiFileTimPemenang
}

void Create_tree(Isi_Tree P, int Jml_Node, infotype Nilai, char namaArr[]) {
	int i;
	for (i = 1; i <= Jml_Node; i++) {
		P[i].nama = Nilai; // Mengisi struktur P dengan nilai Nilai
		P[i].skor = NIL; // Mengisi skor dengan nilai NIL
		P[i].left = NIL; // Mengisi left dengan nilai NIL
		P[i].right = NIL; // Mengisi right dengan nilai NIL
	}

	int posisi = 1, jum_enty = 1; // Variabel posisi untuk menyimpan posisi saat ini, jum_enty untuk menyimpan jumlah entri
	fflush(stdin); // Menghapus buffer input

	P[1].nama = " "; // Mengisi nama node pertama dengan spasi

	if(Jml_Node > 0) {
		P[1].nama = strdup(namaArr); // Mengisi nama node pertama dengan namaArr yang telah disalin
		jum_enty++;
		posisi = 1;
		P[1].left = 2*posisi; // Mengisi left node pertama dengan posisi*2
		P[1].right = 2*posisi+1; // Mengisi right node pertama dengan posisi*2+1
		int posisi2 = 2; // Variabel posisi2 untuk menyimpan posisi saat ini (untuk left dan right)

		while(jum_enty <= Jml_Node) {
			P[posisi*2].nama = strdup(namaArr); // Mengisi nama node left dengan namaArr yang telah disalin
			if(posisi*2 < floor(Jml_Node/2)) {
				P[posisi*2].left = 2 * posisi2; // Mengisi left node left dengan posisi2*2
				P[posisi*2].right = 2 * posisi2 + 1; // Mengisi right node left dengan posisi2*2+1
			} else {
				P[posisi*2].left = 0; // Mengisi left node left dengan 0
				P[posisi*2].right = 0; // Mengisi right node left dengan 0
			}
			jum_enty++;

			if(jum_enty <= Jml_Node) {
				P[posisi*2+1].nama = strdup(namaArr); // Mengisi nama node right dengan namaArr yang telah disalin
				if(posisi*2+1 <= floor(Jml_Node/2)) {
					P[posisi*2+1].left = 2 * posisi2 + 2; // Mengisi left node right dengan posisi2*2+2
					P[posisi*2+1].right = 2 * posisi2 + 3; // Mengisi right node right dengan posisi2*2+3
				} else {
					P[posisi*2+1].left = 0; // Mengisi left node right dengan 0
					P[posisi*2+1].right = 0; // Mengisi right node right dengan 0
				}
				jum_enty++;
			}
			posisi++;
			posisi2 = posisi2 + 2;
		}
	}
}

void printTree(Isi_Tree P, int posisi, int level, char* treeString) {
	if (posisi != NIL) {
		printTree(P, P[posisi].left, level + 1, treeString); // Mencetak subtree kiri

		for (int i = 0; i < level; i++) {
			strcat(treeString, "   "); // Menambahkan spasi untuk indentasi
		}

		char namaArr[MAX_STRING_LENGTH];
		sprintf(namaArr, "%s\n",P[posisi].nama); // Mengonversi nama node ke string
		strcat(treeString, namaArr); // Menambahkan nama node ke treeString

		printTree(P, P[posisi].right, level + 1, treeString); // Mencetak subtree kanan
	}
}

void PrintTree(Isi_Tree P, Isi_Team Q, Isi_Team R, int Jml_Node, char* treeString, char namaTimArr[], char timPemenang[][500], int tahun) {
	int jmlTim = 32; // Jumlah tim
	strcpy(treeString, ""); // Mengosongkan treeString
	printTree(P, 1, 0, treeString); // Memanggil fungsi printTree untuk mencetak pohon
	printf("\nTree:\n");
	printf("%s", treeString); // Menampilkan treeString yang berisi pohon

	operasiFileTimPemenang(P,"timPemenangKualifikasi.txt", treeString, timPemenang, jmlTim, tahun); // Memanggil fungsi operasiFileTimPemenang
}

void cariDaun(Isi_Tree P, int posisi, int* indeksDaun, int* hitungDaun) {
	if (posisi == NIL) {
		return;
	}
	if (P[posisi].left == NIL && P[posisi].right == NIL) {
		indeksDaun[*hitungDaun] = posisi;
		(*hitungDaun)++;
	}
	cariDaun(P, P[posisi].left, indeksDaun, hitungDaun); // Mencari daun pada subtree kiri
	cariDaun(P, P[posisi].right, indeksDaun, hitungDaun); // Mencari daun pada subtree kanan
}

void shuffleArray(char arr[][500], int size) {
	srand(time(NULL)); // Inisialisasi generator angka acak dengan waktu saat ini
	int i, j;
	for (i = size - 1; i > 0; i--) {
		j = rand() % (i + 1); // Menghasilkan indeks acak antara 0 dan i

		// Menukar elemen arr[i] dengan arr[j]
		char temp[500];
		strcpy(temp, arr[i]);
		strcpy(arr[i], arr[j]);
		strcpy(arr[j], temp);
	}
}

void assignDaunTree(Isi_Tree P, int* indeksDaun, int *hitungDaun, char timPemenang[][500]) {
	int i;
	// Membuat salinan array timPemenang
	char timPemenangCopy[*hitungDaun][500];
	for (int i = 0; i < *hitungDaun; i++) {
		strcpy(timPemenangCopy[i], timPemenang[i]);
	}

	shuffleArray(timPemenangCopy, *hitungDaun); // Mengacak salinan array timPemenang
	for(i = 0; i < *hitungDaun; i++) {
		strcpy(P[indeksDaun[i]].nama, timPemenangCopy[i]);
		printf("\nHasil: %s", P[indeksDaun[i]].nama);
	}
}

void updateParent(Isi_Tree P, int index, int* indeksDaun, int* hitungDaun, char timPemenangTree[][500]) {
	int i;
	char kembali;
	int posisi = indeksDaun[0];
	if(posisi < 2) {
		system("cls");  // Membersihkan layar konsol
		printf("Input data selesai\n");
		printf("Apakah ingin kembali ke menu utama? (Y/N)");
		getchar();  // Menghapus karakter newline dari buffer stdin
		scanf("%c", &kembali);  // Membaca input dari pengguna
		if(kembali == 'Y' || kembali == 'y') {
			system("cls");  // Membersihkan layar konsol
			mainmenu();  // Kembali ke menu utama
		} else {
			exit(0);  // Keluar dari program
		}
	}
	for(i = posisi; i <= posisi*2-2; i+=2) {
		strcpy(P[(i-1)/2+1].nama, timPemenangTree[index]);  // Mengupdate nama tim pemenang pada node induk
		index++;  // Meningkatkan indeks untuk memperoleh nama tim pemenang berikutnya
	}
}

void inputSkorTree(Isi_Tree P, Isi_Team Q, Isi_Team R, int* indeksDaun, int* hitungDaun, char* treeString, char timPemenang[][500], char timPemenangTree[][500], char namaTimArr[], int tahun) {
	int i, j, k;
	int posisi;
	int scoreI, scoreJ;
	int index = 0;
	posisi = indeksDaun[0];
	while(P[1].nama != "?") {  // Melakukan iterasi selama nama node pertama tidak sama dengan "?"
		printf("jumlah n adalah : %d\n", posisi);
		for (i = posisi; i <= posisi*2-2; i+=2) {
			printf("\nMasukkan skor %s vs %s : ", P[i].nama, P[i+1].nama);
			scanf("%d-%d", &scoreI, &scoreJ);  // Membaca input skor dari pengguna
			if(scoreI > scoreJ) {
				P[i].skor = scoreI;  // Mengupdate skor tim i
				P[i+1].skor = scoreJ;  // Mengupdate skor tim i+1
				strcpy(timPemenangTree[index], P[i].nama);  // Menyimpan nama tim pemenang ke dalam array timPemenangTree
				index++;
			} else if(scoreI < scoreJ) {
				P[i].skor = scoreI;  // Mengupdate skor tim i
				P[i+1].skor = scoreJ;  // Mengupdate skor tim i+1
				strcpy(timPemenangTree[index], P[i+1].nama);  // Menyimpan nama tim pemenang ke dalam array timPemenangTree
				index++;
			} else {
				//penalti
				P[i].skor = scoreI;  // Mengupdate skor tim i
				P[i+1].skor = scoreJ;  // Mengupdate skor tim i+1
				aduPenalti(P, i, index, timPemenangTree);  // Melakukan adu penalti untuk menentukan tim pemenang
				index++;
			}
		}
		printf("\nindeks : %d\n",index);
		index = index - index;  // Mereset nilai index
		updateParent(P, index, indeksDaun, hitungDaun,timPemenangTree);  // Mengupdate node induk dengan nama tim pemenang yang baru
		PrintTree(P, Q, R, 31, treeString, namaTimArr, timPemenang, tahun);  // Mencetak pohon setelah melakukan update
		system("pause");  // Menunggu pengguna menekan tombol sebelum melanjutkan
		system("cls");  // Membersihkan layar konsol
		posisi = posisi/2;  // Mengupdate nilai posisi menjadi posisi/2
		indeksDaun[0] = posisi;  // Mengupdate nilai indeksDaun[0] dengan nilai posisi
	}
}

void operasiFileTimPemenang(Isi_Tree P, char* filename, char* treeString, char timPemenang[][500], int Jml_Tim, int tahun) {
	char namaFile[100];
	sprintf(namaFile, "%s_%d.txt", filename, tahun);  // Membuat nama file dengan format "filename_tahun.txt"

	FILE* file = fopen(namaFile, "w");  // Membuka file dengan mode write

	if (file == NULL) {
		printf("Gagal membuka file.");
		return;
	}

	int index = 0;
	fprintf(file, "Tournament pada tahun : %d", tahun);  // Menulis tahun turnamen ke file
	for (int i = 0; i < Jml_Tim / 4; i++) {
		fprintf(file, "\nGrup %c\n", 'A' + i);  // Menulis label grup ke file
		fprintf(file, "Tim yang masuk ke babak Gugur:\n");
		fprintf(file, "--------------------\n");

		for (int j = 1 + i * 4; j <= 2 + i * 4; j++) {
			fprintf(file, "%s\n", timPemenang[index]);  // Menulis nama tim pemenang ke file
			index++;
		}
	}
	fprintf(file, "\nTree :\n %s", treeString);  // Menulis pohon ke file
	fprintf(file, "Pemenang Tounament %d adalah : %s", tahun, P[1].nama);  // Menulis nama pemenang turnamen ke file

	fclose(file);
}
