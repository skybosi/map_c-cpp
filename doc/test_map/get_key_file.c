#include<stdio.h>
#include<string.h>
int get_key_line_number(const char *file, const char *key, char *out)
{
	FILE *pf = NULL;
	char string[1024] = { 0 };
	size_t result = 0;
	size_t index = 0;
	size_t row = 1;
	size_t col = 1;
	size_t offset = 0;
	char *pos = NULL;
	char *p = NULL;
	if ((file == NULL) || (key == NULL))
	{
		return -1;
	}
	if ((*file == '\0') || (*key == '\0'))
	{
		return -2;
	}
	pf = fopen(file, "r");
	if (pf == NULL)
	{
		perror("Error opening file");
		return -3;
	}
	do
	{
		memset(string, 0, sizeof(string));
		result = fread(string, 1, sizeof(string) - 1, pf);
		pos = strstr(string, key);
		printf("pos:%s\n",pos);
		p = string;
		offset = (size_t) (pos - string);
		for (index = 0; (index < sizeof(string) - 1) && (*p != '\0'); index++)
		{
			if ((pos != NULL) && (offset == index))
			{
				printf("row:%d\tcol:%d\n",row,col);
//				out += sprintf(out, "row:%d+col:%d\n", row, col);
				pos = strstr(string + offset + strlen(key), key);
				offset = (size_t) (pos - string);
			}
			if (string[index] == (char)'\n')
			{
				row++;
				col = 0;
			}
			else
			{
				col++;
			}
			p++;
		}
	}
	while (!feof(pf));
	fclose(pf);
	pf = NULL;
	return 0;
}
