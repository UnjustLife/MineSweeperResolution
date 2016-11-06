#include"MineSweeper.h"

MineSweeper::MineSweeper() {

	board = new char*[size];
	for (int i = 0; i < size; ++i) {
		board[i] = new char[size];
	}
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			board[i][j] = unknown;
		}
	}

	base = new char*[size];
	for (int i = 0; i < size; ++i) {
		base[i] = new char[size];
	}
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			base[i][j] = unknown;
		}
	}
	
	int *rands = new int[size*size];
	for (int j = 0; j < size*size; ++j)
		rands[j] = j;

	//srand(time(0));

	for (int i = 0; i < mineNum; ++i) {
		int randNum = rand() % (size*size - i);
		base[rands[randNum] / size][rands[randNum] % size] = mine;
		rands[randNum] = rands[size*size - 1 - i];
	}

	delete[] rands;
	
	

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (base[i][j] != mine)
				base[i][j] = (char)(countAround(mine,i, j) + 48);
		}
	}



	return;
}
MineSweeper::~MineSweeper() {
	if (board != nullptr) {
		for (int i = 0; i < size; ++i)
			delete[]board[i];
		delete[]board;
		board = nullptr;
	}

	if (base != nullptr) {
		for (int i = 0; i < size; ++i)
			delete[]base[i];
		delete[]base;
		base = nullptr;
	}
}

void MineSweeper::show(char** a) {

	cout << "   ";
	for (int j = 1; j <= size; ++j) {
		if (j < 10)
			cout << j << " ";
		else
			cout <<  j;
	}
	cout << endl;
	for (int i = 0; i < size; ++i) {
		
		if (i < 9)
			cout << i+1 << "  ";
		else
			cout << i+1 << " ";

		for (int j = 0; j < size; ++j) {
			cout << a[i][j];
			cout << " ";
		}
		cout << endl;
	}

	int m = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (base[i][j] == mine)
				++m;
		}
	}
	cout << m << endl;
}
int MineSweeper::countAround(char key,int x, int y) {
	char ** current;
	if (key == mine)
		current = base;
	else
		current = board;

	bool ban[8];
	memset(ban, 0, sizeof(bool) * 8);

	if (x == 0) {
		ban[0] = 1;
		ban[1] = 1;
		ban[2] = 1;
	}
	else if (x == size - 1) {
		ban[4] = 1;
		ban[5] = 1;
		ban[6] = 1;
	}
	if (y == 0) {
		ban[6] = 1;
		ban[7] = 1;
		ban[0] = 1;
	}
	else if (y == size - 1) {
		ban[2] = 1;
		ban[3] = 1;
		ban[4] = 1;
	}

	int keyAround = 0;
	if (!ban[0]) {
		if (current[x - 1][y - 1] == key)
			++keyAround;
	}
	if (!ban[1]) {
		if (current[x - 1][y] == key)
			++keyAround;
	}
	if (!ban[2]) {
		if (current[x - 1][y + 1] == key)
			++keyAround;
	}
	if (!ban[3]) {
		if (current[x][y + 1] == key)
			++keyAround;
	}
	if (!ban[4]) {
		if (current[x + 1][y + 1] == key)
			++keyAround;
	}
	if (!ban[5]) {
		if (current[x + 1][y] == key)
			++keyAround;
	}
	if (!ban[6]) {
		if (current[x + 1][y - 1] == key)
			++keyAround;
	}
	if (!ban[7]) {
		if (current[x][y - 1] == key)
			++keyAround;
	}

	return keyAround;
}
void MineSweeper::clickAround(int x, int y) {
	bool ban[8];
	memset(ban, 0, sizeof(bool) * 8);

	if (x == 0) {
		ban[0] = 1;
		ban[1] = 1;
		ban[2] = 1;
	}
	else if (x == size - 1) {
		ban[4] = 1;
		ban[5] = 1;
		ban[6] = 1;
	}
	if (y == 0) {
		ban[6] = 1;
		ban[7] = 1;
		ban[0] = 1;
	}
	else if (y == size - 1) {
		ban[2] = 1;
		ban[3] = 1;
		ban[4] = 1;
	}

	if (!ban[0] && board[x - 1][y - 1] == unknown)
		click(x - 1, y - 1);
	if (!ban[1] && board[x - 1][y] == unknown) {
		click(x - 1, y);
	}
	if (!ban[2] && board[x - 1][y + 1] == unknown) {
		click(x - 1, y + 1);
	}
	if (!ban[3] && board[x][y + 1] == unknown) {
		click(x, y + 1);
	}
	if (!ban[4] && board[x + 1][y + 1] == unknown) {
		click(x + 1, y + 1);
	}
	if (!ban[5] && board[x + 1][y] == unknown) {
		click(x + 1, y);
	}
	if (!ban[6] && board[x + 1][y - 1] == unknown) {
		click(x + 1, y - 1);
	}
	if (!ban[7] && board[x][y - 1] == unknown) {
		click(x, y - 1);
	}

	return;
}
void MineSweeper::flagAround(int x, int y) {
	bool ban[8];
	memset(ban, 0, sizeof(bool) * 8);

	if (x == 0) {
		ban[0] = 1;
		ban[1] = 1;
		ban[2] = 1;
	}
	else if (x == size - 1) {
		ban[4] = 1;
		ban[5] = 1;
		ban[6] = 1;
	}
	if (y == 0) {
		ban[6] = 1;
		ban[7] = 1;
		ban[0] = 1;
	}
	else if (y == size - 1) {
		ban[2] = 1;
		ban[3] = 1;
		ban[4] = 1;
	}

	if (!ban[0] && board[x - 1][y - 1] == unknown)
		board[x - 1][y - 1] = mineFlag;
	if (!ban[1] && board[x - 1][y] == unknown) {
		board[x - 1][y] = mineFlag;
	}
	if (!ban[2] && board[x - 1][y + 1] == unknown) {
		board[x - 1][y + 1] = mineFlag;
	}
	if (!ban[3] && board[x][y + 1] == unknown) {
		board[x][y + 1] = mineFlag;
	}
	if (!ban[4] && board[x + 1][y + 1] == unknown) {
		board[x + 1][y + 1] = mineFlag;
	}
	if (!ban[5] && board[x + 1][y] == unknown) {
		board[x + 1][y] = mineFlag;
	}
	if (!ban[6] && board[x + 1][y - 1] == unknown) {
		board[x + 1][y - 1] = mineFlag;
	}
	if (!ban[7] && board[x][y - 1] == unknown) {
		board[x][y - 1] = mineFlag;
	}

	return;
}


double MineSweeper::getProbility(int x, int y) {
	if (x >= size || x<0 ||y<0|| y >= size)
		return -1;

	if (!(board[x][y] > '0' && board[x][y] < '9'))
		return -1;
	return (double)((int)board[x][y] - 48 - countAround(mineFlag, x, y)) / countAround(unknown, x, y);
}
double MineSweeper::getMaxProbility(int x, int y) {
	if ( x >= size || x<0 || y<0 || y >= size ||board[x][y] != unknown  )
		return -1;

	double prob = -1;
	double temp;

	if ((temp = getProbility(x - 1, y - 1)) > prob)
		prob = temp;
	if ((temp = getProbility(x - 1, y)) > prob)
		prob = temp;
	if ((temp = getProbility(x - 1, y + 1)) > prob)
		prob = temp;
	if ((temp = getProbility(x, y + 1)) > prob)
		prob = temp;
	if ((temp = getProbility(x + 1, y + 1)) > prob)
		prob = temp;
	if ((temp = getProbility(x + 1, y)) > prob)
		prob = temp;
	if ((temp = getProbility(x + 1, y - 1)) > prob)
		prob = temp;
	if ((temp = getProbility(x, y - 1)) > prob)
		prob = temp;

	return prob;
}



int MineSweeper::click(int x,int y) {
	if (x >= size || x<0 || y<0 || y >= size)
		return 0;

	if (board[x][y] != unknown)
		return 0;

	if (base[x][y] == mine) {
		base[x][y] = 'A';
		cout << x << "," << y << endl;
		return -1;
	}

	
	
	++brightSpot;
	clickFlag = 1;
	
	int mineAround = countAround(mine,x, y);

	if (mineAround == 0) {
		board[x][y] = blank;

		clickAround(x, y);
	}
	else {
		board[x][y] = (char)(mineAround + 48);
	}

	return 1;
}
void MineSweeper::setFlag(int x, int y) {
	if (board[x][y] == unknown)
		board[x][y] = mineFlag;
	else if (board[x][y] == mineFlag)
		board[x][y] = unknown;

	return;
}
void MineSweeper::doubleClick(int x, int y) {
	if (countAround(mineFlag,x, y) != countAround(mine,x, y) || board[x][y] == unknown || board[x][y] == mineFlag)
		return ;

	clickAround(x, y);

	return;
}

int MineSweeper::run() {
	show(board);

	int result = 0;
	char order[20];
	memset(order, ' ', 20 * sizeof(char));

	int exit = 0;
	while (1) {
		try {
			cin.getline(order, 20);
		}
		catch (int a) {
			cout << "Input over 20!";
			continue;
		}

		switch (order[0]) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8': 
		case '9':{
			string strx;
			string stry;

			int i;
			for (i = 0; order[i] != ' '; ++i)
				strx.push_back(order[i]);
			for (++i; order[i] != ' '; ++i)
				stry.push_back(order[i]);

			int x, y;
			stringstream ss;
			ss << strx;
			ss >> x;
			ss.clear();

			ss << stry;
			ss >> y;
			ss.clear();

			if (!((x > 0 && x <= size) && (y > 0 && y <= size)))
				continue;

			result = click(x - 1, y - 1);

			break;
		}
		case 'f': {
			string strx;
			string stry;

			int i;
			for (i = 2; order[i] != ' '; ++i)
				strx.push_back(order[i]);
			for (++i; order[i] != ' '; ++i)
				stry.push_back(order[i]);

			int x, y;
			stringstream ss;
			ss << strx;
			ss >> x;
			ss.clear();

			ss << stry;
			ss >> y;
			ss.clear();

			if (!((x > 0 && x <= size) && (y > 0 && y <= size)))
				continue;

			setFlag(x - 1, y - 1);

			break;
		}
		case 'd': {
			string strx;
			string stry;

			int i;
			for (i = 2; order[i] != ' '; ++i)
				strx.push_back(order[i]);
			for (++i; order[i] != ' '; ++i)
				stry.push_back(order[i]);

			int x, y;
			stringstream ss;
			ss << strx;
			ss >> x;
			ss.clear();

			ss << stry;
			ss >> y;
			ss.clear();

			if (!((x > 0 && x <= size) && (y > 0 && y <= size)))
				continue;

			doubleClick(x - 1, y - 1);

			break;
		}
		case 'q':exit = 1; break;
		case 'a': result = solve();break;
		default: exit = 2; break;
		}

		if (exit == 1) {
			exit = 0;
			break;
		}
		else if (exit == 2) {
			exit = 0;
			continue;
		}

		if (result == -1) {
			show(base);
			cout << "YOU LOSE !" << endl;

			return -1;
		}
		if (brightSpot + mineNum >= size*size) {
			show(board);
			cout << "YOU WIN !" << endl;
			return 1;
		}

		show(board);
	}

	return 0;
}

int MineSweeper::solve() {

	queue<int> boundary;

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (board[i][j] > '0' && board[i][j] < '9') {
				int unknownCount;
				if ((unknownCount=countAround(unknown, i, j)) + countAround(mineFlag, i, j) == (int)board[i][j] - 48)
					flagAround(i, j);
				if (unknownCount != 0)
					boundary.push(i * size + j);
			}
		}
	}

	clickFlag = 0;
	while (!boundary.empty()) {
		doubleClick(boundary.front()/size,boundary.front()%size);
		boundary.pop();
	}

	if (clickFlag == 0) {
		int result = 0;
		//double * prob = new double(size*size);

		//for (int i = 0; i < size; ++i) {
		//	for (int j = 0; j < size; ++j) {
		//		if (board[i][j] == unknown && (countAround(mineFlag, i, j) + countAround(unknown, i, j)) < 8) //可以不获得所有的prob
		//			prob[i * 5 + j] = getMaxProbility(i, j);
		//	}
		//}

		for (int i = 0; i < size; ++i) {
			int forFlag = 0;

			for (int j = 0; j < size; ++j) {
				if (board[i][j] > '0' && board[i][j] < '9' && (countAround(mineFlag, i, j) != ((int)board[i][j] - 48))) {
					double prob[8];
					double minProb = 10;
					int minCount = 0;
					double totalProb = 0;

					prob[0] = getMaxProbility(i - 1, j - 1);
					prob[1] = getMaxProbility(i - 1, j);
					prob[2] = getMaxProbility(i - 1, j + 1);
					prob[3] = getMaxProbility(i, j + 1);
					prob[4] = getMaxProbility(i + 1, j + 1);
					prob[5] = getMaxProbility(i + 1, j );
					prob[6] = getMaxProbility(i + 1, j - 1);
					prob[7] = getMaxProbility(i, j - 1);

					if (i == 6 && j == 17) {
						int fj;
						fj = 1;
						fj = 2;
					}

					for (int k = 0; k < 8; ++k) {
						if (prob[k] != -1) {
							totalProb += prob[k];

							if (prob[k] < minProb) {
								minProb = prob[k];
								minCount = 1;
							}

							else if (prob[k] == minProb) {
								++minCount;
							}

							
						}
					}

					if (totalProb - minProb*minCount >= (((int)board[i][j] - 48)-countAround(mineFlag,i,j))) {

						if (prob[0] == minProb)
							result=click(i - 1, j - 1);
						if (prob[1] == minProb)
							result=click(i - 1, j);
						if (prob[2] == minProb)
							result=click(i - 1, j + 1);
						if (prob[3] == minProb)
							result=click(i, j + 1);
						if (prob[4] == minProb)
							result=click(i + 1, j + 1);
						if (prob[5] == minProb)
							result=click(i + 1, j);
						if (prob[6] == minProb)
							result=click(i + 1, j - 1);
						if (prob[7] == minProb)
							result=click(i, j - 1);

						forFlag = 1;
						break;
					}

				}
					
			}

			if (forFlag == 1)
				break;
		}

		if (result == -1)
			return -1;
	}
	

	if (clickFlag == 0) {
		

		while (clickFlag == 0) {
			int result;
			int randNum = rand() % (size*size);
			while ((result = click(randNum / size, randNum%size)) == 0) {
				randNum = rand() % (size*size);
			}
			
			//cout << randNum / size << "," << randNum%size<<endl;

			if (result == -1) 
				return -1;
		}
	}

	if (brightSpot + mineNum >= size*size) 
		return 1;
	

	return 0;
}
int MineSweeper::autoRun() {
	int result;
	while ((result = solve()) == 0);

	return result;
}