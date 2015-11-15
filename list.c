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
FILE *fd;  /*file pointr*/

void init(list *l) {   /*initionlising linklist */

	l->head = NULL;
	l->tail = NULL;
	l->length = 0;
}

void showbus(list *l) { /*shows buses available*/

	printf("\n\n\t\t\t______________________");
	printf("\n\n\t\t\t BUSES AVALAIBLE");
	printf("\n\n\t\t\t______________________\n");
	printf("\n");
	
	node *p = l->head;
	while(p != l->tail) {
		printf("\n\t\tbus no-\t\t%d", p->str->BusNum);
		printf("\n\t\tbus code-\t%d", p->str->BusCode);
		printf("\n\t\tDrivers Name-\t%s", p->str->chDrivers_Name);
		printf("\n\t\tFrom-\t\t%s", p->str->chGoesFrom);
		printf("\n\t\tTo-\t\t%s", p->str->GoesTo);
		printf("\n\t\tArrival time-\t%d:%d", p->str->Arrival_Time.Hrs, p->str->Arrival_Time.Mins);
		printf("\n\t\tDeparture time-\t%d:%d", p->str->stDeparture_Time.Hrs, p->str->stDeparture_Time.Mins);
		printf("\n\t\tFare-\t\t%.4f", p->str->fFare);
		printf("\n\t\tTickets Sold-\t%d", p->str->Ticketsold);
		p = p->next;
	}
	
	if(p) {
		printf("\n\t\tbus no-\t\t%d", p->str->BusNum);
		printf("\n\t\tbus code-\t%d", p->str->BusCode);
		printf("\n\t\tDrivers Name-\t%s", p->str->chDrivers_Name);
		printf("\n\t\tFrom-\t\t%s", p->str->chGoesFrom);
		printf("\n\t\tTo-\t\t%s", p->str->GoesTo);
		printf("\n\t\tArrival time-\t%d:%d", p->str->Arrival_Time.Hrs, p->str->Arrival_Time.Mins);
		printf("\n\t\tDeparture time-\t%d:%d", p->str->stDeparture_Time.Hrs, p->str->stDeparture_Time.Mins);
		printf("\n\t\tFare-\t\t%.4f", p->str->fFare);
		printf("\n\t\tTickets Sold-\t%d", p->str->Ticketsold);
	
	}
	printf("\n");
}

void newbus(list *l, Bus *str){ /*adds bus to linklist*/
		
	node *tmp;
	tmp = (node *)malloc(sizeof(node));
	tmp->str = str;
	if(l->head == NULL && l->tail == NULL && l->length == 0) {
		tmp->next = tmp;
		l->head = tmp;
		l->tail = tmp;
		l->length = 1;
		return;
	}
	
	else{
		l->tail->next = tmp;
		l->tail = tmp;
		(l->length)++;	
		return;
	}
}

int length(list *l) {
	return l->length;	
}

void SeatReservation(list *l, int BusNum) {/*reserve seat of asked bus*/

	int index;
	index = 0;	
	char chName[20];
	int a;
	int b;
	int k;
	int j;
	fd = fopen("Bus.txt", "a+");
	printf("\n\n\t\t\t______________________");
	printf("\n\n\t\t\t ALLOTMENT");
	printf("\n\n\t\t\t______________________\n");
	node *p;
	p = l->head;
	a = 1;
	while(a != BusNum) {
		p = p->next;
		a++;
	} /*takes pointer to the asked bus*/
	
	fprintf(fd, "Bus No : %d", BusNum);
	printf("\n\n");
	for(j = 0; j < 8; j++) {
		printf("\n");
		for(k = 0; k < 4; k++) { 
			index++;
			printf("\t%d .%s\t",index, p->str->chSeat[j][k]);
		}
	}

	abc: printf("Enter your seat no");
	scanf("%d", &b);
	if(b > 32) {
		printf("only 32 seats are available");
		goto abc;
	}
	fprintf(fd, "	Seat No : %d", b);
	if(strcmp(p->str->chSeat[b / 4][(b % 4) - 1], "Empty") == 0) {
		printf("\n\t\tEnter the passenger's name-\t");
		name: scanf("%s", chName);
		if(strlen(chName) > 20) {
			printf("\n\t\tplz enter only 20 characters!!!!");
			goto name;
		}
	
		else {
			strcpy(p->str->chSeat[b / 4][(b % 4) - 1], chName);
			printf("\n\t\tYour seat is reserved now!!");
			p->str->Ticketsold++;
		}
	
	}
	fprintf(fd, "	Passengers Name : %s", chName);
}

void fnShowStatus(list *l, int BusNum) {/*function shows all the status of the asked bus*/	

	int index;
	index = 0;
	int j;
	int k;
	int a;
	fnPrintLine();
	node *p = l->head;
	a = 1;
	while(a != BusNum) {
		p = p->next;
		a++;
	}
	
	printf("\nBus code-\t%d\t\tDriver's Name-\t%s", p->str->BusCode, p->str->chDrivers_Name);
	printf("\nArrival Time-\t%d:%d\t\tDeparture Time\t%d:%d", p->str->Arrival_Time.Hrs, p->str->Arrival_Time.Mins, p->str->stDeparture_Time.Hrs, p->str->stDeparture_Time.Mins);
	printf("\nFrom-\t\t%s\t\tTo-\t\t%s", p->str->chGoesFrom, p->str->GoesTo);
	printf("\nFare-\t\t%f\tTickets Sold-\t%d", p->str->fFare, p->str->Ticketsold);
	printf("\n");
	fnPrintLine();
	printf("\n\n");
	for(j = 0; j < 8; j++) {
		printf("\n");
		for(k = 0; k < 4; k++) {
			index++;
			printf("\t%d .%s\t",index, p->str->chSeat[j][k]);
		}
	}
	printf("\n");
}

void fnDailyReport(list *l) {

	int i = 1;
	double dDailyTotal = 0;
	double dBusTotal = 0;
	printf("\n\n\t\t\t______________________");
	printf("\n\n\t\t\t DAILY REPORT");
	printf("\n\n\t\t\t______________________\n");
	fnPrintLine();
	node *p;
	p = l->head;
	while(p != l->tail) {
		dBusTotal = (p->str->Ticketsold)*(p->str->fFare);
		printf("\n\t\t\tBus no-\t%d\t Total tickets Sold-\t%d", i, p->str->Ticketsold);
		printf("\n\t\t\tTotal Fare-\t%.4lf\n", dBusTotal);
		dDailyTotal += dBusTotal;
		i++;
		p = p->next;
	}
	
	if(p) {
		dBusTotal = (p->str->Ticketsold)*(p->str->fFare);
		printf("\n\t\t\tBus no-\t%d\t Total tickets Sold-\t%d", i, p->str->Ticketsold);
		printf("\n\t\t\tTotal Fare-\t%.4lf\n", dBusTotal);
		dDailyTotal += dBusTotal;
		i++;
	}	
	
	printf("\n\n\t\t\tDaily Total = \t%lf",dDailyTotal);
}

void fnEmpty(Bus *str) { /*function prints empty in all the seats*/

	char chEmpty[] = "Empty";
	int i, j;
	for(i = 0; i < 8; i++) {
		for(j = 0; j < 4; j++) {
			strcpy(str->chSeat[i][j], chEmpty);
		}
	}
}

void Cancelticket(list *l){

	int busno;
	int sno;
	int a;
	int j;
	int k;
	char name[20];
	int index;
	index = 0;	
	fnPrintLine();
	printf("\n\n\t\tEnter your Bus no\n");
	scanf("%d", &busno);
	fnPrintLine();
	node *p = l->head;
	a = 1;
	while(a != busno) {
		p = p->next;
		a++;
	} 
	
	abc: printf("\n\n\t\tEnter your seat no\n");
	scanf("%d", &sno);
	if(sno > 32) {
		printf("only 32 seats are available\n");
		goto abc;
	}
	
	printf("\n\n");
	for(j = 0; j < 8; j++) {
		printf("\n");
		for(k = 0; k < 4; k++) { 
			index++;
			printf("\t%d .%s\t",index, p->str->chSeat[j][k]);
		}
	}
	index = 0;
	name: printf("\n\n\t\tEnter your Name\n");
	scanf("%s", name);
	if(strlen(name) > 20) {
			printf("\n\t\tplz enter only 20 characters!!!!");
			goto name;
	}
	
	if(strcmp(p->str->chSeat[sno / 4][(sno % 4) - 1], name) == 0){
		strcpy(p->str->chSeat[sno / 4][(sno % 4) - 1], "Empty");
		printf("\n\t\tYour ticket  is cancelled now!!");
		p->str->Ticketsold--;
	}
	
	printf("\n\n");
	for(j = 0; j < 8; j++) {
		printf("\n");
		for(k = 0; k < 4; k++) { 
			index++;
			printf("\t%d .%s\t",index, p->str->chSeat[j][k]);
		}
	}
}
void fnPrintLine() { 

	int j;
	for(j = 0;j < 70; j++)
	printf("*");
}
