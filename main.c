#include <stdio.h>
#include <string.h>
//atm transaction simulation
int in, out, avail = 10000;
// int pin[100] = {1200, 3189, 1234, 4709};


// can use struct for ease 
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
	printf("Enter amout to transfer\n");
	scanf("%d", &out);
	if(out>avail){
		transfer();
	}
	else{
		avail -= out;
		printf("Amount transferred = %d\nAvailable Balance = %d\n",out,avail);
	}
}

void enquiry(){
	printf("Available balance = %d\n", avail);
}

int main(){
	// int p;
	// print("Enter PIN\n");
	// scanf("%d",&p);
	// for (int i = 0; i<len(pin); i++){
	// 	if (p == pin[i]){	return 1;}
	// 	else{	main();}
	// }
	printf("Welcome to the ATM!\nEnter your choice\n");
	printf("1. Withdrawal\n");
	printf("2. Transfer\n");
	printf("3. Balance Enquiry\n");
	int c;
	scanf("%d", &c);
	switch(c){
		case 1: withdrawal();
				printf("\n");
				return 1;
		case 2: transfer();
				return 1;
		case 3: enquiry();
				return 1;
	}
	return 0;
}

	
