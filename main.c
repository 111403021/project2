/*****************************************************************************
 * Copyright (C) Aishwarya Ramesh Latane   latanear14.comp@coep.ac.in
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

FILE *fp;/*file pointer*/
int Number = 1;
char i = ':'; 
Bus fnNew_Bus();

int printmenu() {/*function prints options*/
	
	int Choice;
	printf("\n\n\t\t\t______________________");
	printf("\n\n\t\t\tBUS RESERVATION SYSTEM");
	printf("\n\n\t\t\t______________________\n");
	fnPrintLine();
	printf("\n\t\t1.Bus Installation");
	printf("\n\t\t2.Show Buses available");
	printf("\n\t\t3.Book ticket");
	printf("\n\t\t4.Status of Bus");
	printf("\n\t\t5.Daily Report");
	printf("\n\t\t6.cancelation of ticket");
	printf("\n\t\t7.Exit");
	printf("\n\n\n\tEnter your choice as(1/2/3/4/5):-\t");
	scanf("%d",&Choice);	
	return Choice;
}

int main() {
	
	list k;
	int choice;
	init(&k);/*initializing link list*/	
	while(1) {
		printf("\n\n\tno of buses = %d \n", length(&k));
		choice = printmenu();
		switch(choice) {
		
		case 1: /*adding new bus*/
			fnPrintLine();
			printf("\n\n................................................................................."); 				aaa: printf("\n\t\tplease enter admine passward");
			int pass;
			scanf("%d", &pass);
			if(pass == 1234){

				printf("\n\t\tWelcome\n\n\t");
				Bus *h;
				Bus g;
				g = fnNew_Bus();
				fnEmpty(&g);
				h = &g;
				newbus(&k, h);
				h = NULL;
			}
			
			else {
				printf("Invalid Passward !!!");
				goto aaa;
			}
			
			int a;
			printf("\n\nDo you wan't to continue ? If yes then press 1 ");
			scanf("%d", &a);
			
			if(a == 1){
		 		goto aaa;
				fnPrintLine();
				break;
			}
				
			else{
				fnPrintLine();
				break;
			}
				
		case 2: /*showing available buses*/
			fnPrintLine();
			printf("\n\n................................................................................."); 
			bbb: printf("\n\n\t\tWelcome\n\n\t");
			showbus(&k);
			int b;
			printf("\n\t\tDo you wan't to continue ? If yes then press 1 ");
			scanf("%d", &b);
			if(b == 1) {
				goto bbb;
				fnPrintLine();
				break;		
			}

			else{
				fnPrintLine();
				break;	
			}
	
		case 3: /*ticket booking*/
			fnPrintLine();
			printf("\n\n................................................................................."); 
			printf("\n\n\t\tWelcome");
			ddd: printf("\n\n\t\tEnter your bus no");
   			int z;
			int w = length(&k);
			scanf("%d",&z);
			if(z > w){
				printf("\n\tBus is not available");
				goto ddd;
			}
	
			SeatReservation(&k,z);
			int c;
			printf("\n\t\tDo you wan't to continue ? If yes then press 1 ");
			scanf("%d", &c);
			if(c == 1) {
				goto ddd;			
				fnPrintLine();
				break;
			}

			else{
				fnPrintLine();
				break;
			}	
			
		case 4: /*showing status of asked bus*/
			fnPrintLine();
			printf("\n\n................................................................................."); 
			printf("\n\n\t\tWelcome");
			eee: printf("\n\n\t\tEnter your bus no");
   			int q;
			int u = length(&k);
			scanf("%d",&q);
			if(q > u){
				printf("\n\tBus is not available");
				goto eee;
			}

			fnShowStatus(&k, q);
			int e;
			printf("\n\t\tDo u wan't to continue ? If yes then press 1 ");
			scanf("%d", &e);
			if(e == 1) {
				goto eee;
				fnPrintLine();
				break;
			}

			else{
				fnPrintLine();
				break;
			}	
			
		case 5: /*showing daily report */
			fnPrintLine();
			printf("\n\n................................................................................."); 
			ppp: printf("\n\n\t\tWelcome");
			fnDailyReport(&k);
			int d;
			printf("\n\t\tDo u wan't to continue ? If yes then press 1 ");
			scanf("%d", &d);
			if(d == 1) {
				goto ppp;
				fnPrintLine();
				break;
			}

			else{
				fnPrintLine();
				break;
			}
		
		case 6: /*Cancelling booked ticket*/
			fnPrintLine();
			printf("\n\n.................................................................................\n"); 
			lll: Cancelticket(&k);
			int l;
			printf("\n\t\tDo u wan't to continue ? If yes then press 1 ");
			scanf("%d", &l );
			if(l == 1) {
				goto lll;
				fnPrintLine();
				break;
			}

			else{
				fnPrintLine();
				break;
			}
		
		case 7: /*exit*/
			fnPrintLine();
			printf("\n\n................................................................................."); 
			printf("\n\n\t\tGood Bye");
			fnPrintLine();
			exit(0);

		default:
			printf("\n\n.................................................................................");  
			printf("\t\t\tYou have entered Wrong Choice!!!!");
			fnPrintLine();
			break;
				}
		
		}	
		return 0;
}

Bus fnNew_Bus(){        

	fp = fopen("Bus_Data.txt", "a+");
	Bus d;
	printf("\n\n\t\tEnter Information about bus\n");
	fnPrintLine();
	printf("\n\n\tBus no:%d", Number);
	busN: printf("\n\n\tEnter above Bus Num:\t");
	scanf("%d", &d.BusNum);
	fprintf(fp, "			Bus No : %d", d.BusNum);
	if(d.BusNum == 0){
		printf("\n\t\tInvalid Bus Number!!!!");
		goto busN;
	}

	d.BusNum = Number;
	busC: printf("\n\n\tEnter 4 digit Bus Code:\t");
	scanf("%d", &d.BusCode);
	fprintf(fp, "	Bus Code : %d", d.BusCode);
	if(d.BusCode<1 || d.BusCode>9999){
		printf("\n\t\tInvalid Bus Code!!!!");
		goto busC;
	}

	dname: printf("\n\n\tEnter driver's name:\t");
	scanf("%s", d.chDrivers_Name);
	fprintf(fp, "	Drivers Name : %s", d.chDrivers_Name);
	if(strlen(d.chDrivers_Name) > 20){
	printf("Maximum 20 characters are allowed");
		goto dname;
	}

	time: printf("\n\tEnter arrival time in the format of hrs:min(please don't enter charactors):\t");
	scanf("%d%c%d", &d.Arrival_Time.Hrs, &i, &d.Arrival_Time.Mins);
	fprintf(fp, "	Arrival Time : %d%c%d", d.Arrival_Time.Hrs, i, d.Arrival_Time.Mins);
	if(d.Arrival_Time.Hrs == 0){
		printf("\n\n\t\tInvalid tTme!!!!");
		goto time;
	}

	if((i != ':') || (d.Arrival_Time.Hrs >= 24) || (d.Arrival_Time.Hrs < 0 ) || (d.Arrival_Time.Mins >= 60) || (d.Arrival_Time.Mins < 0)){
		printf("\n\t\tInvalid Time!!!!\n");
		printf("\t\tEnter only--hh:mm!!!!");
		goto time;
	}
			
	deptime: printf("\n\tEnter departure time in the format of hrs:min(please don't enter charactors0):\t");
	scanf("%d%c%d", &d.stDeparture_Time.Hrs, &i, &d.stDeparture_Time.Mins); 
	fprintf(fp, "	DEparture Time : %d%c%d", d.stDeparture_Time.Hrs, i, d.stDeparture_Time.Mins);
	if(d.stDeparture_Time.Hrs == 0){
		printf("\t\tinvalid Time!!!!");
		goto deptime;
	}

	if((i != ':') || (d.stDeparture_Time.Hrs >= 24) || (d.stDeparture_Time.Hrs < 0) || (d.stDeparture_Time.Mins >= 60)  ||(d.stDeparture_Time.Mins < 0 )){
		printf("\n\t\tInvalid Time!!!!");
		printf("\n\t\tEnter only--hh:mm");
		goto deptime;
	}
					
	from: printf("\n\tFrom:\t");
	scanf("%s", d.chGoesFrom);
	fprintf(fp, "	Gose From : %s", d.chGoesFrom );
	if(strlen(d.chGoesFrom) > 20){
		printf("Maximum 20 characters are allowed");
		goto from;
	}

	to: printf("\n\tTo:\t");
	scanf("%s", d.GoesTo);
	fprintf(fp, "	Gose To : %s", d.GoesTo);
	if(strlen(d.GoesTo) > 20){
		printf("Maximum 20 characters are allowed");
		goto to;
	}

	printf("\n\tFare:\t");
	scanf("%f", &d.fFare);
	fprintf(fp, "	Fare : %f", d.fFare);
	fclose(fp);
	d.Ticketsold = 0;
	printf("\n");
	fnPrintLine();
	printf("\n\n\tBus goes from: %s", d.chGoesFrom);
	printf("\n\n\tBus goes to: %s", d.GoesTo);
	Number++;
	return d;
}

