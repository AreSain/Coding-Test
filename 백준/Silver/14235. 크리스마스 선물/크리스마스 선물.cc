#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num, temp;
    priority_queue<int, vector<int>, less<int> > pq;
    
    cin >> n;
    while (n > 0)
    {
        cin >> temp;
        if (temp == 0)
        {
            if (pq.empty())
                cout << "-1\n";
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            while (temp > 0)
            {
                cin >> num;
                pq.push(num);
                temp--;
            }
        }
        n--;
    }
}