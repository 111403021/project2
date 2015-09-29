#include<stdio.h>
#include<string.h>
struct time {
	int Hrs,Mins;
};
struct bus {
	int BusNum;
	int BusCode;
	char Seat[8][4][100];
	char Drivers_Name[100];
	struct time Departure_Time, Arrival_Time;
	char To[100];
	char From[100];
	float Fare;
	int TicketSold;
};
char Empty[]="Empty"; 
struct bus Bus[100];

void New_Bus();
void MainMenu();
void ShowBuses();
void Empty();
void SeatReservation();
void ShowStatus();
void PrintLine();
void DailyReport();
void passward();
void change();
void change_Pass();
void exit();	

void MainMenu() {
int Choice;
printf("\n\n\t\t\t********************************");
printf("\n\n\t\t\t\tBUS RESERVATION SYSTEM");
printf("\n\n\t\t\t********************************\n");
printf("\n\n\t1.Bus Installation");
printf("\n\t\t2.Alottment");
printf("\n\t\t3.Show details");
printf("\n\t\t4.Status");
printf("\n\t\t5.Daily Report");
printf("\n\t\t6.Change Password");
printf("\n\t\t7.Exit");
printf("\n\n\n\tEnter your choice as(1/2/3/4/5):-\t");

scanf("%d",&Choice);

switch(Choice)
{
case 1: New_Bus();
break;

case 2: SeatReservation();
break;

case 3: ShowBuses();
break;

case 4: ShowStatus();
break;

case 5: DailyReport();
break;

case 6: Change_Pass();
break;

case 7: exit(0);

default: printf("\t\t\tU have entered Wrong Choice!!!!");
}
}

