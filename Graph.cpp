#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int Nodes;
    //Array of list
    list<int> *List;

    public:
    Graph(int Nodes)
    {
        this->Nodes = Nodes;
        List = new list<int>[Nodes];
    }

    void addEdge(int x, int y)
    {
        List[x].push_back(y);
        List[y].push_back(x);
    }

    void printAdjList()
    {
        //Iterate over all the vertices
        for (int i = 0; i < Nodes; i++)
        {
            cout << "Vertex " << i << " -> ";
            for (int j : List[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(9);
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

//Duplicates
    // g.addEdge(1, 0);
    // g.addEdge(2, 1);
    // g.addEdge(3, 2);
    // g.addEdge(4, 3);
    // g.addEdge(5, 2);
    // g.addEdge(5, 3);
    // g.addEdge(5, 4);
    // g.addEdge(6, 5);
    // g.addEdge(7, 1);
    // g.addEdge(7, 6);
    // g.addEdge(8, 2);
    // g.addEdge(8, 6);
    // g.addEdge(8, 7);

    g.printAdjList();
    return 0;
}
