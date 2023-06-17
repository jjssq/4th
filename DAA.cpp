// 1. Implement binary search procedure using divide and conquer method

#include <stdio.h>
#define MAX_SIZE 100

int binarySearch(int arr[], int left, int right, int target)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);
        return binarySearch(arr, mid + 1, right, target);
    }

    return -1;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, target;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    if (n > MAX_SIZE)
    {
        printf("Array size exceeds the maximum limit.\n");
        return 1;
    }
    int arr[MAX_SIZE];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter the target element to search: ");
    scanf("%d", &target);
    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at index %d.\n", result);
    return 0;
}

// 2. Implement divide and conquer method for finding the maximum and minimum number.

#include <iostream>
using namespace std;

void findMaxMin(int arr[], int left, int right, int &maxNum, int &minNum)
{
    if (left == right)
    {

        maxNum = arr[left];
        minNum = arr[left];
    }
    else if (left == right - 1)
    {

        if (arr[left] < arr[right])
        {
            maxNum = arr[right];
            minNum = arr[left];
        }
        else
        {
            maxNum = arr[left];
            minNum = arr[right];
        }
    }
    else
    {
        int mid = (left + right) / 2;
        int maxNum1, maxNum2, minNum1, minNum2;
        findMaxMin(arr, left, mid, maxNum1, minNum1);
        findMaxMin(arr, mid + 1, right, maxNum2, minNum2);
        maxNum = (maxNum1 > maxNum2) ? maxNum1 : maxNum2;
        minNum = (minNum1 < minNum2) ? minNum1 : minNum2;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxNum = arr[0];
    int minNum = arr[0];
    findMaxMin(arr, 0, n - 1, maxNum, minNum);
    cout << "Maximum number: " << maxNum << endl;
    cout << "Minimum number: " << minNum << endl;
    return 0;
}

// 3. Write a program to measure the performance using time function between bubble sort and quick sort

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

void measurePerformance(int n)
{
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    generateRandomArray(arr1, n);
    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr1[i];
    }
    clock_t start, end;
    double timeTaken;

    start = clock();
    bubbleSort(arr1, n);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Bubble Sort:\n";
    cout << "Time taken: " << timeTaken * 1000 << " milliseconds (" << timeTaken << " seconds)\n\n";

    start = clock();
    quickSort(arr2, 0, n - 1);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Quick Sort:\n";
    cout << "Time taken: " << timeTaken * 1000 << " milliseconds (" << timeTaken << " seconds)\n";
    delete[] arr1;
    delete[] arr2;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    measurePerformance(n);
    return 0;
}

// 4. Implement the fractional knapsack problem that will generate an optimal solution for the given set of instance.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int weight;
    int value;
};

bool compareItems(const Item &item1, const Item &item2)
{
    double valuePerUnitWeight1 = double(item1.value) / item1.weight;
    double valuePerUnitWeight2 = double(item2.value) / item2.weight;
    return valuePerUnitWeight1 > valuePerUnitWeight2;
}

double fractionalKnapsack(int capacity, vector<Item> &items)
{
    sort(items.begin(), items.end(), compareItems);
    double totalValue = 0.0;
    int currentWeight = 0;

    for (const Item &item : items)
    {
        if (currentWeight + item.weight <= capacity)
        {
            currentWeight += item.weight;
            totalValue += item.value;
        }
        else
        {
            int remainingCapacity = capacity - currentWeight;
            double fraction = double(remainingCapacity) / item.weight;
            currentWeight += remainingCapacity;
            totalValue += fraction * item.value;
            break;
        }
    }
    return totalValue;
}

int main()
{
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;
    vector<Item> items(numItems);
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < numItems; i++)
    {
        cout << "Item " << i + 1 << ":\n";
        cout << "Weight: ";
        cin >> items[i].weight;
        cout << "Value: ";
        cin >> items[i].value;
    }
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum achievable value: " << maxValue << endl;
    return 0;
}

// 5. Implement the 0/1 knapsack problem that will generate an optimal solutions for the given set of instance such as no of elements n, cost p, and weight wi 5.

#include <iostream>
#include <vector>
using namespace std;

struct Item
{
    int cost;
    int weight;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int capacity, vector<Item> &items)
{
    int n = items.size();
    vector<vector<int>> table(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (items[i - 1].weight <= j)
            {
                table[i][j] = max(items[i - 1].cost + table[i - 1][j - items[i - 1].weight], table[i - 1][j]);
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }
    return table[n][capacity];
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<Item> items(n);
    cout << "Enter the cost and weight of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << ":\n";
        cout << "Cost: ";
        cin >> items[i].cost;
        cout << "Weight: ";
        cin >> items[i].weight;
    }
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    int maxValue = knapsack(capacity, items);
    cout << "Maximum achievable value: " << maxValue << endl;
    return 0;
}

// 6. Write a program to find the minimum cost spanning tree using Prim's algorithm.
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Edge
{
    int source;
    int destination;
    int weight;
};
void primMST(vector<vector<int>> &graph)
{
    int numVertices = graph.size();
    vector<int> parent(numVertices, -1);
    vector<int> minWeight(numVertices, numeric_limits<int>::max());
    vector<bool> inMST(numVertices, false);

    int root = 0;
    minWeight[root] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, root));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (int v = 0; v < numVertices; v++)
        {
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < minWeight[v])
            {
                parent[v] = u;
                minWeight[v] = graph[u][v];
                pq.push(make_pair(minWeight[v], v));
            }
        }
    }

    cout << "Minimum Cost Spanning Tree:\n";
    for (int i = 1; i < numVertices; i++)
    {
        cout << "Edge: " << parent[i] << " - " << i << " \tWeight: " << graph[parent[i]][i]
             << endl;
    }
}

int main()
{
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices));
    cout << "Enter the weight of the edges:\n";
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            cin >> graph[i][j];
        }
    }
    primMST(graph);
    return 0;
}

// 7. Write a program to find the single source shortest path
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Edge
{
    int destination;
    int weight;
};

void dijkstraShortestPath(vector<vector<Edge>> &graph, int source)
{
    int numVertices = graph.size();

    vector<int> distance(numVertices, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (const auto &edge : graph[u])
        {
            int v = edge.destination;
            int weight = edge.weight;
            if (distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    cout << "Shortest Distances from Source Vertex " << source << ":\n";
    for (int i = 0; i < numVertices; i++)
    {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main()
{
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<vector<Edge>> graph(numVertices);
    cout << "Enter the number of edges: ";
    int numEdges;
    cin >> numEdges;
    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < numEdges; i++)
    {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph[source].push_back({destination, weight});
    }
    int sourceVertex;
    cout << "Enter the source vertex: ";
    cin >> sourceVertex;
    dijkstraShortestPath(graph, sourceVertex);
    return 0;
}

// 8. Write a program to implement dynamic programming method for all pair's shortest path problem.

#include <iostream>
using namespace std;
#define nV 4
#define INF 999
void printShortestDistances(int distances[][nV]);
void floydWarshall(int graph[][nV])
{
    int distances[nV][nV], i, j, k;
    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            distances[i][j] = graph[i][j];
    for (k = 0; k < nV; k++)
    {
        for (i = 0; i < nV; i++)
        {
            for (j = 0; j < nV; j++)
            {
                if (distances[i][k] + distances[k][j] < distances[i][j])
                    distances[i][j] = distances[i][k] + distances[k][j];
            }
        }
    }
    printShortestDistances(distances);
}
void printShortestDistances(int distances[][nV])
{
    cout << "Shortest Distances:\n";
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (distances[i][j] == INF)
                cout << "INF\t";
            else
                cout << distances[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{
    int graph[nV][nV] = {{0, 3, INF, 5},
                         {2, 0, INF, 4},
                         {INF, 1, 0, INF},
                         {INF, INF, 2, 0}};
    floydWarshall(graph);
    return 0;
}

// 9. Using backtracking algorithm implement N-queens problem.

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int N)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

bool solveNQueensUtil(vector<vector<int>> &board, int row, int N)
{
    if (row == N)
    {
        return true;
    }
    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col, N))
        {
            board[row][col] = 1;

            if (solveNQueensUtil(board, row + 1, N))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

void solveNQueens(int N)
{
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (solveNQueensUtil(board, 0, N))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution found for N = " << N << endl;
    }
}
int main()
{
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    solveNQueens(N);
    return 0;
}

// 10. Write a program for coloring a graph.

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &graph, vector<int> &colors, int vertex, int color)
{
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[vertex][i] && colors[i] == color)
        {
            return false;
        }
    }
    return true;
}

bool colorGraphUtil(vector<vector<int>> &graph, vector<int> &colors, int vertex, int numColors)
{
    if (vertex == graph.size())
    {
        return true;
    }
    for (int color = 1; color <= numColors; color++)
    {
        if (isSafe(graph, colors, vertex, color))
        {
            colors[vertex] = color;
            if (colorGraphUtil(graph, colors, vertex + 1, numColors))
            {
                return true;
            }
            colors[vertex] = 0;
        }
    }
    return false;
}

void colorGraph(vector<vector<int>> &graph, int numColors)
{
    vector<int> colors(graph.size(), 0);
    if (colorGraphUtil(graph, colors, 0, numColors))
    {
        cout << "Graph can be colored using " << numColors << " colors." << endl;
        cout << "Colors assigned to vertices:" << endl;
        for (int i = 0; i < colors.size(); i++)
        {
            cout << "Vertex " << i << ": Color " << colors[i] << endl;
        }
    }
    else
    {
        cout << "Graph cannot be colored using " << numColors << " colors." << endl;
    }
}
int main()
{
    int numVertices, numColors;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;
    cout << "Enter the number of colors available: ";
    cin >> numColors;
    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));
    cout << "Enter the adjacency matrix representing the graph:" << endl;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            cin >> graph[i][j];
        }
    }
    colorGraph(graph, numColors);
    return 0;
}
