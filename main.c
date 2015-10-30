
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "lista.h"
FILE *fp;
char chEmpty[]="Empty";
list k;
static int Number=1;
char i=':'; 
Bus fnNew_Bus();
void fnMainMenu();
//void fnEmpty();
//void fnSeatReservation();
//void fnShowStatus();
void fnPrintLine();
//void fnDailyReport();


void main() {
	fnMainMenu();
}

void fnMainMenu() {
	init(&k);
	int iChoice;
	printf("\n\n\t\t\t______________________");
	printf("\n\n\t\t\tBUS RESERVATION SYSTEM");
	printf("\n\n\t\t\t______________________\n");
	fnPrintLine();
	printf("\n\n\t\t1.Bus Installation");
	printf("\n\t\t2.Alottment");
	printf("\n\t\t3.Show details");
	printf("\n\t\t4.Status");
	printf("\n\t\t5.Daily Report");
	printf("\n\t\t6.Exit");
	printf("\n\n\n\tEnter your choice as(1/2/3/4/5):-\t");
	scanf("%d",&iChoice);

	switch(iChoice) {
		case 1 :
			printf("dfdf");
			Bus h = fnNew_Bus();
			newbus(&k, &h);
			showbus(&k);
			fnMainMenu();
			break;
		case 2: 
			showbus(&k);
			break;	
	
		//case 3: SeatReservation(&k);
		//	break;
/*		case 4: fnShowStatus();
			break;
		case 5: fnDailyReport();
			break;
		case 6: exit(0);*/
		default: printf("\t\t\tU have entered Wrong Choice!!!!");
			fnMainMenu();
	}
}


Bus fnNew_Bus(){        

			fp = fopen("suru", "w");
			char Choice;
			Bus d;
			printf("\n\n\t\tEnter Information about bus\n");
			do{	
				fnPrintLine();
				printf("Bus no:%d",Number);
				busN: printf("\n\n\tEnter Bus Num:\t");
					scanf("%d",&d.BusNum);
					fprintf(fp, "%d/n",d.BusNum);
					if(d.BusNum==0){
						printf("\n\t\tInvalid Bus Number!!!!");
						goto busN;
					}
					d.BusNum=Number;
					busC: printf("\n\n\tEnter Bus Code:\t");
					scanf("%d",&d.BusCode);
					fprintf(fp, "%d/n", d.BusCode);
					if(d.BusCode<1||d.BusCode>9999){
						printf("\n\t\tInvalid Bus Code!!!!");
						goto busC;
					}
		
					dname: printf("\n\n\tEnter driver's name:\t");
					char v;
					scanf("%s",d.chDrivers_Name);
					fprintf(fp, "%s/n", d.chDrivers_Name);
					if(strlen(d.chDrivers_Name)>20){
						printf("Maximum 20 characters are allowed");
						goto dname;
					}
					time: printf("\n\tEnter arrival time:\t");
					scanf("%d%c%d",&d.Arrival_Time.Hrs,&i,&d.Arrival_Time.Mins);
					fprintf(fp, "%d%c%d/n",d.Arrival_Time.Hrs,i,d.Arrival_Time.Mins);
					if(d.Arrival_Time.Hrs==0){
						printf("\n\n\t\tInvalid tTme!!!!");
						goto time;
					}
					if((i!=':')||(d.Arrival_Time.Hrs>=24)||(d.Arrival_Time.Hrs<0)||(d.Arrival_Time.Mins>=60)||(d.Arrival_Time.Mins<0)){
						printf("\n\t\tInvalid Time!!!!\n");
						printf("\t\tEnter only--hh:mm!!!!");
						goto time;
					}
					deptime: printf("\n\tEnter departure time:\t");
					scanf("%d%c%d",&d.stDeparture_Time.Hrs,&i,&d.stDeparture_Time.Mins);
					fprintf(fp, "%d%c%d/n",d.stDeparture_Time.Hrs,i,d.stDeparture_Time.Mins);
					if(d.stDeparture_Time.Hrs==0){
						printf("\t\tinvalid Time!!!!");
						goto deptime;
					}
					if((i!=':')||(d.stDeparture_Time.Hrs>=24)||(d.stDeparture_Time.Hrs<0)||(d.stDeparture_Time.Mins>=60)||(d.stDeparture_Time.Mins<0)){
						printf("\n\t\tInvalid Time!!!!");
						printf("\n\t\tEnter only--hh:mm");
						goto deptime;
					}
					from: printf("\n\tFrom:\t");
					scanf("%s",d.chGoesFrom);
					fprintf(fp, "%s",d.chGoesFrom );
					if(strlen(d.chGoesFrom)>20)
					{
					printf("Maximum 20 characters are allowed");
					goto from;
					}

					to: printf("\n\tTo:\t");
					scanf("%s",d.GoesTo);
					fprintf(fp, "%s",d.GoesTo );
					if(strlen(d.GoesTo)>20)
					{
					printf("Maximum 20 characters are allowed");
					goto to;
					}
					printf("\n\tFare:\t");
					scanf("%f",&d.fFare);
					fprintf(fp, "%f", d.fFare);
					fclose(fp);
					d.Ticketsold=0;
					printf("\n");
			//		fnEmpty();
					fnPrintLine();

					printf("Bus goes from: %s", d.chGoesFrom);
					printf("Bus goes to: %s", d.GoesTo);


					printf("\n\n\n\tDo u want to continue to add information about new bus(y/n)?? ");
					scanf("%c", &Choice);
					printf("%c", Choice);

					Number++;
					printf("%d",Number);
				}while(Choice=='y'||Choice=='Y');
				 
			return d;
}




void fnPrintLine()
{ int j;
for(j=0;j<60;j++)
printf("*");
}
