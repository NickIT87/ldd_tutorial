#include <stdio.h>

//Use After Return (UAR). Another classic bug, this one involves returning a storage item (or pointer to it) to the calling function. The issue is that the storage is local or automatic, thus implying that once the return is affected, the storage object is now out of scope.

static void * uar(void)
{
	char name[32];
	
	memset(name, 0, 32);
	strncpy(name, "Hands-on Linux Sys Prg", 22);
	//once the return statement in the uar() function takes effect, the name variable is automatically out of scope! Therefore, the pointer to it is invalid,
	return name;
}

int main()
{

	void *res = uar();
	printf("res: %s\n", (char *)res);


	return 0;
}


/*Actually, there are times when this bug escapes notice—it looks like it works fine and there's no bug.
This is because there is no actual guarantee that the stack memory frame is immediately destroyed upon function return—memory and compiler-optimization might keep the frame around (typically for reuse). Nevertheless, it is a dangerous bug and must be fixed!
*/
