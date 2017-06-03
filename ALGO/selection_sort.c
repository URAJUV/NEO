#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
void print_n(int *a,int count){
	int  i=0;
	for(i = 0; i<count; i++){
		printf("%d\t",a[i]);
	}
	return ;
}

void scan_n(int *a,int count){
	int i=0;
	time_t t;
	srand((unsigned)time(&t));
	printf("Enter the numbers to sort\n");
	for(i = 0; i<count; i++){
		a[i] = rand() % 200;
	}
	return ;
}

void selection_sort(int *a,int count){
	int i = 0,j = 0;
	int temp = 0;
	printf("\nSorting the array  in accending......\n");
	for (i=0; i<count; i++){
		for (j=i+1; j<count-i; j++){
			if(a[i]>a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("sorting done \n");
}				

int main(int argc ,char * argv[]){
	int * a = NULL;
	int count = 0;
	int x;
	time_t start;
	double time_taken ;
	printf("How many numbers you want to sort \n");
	scanf("%d",&count);
	a = (int*) malloc(count* sizeof(int));
	scan_n(a,count);
	print_n(a,count);
	start = clock();
	selection_sort(a,count);
	start = clock() - start;
	time_taken = ((double)start)/CLOCKS_PER_SEC;
	print_n(a,count);
	printf("\n");
	printf("Time take is %f\n",time_taken);
}
