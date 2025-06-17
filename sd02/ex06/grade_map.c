typedef const char* (*GradeMapper)(int score);

const char* plus_minus_mapper(int score)
{
	if (score >= 97)
		return "A+";
	if (score >= 93)
		return "A";
	if (score >= 90)
		return "A-";
	if (score >= 87)
		return "B+";
	if (score >= 83)
		return "B";
	if (score >= 80)
		return "B-";
	if (score >= 77)
		return "C+";
	if (score >= 73)
		return "C";
	if (score >= 70)
		return "C-";
	if (score >= 67)
		return "D+";
	if (score >= 63)
		return "D";
	if (score >= 60)
		return "D-";
	return "F";
}

const char* pass_fail_mapper(int score)
{
	if (score <= 60)
		return "F";
	return "P";
}

const char* standard_mapper(int score)
{
	if (score >= 90)
		return "A";
	if (score >= 80)
		return "B";
	if (score >= 70)
		return "C";
	if (score >= 60)
		return "D";
	return "F";
}

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
	while(size-- >= 0)
	{
		*mapped_grades = mapper(*scores);
		mapped_grades++;
		scores++;
	}
}

//#include <stdio.h>
//
//int main()
//{
//	int scores[] = {95, 62, 78, 88, 45, 100, 72};
//	int size = sizeof(scores)/ sizeof(scores[0]);
//	const char *grades[size];
//
//	printf("Plus/Minus Grading:\n");
//	map_scores(scores, size, plus_minus_mapper, grades);
//	for (int i=0; i < size; i++)
//		printf("%d -> %s\n", scores[i], grades[i]);
//
//	printf("\nPass/Fail Grading:\n");
//	map_scores(scores, size, pass_fail_mapper, grades);
//	for (int i=0; i < size; i++)
//		printf("%d -> %s\n", scores[i], grades[i]);
//
//	printf("\nStandard Grading:\n");
//	map_scores(scores, size, standard_mapper, grades);
//	for (int i=0; i < size; i++)
//		printf("%d -> %s\n", scores[i], grades[i]);
//	return (0);
//}
