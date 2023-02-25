#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int N;
    cin >> N;
    float *score = new float[N];
    int subj_score;
    int max_score = -1;
    float sum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> subj_score;
        score[i] = subj_score;
        if (subj_score > max_score)
        {
            max_score = subj_score;
        }
    }
    for (int i = 0; i < N; i++)
    {
        score[i] = score[i] / max_score * 100;
        sum += score[i];
    }
    
    cout << sum / N;

    delete[] score;
    return 0;
}