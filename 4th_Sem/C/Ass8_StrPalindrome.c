#include <stdio.h>
#include <string.h>
 
int isPalindrome(char *, int , int );
 
int main(){
    char newStr[100];
    printf("Enter String :: ");
    scanf("%s", newStr);
         
    if(isPalindrome(newStr, 0, strlen(newStr) - 1))
        printf("%s is a Palindrome \n", newStr);
    else 
        printf("%s is not a Palindrome \n", newStr);
     
    return 0;
}
 
int isPalindrome(char *newStr, int leftIndex, int rightIndex)
{
     /* Input Validation */
     if(NULL == newStr || leftIndex < 0 || rightIndex < 0)
     {
         printf("Invalid Input");
         return 0;
     }
     
     /* Recursion termination condition */
     if(leftIndex >= rightIndex)
         return 1;
     if(newStr[leftIndex] == newStr[rightIndex]){
         return isPalindrome(newStr, leftIndex + 1, rightIndex - 1);
     }
     return 0;
}
