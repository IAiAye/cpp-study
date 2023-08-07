/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	// T = 1;
	cin >> T;

	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
        int n, d;
		// n = 5;
		// d = 10;
		cin >> n >> d;

		int cntZero = 0;
        map<int, int> pm;
		vector<int> pv;
        map<int, int> nm;
		vector<int> nv;

		// int arr[5] = {3, 3, 3, -3, -3};

        for (int i = 0; i < n; i++)
        {
            int tmp;

			// tmp = arr[i];
            cin >> tmp;
            if (abs(tmp) > d)
                continue;
			
			if (tmp == 0)
				cntZero++;
            else if (tmp > 0)
			{
				if (pm.find(tmp) == pm.end())
				{
					pm[tmp] = 1;
					pv.push_back(tmp);
				}
				else
					pm[tmp]++;
			}
			else
			{
				if (nm.find(-tmp) == nm.end())
				{
					nm[-tmp] = 1;
					nv.push_back(-tmp);
				}
				else
					nm[-tmp]++;
			}
        }
		sort(pv.begin(), pv.end());
		sort(nv.begin(), nv.end());
		
		for (auto it = pm.begin(); it != pm.end(); ++it)
		{
			auto nextIt = it;
			++nextIt;
			if (nextIt == pm.end())
				break;
			
			nextIt->second += it->second;
		}
		for (auto it = nm.begin(); it != nm.end(); ++it)
		{
			auto nextIt = it;
			++nextIt;
			if (nextIt == nm.end())
				break;
			
			nextIt->second += it->second;
		}
		
		if (!pm.empty())
			Answer = max(Answer, (pm.rbegin())->second);
		if (!nm.empty())
			Answer = max(Answer, (nm.rbegin())->second);

		int size = pv.size();
		for (int i = 0; i < size; i++)
		{
			if (pv[i] > d / 3)
				break;
			
			int d_tmp = d - pv[i] * 2;

			auto it = std::upper_bound(nv.begin(), nv.end(), d_tmp);
			if (it != nv.begin())
			{
				--it;
				Answer = max(Answer, pm[pv[i]] + nm[(*it)]);
			}
			else
				break;
		}

		size = nv.size();
		for (int i = 0; i < size; i++)
		{
			if (nv[i] > d / 3)
				break;
			
			int d_tmp = d - nv[i] * 2;

			auto it = std::upper_bound(pv.begin(), pv.end(), d_tmp);
			if (it != pv.begin())
			{
				--it;
				Answer = max(Answer, nm[nv[i]] + pm[(*it)]);
			}
			else
				break;
		}
		
		Answer += cntZero;
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}