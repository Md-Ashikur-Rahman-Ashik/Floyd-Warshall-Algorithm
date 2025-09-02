#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numberOfNode, numberOfEdge;
    cin >> numberOfNode >> numberOfEdge;
    int adjacencyMatrix[numberOfNode][numberOfNode];

    for (int i = 0; i < numberOfNode; i++)
    {
        for (int j = 0; j < numberOfNode; j++)
        {
            if (i == j)
            {
                adjacencyMatrix[i][j] = 0;
            }
            else
            {
                adjacencyMatrix[i][j] = INT_MAX;
            }
        }
    }

    for (int i = 0; i < numberOfEdge; i++)
    {
        int firstNode, secondNode, cost;
        cin >> firstNode >> secondNode >> cost;
        adjacencyMatrix[firstNode][secondNode] = cost;
    }

    for (int k = 0; k < numberOfNode; k++)
    {
        for (int i = 0; i < numberOfNode; i++)
        {
            for (int j = 0; j < numberOfNode; j++)
            {
                if (adjacencyMatrix[i][k] != INT_MAX && adjacencyMatrix[k][j] != INT_MAX && adjacencyMatrix[i][k] + adjacencyMatrix[k][j] < adjacencyMatrix[i][j])
                {
                    adjacencyMatrix[i][j] = adjacencyMatrix[i][k] + adjacencyMatrix[k][j];
                }
            }
        }
    }

    bool cycle = false;
    for (int i = 0; i < numberOfNode; i++)
    {
        if (adjacencyMatrix[i][i] < 0)
        {
            cycle = true;
        }
    }

    if (cycle)
    {
        cout << "Negative weighted cycle detected" << endl;
    }
    else
    {
        for (int i = 0; i < numberOfNode; i++)
        {
            for (int j = 0; j < numberOfNode; j++)
            {
                if (adjacencyMatrix[i][j] == INT_MAX)
                {
                    cout << "INF" << " ";
                }
                else
                {
                    cout << adjacencyMatrix[i][j] << " ";
                }
            }

            cout << endl;
        }
    }

    return 0;
}