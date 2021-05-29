#include <iostream>
#include <math.h>
using namespace std;

class IDS
{
    int depth = 0;
    int branching_Factor;
    int target;
    int edge;
    int vertex;
    int depth_of_graph;
    bool visited[100];
    bool element[100][100];
    int V1[100], V2[100];
    bool flag = false;
public:
    IDS();
    void DFS(int, int);
};


IDS::IDS()
{
    cout << "Enter the number of vertexes: ";
    cin >> vertex;
    cout << "Enter the number of edges: ";
    cin >> edge;
    cout << "Enter branching factor: ";
    cin >> branching_Factor;
    cout << "Enter the depth of graph: ";
    cin >> depth_of_graph;
    cout << "Enter target: ";
    cin >> target;

    //set all element of matrix to zero
    //*******************************************************************
    for (int i=0; i<vertex; i++)
        for (int j=i; j<edge; j++)
        {
            element[i][j] = false;
            element[j][i] = false;
        }


    //Initial the graph
    for(int i=0; i<edge; i++)
    {
        cout << "------------------------------------\n";
        cout<<"The vertex we have edge between them\n";
        cout << "Vertex 1: \t";
        cin >> V1[i];
        cout << "Vertex 2: \t";
        cin >> V2[i];
        element[V1[i]][V2[i]] = true;
    }

    cout << "------------------------------------\n\n";
    cout << "\n\t** Between what vertexes we have edge: **\n";
    for (int i=0; i<edge; i++)
        cout << V1[i] << "-" << V2[i] << " | ";
    cout << endl;

    //print the information
    //******************************************
    cout << "------------------------------------\n\n";
    cout << "\n\t** Matrix of graph **\n";
    for (int i=0; i<vertex; i++)
    {
        for (int j=0; j<vertex; j++)
            cout << element[i][j] << "  ";
        cout << "\n\n";
    }


    //start IDS algorithm
    //****************************************************
    cout << "\n\n** In-depth navigation in graph **\n";
    cout << "----------------------------------\n";
    for (int j=0; j<depth_of_graph; j++)
    {
        int sum = 0;
        for (int i=0; i<=depth; i++)
            sum += pow(branching_Factor, i);
        depth++;

        for (int i=0; i<vertex; i++)
            visited[i] = false;
        DFS(0, sum);
        cout << endl;
    }
    if (flag)
        cout << "\n** Element found **\n";
    else
        cout << "\n** Element NOT found **\n";

    cout << "\n\n  -----------------------\n";
    cout << " | Student: Erfan Riahi  |\n | Student ID: 971490031 |\n | Year: 2020            |\n";
    cout << "  -----------------------";
    //****************************************************
}


void IDS::DFS(int v1, int sum)
{
    if (flag)
        return;
    visited[v1] = true;
    cout << v1 << "->";

    //Find target
    //***************************
    if (v1 == target)
        flag = true;
    //***************************

    for (int v2=0; v2<sum; v2++)
    {
        if (element[v1][v2] == true && visited[v2] == false)
            DFS(v2, sum);
    }
}


int main()
{
    IDS A;
}
