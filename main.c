
#include "rico.h"

int main() {
	Isi_Tree P;
	Isi_Team Q;
	int pil, jmlNode, jmlTim, daun, i;
	infotype nilai;
	int indeksDaun[1000];
	int hitungDaun = 0;
	int index = 0;
	char ulang = 'y';
	char treeString[MAX_STRING_LENGTH];
	char timPemenang[200][500];
	char timPemenangTree[200][500];
	while (ulang == 'y'|| ulang == 'Y') {
		printf("1. Buat Tim\n");
		printf("2. Create Tree\n");
		printf("3. Print Tree\n");
		printf("4. Assign\n");
		printf("5. Update Tree\n");
		printf("6. Indeks daun\n");
		printf("Masukkan pilihan anda : ");
		scanf("%d", &pil);
		switch(pil) {
			case 1:
				printf("Masukkan jumlah tim : ");
				scanf("%d", &jmlTim);
				buatArrayKualifikasi(Q, jmlTim);
				tandingGrup(Q,jmlTim);
				system("pause");
				system("cls");
				inputSkor(Q,jmlTim);
				swapHasil(Q,jmlTim);
				sortHasil(Q,jmlTim);
//				ulangPertandingan(Q, jmlTim);
				getPemenang(Q,jmlTim, timPemenang);
				break;
				
			case 2:
				printf("Masukkan jumlah node : ");
				scanf("%d", &jmlNode);
				Create_tree(P,jmlNode,nilai, "?");
				break;

			case 3:
				PrintTree(P, treeString);
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
				inputSkorTree4(P, indeksDaun, &hitungDaun, treeString,timPemenangTree);
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

	}
	return 0;
}
