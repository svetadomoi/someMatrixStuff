#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int matrixB(int **mainMatrix,int **matrix,int n,int lambda);
int matrixC(int **mainMatrix,int **secondaryMatrix,int **matrix,int n,int lambda,int mu);
void matrixOutput(int **matrix, int n);

int main(int argc, char *argv[]) {
	
	int j,i,n,lambda,mu,sum;
	printf("Enter amount of elenments:\n");
	scanf("%d",&n);
	int **A = (int **)malloc(n*sizeof(int *));
	int **B = (int **)malloc(n*sizeof(int *));
	int **C = (int **)malloc(n*sizeof(int *));
	for (i = 0;i<n;i++){
		A[i] = (int *)malloc(n*sizeof(int));
		B[i] = (int *)malloc(n*sizeof(int));
		C[i] = (int *)malloc(n*sizeof(int));
	}
	
	for(i = 0; i<n;i++){
		for (j = 0; j<n;j++){
			A[i][j] = rand()%10;
		}
	}
	printf("Matrix A\n");
	matrixOutput(A,n);
	printf("Enter lambda:\n");
	scanf("%d",&lambda);
	//sum = matrixB(A,B,n,lambda);
	//matrixOutput(B,n);
	printf("Matrix B\n");
	printf("Sum: %d\n",matrixB(A,B,n,lambda));
	printf("Enter mu:\n");
	scanf("%d",&mu);
	printf("Sum: %d\n",matrixC(A,B,C,n,lambda,mu));
	_getch();
	return 0;
}

void matrixOutput(int **matrix, int n){
	int i,j;
	for (i = 0;i<n;i++){
		for (j = 0;j<n;j++){
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	
	
}

int matrixB(int **mainMatrix,int **matrix, int n, int lambda){
	int i,j,sum;
	for(i = 0; i<n;i++){
		for (j = 0; j<n;j++){
			matrix[i][j] = mainMatrix[i][j]*lambda;
		}
	}
	matrixOutput(matrix,n);
	for (i = 0; i<n;i++){
		sum+=matrix[i][n-1-i];
	}
	
	
	return sum;
}

int matrixC(int **mainMatrix,int **secondaryMatrix,int **matrix,int n,int lambda,int mu){
	int i,j,sum;
	for(i = 0; i<n;i++){
		for (j = 0; j<n;j++){
			matrix[i][j] = secondaryMatrix[i][j]*lambda+mu*mainMatrix[i][j];
		}
	}
	matrixOutput(matrix,n);
	for (i = 0; i<n;i++){
		sum+=matrix[i][n-1-i];
	}
	
	return sum;
}




