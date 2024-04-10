//https://github.com/eakozyrev/introduction_C_Cpp.git
// Compile: g++ test.cpp
// Run:     ./a.out

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

char* GetString(FILE* stream, char symbol = '.')
{
  char* pStr;
  char temp[MAX];
  char ch;
  int i, size;
  //for(i = 0; (int)ch != 10; i++) //условие на Enter
  for(i = 0; ch != '.'; i++)
    {
      //ch = getchar();
      fscanf(stream,"%c",&ch);
      temp[i] = ch;
    }
  temp[i] = '\0';

  for(size = 0; *(temp+size) != '\0'; size++);

  printf("size = %d   sizeof(temp) = %d \n", size, sizeof(temp) );

  pStr = (char*)malloc((size+1)*sizeof(char));

  for(i = 0; *(temp+i) != '\0'; i++)*(pStr+i)=temp[i];
  
  *(pStr+size) = '\0';
  return pStr;
}



int main(){

char str1[100] = "Privet, MIR!";
printf("sizeof(str1) = %d\n", sizeof(str1));
printf("str1 = %s\n",str1);
str1[6] = 0; // = '\0'
printf("str1 = %s\n",str1);

// объединение строк
strcat(str1, "!");
printf("strcat(str1, \"!\") = %s\n",str1);

// char * strcpy ( char * destination, const char * source );
strcpy(str1, "Poka");
printf("strcpy(str1, \"Poka\"): %s\n",str1);

// сравнение строк, равные строки вернут 0
int compare = strcmp(str1, "Poka");
printf("compare = %d\n",compare);

char *str2 = GetString(stdin);
printf("str2 = %s\n",str2);

free(str2);

return 0;
}