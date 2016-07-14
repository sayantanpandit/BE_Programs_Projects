#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void showAllRecords();
void insertRecords();
void searchByRoll();
void updateRecords();
void maximumMarks();
void minimumMarks();

int main()
{
   int choice;
   
   while(1)
   {
       printf("\n1. Show All Records");
       printf("\n2. Insert Record");
       printf("\n3. Search by Roll No.");
       printf("\n4. Update Record");
       printf("\n5. Maximum Marks");
       printf("\n6. Minimum Marks");
       printf("\n7. Exit");
       printf("\nEnter UR Choice :: ");
       scanf("%d", & choice);
       
       if(choice == 1)
          showAllRecords();
       else if(choice == 2)
          insertRecords(); 
       else if(choice == 3)
          searchByRoll();
       else if(choice == 4)
          updateRecords();
       else if(choice == 5)
          maximumMarks(); 
       else if(choice == 6)
          minimumMarks();
       else if(choice == 7)
          exit(1);
   }
   return 0;
}

void showAllRecords()
{
    FILE *fp = fopen("Database.txt", "r");
    char ch;
    printf("\n");
    while((ch = fgetc(fp)) != EOF)
          printf("%c", ch);
    fclose(fp);
}

void insertRecords()
{
    FILE *fp = fopen("Database.txt", "a");
    int roll, marks; char name[50];
    printf("Enter Roll No. :: ");
    scanf("%d", &roll);
    printf("Enter Name :: ");
    scanf("%s", name);
    printf("Enter Marks :: ");
    scanf("%d", &marks);
    fprintf(fp, "\n%d\t%s\t%d", roll, name, marks);
    fclose(fp);
}

void searchByRoll()
{  
   int searchRoll, roll=1, marks, flag = 0;
   char name[50], title[20];
   printf("Enter Roll Number to be searched :: ");
   scanf("%d", &searchRoll);
   
   FILE *fp = fopen("Database.txt", "r");   
   fscanf(fp, "%s %s %s", title, title, title);   	
	
   while(!feof(fp))
   {
      fscanf(fp, "%d %s %d", &roll, name, &marks);
      if(roll == searchRoll)
      {
          flag = 1;
       	  printf("Name  = %s\n", name);
       	  printf("Marks = %d\n", marks);
       	  break;
      }
   }
   
   if(flag == 0)
        printf("\n\tRoll No. %d does not exists in Database.\n", searchRoll);  
   fclose(fp);  
}

void updateRecords()
{
   int searchRoll, searchMarks,roll, marks, flag = 0;
   char name[50], title[20];
   printf("Enter Roll Number for modifying :: ");
   scanf("%d", &searchRoll);
   
   FILE *fp = fopen("Database.txt", "r");
   FILE *tf = fopen("TempFile.txt", "w");   
   fscanf(fp, "%s %s %s", title, title, title);
   fprintf(tf, "%s\t%s\t%s\n", "Roll", "Name", "Marks");
   int count=0;
   while(!feof(fp))
   {
      fscanf(fp, "%d %s %d", &roll, name, &marks);
      if(roll == searchRoll && flag == 0)
      {
          printf("Name  = %s\n", name);
       	  printf("Marks = %d\n", marks);
       	  printf("Enter Marks for modifying :: ");
          scanf("%d", &searchMarks);
          flag = 1;
          fprintf(tf, "\n%d\t%s\t%d", searchRoll, name, searchMarks);
      }
      else
          fprintf(tf, "\n%d\t%s\t%d", roll, name, marks);
   }
   if(flag == 0)
       printf("\n\tRoll No. %d does not exists in Database.\n", searchRoll);  
   fclose(fp); 
   fclose(tf);
   
   remove("Database.txt");
   rename("TempFile.txt", "Database.txt");
  /* fp = fopen("Database.txt", "w");
   tf = fopen("TempFile.txt", "r");
   char a[5], b[5], c[5];
   fscanf(tf, "%s %s %s",a,b,c);
   fprintf(fp, "%s\t%s\t%s\n", a, b, c);
   while(!feof(tf))
   {
      fscanf(tf, "%d %s %d", &roll, name, &marks);
      printf("%d\t%s\t%d\n", roll, name, marks);
      fprintf(fp,"%d\t%s\t%d\n", roll, name, marks);
   }
   fclose(fp); 
   fclose(tf);*/
   
   printf("RECORD UPDATED\n");
}

void maximumMarks()
{
   FILE *fp = fopen("Database.txt", "r");
   int roll, marks, maxRoll,maxMarks=0;
   char name[50], maxName[50], title[50];  
  
   fscanf(fp, "%s %s %s", title, title, title);
   while(!feof(fp))
   {
     fscanf(fp, "%d %s %d", &roll, name, &marks);
          
     if(marks > maxMarks)
     {
        maxRoll = roll;
        strcpy(maxName, name);
        maxMarks = marks;
     }
   }
   
   printf("Roll  :: %d\n", maxRoll);
   printf("Name  :: %s\n", maxName);
   printf("Marks :: %d\n", maxMarks);      
     
   fclose(fp);
}

void minimumMarks()
{
   FILE *fp = fopen("Database.txt", "r");
   int roll, marks, minRoll, minMarks=100;
   char name[50], minName[50], title[50];  
  
   fscanf(fp, "%s %s %s", title, title, title);
   while(!feof(fp))
   {
     fscanf(fp, "%d %s %d", &roll, name, &marks);
     
     if(marks < minMarks)
     {
        minRoll = roll;
        strcpy(minName, name);
        minMarks = marks;
     }
   }
   
   printf("Roll  :: %d\n", minRoll);
   printf("Name  :: %s\n", minName);
   printf("Marks :: %d\n", minMarks);
   fclose(fp); 
}
