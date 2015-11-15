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
struct time {
int Hrs;
int Mins;
};

typedef struct Bus {
	int BusNum;
	int BusCode;
	char chSeat[8][4][20];	
	char chDrivers_Name[20];
	struct time stDeparture_Time, Arrival_Time;
	char GoesTo[20];
	char chGoesFrom[20];
	float fFare;
	int Ticketsold;
}Bus;

typedef struct node {
	Bus *str;
	struct node *next;
}node;

typedef struct list {
	struct node *head, *tail;
	int length;
}list;

void init(list *l);
void showbus(list *l);
void insert(list *l, Bus *str, int pos);
char *remov(list *l, int pos);
void newbus(list *l, Bus *str);
int length(list *l);
void SeatReservation(list *l, int BusNum);
void fnShowStatus(list *l, int BusNum);
void fnDailyReport(list *l);
void fnEmpty(Bus *str);
void Cancelticket(list *l);
void fnPrintLine();
