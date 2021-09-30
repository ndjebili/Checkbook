#include <iostream>
#include <string>

using namespace std;

#define N 5

struct Check {
    float checkAmount;
    int checkNum;
    string checkMemo;
};

class CheckBook{
    public:
        CheckBook():balance(0), numOfChecks(0){}
        CheckBook(float initBal):balance(initBal), numOfChecks(0){}
        void deposit(float amount){balance+=amount, lastDeposit=amount, cout<<"Last deposit: "<<lastDeposit<<endl;}
        void displayChecks();
        bool writeCheck(float amount);



    private:
        float balance, lastDeposit;
        int numOfChecks, checkLimit = N;
        Check array[N];





};

int main() {
    std::cout << "Hello, World!" << std::endl;
    CheckBook c1(500);
    c1.writeCheck(250);
    c1.deposit(375);
    c1.writeCheck(10);
    c1.deposit(99);
    c1.writeCheck(10000);
    c1.displayChecks();


    return 0;
}


void CheckBook::displayChecks()
{
    for (int i=numOfChecks-1; i>=0; i--)
    {
        cout<<"Check Number: "<<array[i].checkNum<<endl;
        cout<<"Check Amount: "<<array[i].checkAmount<<endl;
        cout<<"Check Memo: "<<array[i].checkMemo<<endl;

    }
}

bool CheckBook::writeCheck(float amount)
{
    if (balance>=amount)
    {
        cout<<"Check memo: "<<endl;
        cin>>array[numOfChecks].checkMemo;
        array[numOfChecks].checkAmount=amount;
        array[numOfChecks].checkNum=numOfChecks+1;
        numOfChecks++;
        balance-=amount;
    }
    else{
        cout<<"Not enough in balance!"<<endl;
        return false;
    }

}