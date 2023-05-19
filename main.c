#include "head.h"
#include "rico.h"
#include "Naufal.h"
#include "najwan.h"

void mainmenu(){
	int tahun;
	printf("Input tournament tahun : ");
	scanf("%d", &tahun);
	system("cls");
	tampilan();
	Isi_Tree P;
	Isi_Team Q, R;
	int pil, daun, i;
	int jmlNode = 31;
	int  jmlTim = 32;
	infotype nilai;
	int indeksDaun[1000];
	int hitungDaun = 0;
	int index = 0;
	char ulang = 'y';
	char treeString[MAX_STRING_LENGTH] = "";
	char namaTimArr[MAX_STRING_LENGTH];
	char timPemenang[200][500];
	char timPemenangTree[200][500];
	while (ulang == 'y'|| ulang == 'Y') {	
		printf("\t\t\t\t\t\t\t          1. Buat Tim\n");
		printf("\t\t\t\t\t\t\t         2. Create Tree\n");
		printf("\t\t\t\t\t\t\t         3. Print Tree\n");
		printf("\t\t\t\t\t\t\t           4. Assign\n");
		printf("\t\t\t\t\t\t\t         5. Update Tree\n");
		printf("\t\t\t\t\t\t\t         6. Indeks daun\n\n");
		printf("\t\t\t\t\t\t\t      Masukkan pilihan anda : ");
		scanf("%d", &pil);
		switch(pil) {
			case 1:
//				printf("Masukkan jumlah tim : ");
//				scanf("%d", &jmlTim);
				buatArrayKualifikasi(P,Q,R, namaTimArr, treeString, jmlTim, tahun);
				tandingGrup(Q,jmlTim);
				system("pause");
				system("cls");
				inputSkor(Q,jmlTim,1,2);
				for(int i = 1; i <= jmlTim; i++){
					R[i] = Q[i];	
				}
				
				swapScore(R,jmlTim);
				sortByScore(R,jmlTim);
				swapHasil(Q,jmlTim);
				sortHasil(Q,jmlTim);
				cekPemenang(Q, jmlTim, R, timPemenang);
				break;
				
				
			case 2:
//				printf("Masukkan jumlah node : ");
//				scanf("%d", &jmlNode);
				Create_tree(P,jmlNode,nilai, "?");
				break;

			case 3:
				PrintTree(P, Q, R, jmlNode, treeString, namaTimArr, timPemenang, tahun);
//				writeTimPemenangToFile(P,"timPemenangKualifikasi.txt", treeString, timPemenang, jmlTim, tahun);
//				saveData(P, Q, R, treeString, jmlNode);
				break;

			case 4:
				hitungDaun = 0;
				cariDaun(P,1,indeksDaun, &hitungDaun);
				printf("Jumlah daun : %d\n", hitungDaun);
				printf("Indeks daunnya adalah: ");
				for (int i = 0; i < hitungDaun; i++) {
					printf("%d ", indeksDaun[i]);
				}
				assignDaunTree(P, indeksDaun, &hitungDaun,timPemenang);
				break;
			
			case 5:
				hitungDaun = 0;
				cariDaun(P,1,indeksDaun, &hitungDaun);
				inputSkorTree(P, Q, R, indeksDaun, &hitungDaun, treeString, timPemenang, timPemenangTree, namaTimArr, tahun);
				
//				tampilPemenangTree(P, indeksDaun, &hitungDaun,timPemenangTree);
//				updateParent(P, indeksDaun, &hitungDaun,timPemenangTree);
//				printf("Root tree: %s", P[0].nama);
				break;
				
			case 6:
				memset(indeksDaun, -1, sizeof(indeksDaun));
				cariDaun(P,1,indeksDaun, &hitungDaun);
				printf("Jumlah daun : %d\n", hitungDaun);
				printf("Indeks daunnya adalah: ");
				for (int i = 0; i < hitungDaun; i++) {
					printf("%d ", indeksDaun[i]);
				}
					
			default:
				printf("Invalid input");
				break;
		}
		printf("\nKembali ke menu? Y/N");
		ulang = getche();
		system("cls");
		tampilan();
	}
}

int main(){
	int tahun;
	Isi_Tree P;
	Isi_Team Q, R;
	int pil, daun, i;
	int jmlNode = 31;
	int  jmlTim = 32;
	infotype nilai;
	int indeksDaun[1000];
	int hitungDaun = 0;
	int index = 0;
	char ulang = 'y';
	char treeString[MAX_STRING_LENGTH];
	char timPemenang[200][500];
	char timPemenangTree[200][500];
	mainmenu();
	return 0;
}

