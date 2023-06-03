#include <iostream>
#include <string>
using namespace std;

int S, P;
int _A, _C, _G, _T;
int cntA = 0, cntC = 0, cntG = 0, cntT = 0;
string DNA;

void PlusDNA(char &dna)
{
    switch (dna)
    {
    case 'A':
        cntA++;
        break;
    case 'C':
        cntC++;
        break;
    case 'G':
        cntG++;
        break;
    case 'T':
        cntT++;
        break;
    
    default:
        break;
    }
}
void MinusDNA(char &dna)
{
    switch (dna)
    {
    case 'A':
        cntA--;
        break;
    case 'C':
        cntC--;
        break;
    case 'G':
        cntG--;
        break;
    case 'T':
        cntT--;
        break;
    
    default:
        break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> S >> P >> DNA;
    std::cin >> _A >> _C >> _G >> _T;

    int start = 0;
    int end = P - 1;
    int ans = 0;

    for (int i = start; i <= end; i++)
    {
        PlusDNA(DNA[i]);
    }

    int cnt = S - P + 1;
    while (cnt--)
    {
        if (cntA >= _A && cntC >= _C && cntG >= _G && cntT >= _T)
        {
            ans++;
        }
        MinusDNA(DNA[start]);
        start++;
        end++;
        PlusDNA(DNA[end]);

    }
    
    std::cout << ans << '\n';

    return 0;
}