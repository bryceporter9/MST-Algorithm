#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>

using namespace std::chrono;
using namespace std;

const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void initialize()
{
    for (int i = 0; i < MAX; ++i)
        id[i] = i;
}

int root(int x)
{
    while (id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for (int i = 0; i < edges; ++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if (root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main()
{
    //Variables to use for reading in from file
    int x, y;
    long long weight, cost, minimumCost;

    initialize();

    //open the file

    // Use auto keyword to avoid typing long 
    // type definitions to get the timepoint 
    // at this instant use function now() 
    auto start = high_resolution_clock::now();

    //read in nodes (first line in file)

    //read in x and y (both being the node)

    //read in the weight between x and y
        //if 1073741824 there is no direct route, so ignore
        //do not make a pair out of x and y, get next input

    //calculate the number of edges

    cin >> nodes >> edges;
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);

    // After function call 
    auto stop = high_resolution_clock::now();

    // Subtract stop and start timepoints and 
    // cast it to required unit. Predefined units 
    // are nanoseconds, microseconds, milliseconds, 
    // seconds, minutes, hours. Use duration_cast() 
    // function. 
    auto duration = duration_cast<milliseconds>(stop - start);

    // To get the value of duration use the count() 
    // member function on the duration object 
    cout << duration.count() << endl;

    //output the minimum cost

    cout << minimumCost << endl;

    return 0;
}
