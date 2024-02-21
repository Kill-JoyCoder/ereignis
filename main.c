#include <stdio.h>
#include <string.h>

//atm transaction simulation
int in, out, avail = 10000;
int PIN[100] = {1200, 3189, 1234, 4709};
// can use struct for ease 

int loadingpage();
void withdrawal();
void transfer();
void enquiry();
void new_account();
int pin();

int main(){
	
	loadingpage();
	switch(c){
		case 1: withdrawal();
				printf("\n");
				return 0;
		case 2: transfer();
				return 0;
		case 3: enquiry();
				return 0;
		case 4: new_account();
				return 0;
		default: return 0;
		}
}




















int loadingpage(){
	printf("Welcome to the ATM!\nEnter your choice\n");
	printf("1. Withdrawal\n");
	printf("2. Transfer\n");
	printf("3. Balance Enquiry\n");
	printf("4. New Account\n");

	int c;
	scanf("%d", &c);
	return c;
}

void withdrawal(){
	printf("Enter the amount to withdraw\n");
	scanf("%d", &out);
	if(out>avail){
		withdrawal();
	}
	else{
		avail -= out;
		printf("Amount withdrawn = %d\nAvailable Balance = %d\n",out,avail);
	}
}

void transfer(){
	int e = pin();
	if (e==0){
		printf("Enter amout to transfer\n");
		scanf("%d", &out);
		if(out<avail){
			avail -= out;
			printf("Amount transferred = %d\nAvailable Balance = %d\n",out,avail);
		}
		else{
			transfer();
		}
	}
	else{
		printf("Wrong PIN, retry!\n");
		transfer();
	}
}

void enquiry(){
	int e = pin();
	if (e == 0){printf("Available balance = %d\n", avail);}
	else{
		printf("Wrong PIN, retry!\n");
		enquiry();
	}
}

void new_account(){
	int nBAL, nPIN;
	printf("Enter your new PIN");
	scanf("%d", &nPIN);
	printf("Enter balance");
	scanf("%d", &nBAL);
}

int pin(){
	int p;
	print("Enter PIN\n");
	scanf("%d",&p);
	for (int i = 0; i<len(PIN); i++){
		if (p == PIN[i])	
			return 0;
	}
}
	
