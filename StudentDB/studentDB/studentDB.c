#include "studentDB.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


StudentDetails Mike = {"MIKE EDOUARD",
                       "227755",
                        {15, 40, 0, 3, '-'},
                        {12, 50, 0, 2, '-'},
                        {5,  20, 0, 1, '-'},
                        {24, 49, 0, 1, '-'},
                        {0,  45, 0, 2, '-'},
                        {10, 60, 0, 3, '-'},
                        {5,  34, 0, 3, '-'},
                        {1,  40, 0, 2, '-'},
                         0};


StudentDetails John = {"JOHN JOSH",
                       "337755",
                        {15, 48, 0, 3, '-'},
                        {21, 20, 0, 2, '-'},
                        {19, 23, 0, 1, '-'},
                        {10, 31, 0, 1, '-'},
                        {26, 45, 0, 2, '-'},
                        {13, 55, 0, 3, '-'},
                        {15, 13, 0, 3, '-'},
                        {25, 40, 0, 2, '-'},
                         0};


StudentDetails Noni = {"NONI MARCUS",
                       "445577",
                        {25, 52, 0, 3, '-'},
                        {23, 48, 0, 2, '-'},
                        {29, 40, 0, 1, '-'},
                        {19, 49, 0, 1, '-'},
                        {28, 50, 0, 2, '-'},
                        {10, 60, 0, 3, '-'},
                        {24, 44, 0, 3, '-'},
                        {22, 40, 0, 2, '-'},
                         0};


StudentDetails Cynthia = {"CYNTHIA HARRY",
                       "557755",
                        {15, 40, 0, 3, '-'},
                        {15, 43, 0, 2, '-'},
                        {15, 20, 0, 1, '-'},
                        {15, 60, 0, 3, '-'},
                        {15, 50, 0, 2, '-'},
                        {15, 30, 0, 3, '-'},
                        {15, 49, 0, 3, '-'},
                        {15, 44, 0, 2, '-'},
                         0};


StudentDetails Lillian = {"LILLIAN TREVOH",
                       "662299",
                        {13, 40, 0, 3, '-'},
                        {29, 49, 0, 2, '-'},
                        {7 , 0 , 0, 1, '-'},
                        {25, 35, 0, 1, '-'},
                        {11, 20, 0, 2, '-'},
                        {1 , 40, 0, 3, '-'},
                        {30, 50, 0, 3, '-'},
                        {10, 60, 0, 2, '-'},
                         0};



int coursePoint(score *course){
 int a = course->exam;
 int b = course->test;
 int t = a + b;
  course->total = t;
 int point;

 if (t >= 70 ){
 course->Grade = 'A';
 }else if (t >= 60 && t < 70) {
 course->Grade = 'B';
 }else if (t >= 50 && t < 60) {
  course->Grade = 'C';
 }else if (t >= 45 && t < 50) {
 course->Grade = 'D';
 }else if (t >= 40 && t < 45) {
 course->Grade = 'E';
 }else   {
  course->Grade = 'F';
 }


if (t >= 70){
    point = 5;
}else if (t >= 60 && t < 70){
          point = 4;
}else if (t >= 50 && t < 60){
          point = 3;
}else if (t >= 45 && t < 50){
          point = 2;
}else if (t >= 40 && t < 45){
          point = 1;
}else    {
          point = 0;
}
int totalpoint = point * course->unit;

return totalpoint;
}


void coursePointAdder(StudentDetails *course){
int CSC301 = coursePoint( &course->CSC301);
int CSC302 = coursePoint( &course->CSC302);
int CSC303 = coursePoint( &course->CSC303);
int CSC304 = coursePoint( &course->CSC304);
int CSC305 = coursePoint( &course->CSC305);
int CSC306 = coursePoint( &course->CSC306);
int CSC307 = coursePoint( &course->CSC307);
int CSC308 = coursePoint( &course->CSC308);

int all = CSC301 + CSC302 + CSC303 + CSC304 + CSC305 + CSC306 + CSC307 + CSC308 ;
int allunit = 17;
float allf =(float) all;
float allunitf = (float) allunit;
course->GPA = allf / allunitf;
;


}



void saveTofile (StudentDetails *student){
char filename[100];
sprintf(filename, "..\\%s.bin", student->matricNo);
FILE *record;
record = fopen(filename, "wb");
if (record == NULL){
    perror("Unable to write to file");
}
fwrite(student, sizeof(StudentDetails), 1, record);
fclose(record);
printf("Saved Successfully\n");

}

void readFromFile(StudentDetails *student){

 char reads[100];
 printf("Enter Your Matric Number: ");
 fgets(reads, sizeof(reads), stdin);
 reads[strcspn(reads, "\n")] = 0;
 char readss[108];

 sprintf(readss, "..\\%s.bin", reads);
 FILE *read;
 read = fopen(readss, "rb");
 if (read == NULL){
    printf("Matric No and Reg Number Do not Match\n");
}
 while (fread(student, sizeof(StudentDetails), 1, read)== 1){
        printf("===This is Your Result===\n");
    printf("NAME: %s\n", student->name );
    printf("MATRIC NO: %s\n", student->matricNo );

    printf("\n");
    printf("\n");

    printf("S/No\t Course\t Test\t Exam\t Total\t Unit\t Grade\n");
    printf("1.\t CSC301  %d\t %d\t %d\t %d\t %c\n", student->CSC301.test, student->CSC301.exam, student->CSC301.total, student->CSC301.unit, student->CSC301.Grade);
    printf("\n");
    printf("2.\t CSC302  %d\t %d\t %d\t %d\t %c\n", student->CSC302.test, student->CSC302.exam, student->CSC302.total, student->CSC302.unit, student->CSC302.Grade);
    printf("\n");
    printf("3.\t CSC303  %d\t %d\t %d\t %d\t %c\n", student->CSC303.test, student->CSC303.exam, student->CSC303.total, student->CSC303.unit, student->CSC303.Grade);
    printf("\n");
    printf("4.\t CSC304  %d\t %d\t %d\t %d\t %c\n", student->CSC304.test, student->CSC304.exam, student->CSC304.total, student->CSC304.unit, student->CSC304.Grade);
    printf("\n");
    printf("5.\t CSC305  %d\t %d\t %d\t %d\t %c\n", student->CSC305.test, student->CSC305.exam, student->CSC305.total, student->CSC305.unit, student->CSC305.Grade);
    printf("\n");
    printf("6.\t CSC306  %d\t %d\t %d\t %d\t %c\n", student->CSC306.test, student->CSC306.exam, student->CSC306.total, student->CSC306.unit, student->CSC306.Grade);
    printf("\n");
    printf("7.\t CSC307  %d\t %d\t %d\t %d\t %c\n", student->CSC307.test, student->CSC307.exam, student->CSC307.total, student->CSC307.unit, student->CSC307.Grade);
    printf("\n");
    printf("8.\t CSC308  %d\t %d\t %d\t %d\t %c\n", student->CSC308.test, student->CSC308.exam, student->CSC308.total, student->CSC308.unit, student->CSC308.Grade);
    printf("\n");
    printf("Total Unit: 17\n" );
    printf("GPA : %.2f\n", student->GPA );
    printf("CGPA : %.2f\n", student->GPA );
 }
 fclose(read);

}

