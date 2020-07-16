#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system("chcp 1251");
	FILE *fileRead;
	int j,i,m, n,max,sum;
	max = 0;
	scanf("%d %d",&m,&n);
	int **arr = (int **)malloc(m*sizeof(int *));
	for (i = 0;i<m;i++){
		arr[i] = (int *)malloc(n*sizeof(int));
	}
	fileRead = fopen("text.txt","r");
	if ( fileRead== 0) {
    printf("cant open file\n");
    _getch();
    return 1;
  }
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			arr[i][j] = rand()%20;
			fscanf(fileRead,"%d",&arr[i][j]);
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	fclose(fileRead);

	for (i = 0; i < m; i++) {
		sum = 0;
		for (j = 0; j < n; j++) {
			sum += abs(arr[i][j]);
		}
		printf("%d\n",sum);
		if (sum>max) {
			max = sum;
		}
	}
	
	printf("Норма матрицы: %d\n",max);
	_getch();
	return 0;
}
