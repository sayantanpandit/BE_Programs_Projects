#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

void mycreate(char *, char *, char *);
void myopen();
void myread(char *);
void mywrite(char *, char *);
void myclose();
void mydel(char *, char *);
void listshow(char *);
int matchFile(char *, char *);

char cmd[500], *token, txt[100000], nameass[10][10];
char s[2] = " ";
int drive_count=0, file_size, freeSpace=0;

int main()
{   
   while(1)
   {
      printf("myfs> ");
      scanf("%[^\n]%*c", cmd);
      token = strtok(cmd, s);
      
      if(strcmp(cmd, "mkfs") == 0)
         mycreate(strtok(NULL, s), strtok(NULL, s), strtok(NULL, s));
      else if(strcmp(cmd, "use") == 0)
      {
        //use osfile1 as C:
        char *drive_old = strtok(NULL, s);
        char *as = strtok(NULL ,s);
        char *drive_ass = strtok(NULL ,s);
        printf("drive_old : %s\tas : %s\tdrive_ass : %s\n", drive_old, as, drive_ass);
        strcat(nameass[drive_count++], drive_old);
        strcat(nameass[drive_count++], drive_ass);     
      }
      else if(strcmp(cmd, "cp") == 0)
      {
         char *file = strtok(NULL, s);
         char *drive = strtok(NULL, s);
         myread(file);
         mywrite(drive, file);
      }
      else if(strcmp(cmd, "ls") == 0)
      {
         char *drive = strtok(NULL, s); 
         listshow(drive);
      }    
      else if(strcmp(cmd, "rm") == 0)
      {
         char *stment = strtok(NULL,s);
         char delim[2] = ":";
         char *drive = strtok(stment, delim);
         char *file  = strtok(NULL, delim);
        
         //printf("drive = %s\tfile = %s\n", drive, file);
         mydel(drive, file);
         
      }      
      /*else if(strcmp(cmd, "mv") == 0)*/
       
      else if(strcmp(cmd, "exit") == 0)
          exit(1);
   }
}

void mycreate(char *size, char *blk, char *drive)
{
   int c = 0; char size_number[10], size_format[5], details[20];
   while(*(size+c)>='0' && *(size+c)<='9')
   {
      size_number[c] = *(size+c);
      c++;
   }
   strcpy(size_format, (size+c));
   
   int fd = creat(drive, S_IRWXU), s;
   int block, blocksize=atoi(blk);
   if(strcmp(size_format, "B") == 0)
      s = atoi(size);
   else if(strcmp(size_format, "KB") == 0)
      s = atoi(size)*1024;
   else if(strcmp(size_format, "MB") == 0)
      s = atoi(size)*1024*1024;
   ftruncate(fd, s);
   block = s/blocksize;
   int inode = blocksize;
   int dnode = block-2; 
   freeSpace = inode+inode*10+16;//blocksize;
   
   FILE *fp = fopen(drive, "w");
   fseek(fp, 0, SEEK_SET);
   fprintf(fp, "%d", block);   //Total no. of block
   fseek(fp, 10, SEEK_SET);
   fprintf(fp, "%d", inode);   //Total no. of inode
   fseek(fp, 20, SEEK_SET);
   fprintf(fp, "%d", dnode);   //Total no. of dnode
   fseek(fp, 30, SEEK_SET);     
   fprintf(fp, "%d", freeSpace); //Total no. of freeSpace
   
   fseek(fp, inode, SEEK_SET );
   fprintf(fp, "%d", 0);
   fseek(fp, inode+inode*10+12, SEEK_SET);
   fprintf(fp, "%d", 0);
   fclose(fp);
}

void myread(char *drive)
{
    printf("drive:%s\n", drive);
    char temp; file_size=0;
        
    FILE *fp = fopen(drive, "r");
    while(temp != EOF)
    {
      txt[file_size++] = temp;
      temp = fgetc(fp);
    }
    //txt[len] = '\0';
    /*int k = 0;
    while(k < file_size)
    {
      printf("%c", txt[k++]);
    }*/
    printf("file_size in  myread=%d\n", file_size);
   fclose(fp);
}

void myopen()
{
  
}
//cp osfile3 C:tesfile1
void mywrite(char *drive, char *file)
{
   printf("drive = %s\tfile = %s\n", drive, file);    
   char inode[10], ioffset[10], doffset[10], fSpace[10];
   FILE *fp = fopen(drive, "r+");
   
   fseek(fp, 10,SEEK_SET);  //Read Inode value
   fread(inode, 9, 1, fp);
   
   fseek(fp, atoi(inode)*10, SEEK_SET);   //Read Doffset value
   fread(doffset, 4, 1, fp);
   
   fseek(fp, atoi(inode), SEEK_SET);
   fread(ioffset, 3, 1, fp);
   
   printf("ioffset : %d\tdoffset : %d\n", atoi(ioffset), atoi(doffset)+10);
   //printf("File : %s\n", file);
   
   fseek(fp, 30, SEEK_SET);
   fread(fSpace, 10, 1, fp);    // Read Total no. of freeSpace      
   
   fseek(fp, atoi(inode)+atoi(ioffset)*10+4, SEEK_SET);
   fwrite(file, sizeof(char), strlen(file), fp);
   fprintf(fp, " %d", file_size);
   //printf("File_Size : %d\tLocation : %d\n", file_size, atoi(inode));    
   fseek(fp, atoi(inode), SEEK_SET);
   fprintf(fp, "%d ", atoi(ioffset)+1);
   
   fseek(fp, atoi(fSpace), SEEK_SET);
   fwrite(txt, sizeof(char), file_size, fp);
   
   
   fseek(fp, 30, SEEK_SET);
   float a = file_size/atoi(inode);
  // printf("a :: %f\tfilesize=%d\tinode=%d\tfspace=%d\n", a, file_size, atoi(inode),atoi(fSpace));
   if(a <= 0)
       fprintf(fp, "%d", (int)(atoi(fSpace)+atoi(inode))); 
   else
       fprintf(fp, "%d", (int)(atoi(fSpace)+(a+1)*atoi(inode))); 
   
   /*fseek(fp, 30, SEEK_SET);
   fread(fSpace, 10, 1, fp);    // Read Total no. of freeSpace      
   printf("fSpace=%d\n", atoi(fSpace));*/
   
   
   fclose(fp);
}

void myclose(){}

void mydel(char *drive, char *file)
{
   //printf("drive = %s\tfile = %s\n", drive, file);
   char inode[10], ioffset[10], doffset[10], filedet[10]; int i;
   strcat(drive, ":");   
   for(i=0; i<drive_count; i++)
   {
     if(strcmp(drive, nameass[i]) == 0)
     {
       //printf("%d DRIVE I:: %s\n", i, nameass[i-1]);
       strcpy(drive, nameass[i-1]);
     }
   }
   //printf("DRIVE :: %s\n", drive);
   FILE *fp = fopen(drive, "r+"); 
   fseek(fp, 10,SEEK_SET);  //Read Inode value
   fread(inode, 9, 1, fp);
    
   fseek(fp, atoi(inode), SEEK_SET);
   fread(ioffset, 3, 1, fp);
   
   for(i=0; i<atoi(ioffset); i++)
   {
      printf("inode=%d\tioffset=%d\n", atoi(inode), i);
      fseek(fp, atoi(inode)+i*10+4, SEEK_SET);
      fread(filedet, 9, 1, fp);
      //int pos=matchFile(filedet,file); 
       
      printf("Pos = %d\tfile = %s\n",i, file);
      /*if(pos != 1)
           printf("Found at : %d\n", pos-1);
      else
        printf("Not found");*/
   }
    
   fseek(fp, atoi(inode), SEEK_SET);
   fprintf(fp, "%d ", atoi(ioffset)-1);   
   //printf("ioffset = %d\n", atoi(ioffset)+5);
   fclose(fp);
}

void listshow(char *drive)
{
   char inode[10], node[10], filename[10]; int i;
   printf("drive_count LS = %d\n", drive_count);
   for(i=0; i<drive_count; i++)
   {
     if(strcmp(drive, nameass[i]) == 0)
           strcpy(drive, nameass[i-1]);
   }
   FILE *fp = fopen(drive, "r+");
   fseek(fp, 10, SEEK_SET);
   fread(inode, 9, 1, fp); 
   
   fseek(fp, atoi(inode), SEEK_SET);  
   fread(node, 3, 1, fp); 
   
   if(atoi(node) == 0)
        printf("No file exists...\n");
   else
   {
     for(i=0; i<atoi(node); i++)
     {
       fseek(fp, atoi(inode)+4+10*i, SEEK_SET);  
       fread(filename, 10, 1, fp); 
       printf("%s\n", filename);
     }
   }
}

int matchFile(char *a, char *b)
{
   int c;
   int position = 0;
   char *x, *y;
 
   x = a;
   y = b;
 
   while(*a)
   {
      while(*x==*y)
      {
         x++;
         y++;
         if(*x=='\0'||*y=='\0')
            break;         
      }   
      if(*y=='\0')
         break;
 
      a++;
      position++;
      x = a;
      y = b;
   }
   if(*a)
      return position;
   else   
      return -1;   
}
