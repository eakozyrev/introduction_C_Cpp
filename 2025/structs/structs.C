#include <stdio.h>

union fraction_u{

	int numerator;
	int denominator;
	char characters[4];
	
};

struct fraction_s{

	int numerator;
	int denominator;
	
};


void f1(){

	struct fraction_s f1 = {3,4};

	printf("numerator = %d  denominator = %d\n", f1.numerator, f1.denominator);


	fraction_u f2;
	f2.numerator = 5000000;

	printf("numerator = %d  denominator = %d\n", f2.numerator, f2.denominator);
	for(int i = 0; i < 4; i++){
		printf("%c-",f2.characters[i]);
	}


}


void f2(){

	struct fraction_s f1 = {3,4}, f2 = {4,5};
	f2 = f1;
	printf("numerator = %d  denominator = %d\n", f2.numerator, f2.denominator);
}


void f3(){

	int* p;  
	int i;  
	struct fraction_s f1;  
	struct fraction_s * f1_p = &f1;
	printf("p = %p; i = %d; f1.numerator = %d; f1.denominator = %d; f1_p = %p\n", \
		p, i, f1.numerator, f1.denominator, f1_p);
		
	p = &i; 
	printf("p = %p; i = %d; f1.numerator = %d; f1.denominator = %d; f1_p = %p\n", \
		p, i, f1.numerator, f1.denominator, f1_p);
		
	*p = 42; 
	printf("p = %p; i = %d; f1.numerator = %d; f1.denominator = %d; f1_p = %p\n", \
		p, i, f1.numerator, f1.denominator, f1_p);
		
	p = &(f1.numerator); 
	*p = 22;
	printf("p = %p; i = %d; f1.numerator = %d; f1.denominator = %d; f1_p = %p\n", \
		p, i, f1.numerator, f1.denominator, f1_p);
		
	p = &(f1.denominator);
	*p = 7;
	printf("p = %p; i = %d; f1.numerator = %d; f1.denominator = %d; f1_p = %p\n", \
		p, i, f1.numerator, f1.denominator, f1_p);
		
	f1_p->numerator = 88;	
	printf("p = %p; i = %d; f1.numerator = %d; f1.denominator = %d; f1_p = %p\n", \
		p, i, f1.numerator, f1.denominator, f1_p);	
	
	(*f1_p).numerator = 888;		
	printf("p = %p; i = %d; f1.numerator = %d; f1.denominator = %d; f1_p = %p\n", \
		p, i, f1.numerator, f1.denominator, f1_p);
}

int main(){

	f3();

return 0;
}
