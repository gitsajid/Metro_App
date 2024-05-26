#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<queue>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;

void stationNames(int c);
void timing();
void pay();
void cash();
void digw();
void showShortestPath(int s, int d, int c);
void buytkt();
void routes();
void about();

class Station 
{
    public:
    int n;
    list<Station*> connections;
};

class Metro 
{
    public:
    vector<Station*> stations;

    void addStation(int n) 
    {
        Station* station = new Station();
        station->n = n;
        stations.push_back(station);
    }
    
    void addEdge(int n1, int n2) 
    {
        Station* station1 = findStation(n1);
        Station* station2 = findStation(n2);

        if(station1 && station2) 
        {
            station1->connections.push_back(station2);
            station2->connections.push_back(station1);
        }
    }
   
    Station* findStation(int n) 
    {
        for(Station* station : stations) 
        {
            if(station->n == n) 
            {
                return station;
            }
        }

        return nullptr;
    }
    
    list<Station*> shortestPath(int start, int end) 
    {
        Station* start1 = findStation(start);
        Station* end1 = findStation(end);

        map<Station*, Station*> previous;
        map<Station*, int> distances;
        list<Station*> nodes;

        for(Station* station : stations) 
        {
            if (station == start1) 
            {
                distances[station] = 0;
            } 
            else 
            {
                distances[station] = INT_MAX;
            }
            nodes.push_back(station);
        }

        while(!nodes.empty()) 
        {
            nodes.sort([&distances](Station* a, Station* b) { return distances[a] < distances[b]; });

            Station* smallest = nodes.front();
            nodes.pop_front();

            if (smallest == end1) 
            {
                list<Station*> path;
                while (previous.find(smallest) != previous.end()) 
                {
                    path.push_front(smallest);
                    smallest = previous[smallest];
                }

                path.push_front(start1);

                return path;
            }

            if(distances[smallest] == INT_MAX) 
            {
                break;
            }

            for(Station* neighbor : smallest->connections) 
            {
                int alt = distances[smallest] + 1;

                if(alt < distances[neighbor]) 
                {
                    distances[neighbor] = alt;
                    previous[neighbor] = smallest;
                }
            }
        }

        return list<Station*>();
    }
};

class Map
{
    int Stations;
    list<int> *List;

    public:
    double hour1 = 8, hour2 = 8, minute1 = 0.00, minute2 = 0.00;
    double arr1[9], arr2[9];

    public:
    Map(int Stations)
    {
        this->Stations = Stations;
        List = new list<int>[Stations];
    }

    void addEdge(int x, int y)
    {
        List[x].push_back(y);
        List[y].push_back(x);
    }

    void printRoutes()
    {
        string array[9];
        array[0] = "0. Motijheel";
        array[1] = "1. DU";
        array[2] = "2. Shahbagh";
        array[3] = "3. Kawran Bajar";
        array[4] = "4. Farmgate";
        array[5] = "5. Agargaon";
        array[6] = "6. Mirpur";
        array[7] = "7. Pallabi";
        array[8] = "8. Uttara";

        cout << "*******************" << endl;
        cout << "Station names and its serial number(0 to 8)" << endl;

        for(int i = 0; i < 9; i++) cout << array[i] << endl;

        cout << "*******************" << endl;

        for (int i = 0; i < Stations; i++)
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
        stationNames(3);

        for(int i = 0; i < 9; i++) 
        {
            arr1[i] = hour1 + minute1; minute1 += 0.10;

            if(minute1 > 0.50)
            {
                hour1++; 
                minute1 = 0; 
            }
        }

        for(int j = 8; j > -1; j--)
        {
            arr2[j] = hour2 + minute2; minute2 += 0.10;

            if(minute2 > 0.50)
            {
                hour2++;
                minute2 = 0;
            }
        }

        for(int i = 0; i < Stations; i++)
        {
            cout << "Route " << i + 1 << ": " << i << " -> ";
            for(int j : List[i])
            {
                cout << j << " ";
            }

            cout << "--> Timing: " << arr1[i];

            cout << endl;
        }

        cout << endl;

        for(int i = Stations - 1; i > -1; i--)
        {
            cout << "Route " << i + 1 << ": " << i << " -> ";
            for(int j : List[i])
            {
                cout << j << " ";
            }

            cout << "--> Timing: " << arr2[i];

            cout << endl;
        }
    }
};

class DijkstraCalMinAmount
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

        cout << "\nTotal amount to pay: " << dist[dest] << endl;
        cout << endl;
    }
};

void menu()
{
    int choice;
    cout << "****************" << endl;
    cout << "\nMenu" << endl;
    cout << "1. Buy Ticket" << endl << "2. Available Stations" << endl << "3. Routes" << endl << "4. Timing"<< endl << "5. About" << endl << "6. Exit" << endl;
    cout << ":- "; cin >> choice;
    cout << "\n" << endl;

    switch(choice)
    {
        case 1:
            buytkt();
            break;
        case 2:
            stationNames(2);
            break;
        case 3:
            routes();
            break;
        case 4:
            timing();
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

bool IsLoggedIn()
{
    string username, pin, u, p;
    cout << "Enter username: "; cin >> username;
    cout << "Enter PIN: "; cin >> pin;
    cout << "\n" << endl;

    ifstream read("username&password.txt");
    getline(read, u);
    getline(read, p);

    if(u == username && p == pin) return true;
    else return false;

}

int main()
{
    int choice;
    cout << "1. Create account\n2. Log in" << endl;
    cout << ":- "; cin >> choice;

    switch(choice)
    {
        case 1:
            {
                string username, pin;

                cout << "Username: "; cin >> username;
                cout << "PIN: "; cin >> pin;

                ofstream file;
                file.open("username&password.txt");

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
                    cout << "---Failed to login---" << endl;
                    system("PAUSE");
                    return 0;
                }
                else
                {
                    cout << "---Successfully logged in---" << endl;
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
    
    int graphTime[9][9] = 
    {
        {0, 15, 0, 0, 0, 0, 0, 0, 0},
        {15, 0, 20, 0, 0, 0, 0, 40, 0},
        {0, 20, 0, 25, 0, 25, 0, 0, 15},
        {0, 0, 25, 0, 20, 15, 0, 0, 0},
        {0, 0, 0, 20, 0, 30, 0, 0, 0},
        {0, 0, 25, 15, 30, 0, 20, 0, 0},
        {0, 0, 0, 0, 0, 20, 0, 20, 15},
        {0, 35, 0, 0, 0, 0, 15, 0, 20},
        {0, 0, 15, 0, 0, 0, 15, 20, 0}
    };


    DijkstraCalMinAmount d;

    int source, destination, choice;
    cout << "Enter starting: ";
    cin >> source;
    cout << "Enter destination: ";
    cin >> destination;

    cout << "Do you want to reach your destination: " << endl;
    cout << "1. At shortest time?" << endl;
    cout << "2. At lowest cost?" << endl;
    cout << "Your choice:- "; cin >> choice;

    switch(choice)
    {
        case 1:
            d.dijkstra(graphTime, source, destination);
            break;
        case 2:
            d.dijkstra(graph, source, destination);
            break;
        default:
            cout << "Invalid choice" << endl; 
            return buytkt();
    }

    return showShortestPath(source, destination, choice);
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
    cout << "\nHere user need to give information of a digital wallet(Bkash, Nagad, Upay etc) and procced.\n" << endl;
    return menu();
}

void pay()
{
    int choice;
    cout << "\nChoose payment option: " << endl << "1.Cash\n" << "2.Digital wallet" << endl;
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

void showShortestPath(int s, int d, int c)
{
    int time = 0;

    Metro m;

    for (int i = 0; i < 9; i++) 
    {
        m.addStation(i);
    }

    m.addEdge(0, 1);
    m.addEdge(1, 7);
    m.addEdge(1, 2);
    m.addEdge(2, 3);
    m.addEdge(2, 5);
    m.addEdge(2, 8);
    m.addEdge(3, 4);
    m.addEdge(3, 5);
    m.addEdge(4, 5);
    m.addEdge(5, 6);
    m.addEdge(6, 8);
    m.addEdge(6, 7);
    m.addEdge(7, 8);


    list<Station*> path = m.shortestPath(s, d);

    cout << "Shortest path to the destination: ";
    for (Station* station : path) 
    {
        cout << station->n << " -> ";
        time += 10;
    }

    cout << "End" << endl;

    if(c == 1)
        cout << "Required time is: " << time << " Minutes" << endl;

    return pay();
}

void stationNames(int c)
{
        string array[9];
        array[0] = "0. Motijheel";
        array[1] = "1. DU";
        array[2] = "2. Shahbagh";
        array[3] = "3. Kawran Bajar";
        array[4] = "4. Farmgate";
        array[5] = "5. Agargaon";
        array[6] = "6. Mirpur";
        array[7] = "7. Pallabi";
        array[8] = "8. Uttara";

        cout << "*******************" << endl;
        cout << "Station names and its serial number(0 to 8)" << endl;

        for(int i = 0; i < 9; i++) cout << array[i] << endl;

        cout << "*******************" << endl;

        if(c == 2) return menu();
}

void about()
{
    cout << "\nMetrorail or metro rail may refer to: Rapid transit, a frequent electric rail system commonly called a metro." << endl;
    cout << "This application is created by SAJID, MUAZ, ABIR\n" << endl;
    return menu();
}