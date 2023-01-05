#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[32];
	double midterm_score;
	int student_id;
}student_t;

void my_search(student_t* a, int len) {
	int op;
	char search_name[32];
	int search_id;
	int i;
	int find = 0; // 일치하는 데이터 있는 경우에 +1
	printf("Input option:");
	scanf("%d", &op);

	if (op == 1) {
		printf("Input student id:");
		scanf("%d", &search_id);
		for (i = 0; i < len; i++) {
			if (search_id == a[i].student_id) {
				printf("%s(%d):%.2lf\n", a[i].name, a[i].student_id, a[i].midterm_score);
				find++;
			}
		}
		if (find == 0)
			printf("Could not find");
	}
	else if (op == 2) {
		printf("Input name:");
		scanf("%s", search_name);
		for (i = 0; i < len; i++) {
			if (strncmp(search_name, a[i].name, 33) == 0) {
				printf("%s(%d):%.2lf\n", a[i].name, a[i].student_id, a[i].midterm_score);
				find++;
			}
		}
		if (find == 0)
			printf("Could not find");
	}
	else
		printf("Invalid option\n");
}

typedef struct {
	void(*search)(student_t*, int);
}utils_t;


int main(int argc, char* argv[]) {
	student_t list[20];
	int i; char* ptoken; char* delim = " ";
	for (i = 1; i < argc; i++) {
		ptoken = strtok(argv[i], delim);
		list[i - 1].student_id = atoi(ptoken);

		ptoken = strtok(NULL, delim);
		strcpy(list[i - 1].name, ptoken);

		ptoken = strtok(NULL, delim);
		list[i - 1].midterm_score = atof(ptoken);
	}

	utils_t my_util;
	my_util.search = my_search;
	my_util.search(list, argc - 1);


	return 0;
}