#include <stdio.h>
#include <string.h>

typedef struct Patient{
	char pet_name[20];
	char pet_type[20];
	int age;
	int payment;
	char op_performed[20];
} Pat;

//gets patient information into an array of structures from a text file and returns it and its size to the calling function. (F1)
void loaddata(Pat arr[30], int *size);  

/*receives an array of Patient structure, its size, and a pet type, 
and returns another array of structures holding only the patients information with the matching type and its size. (F2)*/
void findPatients(Pat arr[30], int size, char ptype[20], Pat arr2[30], int *size2);  

//receives an array of Patient structure and its size, it finds and returns the patients who have operation “transfused”. (F3)
void transfused(Pat arr[30], int size, char transfusedpets[10][20]);

//input a newly arrived patient’s info into a structure and returns it to the calling function. (F5)
Pat newinput(void);

/*receives an array of Patient structure and its size, updates the array
by adding the new patient data to the end of the array (assume there is enough space in the array)
and returns it to the calling function (F6)*/
void updatearr(Pat arr[30], int *size, Pat newpat);

// receives an array of Patient structure and its size, displays patient info that has the maximum payment (F7).
void max(Pat arr[30], int size);

//displays the menu continuously until user chooses to quit, gets user input and returns it to the calling function. (F8)
int menu(void);

int main(void)
{
	int i, choice, size, typesize, flag = 1;
	Pat data[30], typearr[30], newpatient;
	char ptype[20], transfusedpets[10][20];
	
	do{
		choice = menu();
		
		switch(choice)
		{
				case 1:
				loaddata(data, &size);
				flag = 0;
				break;
			
			case 2:
				if(flag)
					printf("You need to load the data first!!!");
				
				else
				{
					printf("\nPlease enter a pet type: ");
					scanf("%s", &ptype);
					findPatients(data, size, ptype, typearr, &typesize);
					if(typesize == 0)
					{
						puts("There aren't any patients with that type");
						break;
					}
					printf("\nPet_name Pet_type Age Payment Operation_performed");
					for(i=0; i<typesize; i++)
					{
						printf("\n%8s%8s%4d%8d%15s", typearr[i].pet_name, typearr[i].pet_type, typearr[i].age, typearr[i].payment, typearr[i].op_performed);
					}
				}
				
				break;
			
			case 3:
				if(flag)
					printf("You need to load the data first!!!");
				
				else
				{
					transfused(data, size, transfusedpets);
					printf("Pet_name");
					for(i=0; i<10; i++)
					{
						if(transfusedpets[i][0] < 'A' || transfusedpets[i][0] > 'z')
							break;
							
						printf("\n%s", transfusedpets[i]);
					}
				}
			
				break;
			
			case 4:
				 if(flag)
					printf("You need to load the data first!!!");
				
				else
					updatearr(data, &size, newinput());
			
				break;
				
			case 5:
				 if(flag)
					printf("You need to load the data first!!!");
				
				else
					max(data, size);
					
				break;
				
			case 6:
				break;
				
			default:
				puts("You have entered a wrong choice!");
				break;
		}
		
	}while(choice != 6);
	                                            
	return 0;
}

int menu(void)
{
	int choice;
	printf("\n--------------------------------------");
	printf("\n     Welcome to Pet Hospital");
	printf("\n--------------------------------------");
	printf("\n    1. Load patient info from a file");
	printf("\n    2. Find patients");
	printf("\n    3. View patients \"transfused\"");
	printf("\n    4. Add new patient info");
	printf("\n    5. Find largest payment");
	printf("\n    6. Quit");
	printf("\n\nChoose 1, 2, 3, 4, 5 or 6: ");
	scanf("%d", &choice);
	
	return(choice);
}

void loaddata(Pat arr[30], int *size)
{
	FILE *fp = fopen("data.txt", "r");
	int sizectr = 0, i = 0;
	
	while(fscanf(fp, "%s%s%d%d%s\n", &arr[i].pet_name, &arr[i].pet_type, &arr[i].age, &arr[i].payment, &arr[i].op_performed) != EOF)
	{
		i++;
		sizectr++;
	}
	
/*	for(i=0; i<sizectr; i++)
	{
		printf("%s %s %d %d %s\n", arr[i].pet_name, arr[i].pet_type, arr[i].age, arr[i].payment, arr[i].op_performed);
	}
*/
	
	*size = sizectr;
	printf("\nLoaded data successfully");
	fclose(fp);
}

void findPatients(Pat arr[30], int size, char ptype[20], Pat arr2[30], int *size2)
{
	int i, j = 0;
	
	for(i=0; i<size; i++)
	{
		if(strcmp(arr[i].pet_type, ptype) == 0)
		{
			strcpy(arr2[j].pet_name, arr[i].pet_name);
			strcpy(arr2[j].pet_type, ptype);
			arr2[j].age = arr[i].age;
			arr2[j].payment = arr[i].payment;
			strcpy(arr2[j].op_performed, arr[i].op_performed);
			j++;
		}
	}
	
	*size2 = j;
	puts("\nPatient list has been created successfully");
}

void transfused(Pat arr[30], int size, char transfusedpets[10][20])
{
	int i, j=0;
	
	for(i=0; i<size; i++)
	{
		if(strcmp(arr[i].op_performed, "transfused") == 0)
		{
			strcpy(transfusedpets[j], arr[i].pet_name);
			j++;
		}
	}
	
	puts("\nPatient list has been created successfully");
}

Pat newinput(void)
{
	Pat a;
	puts("Please input the name, type, age of the patient:");
	scanf("%s%s%d", &a.pet_name, &a.pet_type, &a.age);
	puts("Please input the payment and the performed operation");
	scanf("%d%s", &a.payment, &a.op_performed);
	
	return(a);
}

void updatearr(Pat arr[30], int *size, Pat newpat)
{
	strcpy(arr[*size].pet_name, newpat.pet_name);
	strcpy(arr[*size].pet_type, newpat.pet_type);
	strcpy(arr[*size].op_performed, newpat.op_performed);
	arr[*size].age = newpat.age;
	arr[*size].payment = newpat.payment;
	*size = *size + 1;
	puts("\nNew patient info added successfully");
}

void max(Pat arr[30], int size)
{
	int i, maxloc=0;
	
	for(i=1; i<size; i++)
	{
		if(arr[i].payment > arr[maxloc].payment)
			maxloc = i;
	}
	
	printf("\nPet_name Pet_type Age Payment Operation_performed");
	printf("\n%8s%8s%4d%8d%15s", arr[maxloc].pet_name, arr[maxloc].pet_type, arr[maxloc].age, arr[maxloc].payment, arr[maxloc].op_performed);
}