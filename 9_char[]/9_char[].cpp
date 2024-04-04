#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define Nmax 15
#include <string.h>

int main()
{
	char arr[Nmax];
	for (int i = 0; i < Nmax; i++)printf("_");
	printf("\n");
	for (int i = 0; i < Nmax; i++)scanf("%c", &arr[i]);
	for (int i = 0; i < Nmax; i++)printf("%c", arr[i]);
	printf("\n");
	char c = 'A';
	// c = A
	printf("c = %c\n", c);
	// c_int = 65
	printf("c_int = %d\n", (int)c);

	printf("66_to_char = %c\n", (char)66);

	scanf("%c", &c);
	if (c >= 'A' && c <= 'Z')
	{
		printf("%c is a Capital letter\n", c);
	}
	else if (c >= 'a' && c <= 'z')
	{ 
		printf("%c is a Lower-case letter\n", c);
	}
	else if (c >= '0' && c <= '9')
	{
		printf("%c is a Digit\n", c);
	}
	else
	{ 
		printf("%c belongs to an unknown category\n", c);
	}

	printf("\n");
	c = 'Q';
	c = c + 'a' - 'A';
	printf("c = %c\n", c);

	char s[256] = "Hello, world!";
	s[5] = 0;
	printf("s = (%s)", s);// s = (Hello)

	printf("\n");
	{
	char s1[256] = "Hello, ";
	char s2[256] = "wor77ld!";
	printf("s1 = %s\n", s1);
	printf("strlen: %d\n", strlen(s1));
	printf("pointer s1 = %p \n", s1);
	strcat(s1, "world!");
	printf("s1 = %s\n", s1);
	printf("strlen: %d\n", strlen(s1));

	strcpy(s1, s2);
	printf("s1 = %s\n", s1);
	printf("strlen: %d\n", strlen(s1));
	if (strcmp(s1, s2) == 0)
	{
		printf("s1 and s2 are equal \n");
	}
	s1[5] = 100;
	printf("s1 = %s  s2 = %s\n", s1, s2);
	printf("strcmp(s1,s2) = %d \n", strcmp(s1, s2));

}
	char s1[] = "wert";
	char s2[] = "wert";
	if (s1 == s2)
	{ 
		printf("s1 and s2 are Equal\n");
	}
	
	if (strcmp(s1, s2) == 0)
	{
		printf("s1 and s2 are equal\n");
	}


	return 0;

}

