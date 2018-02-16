#include <stdio.h>
#include <stdlib.h>
unsigned char char2u(char c)
{
	return c-'0';
}


unsigned int str2u(const char* s, unsigned char n)
{
	///A compléter
	int i=0;
	int p=1;
	int res=0;
	for( i=n-1; i>=0; i--) {
	res=res+char2u(s[i])*p;
	p=p*10;
	}
	return res;
}

int main()
{
	char s[]={'4','6','0','1'};
	int res=str2u(s,4);
	printf("%d /n",res);
	return 0;
}