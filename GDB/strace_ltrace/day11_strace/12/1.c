#include<stdio.h>

/* Our structure */
struct rec
{
	int x,y,z;
	float value;
};

int main()
{
	int counter;
	struct rec my_record;
	int counter_limit;
	FILE *ptr_myfile;

	counter_limit = 1000;

	ptr_myfile=fopen("test.bin","wb");
	if (!ptr_myfile)
	{
		printf("Unable to open file!");
		return 1;
	}
	for ( counter=1; counter <= counter_limit; counter++)
	{
		my_record.x = counter;
		my_record.y = counter + 1;
		my_record.z = counter + 2;
		my_record.value = (float) counter * 10.0;
		fwrite(&my_record, sizeof(struct rec), 1, ptr_myfile);
	}
	fclose(ptr_myfile);
	return 0;
}
