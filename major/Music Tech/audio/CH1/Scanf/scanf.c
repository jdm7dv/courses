#include <stdio.h>

int main()
{
	int a, b, c;
	printf_s("\n Please enter a number: ");
	scanf_s("%d", &a);
	printf_s("Please enter a sencond number: ");
	scanf_s("%d", &b);
	c = a + b;
	printf_s(" %d + %d = %d \n",a,b, c);
	return 0;
}
