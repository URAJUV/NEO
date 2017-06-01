#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void print_n(int *a,int count){
	int  i=0;
	for(i = 0; i<count; i++){
		printf("%d\t",a[i]);
	}
	return ;
}

void scan_n(int *a,int count){
	int i=0;
	printf("Enter the numbers to sort\n");
	for(i = 0; i<count; i++){
		scanf("%d",a+i);
	}
	return ;
}

void scan_f(int *a,int count){
	int i=0;

	printf("Enter the numbers to sort\n");
	for(i = 0; i<count; i++){
		scanf("%d",a+i);
	}
	return ;
}

void insert_sort(int *a,int count){
	int i = 0,j = 0;
	int temp = 0;
	printf("\nSorting the array  in accending......\n");
	for (i=2; i<count; i++){
		for (j=0; j<i; j++){
			if(a[j]>a[i]){
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	printf("sorting done \n");
}				

int main(int argc ,char * argv[]){
	int * a = NULL;
	int count = 0;
	int x;
	FILE *file;
	if(argc != 2){
		printf("Expect two inputs %s: filename",argv[0]);
		return 0;
	}
	else{
		file = fopen(argv[1],"r");
		fseek(file, 0, SEEK_END);
		long fsize = ftell(f);
		a = (int *) malloc(fsize + 1);
		fseek(file, 0, SEEK_SET);  //same as rewind(f);

		if(file ==0){
			printf("could not open file \n");
			return 0;
		}
		else{
			while ( (fscanf(file,"%d ",&x)) >0){
				printf("%d",x);
				count++;
			}
			fclose(file);
		}
	}


//	printf("How many numbers you want to sort \n");
//	scanf("%d",&count);
	scan_f(a,count);
//	scan_n(a,count);
	print_n(a,count);
	insert_sort(a,count);
	print_n(a,count);
	printf("\n");
*/
}
