// 1차원 배열로 표현한 nqueen 문제.
#include <iostream>
int n;
int cnt = 0;
int board[15];

bool check(int k, int i) {
	for (int j = 0; j < k; j++) // 위의 행들을 검사. 즉 k 이전의 인덱스에서 확인.
		if ((i == board[j]) || (k - j == abs(board[j] - i))) 
			return 0;
	return 1;
}
void nq(int k) {
	if (k == n) { // 마지막까지 도달하면 이탈
		cnt++;
		return;
	}
    for (int i = 0; i < n; i++) {
		if (check(k, i)) {
			board[k] = i; // k행의 i열에 퀸이 존재한다는 것을 표시.
			nq(k + 1);
		}
	}
}
int main() {
	std::cin >> n;
	nq(0);
	std::cout << cnt << '\n';
}