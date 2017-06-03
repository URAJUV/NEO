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
		a[i] = rand() % 100000;
	}
	return ;
}

void merge(int *a,int l,int m,int r){
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++){
		L[i] = a[l+i];
	}
	for(j=0;j<n2;j++){
		R[j] = a[m+1+j];
	}
	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
		    a[k] = L[i];
		    i++;
		}
		else
		{
		    a[k] = R[j];
		    j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}

}

void merge_sort(int *a,int l,int r){
	
	if(l<r){
		int m = (r+l)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,r);
		merge(a,l,m,r);
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
	merge_sort(a,0,count-1);
	start = clock() - start;
	time_taken = ((double)start)/CLOCKS_PER_SEC;
	print_n(a,count);
	printf("\n");
	printf("Time take is %f\n",time_taken);
}
