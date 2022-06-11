#include <iostream>
using namespace std;

	//declare all the variables here
	int safety_pin, option, recepient;
	float withdraw, transfer, deposit;
	
	//for the user;
	int safety_pin1 = 1971;		//explain to bryant why his 0000 pin sucks ass
	string name1 = "Yi Long Mask";
	int acc_num1 = 3837;
	float acc_balance1 = 256.00;


void showMenu(){			//this shows the option for user to choose
	cout<<"\n-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n"
		<<"Choose what to do\n"
		<<"Press 1 to check balance\n"
		<<"Press 2 to withdraw money\n"
		<<"Press 3 to transfer credit\n"
		<<"Press 4 to deposit money\n"
		<<"Press 0 to quit program\n"
		<<"-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n";;
}

void login(){
	cout<<"Please enter your safety pin: ";
	cin>>safety_pin;
	if (safety_pin != safety_pin1){
		do{
			cout<<"Wrong pin. Try again\n";
			cout<<"Enter pin: ";
			cin>>safety_pin;
		}while(safety_pin != safety_pin1);
	}
	else{
		cout<<"Name: "<<name1<<"\n";
		cout<<"Account number: "<<acc_num1<<endl;
	}
}

int main(){
	cout<<"-~-~-~-~-~-~-~-~-~-~-~-~-~-~-Welcome-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n\n";
	login();

	do{
		showMenu();
		cin>>option;	
	
		switch(option){		//code a do...while loop
			case 1:			//account inquiry
				cout<<"Inquiry:\n"
					<<"Your name: "<<name1
					<<"\nAccount number: "<<acc_num1
					<<"\nAccount balance: RM"<<acc_balance1<<endl;
			break;
			
			case 2: 		//withdraw money, maybe can use do...while loop
				cout<<"Withdraw:\n"
					<<"Your name: "<<name1
					<<"\nAccount number: "<<acc_num1
					<<"\nAccount balance: RM"<<acc_balance1
					<<"\nWithdraw amount: RM";
				cin>>withdraw;
				
				if (withdraw <= acc_balance1){
					acc_balance1 = acc_balance1 - withdraw;
						cout<<"\nMoney withdrawal success. The money has been deducted from your account.\n"
						<<"Your current account balance is: "<<acc_balance1<<endl;
						if (acc_balance1 == 0){
							cout<<"You have no money now!!";
						}
				}
				else{
					cout<<"The withdrawal amount is too much! Not enough in account balance!";
				}
			break;
	
			case 3: 		//transfer credit
				cout<<"Transfer:\n"
					<<"Your name: "<<name1
					<<"\nAccount number: "<<acc_num1
					<<"\nAccount balance: RM"<<acc_balance1
					<<"\nTransfer amount: RM";
				cin>>transfer;
				
				if (transfer <= acc_balance1){
					acc_balance1 = acc_balance1 - transfer;
					cout<<"Transfer to: (Enter recipient account number):";
					cin>>recepient; //this is for when we want to add 3 users
					cout<<"\nMoney transfer success. The money has been deducted from your account.\n"
						<<"Your current account balance is: "<<acc_balance1<<endl;
						if (acc_balance1 == 0){
							cout<<"You have no money now!!";
						}
				}
				
				else{
					cout<<"The transfer amount is too much! Not enough in account balance!";
				}
			break;
			
			case 4:
				cout<<"Deposit:\n"
					<<"Your name: "<<name1
					<<"\nAccount number: "<<acc_num1
					<<"\nAccount balance: RM"<<acc_balance1
					<<"\nDeposit amount: RM";
				cin>>deposit;
				acc_balance1 = acc_balance1 + deposit;
				cout<<"\nMoney deposit success. The money has been deposited to your account.\n"
					<<"Your current account balance is: "<<acc_balance1<<endl;
			break;

			case 0:
				cout<<"Thank you for using this program!";
			break;
			
			default:
				cout<<"Sorry, this action cannot be done. Please try again.";
			break;
		}
	}while(option!=0);
	
return 0;
}
