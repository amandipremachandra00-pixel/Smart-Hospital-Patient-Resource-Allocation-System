#include <stdio.h>
#include <stdlib.h>
#define MAX 4
#define SPECIALIST 4
void printSpecialistData(char specialist[][4],float baseFee[],float consultantTime[],int patientCap[]);

int main()

{char specialist[SPECIALIST][20]={"Genaral Practise(OPD)",
                                   "Paediatrics",
                                   "cardiology",
                                   "Neurology"};
float baseFee[SPECIALIST]={1500.00,
                            2500.00,
                            4500.00,
                            5000.00};
float consultantTime[SPECIALIST]={15,
                                   20,
                                   30,
                                   30};
int patientCap[SPECIALIST]={30,
                            20,
                            12,
                            10};
 printSpecialistData(specialist[][SPECIALIST],baseFee,consultantTime, patientCap);

}
void printSpecialistData(char specialist[][SPECIALIST],float baseFee[],float consultantTime[],int patientCap[]){
printf("%-20s%-20s%-20s%-20s%-20s","Specialty ID","Specialty Name","Base Consultation Fee(LKR)","Consaltation Time//Patient","Daily Patient Cap");
for(int i=0;i<4;i++){
    scanf("%d%f%f%d",specialist[i][4],&baseFee[i],&consultantTime[i],&patientCap[i]);
    printf("%-20d%-20s%-20d%-20d%-20d",i+1,specialist[i][4],baseFee[i],consultantTime[i],patientCap[i]);
}
}
