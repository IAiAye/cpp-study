#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(NULL);
	cin.sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    queue <int> deck;
    for (int i = 0; i < n; i++)
    {
        deck.push(i + 1);
    }

    cout << '<';
    while(deck.size() != 1)
    {
        for (int j = 0; j < k - 1; j++)
        {
            deck.push(deck.front());
            deck.pop();
        }
        cout << deck.front() << ", ";
        deck.pop();
    }
    cout << deck.front() << '>';
}