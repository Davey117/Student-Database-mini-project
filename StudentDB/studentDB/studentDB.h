#ifndef STUDENTDB_H
#define STUDENTDB_H



typedef struct{
int test;
int exam;
int total;
int unit;
char Grade;



}score;

typedef struct{
char name[50];
char matricNo[50];
score CSC301;
score CSC302;
score CSC303;
score CSC304;
score CSC305;
score CSC306;
score CSC307;
score CSC308;
float GPA;

}StudentDetails;

extern StudentDetails Mike;

extern StudentDetails John;

extern StudentDetails Noni;

extern StudentDetails Cynthia;


extern StudentDetails Lillian;



 int coursePoint(score *course);

void coursePointAdder(StudentDetails *course);

void ResultPrinter(StudentDetails *Name);

void saveTofile (StudentDetails *student);

void readFromFile (StudentDetails *student);
#endif // STUDENTDB_H
