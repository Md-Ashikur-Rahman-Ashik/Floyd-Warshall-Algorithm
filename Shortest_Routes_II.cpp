#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int numberOfNode, numberOfEdge, queries;
    cin >> numberOfNode >> numberOfEdge >> queries;

    long long int adjacencyMatrix[numberOfNode + 5][numberOfNode + 5];

    for (int i = 1; i <= numberOfNode; i++)
    {
        for (int j = 1; j <= numberOfNode; j++)
        {
            if (i == j)
            {
                adjacencyMatrix[i][j] = 0;
            }
            else
            {
                adjacencyMatrix[i][j] = LLONG_MAX;
            }
        }
    }

    for (int i = 1; i <= numberOfEdge; i++)
    {
        long long int firstNode, secondNode, length;
        cin >> firstNode >> secondNode >> length;

        adjacencyMatrix[firstNode][secondNode] = min(adjacencyMatrix[firstNode][secondNode], length);
        adjacencyMatrix[secondNode][firstNode] = min(adjacencyMatrix[secondNode][firstNode], length);
    }

    for (int k = 1; k <= numberOfNode; k++)
    {
        for (int i = 1; i <= numberOfNode; i++)
        {
            for (int j = 1; j <= numberOfNode; j++)
            {
                if (adjacencyMatrix[i][k] != LLONG_MAX && adjacencyMatrix[k][j] != LLONG_MAX && adjacencyMatrix[i][k] + adjacencyMatrix[k][j] < adjacencyMatrix[i][j])
                {
                    adjacencyMatrix[i][j] = adjacencyMatrix[i][k] + adjacencyMatrix[k][j];
                }
            }
        }
    }

    for (int i = 0; i < queries; i++)
    {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;

        if (adjacencyMatrix[firstNode][secondNode] == LLONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << adjacencyMatrix[firstNode][secondNode] << endl;
        }
    }

    return 0;
}