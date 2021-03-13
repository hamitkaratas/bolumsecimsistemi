#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp;
	char bolumler[1000];
	char buffer[1000];
	char isim[50];

	int  i, index = 0;
	int x[4];   //xbil=0,xbme=0,xend=0,xmak=0,xeem=0;
	for (i = 0; i <= 4; i++)
		x[i] = 0;
	int n, j, m;




	fp = fopen("tanitim.txt", "a+");

	printf("isminizi giriniz  \n");
	scanf("%s", &bolumler);
	fputs(bolumler, fp);
	fprintf(fp, " ");
	printf("bilgi aldiginiz ders sayisini giriniz  \n");
	scanf("%d", &m);
	printf("bilgi aldiginiz dersleri giriniz  \n");

	for (i = 0; i <= m; i++)
	{


		gets(bolumler);
		fputs(bolumler, fp);
		fprintf(fp, " ");

	}
	fprintf(fp, "\n");
	fclose(fp);




	FILE* fpt;
	fpt = fopen("tanitim.txt", "r+");
	char* c1 = "bil";
	char* c2 = "bme";
	char* c3 = "eem";
	char* c4 = "mak";
	char* c5 = "end";

	while (!feof(fpt)) {

		fscanf(fpt, "%s", bolumler);

		if (strcmp(bolumler, c1) == 0) {
			x[0] = x[0] + 1;

		}
		else if (strcmp(bolumler, c2) == 0) {
			x[1] = x[1] + 1;
		}
		else if (strcmp(bolumler, c3) == 0) {
			x[2] = x[2] + 1;
		}
		else if (strcmp(bolumler, c4) == 0) {
			x[3] = x[3] + 1;
		}
		else if (strcmp(bolumler, c5) == 0) {
			x[4] = x[4] + 1;
		}
	}

	fclose(fp);

	int max = 0;
	for (i = 0; i <= 4; i++)
	{
		if (x[i] > max) {

			max = x[i];

			index = i;
		}
	}
	printf("%d \n", max);












	FILE* fptr;
	fptr = fopen("bilgi.txt", "w");
	if (index == 0) {

		fputs("enfazla bilgi alinan bolum: bil \n", fptr);
		fprintf(fptr, "%d %s", max, "kisiye tanýtýlmýþtýr");
	}
	else if (index == 1) {

		fputs("enfazla bilgi alinan bolum: bme \n", fptr);
		fprintf(fptr, "%d %s", max, "kisiye tanitilmistir");
	}
	else if (index == 2) {

		fputs("enfazla bilgi alinan bolum: eem \n", fptr);
		fprintf(fptr, "%d %s", max, "kisiye tanitilmistir");
	}
	if (index == 3) {

		fputs("enfazla bilgi alinan bolum: mak \n", fptr);
		fprintf(fptr, "%d %s", max, "kisiye tanitilmistir");
	}
	if (index == 4) {

		fputs("enfazla bilgi alinan bolum: end \n", fptr);
		fprintf(fptr, "%d %s", max, "kisiye tanitilmistir");
	}
	fclose(fptr);





	return 0;
}