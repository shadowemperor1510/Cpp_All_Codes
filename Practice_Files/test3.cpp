#include <iostream>
#include <map>
#include<vector>
using namespace std;

void perform()
{
    int i, j, n, k;
    map<int, int> u;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> u[i];
    }
    for (i = 0; i < n; i++)
    {
        k=0;
        for (j = 0; j < n; j++)
        {
            if (u[j] == u[i])
            {
                k++;
            }
        }
        if(k<2)
        {
            cout<<u[i]<<endl;
            break;
        }
    }
    cout<<u[i]<<endl;
    cout<<u[j]<<endl;
}

int main()
{
    int t;
    cin >> t;
    int i;
    while (t > 0)
    {
        perform();
        t--;
    }
    return 0;
}