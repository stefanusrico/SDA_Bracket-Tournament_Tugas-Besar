#include "rico.h"
#include "head.h"
#include "najwan.h"

void buatArrayKualifikasi(Isi_Tree P, Isi_Team Q, Isi_Team R, char namaTimArr[MAX_STRING_LENGTH], char* treeString, int Jml_Tim) {
	int i;
	char namaGrup = 'A';
	int jumlahTimGrup = 4;
	int indeksTim = 0;
//	char namaTimArr[MAX_STRING_LENGTH];
	for(i = 1; i <= Jml_Tim; i++) {
		if(indeksTim == 0) {
			printf("Grup %c\n", namaGrup);
		}
		printf("Masukkan nama tim %d : ", indeksTim+1);		
//		char namaTimArr[MAX_STRING_LENGTH];
		fflush(stdin);
		fgets(namaTimArr, MAX_STRING_LENGTH, stdin);
		strtok(namaTimArr, "\n");
		Q[i].name = strdup(namaTimArr);
		Q[i].score = 0;

		indeksTim++;
		if(indeksTim == jumlahTimGrup) {
			indeksTim = 0;
			namaGrup++;
		}
	}
	saveData(P, Q, R, treeString, namaTimArr, 31, 1);
}

void Create_tree(Isi_Tree P, int Jml_Node, infotype Nilai, char namaArr[]) {
	int i;
	for (i = 1; i <= Jml_Node; i++) {
		P[i].nama = Nilai;
		P[i].skor = NIL;
		P[i].left = NIL;
		P[i].right = NIL;
	}

	int posisi = 1, jum_enty = 1;
	fflush(stdin);
	P[1].nama = " ";

	if(Jml_Node > 0) {
//		printf("\nMasukkan Nilai untuk Root: ");
//		char namaArr[MAX_STRING_LENGTH];
//		fgets(namaArr, MAX_STRING_LENGTH, stdin);
		P[1].nama = strdup(namaArr);
		jum_enty++;
		posisi = 1;
		P[1].left = 2*posisi;
		P[1].right = 2*posisi+1;
		int posisi2 = 2;

		while(jum_enty <= Jml_Node) {
//			printf("\nNilai Parent ke-%d: %s", posisi, (P[posisi].nama));
//			printf("\nAnak kiri: ");
//			fgets(namaArr, MAX_STRING_LENGTH, stdin);
			P[posisi*2].nama = strdup(namaArr);
			if(posisi*2 < floor(Jml_Node/2)) {
				P[posisi*2].left = 2 * posisi2;
				P[posisi*2].right = 2 * posisi2 + 1;
			} else {
				P[posisi*2].left = 0;
				P[posisi*2].right = 0;
			}
			jum_enty++;

			if(jum_enty <= Jml_Node) {
//				printf("Anak kanan: ");
//				fgets(namaArr, MAX_STRING_LENGTH, stdin);
				P[posisi*2+1].nama = strdup(namaArr);
				if(posisi*2+1 <= floor(Jml_Node/2)) {
					P[posisi*2+1].left = 2 * posisi2 + 2;
					P[posisi*2+1].right = 2 * posisi2 + 3;
				} else {
					P[posisi*2+1].left = 0;
					P[posisi*2+1].right = 0;
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
		printTree(P, P[posisi].left, level + 1, treeString);

		for (int i = 0; i < level; i++) {
			strcat(treeString, "   ");
		}

		char namaArr[MAX_STRING_LENGTH];
		sprintf(namaArr, "%s\n",P[posisi].nama);
		strcat(treeString, namaArr);

		printTree(P, P[posisi].right, level + 1, treeString);
	}
}

void PrintTree(Isi_Tree P, Isi_Team Q, Isi_Team R, int Jml_Node, char* treeString, char namaTimArr[]) {
	strcpy(treeString, "");
	printTree(P, 1, 0, treeString);
	printf("\nTree:\n");	
	printf("%s", treeString);
	saveData(P, Q, R, treeString, namaTimArr, 31, 2);
}

void cariDaun(Isi_Tree P, int posisi, int* indeksDaun, int* hitungDaun) {
	if (posisi == NIL) {
		return;
	}
	if (P[posisi].left == NIL && P[posisi].right == NIL) {
		indeksDaun[*hitungDaun] = posisi;
		(*hitungDaun)++;
	}
	cariDaun(P, P[posisi].left, indeksDaun, hitungDaun);
	cariDaun(P, P[posisi].right, indeksDaun, hitungDaun);
}

void assignDaunTree(Isi_Tree P, int* indeksDaun, int *hitungDaun, char timPemenang[][500]) {
	int i;
	printf("masuk");
	for(i = 0; i < *hitungDaun; i++) {
		
		strcpy(P[indeksDaun[i]].nama, timPemenang[i]);
		printf("\nHasil: %s", P[indeksDaun[i]].nama);
	}
}

void updateParent(Isi_Tree P, int index, int* indeksDaun, int* hitungDaun, char timPemenangTree[][500]){
	int i;
	int posisi = indeksDaun[0];
	if(posisi < 2){
		system("cls");
		mainmenu();
	}
	for(i = posisi; i <= posisi*2-2; i+=2){
		strcpy(P[(i-1)/2+1].nama, timPemenangTree[index]);
		index++;
	}
	
}

void inputSkorTree(Isi_Tree P, Isi_Team Q, Isi_Team R, int* indeksDaun, int* hitungDaun, char* treeString, char timPemenangTree[][500], char namaTimArr[]) {
    int i, j, k;
    int posisi;
    int scoreI, scoreJ;
    int index = 0;
    posisi = indeksDaun[0];
	while(P[1].nama != "?"){
		printf("jumlah n adalah : %d\n", posisi);
    for (i = posisi; i <= posisi*2-2; i+=2) {
        printf("\nMasukkan skor %s vs %s : ", P[i].nama, P[i+1].nama);
        scanf("%d-%d", &scoreI, &scoreJ);
        if(scoreI > scoreJ) { 
            P[i].skor = scoreI;
            P[i+1].skor = scoreJ;
			strcpy(timPemenangTree[index], P[i].nama);
			index++;
        }
        else if(scoreI < scoreJ) { 
            P[i].skor = scoreI;
            P[i+1].skor = scoreJ;
			strcpy(timPemenangTree[index], P[i+1].nama);
			index++;
        }
        else {
        	//penalti
            P[i].skor = scoreI;
            P[i+1].skor = scoreJ;
            aduPenalti(P, i, index, timPemenangTree);
            index++;
            
        }
    }
    printf("\nindeks : %d\n",index);
    index = index - index;
    updateParent(P, index, indeksDaun, hitungDaun,timPemenangTree);
	PrintTree(P, Q, R, 31, namaTimArr, treeString);
	system("pause");
    system("cls");
    posisi = posisi/2;
    indeksDaun[0] = posisi;
  }
}

void saveData(Isi_Tree P, Isi_Team Q, Isi_Team R, char* treeString, char namaTimArr[], int Jml_Node, int i) {
	int j = 1;
	int k;
	int Jml_Tim = 32;
    FILE *file1 = fopen(FILE_NAME1, "wb");
    FILE *file2 = fopen(FILE_NAME2, "wb");
    if (file1 != NULL && i == 1) {
//        fwrite(&P, sizeof(Node), 1, file);
//        fwrite(&Q, sizeof(team), 1, file);
//        fwrite(&R, sizeof(int), 1, file);
		for(k = 0; k < Jml_Tim/4; k++) {
			for(j = 1+k*4; j <= 4+k*4; j++){
				fwrite(Q[j].name, sizeof(char), strlen(Q[j].name)+1, file1);
				fwrite("\n", sizeof(char), 1, file1);
			}
			fwrite("\n", sizeof(char), 1, file1);
		}
        fclose(file1);
        printf("Data saved successfully.\n");
    } else if (file2 != NULL && i == 2){
    	fwrite(treeString, sizeof(treeString), strlen(treeString)+1, file2);
        fclose(file2);
        printf("Data saved successfully.\n");
    }else{
    	printf("Error saving data.\n");
	}
}	

void loadData(Isi_Tree *P, Isi_Team *Q, Isi_Team *R) {
    FILE *file = fopen(FILE_NAME2, "rb");
    if (file != NULL) {
        fread(P, sizeof(Isi_Tree), 1, file);
        fread(Q, sizeof(Isi_Team), 1, file);
        fread(R, sizeof(Isi_Team), 1, file);
        fclose(file);
        printf("Data loaded successfully.\n");
    } else {
        printf("Error loading data.\n");
    }
}