#include <stdio.h>
#include <stdlib.h>
#define MAX 4
#define SPECIALIST 4
#define WARDS 4
void printSpecialistData(int ids[4][4],char specialist[4][20],float baseFee[],float consultantTime[],int patientCap[]);
void printWardData(int wids[4][20],char wards[4][25],float bedRate[],int totalBed[]);
void bedTracker( int bedOccupancy[4][20]);

int main()

{int ids[4][4]={1,
                2,
                3,
                4};
char specialist[4][20]={"Genaral Practise OPD",
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

int wids[4][20]={1,
                2,
                3,
                4};
char wards[4][25]={"Genaral Ward",
                   "Paediatric Ward",
                   "Surgical Ward",
                   "ICU(Intensive Care Unit)"};
float bedRate[WARDS]={3000.00,
                      6000.00,
                      12000.00,
                      25000.00};
int totalBed[WARDS]={20,
                    10,
                    10,
                    05};
int bedOccupancy[4][20];
printSpecialistData(ids,specialist,baseFee,consultantTime, patientCap);
printWardData(wids,wards,bedRate,totalBed);
bedTracker(bedOccupancy);
return 0;





}
void printSpecialistData(int ids[4][4],char specialist[4][20],float baseFee[],float consultantTime[],int patientCap[]){
printf("Doctor Speecialist Data\n");
printf("------------------------------------------------------------------------------------------------------------------------");
printf("\n%-15s%-30s%-28s%-30s%-10s","Specialty ID","Specialty Name","Base Consultation Fee(LKR)","Consaltation Time/Patient","Daily Patient Cap");
printf("\n-----------------------------------------------------------------------------------------------------------------------");
for(int i=0;i<4;i++){

    printf("\n%-15d%-35s%-30.2f%-30.2f%-10d\n",
           i+1,
           specialist[i],
           baseFee[i],
           consultantTime[i],
           patientCap[i]);
printf("\n-------------------------------------------------------------------------------------------------------------------------");
}
}
void printWardData(int wids[4][20],char wards[4][25],float bedRate[],int totalBed[]){
printf("\n");
printf("\n");
printf("\nHospital Wards Data");
printf("\n---------------------------------------------------------------------------------------------------------------------");
printf("\n%-15s%-35s%-25s%-15s","Ward Id","Ward Name","Daily Bed Rate(LKR/Day)","Total Bed Capacity" );
printf("\n----------------------------------------------------------------------------------------------------------------------");
for(int j=0;j<4;j++){
    printf("\n%-15d%-35s%-25.2f%-15d\n",
           j+1,
           wards[j],
           bedRate[j],
           totalBed[j]);
printf("\n-------------------------------------------------------------------------------------------------------------------");
}
}
void bedTracker(int bedOccupancy[4][20]){
for (int i=0;i<4;i++){

for(int j=0;j<=20;j++){
    bedOccupancy[i][j]=0;

}
}
bedOccupancy[3][1]=1;
bedOccupancy[2][2]=1;
bedOccupancy[1][25]=1;
bedOccupancy[2][5]=1;
printf("--------------------Bed Status--------------------------------");
for (int i=0;i<4;i++){
    printf("\nWard number %d",i+1);

for(int j=0;j<=20;j++){
if(bedOccupancy[i][j]==1){
    printf("\n%d= Bed Occupied",j);}
else{
    printf("\n%d= Bed aviable",j);
}
}
}
}


