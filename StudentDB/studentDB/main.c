#include "studentDB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
printf("===Welcome To Your Dashboard===\n");
printf("Press 1 to Upload Result.\n");
printf("Press 2 to Check Result.\n");
char sAction[3];
int Action;
char sAction2[3];
int Action2;

fgets(sAction, sizeof(sAction), stdin);
sAction[strcspn(sAction, "\n")] = 0;
Action = atoi(sAction);

switch (Action) {

case 1 : {
printf("Enter Reg Number:");

fgets(sAction2, sizeof(sAction2), stdin);
sAction2[strcspn(sAction2, "\n")] = 0;
Action2 = atoi(sAction2);
switch(Action2) {
case 1: {
saveTofile(&Mike);
break;
}
case 2: {
saveTofile(&John);
break;
}
case 3: {
saveTofile(&Noni);
break;
}
case 4: {
saveTofile(&Cynthia);
break;
}
case 5: {
saveTofile(&Lillian);
break;
}
default : {printf("No record Found");
break;}

}
break;


}


case 2 : {
printf("Enter Reg Number:");

fgets(sAction2, sizeof(sAction2), stdin);
sAction2[strcspn(sAction2, "\n")] = 0;
Action2 = atoi(sAction2);
switch(Action2) {
case 1: {
readFromFile(&Mike);
break;
}
case 2: {
readFromFile(&John);
break;
}
case 3: {
readFromFile(&Noni);
break;
}
case 4: {
readFromFile(&Cynthia);
break;
}
case 5: {
readFromFile(&Lillian);
break;
}
default : {printf("No record Found");
break;}

}
break;


}
default : {printf("Invalid Input\n");
break;}

}


return 0;
}
