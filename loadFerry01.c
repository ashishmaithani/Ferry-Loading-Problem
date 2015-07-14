#include<stdio.h>
int store[110][110] = {{0}};
int ferrySize,num;

void loadFerry(int *,int,int);

int main(){
	int i;
	scanf("%d",&ferrySize);
	scanf("%d",&num);
	int cars[num+1];
	cars[0] = 0;
	for(i=1;i<num+1;i++){
		scanf("%d",&cars[i]);
	}

	printf("Size of ferry: %d\n",ferrySize);
	printf("No of Cars: %d\n",num);
	for(i=1;i<num+1;i++){
		printf("%d ",cars[i]);
	}
	printf("\n");

	loadFerry(cars,ferrySize,num);
	return 0;
}

void loadFerry(int *cars,int size,int numCars){
	int i,j,sum=0,find=0;
	char LeftRight[numCars+1];

//	Set the valid bit in the Store 2D-Array.
//	This is required during backtracking.
	for(i=1;i<numCars+1;i++){
		sum = sum + cars[i];
		for(j=0;j<size+1;j++){
			if(j==0 || j == cars[i] || store[i-1][j] == 1){
				if(sum - j <= size){
					store[i][j] = 1;
				}
			}else if(j-cars[i] >=0 && store[i-1][j-cars[i]] == 1){
				store[i][j] = 1;
			}
		}
	}

//	Print the contents of the Store 2D-Array
//	Uncomment below if you want to check the valid bits of Store 2D-Array
/*
	printf("==================================\n");
	for(i=1;i<numCars+1;i++){
		for(j=0;j<size+1;j++){
			printf("%d ",store[i][j]);
		}
		printf("\n");
	}
	printf("==================================\n");
*/

//	Backtrack the Store 2D-Array and store left/rignt in LeftRight array
	for(i=numCars,j=size;i>0 && j>=0;){
		LeftRight[i] = 'X';
		if(store[i][j] == 0){
			if(i==1 && find==0){
				i = numCars;
				j--;
			}else{
				i--;
			}
			continue;
		}

		if(store[i][j] == 1){
			find = 1;
			if(store[i-1][j] == 1){
				LeftRight[i] = 'R';
				i--;
			}else if(store[i-1][j] == 0){
				LeftRight[i] = 'L';
				j = j - cars[i];
				i--;
			}
		}

	}

//	Output the nuber of cars that can be accomodated in the given ferry
	for(i=numCars;i>0;i--){
		for(j=size;j>0;j--){
			if(store[i][j] == 1){
				printf("No. of cars accomodated: %d\n",i);
				j=0;
				i=0;
			}
		}
	}

//	Print the contents of LeftRight array
	for(i=1;i<=numCars;i++){
		printf("%c\n",LeftRight[i]);
	}
}