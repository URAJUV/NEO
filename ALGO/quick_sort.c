#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
void print_n(int *a,int count){
	int  i=0;
	for(i = 0; i<count; i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
	return ;
}

void scan_n(int *a,int count){
	int i=0;
	time_t t;
	srand((unsigned)time(&t));
	printf("Enter the numbers to sort\n");
	for(i = 0; i<count; i++){
		a[i] = rand() % 100;
	}
	return ;
}


void swap(int *a,int*b){
	int temp;
	temp =*a;
	*a =*b;
	*b = temp;
}

int partition (int *a ,int l,int h){
	int pi = a[h];
	int i = l-1;
	int j;
	for(j=l;j<=h-1;j++){
		/* If the current element is less than pivot*/
		if(a[j]<=pi){
			i++;
			swap(&a[j],&a[i]);
		}
	}
	swap(&a[i+1],&a[h]);
	return (i+1);
}
void quick_sort(int *a,int l,int h){
	
	if(l<h){
		int pi = partition(a,l,h);
		quick_sort(a,l,pi-1);
		quick_sort(a,pi+1,h);
	}
}				
int main(int argc ,char * argv[]){
	int * a  = NULL;
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
	quick_sort(a,0,count-1);
	start = clock() - start;
	time_taken = ((double)start)/CLOCKS_PER_SEC;
	print_n(a,count);
	printf("\n");
	printf("Time take is %f\n",time_taken);
}
