#include <stdio.h>
#define maxKolone 50
void lexoMatrice(int [][maxKolone],int , int );
void afishoMatrice(int [][maxKolone],int , int );
void shumaRreshta(int [][maxKolone],int , int );
void maksimumRreshta(int [][maxKolone],int , int );
int rreshtiShumeMaksimale(int [][maxKolone],int , int );
int main(){
	//tip emer[dim1][dim2]
	int m=4,n=5;
	//printf("Jep permasat e matrices: ");
	//scanf("%d%d",&m,&n);
	int M[][maxKolone]={{2,3,1,4,5},{6,7,1,2,4},{7,5,8,9,0},{-1,3,0,0,3}};
	//lexoMatrice(M,m,n);
	afishoMatrice(M,m,n);
	shumaRreshta(M,m,n);
	maksimumRreshta(M,m,n);
	printf("Rreshti me shumen maksimale eshte rreshti %d\n",rreshtiShumeMaksimale(M,m,n)+1);
	return 0;
} 
int rreshtiShumeMaksimale(int A[][maxKolone],int dim1, int dim2){
	int shumat[dim1];
	for(int i=0;i<dim1;i++){
		int s=0;
		for(int j=0;j<dim2;j++){
			s=s+A[i][j];
		}
		shumat[i]=s;
	}
	int max=shumat[0];
	int poz=0;
	for(int i=0;i<dim1;i++){
		if(shumat[i]>max){
			max=shumat[i];
			poz=i;
		}
	}
	return poz;
}
void maksimumRreshta(int A[][maxKolone],int dim1, int dim2){
	for(int i=0;i<dim1;i++){
		int max=A[i][0];
		int poz=0;
		for(int j=0;j<dim2;j++){
			if(A[i][j]>max){
				max=A[i][j];
				poz=j;
			}
		}
		printf("Maksimumi i rreshtit %d eshte %d dhe ndodhet ne kolonen %d\n",i+1,max,poz+1);
	}
}

void shumaRreshta(int A[][maxKolone],int dim1, int dim2){
	for(int i=0;i<dim1;i++){
		int s=0;
		for(int j=0;j<dim2;j++){
			s=s+A[i][j];
		}
		printf("Shuma e rreshtit %d eshte %d\n",i+1,s);
	}
}



void afishoMatrice(int A[][maxKolone],int dim1, int dim2){
	for(int i=0;i<dim1;i++){
		for(int j=0;j<dim2;j++){
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	}
}
void lexoMatrice(int A[][maxKolone],int dim1, int dim2){
	printf("Lexo elementet e matrices:\n");
	for(int i=0;i<dim1;i++){
		printf("Elementet e rreshtit %d\n",i+1);
		for(int j=0;j<dim2;j++){
			printf("\tKolona %d: ",j+1);
			scanf("%d",&A[i][j]);
		}
	}
}





