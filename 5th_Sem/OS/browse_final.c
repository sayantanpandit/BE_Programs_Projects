#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <dirent.h>
#include<string.h>
#include<sys/stat.h>
#include <errno.h>
#define MAX_DIR_PATH 2048
void access1(char path[])
{
 int rval;

 /* Check file existence. */
 rval = access (path, F_OK);
 if (rval == 0) 
  printf ("%s exists\n", path);
 else {
  if (errno == ENOENT) 
   printf ("%s does not exist\n", path);
  else if (errno == EACCES) 
   printf ("%s is not accessible\n", path);
 }

 /* Check read access. */
 rval = access (path, R_OK);
 if (rval == 0)
  printf ("%s is readable\n", path);
 else
  printf ("%s is not readable (access denied)\n", path);

 /* Check write access. */
 rval = access (path, W_OK);
 if (rval == 0)
  printf ("%s is writable\n", path);
 else if (errno == EACCES)
  printf ("%s is not writable (access denied)\n", path);
 else if (errno == EROFS)
  printf ("%s is not writable (read-only filesystem)\n", path);
}
void readfile(char path[])
{
	char temp[100]="ls -l ";
	strcat(temp,path);
	struct stat f;
	char ch;
	FILE* f_read;// write="w" read-write="r+" append="a"
	//f_read = fopen(path, "r");
	if (!f_read) 
	{ 	
    		printf("\n\033[31mFailed opening file %s for reading:\n\033[0m",path);
	}
	else
	{
		printf("\n\n\t~~~DETAILS of the file~~~\n\n");
		system(temp);
		printf("\n");
		access1(path);
		printf("\n\n");
		/*printf("\n\n\t~~~Contents of the file~~~\n\n");
		while( ( ch = fgetc(f_read) ) != EOF )
      			printf("%c",ch);
      		printf("\n\n");
      		fclose(f_read);*/
	}
}
int display_directory(char path[])
{
	int i=2,count=2;
	struct dirent **namelist;
	int n=scandir(path,&namelist,NULL,alphasort);
	DIR* dir = opendir(path);
	if (dir)
	{
   	   //perror("opendir");
	   struct dirent* entry;
	   while ( count<n ) 
	   {
		
    		printf("\t\033[36m%d  %s ", i,namelist[count]->d_name);
		if(namelist[count]->d_type==DT_DIR)
			printf("(folder)\033[0m\n");
		else
			printf("(file)\033[0m\n");
    		i++;
		count++;
	   }
	   printf("\n\033[33m--------------------------------\033[0m\n");
	   return 1;
	}
	else
	{
		printf("\n\033[33m--------------------------------\033[0m\n");
		//perror("opendir");
		return 0;
	}
}
char* change_dir(char path[],int i)
{
	int j=2;
	char b[2]="/";
	DIR* dir = opendir(path);
	struct dirent* entry;
	   while ( (entry = readdir(dir)) != NULL ) 
	   {
	   	if(j==i)
	   	{
	   		strcat(path,entry->d_name);
	   		strcat(path,b);	
	   		dir=opendir(path);
	   		return (path);
	   	}
	   	j++;
	   	if(j>i)
	   		return NULL;
	   }
}
/*void current_dir()
{
	char cwd[MAX_DIR_PATH+1];
	if (getcwd(cwd, MAX_DIR_PATH+1))
	{
		printf("Current Directory : %s\n",cwd);
    		perror("getcwd");
    		exit(1);
	}
}*/
char* parent_dir(char path[])
{
	if(strcmp(path,"/")==0)
	{
		printf("\n\n\033[31mUnable to access parent directory\033[0m\n\n");
		return NULL;
	}
	int i=strlen(path)-2;
	while(path[--i]!='/')
	{}
	path[i+1]='\0';
	return path;
}
int main()
{
	int i,flag;;
	int check;
	char *temp;
	char *path;
	char *temp1;
	char *choice;
	path=(char*)malloc(sizeof(char)*1000);
	temp=(char*)malloc(sizeof(char)*1000);
	temp1=(char*)malloc(sizeof(char)*1000);
	choice=(char*)malloc(sizeof(char)*100);
	strcpy(path,"/home/");
	strcpy(temp1,path);
	printf("\n\t\t\t\033[41mWELCOME TO THE FILE MANAGER\033[0m\n");
	while(1)
	{
		flag=0;i=0;
		printf("\n\033[33m--------------------------------\033[0m\n\n");
		printf ("\t\033[36m0  EXIT\n\t1  PARENT DIRECTORY(./)\033[0m\n");
		strcpy(path,temp1);
		check=display_directory(temp1);
		strcpy(temp1,path);
		printf("\n\033[32mGive the number corresponding to the above options : \033[0m");
		scanf("%d",&i);
		while(choice[i]!='\0')
		{
			if(!isdigit(choice[i]))
			{
				printf("\033[31m\nInvalid Input\033[0m\n");
				flag=1;
				break;
			}
			i++;
		}
		if(flag)
		  continue;
		i=atoi(choice);
		if(i==0)
		{
			break;
		}
		else if(i==1)
		{
			parent_dir(temp1);
		}
		else
		{
			if(!((temp=change_dir(temp1,i))==NULL))
			{
				strcpy(temp,temp1);
			}
			if(temp==NULL)
			{
				printf("\n\033[31mInvalid Input!!!\033[0m\n");
				continue;
			}
			else if(!(opendir(temp)))
			{
				
				temp1[strlen(temp1)-1]='\0';
				readfile(temp1);
				strcpy(temp1,path);
			}
		}
	}
}
