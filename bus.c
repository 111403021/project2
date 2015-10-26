
#include<stdio.h>
#include<string.h>
struct time {
int Hrs;
int Mins;
};

struct bus {
int BusNum;
int BusCode;
char chSeat[8][4][20];
char chDrivers_Name[20];
struct time stDeparture_Time, Arrival_Time;
char GoesTo[20];
char chGoesFrom[20];
float fFare;
int Ticketsold;
};
struct bus Bus[100];

char chEmpty[]="Empty";

static int Number=1;
char i=':'; 

void fnNew_Bus();
void fnMainMenu();
void fnShowBuses();
//void fnEmpty();
void fnSeatReservation();
//void fnShowStatus();
//void fnPrintLine();
//void fnDailyReport();


void main() {
	fnMainMenu();
}

void fnMainMenu() {
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
		case 1 :fnNew_Bus();
			break;
		case 2: fnSeatReservation();
			break;
		case 3: fnShowBuses();
			break;
/*		case 4: fnShowStatus();
			break;
		case 5: fnDailyReport();
			break;
		case 6: exit(0);*/
		default: printf("\t\t\tU have entered Wrong Choice!!!!");
			fnMainMenu();
	}
}


void fnNew_Bus(){ 
	char Choice;
	printf("\n\n\t\tEnter Information about bus\n");
	
	do{	
		fnPrintLine();
		printf("Bus no:%d",Number);
		busN: printf("\n\n\tEnter Bus Num:\t");
		scanf("%d",&Bus[Number].BusNum);
		if(Bus[Number].BusNum==0){
			printf("\n\t\tInvalid Bus Number!!!!");
			goto busN;
		}
		Bus[Number].BusNum=Number;
		busC: printf("\n\n\tEnter Bus Code:\t");
		scanf("%d",&Bus[Number].BusCode);
		if(Bus[Number].BusCode<1||Bus[Number].BusCode>9999){
			printf("\n\t\tInvalid Bus Code!!!!");
			goto busC;
		}
		
		dname: printf("\n\n\tEnter driver's name:\t");
		char v;
		scanf("%s",Bus[Number].chDrivers_Name);
		if(strlen(Bus[Number].chDrivers_Name)>20){
			printf("Maximum 20 characters are allowed");
			goto dname;
		}
		time: printf("\n\tEnter arrival time:\t");
		scanf("%d%c%d",&Bus[Number].Arrival_Time.Hrs,&i,&Bus[Number].Arrival_Time.Mins);
		if(Bus[Number].Arrival_Time.Hrs==0){
			printf("\n\n\t\tInvalid tTme!!!!");
			goto time;
		}
		if((i!=':')||(Bus[Number].Arrival_Time.Hrs>=24)||(Bus[Number].Arrival_Time.Hrs<0)||(Bus[Number].Arrival_Time.Mins>=60)||(Bus[Number].Arrival_Time.Mins<0)){
			printf("\n\t\tInvalid Time!!!!\n");
			printf("\t\tEnter only--hh:mm!!!!");
			goto time;
		}
		deptime: printf("\n\tEnter departure time:\t");
		scanf("%d%c%d",&Bus[Number].stDeparture_Time.Hrs,&i,&Bus[Number].stDeparture_Time.Mins);
		if(Bus[Number].stDeparture_Time.Hrs==0){
			printf("\t\tinvalid Time!!!!");
			goto deptime;
		}
		if((i!=':')||(Bus[Number].stDeparture_Time.Hrs>=24)||(Bus[Number].stDeparture_Time.Hrs<0)||(Bus[Number].stDeparture_Time.Mins>=60)||(Bus[Number].stDeparture_Time.Mins<0)){
			printf("\n\t\tInvalid Time!!!!");
			printf("\n\t\tEnter only--hh:mm");
			goto deptime;
		}
		from: printf("\n\tFrom:\t");
		scanf("%s",Bus[Number].chGoesFrom);
		if(strlen(Bus[Number].chGoesFrom)>20)
		{
		printf("Maximum 20 characters are allowed");
		goto from;
		}

		to: printf("\n\tTo:\t");
		scanf("%s",Bus[Number].GoesTo);
		if(strlen(Bus[Number].GoesTo)>20)
		{
		printf("Maximum 20 characters are allowed");
		goto to;
		}
		printf("\n\tFare:\t");
		scanf("%f",&Bus[Number].fFare);
		Bus[Number].Ticketsold=0;
		printf("\n");
//		fnEmpty();
		fnPrintLine();

		printf("Bus goes from: %s",Bus[Number].chGoesFrom);
		printf("Bus goes to: %s",Bus[Number].GoesTo);

		printf("\n\n\n\tDo u want to continue to add information about new bus(y/n)?? ");
		scanf("%c",&Choice);
		printf("%c",Choice);

		Number++;
		printf("%d",Number);
	}while(Choice=='y'||Choice=='Y');
	fnMainMenu(); 
	
}

void fnShowBuses() {
	int i1;
	printf("\n\n\t\t\t______________________");
	printf("\n\n\t\t\t BUSES AVALAIBLE");
	printf("\n\n\t\t\t______________________\n");

	for(i1=1;i1<Number;i1++) { 
		printf("\n");
		fnPrintLine();
		printf("\n\t\tbus no-\t\t%d",Bus[i1].BusNum);
		printf("\n\t\tbus code-\t%d",Bus[i1].BusCode);
		printf("\n\t\tDrivers Name-\t%s",Bus[i1].chDrivers_Name);
		printf("\n\t\tFrom-\t\t%s",Bus[i1].chGoesFrom);
		printf("\n\t\tTo-\t\t%s",Bus[i1].GoesTo);
		printf("\n\t\tArrival time-\t%d%c%d",Bus[i1].Arrival_Time.Hrs,i,Bus[i1].Arrival_Time.Mins);
		printf("\n\t\tDeparture time-\t%d%c%d",Bus[i1].stDeparture_Time.Hrs,i,Bus[i1].stDeparture_Time.Mins);
		printf("\n\t\tFare-\t\t%.4f",Bus[i1].fFare);
		printf("\n\t\tTickets Sold-\t%d",Bus[i1].Ticketsold);
		printf("\n");
		fnPrintLine();
	}
	fnMainMenu();
}

void fnSeatReservation() {
	char chName[20];
	int BusN;
	int iSeat;
	char Choice;
	printf("\n\n\t\t\t______________________");
	printf("\n\n\t\t\t ALLOTMENT");
	printf("\n\n\t\t\t______________________\n");
	fnPrintLine();
	printf("\n\n\t\tEnter the Bus Number-\t");
	scanf("%d",&BusN);
	if(BusN>=Number) {
		printf("\n\t\t\tSorry Bus Doesn,t Exist!!!!");
		fnSeatReservation();
	}

	seat: printf("\n\t\tEnter the Seat number-\t");
	scanf("%d",&iSeat);
	if(iSeat>32){
		printf("\n\t\tSorry!! There r only 32 seats in the bus!!!!") ;
		goto seat;
	}
	else if(strcmp(Bus[BusN].chSeat[iSeat/4][(iSeat%4)-1],"Empty")==0) {
		printf("\n\t\tEnter the passenger's name-\t");
		name: scanf("%s",chName);
		if(strlen(chName)>20) {
			printf("\n\t\tplz enter only 20 characters!!!!");
			goto name;
		}
		else {
			strcpy(Bus[BusN].chSeat[iSeat/4][iSeat%4-1],chName);
			printf("\n\t\tYour seat is reserved now!!");
			Bus[BusN].Ticketsold++;
			printf("\n\t do u want to continue with reservation(y/n)??");
			scanf("%c",&Choice);
			if(Choice=='y'||Choice=='Y')	
				fnSeatReservation();
			else
				fnMainMenu();
		}
	}
	else{
		printf("\n\tThis seat is already reserved!!!!");
		printf("\n\t do u want to try again??");
		scanf("%c",&Choice);
		if(Choice=='y'||Choice=='Y')
			fnSeatReservation();
		else
			fnMainMenu();
	}
	Bus[BusN].Ticketsold++;
}
