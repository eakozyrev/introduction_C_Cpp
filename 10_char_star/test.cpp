//https://github.com/eakozyrev/introduction_C_Cpp.git
// Compile: g++ test.cpp
// Run:     ./a.out

#include <stdio.h>
#include <stdlib.h>

char* GetString(FILE* stream)
{
  char* pStr;
  char temp[20];
  char ch;
  int i, size;
  for(i = 0; (int)ch != 10; i++)
    {
      //ch = getchar();
      fscanf(stream,"%c",&ch);
      temp[i] = ch;
    }
  temp[i] = '\0';

  for(size = 0; *(temp+size) != '\0'; size++);

  pStr = (char*)malloc((size+1)*sizeof(char));

  for(i = 0; *(temp+i) != '\0'; i++)*(pStr+i)=temp[i];
  
  *(pStr+size) = '\0';
  return pStr;
}



int main(){

  char *str = GetString(stdin);
  printf("%s",str);
  return 0;
}
