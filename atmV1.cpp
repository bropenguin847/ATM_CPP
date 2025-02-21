/*
* This is version 1 of the C++ ATM
* Features: - Welcome and Login Screen
            - 3 Users
            - Balance Inquiry, Money withdrawal
            - Credit transfer, Money deposit
            - Touch N Go reload, Clear screen

* Developed by: Keith L
*/

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

    //declare all the variables here
    int safety_pin, option, recepient, acc_num;
    float acc_balance, withdraw, transfer, deposit, reload;
    string name;
    
    //for the users;
    int safety_pin1 = 1971;
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

void login()			//login menu
{
    cout<<"Please enter your safety pin: ";
    while(!(cin >> safety_pin))			//filter out chars
    {
        cout <<"This is not integers! Try again!\n";
        cout<<"Enter pin: ";
        cin.clear();                                      
        cin.ignore(123,'\n');
    }
    
    if (safety_pin != safety_pin1 and safety_pin != safety_pin2 and safety_pin != safety_pin3)
    {
        do
        {
            system("color 0c");		//change the terminal color to red, because it looks cool
            cout<<"\a";
            cout<<"Wrong pin. Try again!\n";
            cout<<"Enter pin: ";
            while(!(cin >> safety_pin))			//filter out chars further, trust me, there was a bug here
            {
                cout <<"This is not integers! Try again!\n";
                cout<<"Enter pin: ";
                cin.clear();                                      
                cin.ignore(123,'\n');
            }
        }while(safety_pin != safety_pin1 and safety_pin != safety_pin2 and safety_pin != safety_pin3);
    }
}

void showMenu()			//main menu
{
    cout<<"\n-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n"
        <<"Choose what to do:\n"
        <<"  [1] - Balance Inquiry\n"
        <<"  [2] - Money Withdrawal\n"
        <<"  [3] - Credit Transfer\n"
        <<"  [4] - Money Deposit\n"
        <<"  [5] - Touch N Go reload\n"
        <<"  [6] - Clear screen\n"
        <<"  [0] - Quit Program\n"
        <<"-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n";;
}

void action()			//the looping action of atm
{

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);	

    do
    {
        showMenu();
        while(!(cin >> option))		//filter out chars
        {
            cout <<"This is not integers! Try again!\n";
            cout<<"Choose what to do:\n";
            cin.clear();                                      
            cin.ignore(123,'\n');
        }
    
        switch(option)
        {
            case 1:		//account inquiry
                system("cls");
                cout<<"Balance Inquiry:\n"
                    <<"Your name: "<<name
                    <<"\nAccount number: "<<acc_num
                    <<"\nAccount balance: RM "<<acc_balance<<endl;
            break;
            
            case 2: 	//withdraw money
                cout<<"Withdraw:\n"
                    <<"Account balance: RM "<<acc_balance
                    <<"\nWithdraw amount: RM ";
                    
                while(!(cin >> withdraw))			//filter out chars
                {
                    cout <<"This is not integers! Try again!\n";
                    cin.clear();                                      
                    cin.ignore(123,'\n');
                    cout << "\nWithdraw amount: RM ";
                }
                
                if (withdraw <= acc_balance)
                {
                    acc_balance = acc_balance - withdraw;
                        cout<<"\nMoney withdrawal success. The money has been deducted from your account."
                            <<"\nYour current account balance is: RM "<<acc_balance<<endl;
                        if (acc_balance == 0)
                        {
                            cout<<"You have no money now!!";
                        }
                }
                else{
                    cout<<"The withdrawal amount is too much! Not enough in account balance!";
                }
            break;
    
            case 3: 	//transfer credit
                cout<<"Transfer:\n"
                    <<"Account balance: RM "<<acc_balance
                    <<"\nTransfer amount: RM ";
                    
                while(!(cin >> transfer))			//filter out chars
                {
                    cout <<"This is not integers! Try again!\n";
                    cin.clear();                                      
                    cin.ignore(123,'\n');
                    cout << "\nTransfer amount: RM ";
                }
                
                if (transfer <= acc_balance)
                {
                    acc_balance = acc_balance - transfer;
                    cout<<"Transfer to (Enter recipient account number):";
                    cin>>recepient;
                    cout<<"\nMoney transfer success. The money has been deducted from your account."
                        <<"\nYour current account balance is: RM "<<acc_balance<<endl;
                        if (acc_balance == 0)
                        {
                            cout<<"You have no money now!!";
                        }
                }
                
                else{
                    cout<<"The transfer amount is too much! Not enough in account balance!";
                }
            break;
            
            case 4:		//deposit
                cout<<"Deposit:\n"
                    <<"Account balance: RM "<<acc_balance
                    <<"\nDeposit amount: RM ";
                    
                while(!(cin >> deposit))			//filter out chars
                {
                    cout <<"This is not integers! Try again!\n";
                    cin.clear();                                      
                    cin.ignore(123,'\n');
                    cout << "\nDeposit amount: RM ";
                }
                
                acc_balance = acc_balance + deposit;
                cout<<"\nMoney deposit success. The money has been deposited to your account."
                    <<"\nYour current account balance is: RM "<<acc_balance<<endl;
            break;
            
            case 5:		//reload TnG card
                cout<<"Reload Touch 'N Go card:\n"
                    <<"Account balance: RM "<<acc_balance
                    <<"\nReload Value: RM ";
                    
                while(!(cin >> reload))			//filter out chars
                {
                    cout <<"This is not integers! Try again!\n";
                    cin.clear();                                      
                    cin.ignore(123,'\n');
                    cout << "\nReload Value: RM ";
                }
                
                if (reload <= acc_balance){
                    acc_balance = acc_balance - reload;
                    cout<<"Reload to (Enter Touch 'N Go card number):";
                    cin>>recepient;
                    cout<<"\nCard reload success. The money has been deducted from your account."
                        <<"\nYour current account balance is: RM "<<acc_balance<<endl;
                        if (acc_balance == 0){
                            cout<<"You have no money now!!";
                        }
                }
                
                else{
                    cout<<"The transfer amount is too much! Not enough in account balance!";
                }
            break;
            
            case 6:		//clear screen
                system("cls");
            break;

            case 0:
                cout<<"Thank you for using this program!"<<endl;
                system("pause");
            break;
            
            default:
                cout<<"Sorry, this action cannot be done. Please try again.";
            break;
        }
    }while(option != 0);
}

int main(){
    system("color 0e");		//change the color of the terminal to yellow
    cout<<"-~-~-~-~-~-~-~-~-~-~-~-~-~-~-Welcome-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n";
    cout<<"---------------------------created by BP-------------------------\n";
    login();
    
    system("cls");
    system("color 03");
    
    if(safety_pin == safety_pin1){			//user 1 menu
        name = name1;
        acc_num = acc_num1;
        acc_balance = acc_balance1;
        
        cout<<"\nName: "<<name;
        cout<<"\nAccount number: "<<acc_num<<endl;
        
        do{
            action();
        }while(option != 0);
    }
    
    else if(safety_pin == safety_pin2){		//user 2 menu
        name = name2;
        acc_num = acc_num2;
        acc_balance = acc_balance2;
        
        cout<<"\nName: "<<name;
        cout<<"\nAccount number: "<<acc_num<<endl;
        
        do{
            action();
        }while(option != 0);
    }
    
    else if(safety_pin == safety_pin3){		//user 3 menu
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
