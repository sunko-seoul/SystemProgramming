#ifndef STUDENT_DB_H
#define STUDENT_DB_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM_STUDENT 255

enum action {ADD, FIND, EXIT};

typedef struct {
	int ID;        // 4byte
	char name[8];  // 8byte
	float score;   // 4byte
} Student;

int		fileOpen(FILE **_fp, char *_fileName, char *_mode);
int		selectAction(void);
void	printStudentInfo(Student *_info);
int		addStudentInfo(FILE *_fp, Student *_info);
long	findStudent(FILE *_fp, Student *_info);

#endif
