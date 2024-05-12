#include<iostream>
#include<fstream>
#include<string>
#include<list>
using namespace std;

class Map
{
    int Nodes;
    list<int> *List;

    public:
    Map(int Nodes)
    {
        this->Nodes = Nodes;
        List = new list<int>[Nodes];
    }

    void addEdge(int x, int y)
    {
        List[x].push_back(y);
        List[y].push_back(x);
    }

    void printRoutes()
    {
        for (int i = 0; i < Nodes; i++)
        {
            cout << "Route " << i + 1 << ": " << i << " -> ";
            for (int j : List[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void printTiming()
    {
        double hour1 = 8, hour2 = 8, minute1 = 0, minute2 = 0;

        for(int i = 0; i < Nodes; i++)
        {
            cout << "Route " << i + 1 << ": " << i << " -> ";
            for(int j : List[i])
            {
                cout << j << " ";
            }

            cout << "--> Timing: " << hour1;
            // hour1 += minute1;
            // if(minute1 == 0.60)
            // {
            //     minute1 = 0;
            //     hour1++;
            //     hour1 += minute1;
            // }
            // minute1 += 0.10;

            cout << endl;
        }

        cout << endl;

        for(int i = Nodes - 1; i > -1; i--)
        {
            cout << "Route " << i + 1 << ": " << i << " -> ";
            for(int j : List[i])
            {
                cout << j << " ";
            }

            cout << "--> Timing: " << hour2;
            // hour2 += minute2;
            // if(minute2 == 0.60)
            // {
            //     minute2 = 0;
            //     hour2++;
            //     hour2 += minute2;
            // } 
            // minute2 += 0.10;

            cout << endl;
        }
    }
};

class Dijkstra
{
    public:
    int minDistance(int dist[], bool sptSet[]) 
    {
        int min = INT_MAX, min_index;

        for (int v = 0; v < 9; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;

        return min_index;
    }

    void dijkstra(int graph[9][9], int src, int dest) 
    {
        int dist[9];
        bool sptSet[9];

        for (int i = 0; i < 9; i++)
            dist[i] = INT_MAX, sptSet[i] = false;

        dist[src] = 0;

        for (int count = 0; count < 8; count++) 
        {
            int u = minDistance(dist, sptSet);
            sptSet[u] = true;

            for (int v = 0; v < 9; v++)
                if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
        }

        cout << "Total amount to pay: " << dist[dest] << endl;
        cout << endl;
    }
};

void timing();
void pay();
void cash();
void digw();
void buytkt();
void routes();
void about();

void menu()
{
    int choice;
    cout << "1.Buy Ticket" << endl << "2.Routes" << endl << "3.Timing"<< endl << "4.About" << endl << "5.Exit" << endl;
    cout << ":-"; cin >> choice;

    switch(choice)
    {
        case 1:
            buytkt();
            break;
        case 2:
            routes();
            break;
        case 3:
            timing();
            break;
        case 4:
            about();
            break;
        case 5:
            cout << "Exit!!!" << endl; break;
        default:
            cout << "Invalid choice!!!";
            return menu();
    }
}

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
                    menu();
                    return 1;
                }
                break;
            }
    }

}

void buytkt()
{
    Map g(9);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(2, 8);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 8);
    g.addEdge(6, 7);
    g.addEdge(7, 8);

    cout << endl;
    g.printRoutes();
    cout << endl;

    int graph[9][9] = 
    {
        {0, 10, 0, 0, 0, 0, 0, 0, 0},
        {10, 0, 15, 0, 0, 0, 0, 30, 0},
        {0, 15, 0, 20, 0, 20, 0, 0, 10},
        {0, 0, 20, 0, 15, 10, 0, 0, 0},
        {0, 0, 0, 15, 0, 25, 0, 0, 0},
        {0, 0, 20, 10, 25, 0, 15, 0, 0},
        {0, 0, 0, 0, 0, 15, 0, 15, 10},
        {0, 30, 0, 0, 0, 0, 10, 0, 15},
        {0, 0, 10, 0, 0, 0, 10, 15, 0}
    };

    Dijkstra d;

    int source, destination;
    cout << "Enter starting: ";
    cin >> source;
    cout << "Enter destination: ";
    cin >> destination;

    d.dijkstra(graph, source, destination);
    return pay();
}

void routes()
{
    Map g(9);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(2, 8);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 8);
    g.addEdge(6, 7);
    g.addEdge(7, 8);

    cout << endl;
    g.printRoutes();
    cout << endl;

    return menu();
}

void timing()
{
    Map g(9);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(2, 8);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 8);
    g.addEdge(6, 7);
    g.addEdge(7, 8);

    cout << endl;
    g.printTiming();
    cout << endl;

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
    cout << "Choose payment option: " << endl << "1.Cash\n" << "2.Digital wallet" << endl;
    cout << ":- "; cin >> choice;

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

void about()
{
    cout << "\nMetrorail or metro rail may refer to: Rapid transit, a frequent electric rail system commonly called a metro." << endl;
    cout << "This application is created by SAJID, MUAZ, ABIR\n" << endl;
    return menu();
}