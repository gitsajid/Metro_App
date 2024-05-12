#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool IsLoggedIn()
{
    string username, pin, u, p;
    cout << "Enter username: "; cin >> username;
    cout << "Enter PIN: "; cin >> pin;

    ifstream read("E:\\BDU\\Projects\\CSE - 114 - DSA\\" + username + ".txt");
    getline(read, u);
    getline(read, p);

    if(u == username && p == pin) return true;
    else return false;
}

int main()
{
    int choice;
    cout << "1.Create account\n2.Log in" << endl;
    cout << ":-"; cin >> choice;

    switch(choice)
    {
        case 1:
            {
                string username, pin;

                cout << "Username: "; cin >> username;
                cout << "PIN: "; cin >> pin;

                ofstream file;
                file.open("E:\\BDU\\Projects\\CSE - 114 - DSA\\" + username + ".txt");

                file << username << endl << pin;
                file.close();

                main();
                break;
            }
        
        case 2:
            {
                bool status = IsLoggedIn();

                if(!status)
                {
                    cout << "Failed to login" << endl;
                    system("PAUSE");
                    return 0;
                }

                else
                {
                    cout << "Successfully logged in" << endl;
                    system("PAUSE");
                    return 1;
                }
                break;
            }
    }
}
