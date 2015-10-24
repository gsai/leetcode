#include <cstdio>

const int MAX_LEN = 80;
int gmain()
{
	char name[MAX_LEN];
	char fm[10];
	sprintf_s(fm, "%%ds", MAX_LEN - 1);
	printf("%d\n", sizeof(fm));
	printf("%d\n", MAX_LEN);
	printf("%s", fm);
	//scanf_s(fm, name);
	//printf("%s\n", name);

	return 0;
}