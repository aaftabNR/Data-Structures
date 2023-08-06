//SEQUENTIAL

#include <stdio.h>
#include <stdlib.h>

const char *STUDENT_FORMAT_IN = " %[^,], %lli";
const char *FILE_READ_FORMAT = " Name -> %[^,], PRN -> %lli";
const char *FILE_WRITE_FORMAT = "Name -> %s, PRN -> %lli\n";

typedef struct Student_demo
{
char name[20];
long long int prn;
} Student;

void search()
{
	long long int prn;
	printf("\nEnter PRN -> ");
	scanf("%lli", &prn);
	FILE *fptr = fopen("C:/Users/HP/Desktop/Test.txt.txt", "r");
	
	if (fptr == NULL) 
	{
		printf("Error !!!");
		exit(1);
	}
	Student st;
	while (fscanf(fptr, FILE_READ_FORMAT, &st.name, &st.prn) != EOF) 
	{
		if (prn == st.prn)
		{
			printf("\nFound :) !!! \n\n");
			printf(FILE_WRITE_FORMAT, st.name, st.prn);
			fclose(fptr);
			return;
		}
		else
		{
			continue;
		}
	}
	fclose(fptr);
	printf("\nNot Found :( !!!\n");
	return;
}

int main(void) 
{
	FILE *fptr = fopen("C:/Users/HP/Desktop/Test.txt.txt", "w");
	if (fptr == NULL) 
	{
		printf("Error !!!");
		exit(1);
	}
	int record;
	printf("\nEnter the Number of Records -> ");
	scanf("%d",&record);
	
	for (int i = 0; i < record; i++) 
	{
		Student st;
		printf("Enter record: ");
		scanf(STUDENT_FORMAT_IN, &st.name, &st.prn);
		fprintf(fptr, FILE_WRITE_FORMAT, st.name, st.prn);
	}
	fclose(fptr);
	printf("\nSearch :->\n");
	search();
	
	int choice;
	printf("\nPress -1 to Exit, else to Continue .... ");
	scanf("%d",&choice);
	while(choice != -1)
	{
		search();
		printf("\nPress -1 to Exit, else to Continue .... ");
		scanf("%d",&choice);
	}
		return 0;
}
