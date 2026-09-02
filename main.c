#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 4
#define SPECIALIST 4
#define WARDS 4
#define MAX_PATIENTS 100
void printSpecialistData(int ids[4][4],char specialist[4][20],float baseFee[],float consultantTime[],int patientCap[]);
void printWardData(int wids[4][20],char wards[4][25],float bedRate[],int totalBed[]);
void bedTracker( int bedOccupancy[4][20]);
void patientregister(int i,
                     char name[][50],
                     int age[],
                     int patientlevel[],
                     int specialid[],
                     int ward[],
                     int days[]);
float waitingtimecalculate(int specialid[4],int specialtyQueue[4],int i);
float emergencySurcharge(int patientlevel[MAX_PATIENTS],int  specialid[SPECIALIST],float baseFee[SPECIALIST],int i);
float wardstayCost(float bedRate[WARDS],int days[MAX_PATIENTS],int ward[MAX_PATIENTS],int i);
float grossBillTotal(int specialid[MAX_PATIENTS],float baseFee[SPECIALIST],float surchargeFee[],float wardCost[],int i);
float calculateDiscount(int age[MAX_PATIENTS],float grossTotalBill[MAX_PATIENTS],int i);
float finalAmountBill(float grossTotalBill[MAX_PATIENTS],float discount[MAX_PATIENTS],int i);
void bubbleSortPatients(int totalPatients,char name[][50],int age[],int patientlevel[],int ward[],int specialid[],int days[],float surchargeFee[],float wardcost[],float grossTotalBill[],float discount[],float finalAmount[],float waitingtime[]);
void printBill(char name[][50],int age[],int patientlevel[],int ward[],int specialid[],int days[],float waitingtime[],float surchargeFee[],float baseFee[],float wardcost[],float grossTotalBill[],float discount[],float finalAmount[],int i);
void summaryReports(int totalPatients,char name[][50],int patientlevel[],float finalAmount[],int ward[],float discount[],int totalBed[]);

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
int i=0;
int bedOccupancy[4][20];
char name[MAX_PATIENTS][50];
int age[MAX_PATIENTS];
int patientlevel[MAX_PATIENTS];
int specialid[MAX_PATIENTS];
int ward[MAX_PATIENTS];
int days[MAX_PATIENTS];
float waitingtime[MAX_PATIENTS];
float surchargeFee[MAX_PATIENTS];
float wardcost[MAX_PATIENTS];
float grossTotalBill[MAX_PATIENTS];
float discount[MAX_PATIENTS];
float finalAmount[MAX_PATIENTS];

int specialtyQueue[4]={0,0,0,0};
int totalpatients;
int choice;
do{
    printf("\n---------------------------------------------------------------------------------------------------------------");
    printf("\n                   SMART HOSPITAL MANAGEMENT SYSTEM");
    printf("\n---------------------------------------------------------------------------------------------------------------");
    printf("\n1.Display Specialist Information");
    printf("\n2.Display Ward Information");
    printf("\n3.Bed Tracker");
    printf("\n4.Register Patients");
    printf("\n5.Display Patient Piority List");
    printf("\n6.Display Patient Bills");
    printf("\n7.Genarate Summary Reprts");
    printf("\n8.Exit");
    printf("\nEnter Your Choice");
    scanf("%d",&choice);
    switch(choice){
    case 1:printf("\n");
    printSpecialistData(ids,specialist,baseFee,consultantTime, patientCap);
    break;
    case 2:printf("\n");
    printWardData(wids,wards,bedRate,totalBed);
    break;
    case 3:printf("\n");
    bedTracker(bedOccupancy);
    break;
    case 4:printf("\n");
    printf("Enter the total Patients for register");
    scanf("%d",&totalpatients);
    getchar();

      if(totalpatients <= 0 || totalpatients > MAX_PATIENTS){
        printf("\nInvalid number Please check\n");
        totalpatients = 0;
        break;
        }
    for(int i=0;i<totalpatients;i++){
    printf("patient Registration");
    patientregister(i, name, age, patientlevel, specialid, ward, days);
    waitingtime[i] =
    waitingtimecalculate(specialid, specialtyQueue, i);
    printf("\n Patient Estimated Waiting Time: %.2f minutes\n", waitingtime[i]);
    surchargeFee[i] = emergencySurcharge(patientlevel, specialid, baseFee, i);

    printf("Surcharge Fee: %.2f\n", surchargeFee[i]);
    wardcost[i]=wardstayCost(bedRate,days,ward,i);
    printf("\n Wardstaycost:%.2frupees\n",wardcost[i]);
    grossTotalBill[i]=grossBillTotal(specialid,baseFee, surchargeFee, wardcost, i);
    printf("\n grossTotalBill:%.2frupees\n",grossTotalBill[i]);
    discount[i]=calculateDiscount(age,grossTotalBill,i);
    printf("Discount:%.2frupees\n",discount[i]);
    finalAmount[i]=finalAmountBill(grossTotalBill,discount,i);
    printf("Patients Succesfully Registerd");}
    bubbleSortPatients(totalpatients,name,age, patientlevel,ward,specialid,days, surchargeFee ,wardcost,grossTotalBill,discount, finalAmount,waitingtime);
    break;
    case 5:
        if(totalpatients==0){
            printf("PAtients not registerd");

        break;}
        printf("\n");
        printf("\n***************************************************************************************************************\n");
printf("Patient Piority Order\n");
printf("-----------------------------------------------------------------------------------------------------------------\n");
printf("%-7s%-20s%-5s%-20s%-5s","Number",
                                "Patient Name",
                                "age",
                                "Patient Level",
                                "Specialty ID");
printf("\n-----------------------------------------------------------------------------------------------------------------");
for(int i=0;i<totalpatients;i++){
        printf("\n%-7d%-20s%-5d%-20d%-5d",i+1,
                                          name[i],
                                          age[i],
                                          patientlevel[i],
                                          specialid[i]);

}
break;
case 6:printf("\n");
if(totalpatients==0)
    printf("no patients Register");
for(int i=0;i<totalpatients;i++){
printBill(name,
          age,
          patientlevel,
          ward,
          specialid,
          days,
          waitingtime,
          surchargeFee,
          baseFee,
          wardcost,
          grossTotalBill,
          discount,
          finalAmount,
          i);
}
break;
case 7:
    summaryReports(totalpatients,name,patientlevel,finalAmount,ward,discount,totalBed);
    break;
case 8:
    printf("\n-------------------------------------------------------------------------------------------------------------------");
    printf("\nThank you for joining with smart patient management system");
    printf("----------------------------------------------------------------------------------------------------------------------");
    break;
default:
    printf("INVALID CHOICE");
    break;
}

} while(choice!=8);
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

for(int j=0;j<20;j++){
    bedOccupancy[i][j]=0;

}
}
bedOccupancy[3][1]=1;
bedOccupancy[2][2]=1;
bedOccupancy[1][5]=1;
bedOccupancy[2][5]=1;
printf("--------------------Bed Status--------------------------------");
for (int i=0;i<4;i++){
    printf("\nWard number %d",i+1);

for(int j=0;j<20;j++){
if(bedOccupancy[i][j]==1){
    printf("\n%d= Bed Occupied",j);}
else{
    printf("\n%d= Bed aviable",j);
}
}
}
}
void patientregister(int i,
                     char name[][50],
                     int age[],
                     int patientlevel[],
                     int specialid[],
                     int ward[],
                     int days[]){
int choice;



printf("\n------------------------------------------------------------------------------------------------------------------");
printf("\nPatient Details:");
printf("\n-----------------------------------------------------------------------------------------------------------------");

printf("\nEnter Patient Name ");

fgets(name[i],sizeof(name[i]),stdin);
name[i][strcspn(name[i],"\n")]='\0';
do{
printf("\nEnter Patient Age");
scanf("%d",&age[i]);
if(age[i]<0){
    printf("Invalid Age");
}
}
while(age[i]<0);
do{
printf("\nEnter Emergency/Triage Level");
printf("\n1=Normal\n2=Urgent\n3=Critical");
scanf("%d",&patientlevel[i]);
if(patientlevel[i]<1||patientlevel[i]>3){
    printf("Invalid ");
}
}
while(patientlevel[i]<1||patientlevel[i]>4);
printf("\n-------------------------------------------------------------------------------------------------------------------");
printf("\nSpecialty Selection");
printf("\n----------------------------------------------------------------------------------------------------------------------");
printf("\nEnter the Specialty ID");
do{
printf("\n1=Genaral Practice OPD\n2=Paediatrics\n3=Cardiology\n4=Neurology");
scanf("%10d",&specialid[i]);
if(specialid[i]<1 || specialid[i]>4){
    printf("Invalid Speciality ID");
}
}
while(specialid[i]<1||specialid[i]>4);
printf("\n-----------------------------------------------------------------------------------------------------------------------");
printf("\nWard Admission Details");
printf("\n------------------------------------------------------------------------------------------------------------------------");
do{
printf("\nIs Patient Admitt to Ward");
printf("\n If Yes Enter 1\n If No Enter 0");
scanf("%d",&choice);
if (choice==1){
   printf("Enter the Ward ID(1-4)");
   printf("\n1=Genaral Ward\n2=Paediatric Ward\n3=Surgical Ward\n4=ICU(Intensive Care Unit)");
   scanf("%d",&ward[i]);
   printf("Enter the days Admitted");
   scanf("%d",&days[i]);

}
else if(choice==0){
        ward[i]=0;
        days[i]=0;
    printf("Days Admitted=0 (Outpatient/OPD status)");
}
else{
    printf("Invalid choice");
}

}
while(choice!=0&&choice!=1);


}




float waitingtimecalculate(int specialid[4],int specialtyQueue[4],int i){
int consultantTime[4]={15,20,30,30};
int index=specialid[i]-1;
float wait;
wait=specialtyQueue[index]*consultantTime[index];
specialtyQueue[index]++;
return wait;}

float emergencySurcharge(int patientlevel[MAX_PATIENTS],int specialid[MAX_PATIENTS],float baseFee[SPECIALIST],int i){
float surchargeFee=0.00;
if (patientlevel[i]==1){
    surchargeFee=0.00;}
    else if(patientlevel[i]==2){
    surchargeFee=0.20*baseFee[specialid[i]-1];}
    else if(patientlevel[i]==3){
    surchargeFee=0.50*baseFee[specialid[i]-1];}
return surchargeFee;

}
float wardstayCost(float bedRate[WARDS],int days[MAX_PATIENTS],int ward[MAX_PATIENTS],int i){
float wardcost=0.00;
if(days[i]==0){
    wardcost=0.00;}
else{
    wardcost=days[i]*bedRate[ward[i]-1];
}
return wardcost;
}
float grossBillTotal(int specialid[MAX_PATIENTS],float baseFee[SPECIALIST],float surchargeFee[],float wardcost[],int i){
float grossTotalBill=0.00;
grossTotalBill=baseFee[specialid[i]-1]+surchargeFee[i]+wardcost[i];
return grossTotalBill;
}
float calculateDiscount(int age[MAX_PATIENTS],float grossTotalBill[MAX_PATIENTS],int i){
float discount;
if(age[i]<=5||age[i]>=65)
    discount=grossTotalBill[i]*0.15;
else
    discount=0.00;
return discount;
}
float finalAmountBill(float grossTotalBill[MAX_PATIENTS],float discount[MAX_PATIENTS],int i){
float finalAmount;
finalAmount=grossTotalBill[i]-discount[i];
return finalAmount;}
//bubble sort patients

void bubbleSortPatients(int totalPatients,char name[][50],int age[],int patientlevel[],int ward[],int specialid[],int days[],float surchargeFee[],float wardcost[],float grossTotalBill[],float discount[],float finalAmount[],float waitingtime[]){
    int i,j;
    /*level3>level2>level1
    this gives secondary piority automatically*/

    for(i=0;i<totalPatients-1;i++){
        for(j=0;j<totalPatients-1-i;j++){
            if(patientlevel[j]<patientlevel[j+1]){
                    //name
                char tempname[50];
                strcpy(tempname,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],tempname);
            //age

              int tempage;
              tempage=age[j];
              age[j]=age[j+1];
              age[j+1]=tempage;
              //patientlevel
              int temppatientlevel=patientlevel[j];
              patientlevel[j]=patientlevel[j+1];
              patientlevel[j+1]=temppatientlevel;
              //specialid
              int tempSpecialid=specialid[j];
              specialid[j]=specialid[j+1];
              specialid[j+1]=tempSpecialid;
              //days
              int tempDays=days[j];
              days[j]=days[j+1];
              days[j+1]=tempDays;
              //wards
              int tempWard=ward[j];
              ward[j]=ward[j+1];
              ward[j+1]=tempWard;
              //waitintime
              float tempWaitingTime;
              tempWaitingTime = waitingtime[j];
              waitingtime[j] = waitingtime[j + 1];
              waitingtime[j + 1] = tempWaitingTime;
              //surchargefee
              float tempsurchargeFee=surchargeFee[j];
              surchargeFee[j]=surchargeFee[j+1];
              surchargeFee[j+1]=tempsurchargeFee;
              //wardcost
              float tempwardCost=wardcost[j];
              wardcost[j]=wardcost[j+1];
              wardcost[j+1]=tempwardCost;
              //gross total bill
              float tempgross=grossTotalBill[j];
              grossTotalBill[j]=grossTotalBill[j+1];
              grossTotalBill[j+1]=tempgross;
              float tempDiscount=discount[j];
              //discount
              discount[j]=discount[j+1];
              discount[j+1]=tempDiscount;
              //final bill
              float tempfinalBill=finalAmount[j];
              finalAmount[j]=finalAmount[j+1];
              finalAmount[j+1]=tempfinalBill;

            }
        }
    }
}
//print the admission and bill
void printBill(char name[][50],int age[],int patientlevel[],int ward[],int specialid[],int days[],float waitingtime[],float surchargeFee[],float baseFee[],float wardcost[],float grossTotalBill[],float discount[],float finalAmount[],int i) {
char *specialist[]={"Genaral practise OPD",
                    "Peadrictics",
                    "Cardiology",
                    "Neuronology"};
char *wards[]={"Genaral Ward",
               "Paediatric Ward",
               "Surgical Ward",
               "ICU(Intensive Care Unit)"};
printf("\n_________________________________________________________________________________________________________________________");
printf("\n__________________________________________________________________________________________________________________________");
printf("\nSMART HOSPITAL ADMISSION & BILL");
printf("\n---------------------------------------------------------------------------------------------------------------------------");
printf("\nPatient ID                                          :PAT-%04d",1001+i);
//Patient name
printf("\nPatient Name                                        :%s",name[i]);
//patient age
if(age[i]<5||age[i]>65)
        printf("\nAge                                                 :%d Years(15%Subsidy Eligigible)",age[i]);
else
        printf("\nAge                                                 :%d Years",age[i]);
//secialty
printf("\nSpecialty                                           :%s",specialid[i]>=1&&specialid[i]<=4?specialist[specialid[i]-1]:"Unkown");
//ward
if (ward[i]>=1 && ward[i] <=4)
        printf("\nAssigned Ward                                       :%s",wards[ward[i]-1]);
else
        printf("\nAssigned Ward                                       :Outpatient/OPD");
//patient level
if(patientlevel[i]==3)
        printf("\nUrgency Level                                        :Level 3(Critical)");
else if(patientlevel[i]==2)
        printf("\nUrgency Level                                        :Level 2(Urgent)");
else
        printf("\nUrgency Level                                        :Level 1(Normal)");
        printf("\n------------------------------------------------------------------------------------------------------------");
//Base consultant Fee
        printf("\nBase Consultation Fee                                :LKR %.2f",baseFee[specialid[i]-1]);
//Surcharge
printf("\nEmergency Surcharge                                  :LKR %.2f",
       surchargeFee[i]);
//ward cost
if(days[i]>0)
        printf("\nWard Stay Cost(%d)                                   :LKR %.2f",
               days[i],wardcost[i]);
else
        printf("\nWard Stay Cost                                       :LKR %.2f",wardcost[i]);
printf("\n------------------------------------------------------------------------------------------------------------------");
//gross Total Bill
        printf("\nGross Total Bill                                     :LKR %.2f",grossTotalBill[i]);
//age subsity discount
if(age[i] <=5||age[i] >=65)
        printf("\nAge Subsity Discount                                 :LKR -%.2f(%%15)",discount[i]);
else
        printf("\nAge Subsity Discount                                 :LKR %.2f",discount[i]);
        printf("\n-------------------------------------------------------------------------------------------------------------------");
//final Payable Amount
        printf("\nFinal Payable Amount                                 :LKR %.2f",finalAmount[i]);
//Estimated Waiting Time
printf("\nEstimated Waiting Time                               :LKR %.2f mins",waitingtime[i]);
printf("\n____________________________________________________________________________________________________________________");
printf("\n_____________________________________________________________________________________________________________________");}

void summaryReports(int totalPatients,char name[][50],int patientlevel[],float finalAmount[],int ward[],float discount[],int totalBed[]){
    //initialized the variables
int level1=0;
int level2=0;
int level3=0;
float totalRevenue=0.00;
float totaldiscount=0.00;
int ocuupiedBeds[WARDS]={0,0,0,0};
int highestpatient=0;
//total patient registerd and  categorized by Urgency Level Report
for(int i=0;i<totalPatients;i++){
    if(patientlevel[i]==1)
        level1++;
    else if(patientlevel[i]==2){
        level2++;}
    else{
        level3++;}

//total revenue and total discount
totalRevenue+=finalAmount[i];
//total discount
totaldiscount+=discount[i];
if(ward[i]>=1&&ward[i]<=4)
    ocuupiedBeds[ward[i]-1]++;
//highest patient
if(finalAmount[i]>finalAmount[highestpatient])
    highestpatient=i;
}
printf("\n *****************SMART HOSPITAL SUMMARY REPORTS**********************************************");
printf("\n----------------------------------------------------------------------------------------------");
printf("\n REPORT OF TOTAL PATIENTS REGISTERD AND CATEGORIZED BY URGENCY LEVEL");
printf("\n-----------------------------------------------------------------------------------------------");
printf("\nTotal Patients= %d",totalPatients);
printf("\nTotal Number of patients in Normal=%d",level1);
printf("\nTotal Number of patients in Urgent=%d",level2);
printf("\nTotal Number of patients in Critical=%d",level3);
//Total Revenue and Total Revenue
printf("\n------------------------------------------------------------------------------------------------");
printf("\nTOTAL REVENUE EARNED AND TOTAL DISCOUNTS GRANTED");
printf("\n-------------------------------------------------------------------------------------------------");
printf("\nTotal Revenue Earned= %.2f",totalRevenue);
printf("\n Total discount granted= %.2f",totaldiscount);
//Bed occupancy Percantage
printf("\n-------------------------------------------------------------------------------------------------");
printf("\nBED OCCUPANCY PERCANTAGE PER WARD");
printf("\n-------------------------------------------------------------------------------------------------");
for(int i=0;i<WARDS;i++){
float occupancyPercentage;
if(totalBed[i]>0){
    occupancyPercentage =((float)ocuupiedBeds[i] / totalBed[i]) * 100;}
else
    {occupancyPercentage=0.00;}
printf("\nWard : %d",i+1);
printf("\nTotal Beds %d",totalBed[i]);
printf("\nOccupied Beds %d",ocuupiedBeds[i]);
printf("\nOccupancy Percantage %.2f",occupancyPercentage);}
//name and total Bill of highest Person
printf("\n-------------------------------------------------------------------------------------------------");
printf("\nNAME AND TOTAL BILL OF THE HIGHEST-PAYING PATIENT");
printf("\n--------------------------------------------------------------------------------------------------");
if(totalPatients>0){
    printf("\nHighest amount Paid patient is %s",name[highestpatient]);
    printf("\nPaid amount is %.2f",finalAmount[highestpatient]);}
else{
    printf("Patients are not registered");
    }
  }





















