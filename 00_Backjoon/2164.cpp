#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(NULL);
	cin.sync_with_stdio(false);

    int n;
    cin >> n;
    queue <int> deck;
    for (int i = 0; i < n; i++)
    {
        deck.push(i + 1);
    }
    while(deck.size() != 1)
    {
        deck.pop();
        deck.push(deck.front());
        deck.pop();
    }
    cout << deck.front();
}