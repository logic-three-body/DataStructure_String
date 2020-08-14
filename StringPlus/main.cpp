#include"string1.h"
int main()
{
	const char *s1 = "bababaababababca";
	const char *s2 = "ababababca";
	String s3, s4;
	s3= "bababaababababca";
	s4= "ababababca";
	int offset = s3.KMP_match(s4);
	int offset2 = s3.KMP_match(s2);
	printf("offset is %d %d\n", offset,offset2);
	return 0;
}