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
	struct node *next, *prev;
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
void reverse(list *l);
void SeatReservation(list *l);
