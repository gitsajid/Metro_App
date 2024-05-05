#include<iostream>
using namespace std;

void timing();
void buytkt();
void routes();
void user();
void about();

void menu()
{
    int choice;
    cout << "1.Buy tickets" << endl << "2.Timing" << endl << "3.Routes" << endl << "4.User info." << endl << "5.About" << endl << "6.Exit" << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
            buytkt();
            break;
        case 2:
            timing();
            break;
        case 3:
            routes();
            break;
        case 4:
            user();
            break;
        case 5:
            about();
            break;
        case 6:
            cout << "Exit!!!" << endl; break;
        default:
            cout << "Invalid choice!!!";
            return menu();
    }

}

void login()
{
    string name; int PIN;
    cout << "Enter username: ";
    cin >> name;
    cout << "Enter PIN: ";
    cin >> PIN;
    return menu();
}

void createac()
{
    string name; int age, num, PIN;
    cout << "Enter your name: "; cin >> name;
    cout << "Age: "; cin >> age;
    cout << "Number: "; cin >> num;
    cout << "Create a PIN: "; cin >> PIN;
    return menu();
}

int main()
{
    int choice;
    cout << "1.Log in" << endl << "2.Create account" << endl;
    cout << ":-";
    cin >> choice;


    switch(choice)
    {
        case 1:
            login();
            break;
        case 2:
            createac();
            break;
        default:
            cout << "Invalid choice!!!";
            break;
    }

}


void user()
{
    cout << "User information <--->!" << endl;
    return menu();
}

void about()
{
    cout << "Informations of the app and metro will be shown here" << endl;
    return menu();
}

void timing()
{
    cout << "Timings will be shown here" << endl;
    return menu();
}

void cash()
{
    cout << "Insert amount!!!" << endl;
    return menu();
}
void digw()
{
    cout << "Here user need to give information of a digital wallet(Bkash, Nagad, Upay etc) and procced" << endl;
    return menu();
}

void pay()
{
    int choice;
    cout << "Choose payment option: " << endl << "1.Cash\n" << "2.Digital wallet" << endl; cin >> choice;

    switch(choice)
    {
        case 1:
            cash();
            break;
        case 2:
            digw();
            break;
        default:
            cout << "Invalid choice";
            return menu();
    }
}

void routes()
{
    cout << "1.A\n" << "2.B\n" << "3.C\n" << "4.D\n" << "5.E" << endl;
    return menu();
}

void buytkt()
{
    int start, dest, tkt;
    cout << "Routes: " << endl;
    cout << "1.A\n" << "2.B\n" << "3.C\n" << "4.D\n" << "5.E" << endl;
    cout << "Select starting point: "; cin >> start;
    cout << "Select destination: "; cin >> dest;
    cout << "How many tickets do you need: "; cin >> tkt;
    pay();
}