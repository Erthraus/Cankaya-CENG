/* DO NOT USE 0 for Datas Such as Store ID etc.*/

#include <stdio.h>

#define STRN 4  // STRN --> Number of Stores

FILE *fp;
int rowctr;					//Counter to find how many rows in the text file
int pdata[STRN*8][4];		//2D Array which contains phone data
int dif[10];				//Array for function diffphones
int comm[10];				//Array for function commonphones

void menu(void);
void funcswitch(int choice);
void readdata(int pdata[100][4]);
void sortquantity(int pdata[100][4], int rows);
void updatedata(void);
void updatepquantity(int pdata[100][4], int rows, int newq, int id, int ptype);
void bubblesort(int pdata[100][4], int rows);
void cheapest(int pdata[100][4], int rows);
void diffphones(int pdata[100][4], int rows, int dif[10]);
void commonphones(int pdata[100][4], int rows, int comm[10]);
void totalnum(int pdata[100][4], int rows);
void updatetextdata(int pdata[100][4], int rows);

int main(void)
{
	printf("Welcome to ABC Mobile Phone\n");
	menu();
	
	return 0;
}

void menu(void)  //Menu Function
{
	int choice;
	
	while(1)
	{
		printf("\n\n-----MENU------\nChoose one:");
		printf("\n1. Load phone data from text file");
		printf("\n2. Order data based on phone quantity");
		printf("\n3. Update phone quantity for a store");
		printf("\n4. View ordered phone quantity of a store");
		printf("\n5. Find cheapest price of a phone type");
		printf("\n6. Compare two stores to find different phone types");
		printf("\n7. Compare two stores to find common phone types");
		printf("\n8. View total quantity of each phone type");
		printf("\n9. Update text file");
		printf("\n10. Quit");
		
		while(1)
		{
			printf("\nMake your choice: ");
			scanf(" %d", &choice);
			
			if(choice >= 1 && choice <=10)
				break;
			else
				printf("You have entered a wrong choice! Try again.");
		}

		if(choice == 10)
			break;
		else
			funcswitch(choice);
	}
}

void funcswitch(int choice)  //Switch Function
{
	switch(choice)
	{
		case 1:
			readdata(pdata);
			break;
		
		case 2:
			sortquantity(pdata, rowctr);
			break;
			
		case 3:
			updatedata();
			break;
			
		case 4:
			bubblesort(pdata, rowctr);
			break;
			
		case 5:
			cheapest(pdata, rowctr);
			break;
			
		case 6:
			diffphones(pdata, rowctr, dif);
			break;
			
		case 7:
			commonphones(pdata, rowctr, comm);
			break;
			
		case 8:
			totalnum(pdata, rowctr);
			break;
			
		case 9:
			updatetextdata(pdata, rowctr);
			break;
		
		default:
			printf("You have entered a wrong choice! Try again.");
			break;
	}
}

void readdata(int pdata[100][4])  //Reads data from text file into a 2d array
{
	int i=0;
	fp = fopen("phonedata.txt", "r");
	
	while(fscanf(fp, "%d %d %d %d\n", &pdata[i][0], &pdata[i][1], &pdata[i][2], &pdata[i][3]) != EOF)
	{
		//printf("\n%d %d %d %d", pdata[i][0], pdata[i][1], pdata[i][2], pdata[i][3]);
		rowctr++;
		i++;
	}
	
	printf("Data is read from text file!\n");
	
	fclose(fp);
}

void sortquantity(int pdata[100][4], int rows)  //Selection Sort Algorithm for quantity
{
	int i, j, k, temp;
	if(**pdata == 0)
		printf("First you need to load phone data from text file!");
	
	else
	{
		for(i=0; i<rows; i++)
		{
			
			for(j=i+1; j<rows; j++)
			{
				if(pdata[j][2] > pdata[i][2])
				{
					for(k=0; k<4; k++)
					{
						temp = pdata[i][k];
						pdata[i][k] = pdata[j][k];
						pdata[j][k] = temp;
					}
				}
			}
		}
		
		printf("Sorted array based on phone quantity\nStore_id Phone_type Quantity Price\n");
		
		for(i=0; i<rows; i++)
		{
			for(j=0; j<4; j++)
			{
				printf("%8d", pdata[i][j]);
			}
			
			printf("\n");
		}
	}
}

void updatedata(void)  //Inputs new data and changes old data
{
	int id, ptype, newq;
	
	if(**pdata == 0)
		printf("First you need to load phone data from text file!");
	
	else
	{
		printf("Input store id, phone type and new quantity: ");
		scanf(" %d %d %d", &id, &ptype, &newq);
		updatepquantity(pdata, STRN*8, newq, id, ptype);
	}
}

void updatepquantity(int pdata[100][4], int rows, int newq, int id, int ptype)  //Updates data
{
	int i, flag = 1;
	
	for(i=0; i<rows; i++)
	{
		if(pdata[i][0] == id && pdata[i][1] == ptype)
		{
			pdata[i][2] = newq;
			printf("Quantity data has changed successfully");
			flag = 0;
			break;
		}
	}
	
	if(flag)
		printf("You have entered a wrong data! Failed to update.");
}

void bubblesort(int pdata[100][4], int rows) 		//Inputs store id and outputs sorted quantities of the phones available in that store
{
	int id, i, j, k=0, x, arr[10][4], temp;
	
	if(**pdata == 0)
		printf("First you need to load phone data from text file!");
	
	else
	{
		printf("Input store id: ");
		scanf(" %d", &id);
		
		for(i=0; i<rows; i++)
		{
			if(pdata[i][0] == id)
			{
				for(j=0; j<4; j++)
				{
					arr[k][j] = pdata[i][j];
				}
				
				k++;
			}
		}
		
		for(i=0; i<k-1; i++)
		{
			for(j=0; j<k-i-1; j++)
			{
				if(arr[j][2] < arr[j+1][2])
				{
					for(x=0; x<4; x++)
					{
						temp = arr[j][x];
						arr[j][x] = arr[j+1][x];
						arr[j+1][x] = temp;
					}
				}
			}
		}
		
		printf("Phone_type  Quantity  Price");
		
		for(i=0; i<k; i++)
		{
			printf("\n%5d  %10d  %8d$", arr[i][1], arr[i][2], arr[i][3]);
		}
	}
}

void cheapest(int pdata[100][4], int rows)	// Inputs phone type, finds and outputs the store id which has the cheapest
{
	int ptype, id, i, price;
	
	if(**pdata == 0)
		printf("First you need to load phone data from text file!");
	
	else
	{
		printf("Enter phone type: ");
		scanf(" %d", &ptype);
		
		for(i=0; i<rows; i++)
		{
			if(pdata[i][1] == ptype)
			{
				id = pdata[i][0];
				price = pdata[i][3];				
			}
		}
		
		for(; i<rows; i++)
		{
			if(pdata[i][1] == ptype && pdata[i][3] < price)
			{
				id = pdata[i][0];
				price = pdata[i][3];
			}
		}
		
		printf("Cheapest Phone %d is at Store %d (price: %d)", ptype, id, price);
	}
}

void diffphones(int pdata[100][4], int rows, int dif[10])		//Finds the phones available in the first store and not available in the second
{
	int id1, id2, i, j=0, k, types[10];
	if(**pdata == 0)
		printf("First you need to load phone data from text file!");
	
	else
	{
		for(i=0; i<10; i++)
		{
			dif[i] = 0;
		}
		
		printf("Enter store ID's': ");
		scanf(" %d %d", &id1, &id2);
		
		for(i=0; i<rows; i++)
		{
			if(id1 == pdata[i][0])
			{
				types[j] = pdata[i][1];
				j++;				
			}
		}
		
		for(i=0; i<rows; i++)
		{
			if(id2 == pdata[i][0])
			{
				for(k=0; k < j; k++)
				{
					if(pdata[i][1] == types[k])
						types[k] = 0;
				}				
			}
		}
		
		k = 0;
		
		for(i=0; i < j; i++)
		{
			if(types[i] != 0)
			{
				dif[k] = types[i];
				k++;				
			}
		}
		
		printf("Phone types which are available in store %d and not available in store %d: ", id1, id2);
		
		if(*dif == 0)
			printf("NONE");
			
		else
		{
			for(i=0; i<k; i++)
			{	
				printf("%d ", dif[i]);
			}
		}
		
	}
}

void commonphones(int pdata[100][4], int rows, int comm[10])		//Finds the phones which are both available in the inputted stores
{
	int id1, id2, i, j=0, k;
	if(**pdata == 0)
		printf("First you need to load phone data from text file!");
	
	else
	{
		for(i=0; i<10; i++)
		{
			comm[i] = 0;
		}
		
		printf("Enter store ID's': ");
		scanf(" %d %d", &id1, &id2);
		
		for(i=0; i<rows; i++)
		{
			if(id1 == pdata[i][0])
			{	
				for(k=0; k<rows; k++)
				{
					if(id2 == pdata[k][0] && pdata[i][1] == pdata[k][1])
					{
						comm[j] = pdata[i][1];
						j++;
					}	
				}			
			}
		}
		
		printf("Common phone types in stores %d and %d: ", id1, id2);
		
		if(*comm == 0)
			printf("NONE");
			
		else
		{
			for(i=0; i<j; i++)
			{	
				printf("%d ", comm[i]);
			}
		}
	}
}

void totalnum(int pdata[100][4], int rows)		//Finds and outputs outputs the total number of each phone type available in all the stores
{
	int i, j, ctr=0;
	
		if(**pdata == 0)
		printf("First you need to load phone data from text file!");
	
	else
	{
		printf("Phone_type  Total_number");
		
		for(i=1; i<=8; i++)
		{
			for(j=0; j<rows; j++)
			{
				if(pdata[j][1] == i)
					ctr += pdata[j][2];
			}
			
			printf("\n%5d  %12d", i, ctr);
			ctr = 0;
		}
	}
}

void updatetextdata(int pdata[100][4], int rows)		//Updates the text file with the new datas in the 2D array
{
	int i, j;
	
	if(**pdata == 0)
		printf("First you need to load phone data from text file!");
	
	else
	{
		
		fp = fopen("phonedata.txt", "w");
	
		for(i=0; i<rows; i++)
		{
			for(j=0; j<4; j++)
			{
				fprintf(fp, "%d ", pdata[i][j]);
			}
		
			fprintf(fp, "\n");
		}
	
		printf("Text file updated successfully");
	
		fclose(fp);
		
	}
}