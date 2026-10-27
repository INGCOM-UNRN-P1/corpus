

#include<stdio.h>
void ateriscosTriangulo(int n);
int main(){
	int n;
	
	do{
		printf("Ingrese un numero natural# ");
		scanf("%d", &n);
	}while(n<=0);
	
	ateriscosTriangulo(n);
	return 0;
}
void ateriscosTriangulo(int n){
	int i, j;
	
	for(i= 0; i < n; i++){
		for(j= 0; j < i+1; j++){
			printf("*");
		}
		printf("\n");
	}		
}
