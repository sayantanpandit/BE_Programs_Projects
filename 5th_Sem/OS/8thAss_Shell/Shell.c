#include "ShellInclude.h"

int main(int argc, char *argv[])
{
   /*char cmd[100], history[100][100], path[100];
   char letcmd[100], token[100];*/
   char s[2] = " ";
   int flag = 0;
   histCount = 0;
   while(1)
   {
      //printf("codziac:~%s$ ", getenv("PWD"));
      printf("codziac:$ ");
      scanf("%[^\n]%*c", cmd);
      strcat(history[histCount++], cmd);
      strcpy(letcmd, cmd);
      count   = countWord(cmd);
      countSC = noOfSpecialChar(cmd);
      
      //printf("count = %d\tcountSc=%d\n", count, countSC);
      //strcpy(cmd, strtok(cmd, s));    
      
      if(countSC == 0) 
      {
         strcpy(cmd, strtok(cmd, s));    
         if(findPath(cmd) != (char *)0) 
         {
            strcpy(path, findPath(cmd));
            strcat(path, cmd);  
            operation(cmd);
         }
         else if(strcmp(cmd,"exit")==0 || strcmp(cmd,"cd")==0 || strcmp(cmd,"history")==0)
         {
            strcpy(path, "");
            strcpy(token, letcmd);
            operation(cmd);
         }
         else
           printf(MAKE_RED_DARK"Command Not Found...\n"RESET_COLOR);
      }
      else if(countSC != 0)
      {
         //printf("SPecial...cmd=%s\tcountSC=%d\n",letcmd, countSC);
      int i, pos=0, flag=0,len=posSC[0]; char *pointer, *SpecialChar;
         for(i=0; i<countSC; i++)
         {
           pointer = substring(cmd, pos, len);
           SpecialChar = substring(cmd, posSC[i]+1, 1);
           if(*SpecialChar == '&')
           {
             char *schar = substring(cmd, posSC[i++]+1, 1);
             printf("subString=%s\n", SpecialChar);
             if(*schar == '&')
             {
                 flag=1; printf("I am &&");
             }
           }
           //printf("%d\tSC=%s\n", posSC[i], SpecialChar);
           //printf("pos=%d\tlen=%d\tposSC=%d\tpointer=%s\n", pos, len, posSC[i], pointer);
            pos = posSC[i]+2;
            len = posSC[i+1] - pos + 1;
           // printf("Special Char = %s\n", SpecialChar);
            strcpy(cmd, pointer);
            removeWhiteSpace(cmd);
            if(*SpecialChar == '|')
            {
               printf("i am |");
               if(fork() == 0)
                   pipel(letcmd);
               else
                   wait(NULL);
            }
            else if(flag == 1)
            {
               strcpy(cmd, pointer);
               printf("I am &&");
            }
            //strcpy(cmd, pointer);
            //strcpy(cmd, strtok(cmd, s)); 
            //printf("pointer-cum-cmd=%s\n", cmd);   
          /*  if(findPath(cmd) != (char *)0) 
            {
              strcpy(path, findPath(cmd));
              strcat(path, cmd);  
              operation(cmd);
            }
            else if(strcmp(cmd,"exit")==0 || strcmp(cmd,"cd")==0 || strcmp(cmd,"history")==0)
            {
               strcpy(path, "");
               strcpy(token, cmd);
               operation(cmd);
            }
           else
           printf(MAKE_RED_DARK"Command Not Found...\n"RESET_COLOR);*/
      }
      if(posSC[countSC-1] != strlen(letcmd)-1)
      {
         pointer = substring(cmd, posSC[countSC-1]+2, strlen(letcmd)-posSC[countSC]);
 	 printf("pointer = %s\n", pointer);
      }
     }
   }
}
