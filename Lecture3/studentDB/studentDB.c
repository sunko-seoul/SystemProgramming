#include "studentDB.h"

int main(void)
{
	FILE *fp = NULL;
	Student data = {0};
	fileOpen(&fp, "StudentDB", "ab+");

	while (1)
	{
		switch (selectAction())
		{
			case ADD:
				addStudentInfo(fp, &data);
				break;
			case FIND:
				if (findStudent(fp, &data) < 0)
					printf("Cannot  find the student\n");
				else
					printStudentInfo(&data);
				break;
			case EXIT:
				exit(0);
		}
	}
}

int	fileOpen(FILE **_fp, char *_fileName, char *_mode)
{
	*_fp = fopen(_fileName, _mode);
	if (!*_fp)
	{
		printf("Fail to open -%s\n", _fileName);
		return (-1);
	}
	return (0);
}

int	selectAction(void)
{
	int sel = 0;
	printf("[%d]add [%d]find [%d]exit: ", ADD, FIND, EXIT);
	scanf("%d", &sel);
	return (sel);
}

void printStudentInfo(Student *_info)
{
	printf("%d %s %.2f\n", _info->ID, _info->name, _info->score);
}

int addStudentInfo(FILE *_fp, Student *_info)
{
	printf("Enter ID Name Score : ");
	scanf("%d %s %f", &_info->ID, (char *)&_info->name, &_info->score);
	getchar();

	fseek(_fp, 0, SEEK_END);
	fwrite(_info, sizeof(Student), 1, _fp);
	return (0);
}

long	findStudent(FILE *_fp, Student *_info)
{
	char name[255] = {0};
	printf("Name: ");
	scanf("%s", name);
	getchar();

	int elementSize = sizeof(Student);
	fseek(_fp, 0, SEEK_SET);
	while(!feof(_fp)){
		fread(_info, elementSize, 1, _fp);
		if (strcmp(_info->name, name) == 0){
			fseek(_fp, -elementSize, SEEK_CUR);
			return ftell(_fp);
		}
	}
	return (-1);
}
