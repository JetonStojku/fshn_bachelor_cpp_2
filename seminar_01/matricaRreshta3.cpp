#include <stdio.h>
#define maxKolone 50
void lexoMatrice(int [][maxKolone],int , int );
void afishoMatrice(int [][maxKolone],int , int );

int main(){
	//tip emer[dim1][dim2]
	int m=4,n=5;
	//printf("Jep permasat e matrices: ");
	//scanf("%d%d",&m,&n);
	int M[][maxKolone]={{2,3,1,4,5},{6,7,1,2,4},{7,5,8,9,10},{8,3,2,8,3}};
	int kodet[]={1000,2400,800,500};
	char gjinia[]={'m','f','f','m'};
	int kreditet[]={5,4,7,3,9};
	char kategori[]={'A','A','B','A','B'};
	//lexoMatrice(M,m,n);
	//afishoMatrice(M,m,n);
	float mesatare[m];
	int poz[m];
	int d=0;
	/*
	int shumaKredite=0;
	for(int j=0;j<n;j++){
		if(kategori[j]=='A'){
			shumaKredite=shumaKredite+kreditet[j];
		}
	}
	*/
	for(int i=0;i<m;i++){
		if(gjinia[i]=='f'){
			int sh=0;
			int shumaKredite=0;
			for(int j=0;j<n;j++){
				if(kategori[j]=='A'&&M[i][j]>4){
					sh=sh+M[i][j]*kreditet[j];
					shumaKredite=shumaKredite+kreditet[j];
				}
			}
			float mes=-1;
			if(shumaKredite>0){
				mes=(float)sh/shumaKredite;
			}
			mesatare[d]=mes;
			poz[d]=i;
			d++;
		}
	}

	for(int i=0;i<d;i++){
		for(int j=i+1;j<d;j++){
			if(mesatare[i]<mesatare[j]){
				float tmp=mesatare[i];
				mesatare[i]=mesatare[j];
				mesatare[j]=tmp;
				int tmp2=poz[i];
				poz[i]=poz[j];
				poz[j]=tmp2;
			}
		}
	}
	for(int i=0;i<d;i++){
		printf("Studenti %d me mesatare %.2f\n",kodet[poz[i]],mesatare[i]);
	}
	
		return 0;
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





