#include <iostream>
using namespace std;

	//declare all the variables here
	int safety_pin, option, recepient, acc_num;
	float acc_balance, withdraw, transfer, deposit, reload;
	string name;
	
	//for the users;
	int safety_pin1 = 1971;		//explain to bryant why his 0000 pin sucks
	string name1 = "Yi Long Mask";
	int acc_num1 = 2203837;
	float acc_balance1 = 20000.00;
	
	int safety_pin2 = 6969;
	string name2 = "Zhong Xina";
	int acc_num2 = 80085;
	float acc_balance2 = 420420.00;
	
	int safety_pin3 = 111;
	string name3 = "Bing Chilling";
	int acc_num3 = 444;
	float acc_balance3 = 111111.00;

void login(){			//login menu
	cout<<"Please enter your safety pin: ";
	cin>>safety_pin;
	if (safety_pin != safety_pin1 and safety_pin != safety_pin2 and safety_pin != safety_pin3){
		do{
			cout<<"Wrong pin. Try again\n";
			cout<<"Enter pin: ";
			cin>>safety_pin;
		}while(safety_pin != safety_pin1 and safety_pin != safety_pin2 and safety_pin != safety_pin3);
	}
}

void showMenu(){		//main menu
	cout<<"\n-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n"
		<<"Choose what to do\n"
		<<"Press 1 for Balance Inquiry\n"
		<<"Press 2 for Money Withdrawal\n"
		<<"Press 3 for Credit Transfer\n"
		<<"Press 4 for Money Deposit\n"
		<<"Press 5 for Touch N Go reload\n"
		<<"Press 0 to  Quit Program\n"
		<<"-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n";;
}

void action(){			//the looping action of atm
	do{
		showMenu();
		cin>>option;	
	
		switch(option){
			case 1:			//account inquiry
				cout<<"Balance Inquiry:\n"
					<<"Your name: "<<name
					<<"\nAccount number: "<<acc_num
					<<"\nAccount balance: RM"<<acc_balance<<endl;
			break;
			
			case 2: 		//withdraw money
				cout<<"Withdraw:\n"
					<<"Account balance: RM"<<acc_balance
					<<"\nWithdraw amount: RM";
				cin>>withdraw;
				
				if (withdraw <= acc_balance){
					acc_balance = acc_balance - withdraw;
						cout<<"\nMoney withdrawal success. The money has been deducted from your account."
							<<"\nYour current account balance is: "<<acc_balance<<endl;
						if (acc_balance == 0){
							cout<<"You have no money now!!";
						}
				}
				else{
					cout<<"The withdrawal amount is too much! Not enough in account balance!";
				}
			break;
	
			case 3: 		//transfer credit
				cout<<"Transfer:\n"
					<<"Account balance: RM"<<acc_balance
					<<"\nTransfer amount: RM";
				cin>>transfer;
				
				if (transfer <= acc_balance){
					acc_balance = acc_balance - transfer;
					cout<<"Transfer to (Enter recipient account number):";
					cin>>recepient;		//this is for when we want to add 3 users
					cout<<"\nMoney transfer success. The money has been deducted from your account."
						<<"\nYour current account balance is: "<<acc_balance<<endl;
						if (acc_balance == 0){
							cout<<"You have no money now!!";
						}
				}
				
				else{
					cout<<"The transfer amount is too much! Not enough in account balance!";
				}
			break;
			
			case 4:		//deposit
				cout<<"Deposit:\n"
					<<"Account balance: RM"<<acc_balance
					<<"\nDeposit amount: RM";
				cin>>deposit;
				acc_balance = acc_balance + deposit;
				cout<<"\nMoney deposit success. The money has been deposited to your account."
					<<"\nYour current account balance is: "<<acc_balance<<endl;
			break;
			
			case 5:		//reload TnG card
				cout<<"Reload Touch 'N Go card:\n"
					<<"Account balance: RM"<<acc_balance
					<<"\nReload Value: RM";
				cin>>reload;
				
				if (reload <= acc_balance){
					acc_balance = acc_balance - transfer;
					cout<<"Reload to (Enter Touch 'N Go card number):";
					cin>>recepient;
					cout<<"\nCard reload success. The money has been deducted from your account."
						<<"\nYour current account balance is: "<<acc_balance<<endl;
						if (acc_balance == 0){
							cout<<"You have no money now!!";
						}
				}
				
				else{
					cout<<"The transfer amount is too much! Not enough in account balance!";
				}
			break;

			case 0:
				cout<<"Thank you for using this program!";
			break;
			
			default:
				cout<<"Sorry, this action cannot be done. Please try again.";
			break;
		}
	}while(option!=0);
}

int main(){
	cout<<"-~-~-~-~-~-~-~-~-~-~-~-~-~-~-Welcome-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n\n";
	login();
	
	if(safety_pin == safety_pin1){
		name = name1;
		acc_num = acc_num1;
		acc_balance = acc_balance1;
		
		cout<<"\nName: "<<name;
		cout<<"\nAccount number: "<<acc_num<<endl;
		
		do{
			action();
		}while(option != 0);
	}
	
	else if(safety_pin == safety_pin2){
		name = name2;
		acc_num = acc_num2;
		acc_balance = acc_balance2;
		
		cout<<"\nName: "<<name;
		cout<<"\nAccount number: "<<acc_num<<endl;
		
		do{
			action();
		}while(option != 0);
	}
	
	else if(safety_pin == safety_pin3){
		name = name3;
		acc_num = acc_num3;
		acc_balance = acc_balance3;
		
		cout<<"\nName: "<<name;
		cout<<"\nAccount number: "<<acc_num<<endl;
		
		do{
			action();
		}while(option != 0);
	}
return 0;
}
