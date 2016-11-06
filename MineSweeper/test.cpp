#include"MineSweeper.h"
#include<Windows.h>
int game() {
	MineSweeper ms = MineSweeper();
	ms.run();

	return 0;
}
int winCount = 0;
int loseCount = 0;

int autoGame() {
	MineSweeper ms = MineSweeper();
	int result;
	if ((result = ms.autoRun()) == 1)
		++winCount;
	else
		++loseCount;

	return 0;
}
int main() {
	
	srand(time(0));
	game();

	string order;
	while (cin >> order) {
		if (order == "exit")
			break;
	else if (order == "new") {
			game();
		}
	}
	
	//srand(time(0));
	//for (int i = 0; i < 10000; ++i) {
	//	autoGame();
	//	if (i % 1000 == 0)
	//		cout << (double)winCount / (double)(winCount + loseCount) * 100 << "%" << endl;
	//}

	

	
	system("pause");

	return 0;
}