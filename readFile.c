#include <stdio.h>

#define BUF	1

unsigned long stringToLong(char*);

int main(void)
	{
		FILE* file;
		char buf, str[50];
		unsigned long i;
		unsigned long number = 0;
		file = fopen("./history/012013.hry","r");
		if(file == NULL)
			{
				printf("Error file!");
				return 1;
			}
		i = 0;
		/*
		for(i=0; (str[i] = fgetc(file) ) != EOF; i++);
		str[i] = '\0';
		*/
		i=0;
		while(fgets(str, 50, file) )
			{
				if(str[0]!= '[')
					{
						number = 0;
						printf("%s", str);
						for(i=0; str[i]!=':';i++);
						i++;
						while( (str[i]!='\0')&& (str[i]!='\n') ) 
							{
								number = number*10 + str[i] - '0';
								i++;
							}
					}
				printf("%d\n", number);
			}
		fclose(file);
		return 0;
	}

unsigned long stringToLong(char* str)
	{
		unsigned long number = 0;
		int i;
		printf("%s", str);
		for(i=0; str[i]!=':';i++);
		while(str[i]!='\0' ) 
			{
				number = number*10 + str[i] - '0';
				i++;
			}
		return number;
	}
