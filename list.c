#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
void init(list *l) {
	l->head = l->tail = NULL;
	l->length = 0;
}
void showbus(list *l) {
	
	printf("\n\n\t\t\t______________________");
	printf("\n\n\t\t\t BUSES AVALAIBLE");
	printf("\n\n\t\t\t______________________\n");
	printf("\n");
	fnPrintLine();
	printf("Forwards: [ ");
	node *p;
	p = l->head;
	
	while(p != l->tail) {
		printf ("hjgjh");
		printf("\n\t\tbus no-\t\t%d",p->str->BusNum);
		printf("\n\t\tbus code-\t%d",p->str->BusCode);
		printf("\n\t\tDrivers Name-\t%s",p->str->chDrivers_Name);
		printf("\n\t\tFrom-\t\t%s",p->str->chGoesFrom);
		printf("\n\t\tTo-\t\t%s",p->str->GoesTo);
		printf("\n\t\tArrival time-\t%d:%d",p->str->Arrival_Time.Hrs,p->str->Arrival_Time.Mins);
		printf("\n\t\tDeparture time-\t%d:%d",p->str->stDeparture_Time.Hrs,p->str->stDeparture_Time.Mins);
		printf("\n\t\tFare-\t\t%.4f",p->str->fFare);
		printf("\n\t\tTickets Sold-\t%d",p->str->Ticketsold);
		p = p->next;
	}
	if(p) {
		printf("\n\t\tbus no-\t\t%d",p->str->BusNum);
		printf("\n\t\tbus code-\t%d",p->str->BusCode);
		printf("\n\t\tDrivers Name-\t%s",p->str->chDrivers_Name);
		printf("\n\t\tFrom-\t\t%s",p->str->chGoesFrom);
		printf("\n\t\tTo-\t\t%s",p->str->GoesTo);
		printf("\n\t\tArrival time-\t%d%d",p->str->Arrival_Time.Hrs,p->str->Arrival_Time.Mins);
		printf("\n\t\tDeparture time-\t%d%d",p->str->stDeparture_Time.Hrs,p->str->stDeparture_Time.Mins);
		printf("\n\t\tFare-\t\t%.4f",p->str->fFare);
		printf("\n\t\tTickets Sold-\t%d",p->str->Ticketsold);
	printf(" ]\n");
	}
	printf("\n");
		fnPrintLine();
	
	fnMainMenu();
}
/* can insert at positions [0..length] */
/*void insert(list *l, char *str, int pos) {
	node *p, *tmp;
	int i;
	if(pos < 0 || pos > l->length)		
		return;

	tmp = (node *)malloc(sizeof(node));
	tmp->str = (char *)malloc(strlen(str) + 1);
	strcpy(tmp->str, str);
	if(l->head == NULL) {
		tmp->next = tmp->prev = 
		l->head = l->tail = tmp;
		l->length = 1;
		return;
	}
	/* assert: posoitin is =>0 && <= length 
	p = l->head;
	for(i = 0; i < pos - 1; i++)
		p = p->next;
	if(pos == 0)
		p = p->prev;
	/* assert: p points to the node after which we link tmp

	tmp->prev = p;	
	tmp->next = p->next;
	p->next->prev = tmp;
	p->next = tmp;
	if(pos == l->length)
		l->tail = tmp;
	if(pos == 0)
		l->head = tmp;
	(l->length)++;
}*/
char *remov(list *l, int pos) {
	return NULL;
}
void newbus(list *l, Bus *str){
		
	node *tmp;
	tmp = (node *)malloc(sizeof(node));
	tmp-> str = str;
	if(l->head == NULL) {
		tmp->next = NULL;
		l->head = tmp;
		l->tail = tmp;
		l->length = 1;
		return;
	}
	else{
		l->tail->next = tmp;
		l->tail = tmp;
		(l->length)++;	

}
}
int length(list *l) {
	return l->length;	
}
void reverse(list *l) {
	node *p, *q, *r;
	if(l->head == l->tail)
		return;
	if(l->length == 2) {
		p = l->tail;
		l->tail = l->head;
		l->head = p;
		return;
	}		
	q = l->head;
	p = q->next;
	r = p->next;
	while(q != r) {
		p->next = q;
		q = p;	
		p = r;
		r = r->next;
	}
	l->head  = q->next;

	q = l->tail;
	p = q->prev;
	r = p->prev;
	while(q != r) {
		p->prev = q;
		q = p;	
		p = r;
		r = r->prev;
	}
	l->tail = q->prev;
}
/*void sort(list *l) {
	node *p, *q, *tmp, *pnext;
	if(l->head == NULL)
		return;
	p = l->head->next;
	while(p != l->head) {
		//insert p in already sorted list
		q = l->head;
		while(strcmp(q->str, p->str) < 0)
			q = q->next;
		/* q points to the node, before which we have to insert p 
		if(q == p) {
			p = p->next;
			continue;
		}	
		tmp = (node *)malloc(sizeof(node));
		tmp->str = p->str;

		
		//link tmp to before q
		tmp->next = q;
		tmp->prev = q->prev;
		q->prev->next = tmp;
		q->prev = tmp;
		if(q == l->head)
			l->head = tmp;
		//destroy p;	
		p->next->prev = p->prev;
		p->prev->next = p->next;
		pnext = p->next;
		if(p == l->tail)
			l->tail = p->prev;
		free(p);	
		p = pnext;
	}
}
void SeatReservation(list *l) {
	node *p=l->head;
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
	//if(BusN>=p->str->BusNum) {
	//	printf("\n\t\t\tSorry Bus Doesn,t Exist!!!!");
//		fnSeatReservation();
	//	p=p->next;
	//}

	seat: printf("\n\t\tEnter the Seat number-\t");
	scanf("%d",&iSeat);
	if(iSeat>32){
		printf("\n\t\tSorry!! There r only 32 seats in the bus!!!!") ;
		goto seat;
	}
	else if(strcmp(p->str->chSeat[iSeat/4][(iSeat%4)-1],"Empty")==0) {
		printf("\n\t\tEnter the passenger's name-\t");
		name: scanf("%s",chName);
		if(strlen(chName)>20) {
			printf("\n\t\tplz enter only 20 characters!!!!");
			goto name;
		}
		else {
			strcpy(p->str->chSeat[iSeat/4][iSeat%4-1],chName);
			printf("\n\t\tYour seat is reserved now!!");
			p->str->Ticketsold++;
			printf("\n\t do u want to continue with reservation(y/n)??");
			scanf("%c",&Choice);
			//if(Choice=='y'||Choice=='Y')	
				//fnSeatReservation();
			//else
				fnMainMenu();
		}
	}
	else{
		printf("\n\tThis seat is already reserved!!!!");
		printf("\n\t do u want to try again??");
		scanf("%c",&Choice);
		//if(Choice=='y'||Choice=='Y')
		//	fnSeatReservation();
		//else
			fnMainMenu();
	}
	p->str->Ticketsold++;
}
*/
