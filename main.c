#include "head.h"
#include "rico.h"
#include "Naufal.h"
#include "najwan.h"

int main() {
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
	tampilan();
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
				buatArrayKualifikasi(Q, jmlTim);
				tandingGrup(Q,jmlTim);
				system("pause");
				system("cls");
				inputSkor(Q,jmlTim);
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
				inputSkorTree(P, indeksDaun, &hitungDaun, treeString,timPemenangTree);
				
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
