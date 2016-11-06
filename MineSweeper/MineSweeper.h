#pragma once
 
#include<iostream>
#include<random>
#include<time.h>
#include<string>
#include<sstream>
#include<queue>

#define unknown '*'
#define blank '0'
#define mineFlag '!'
#define mine 'X'

using namespace std;

class MineSweeper {
private:
	int size = 22;
	int mineNum =99;
	char** board=nullptr;
	char** base = nullptr;
	int brightSpot = 0;
	int clickFlag = 0;

	void show(char** a);
	int countAround(char key, int x, int y);
	void clickAround(int x, int y);
	void flagAround(int x, int y);
	double circle(int x, int y, double (*func)(int a, int b));

	double getProbility(int x, int y);
	double getMaxProbility(int x, int y);

	int click(int x, int y);
	void setFlag(int x, int y);
	void doubleClick(int x, int y);

	int solve();
public:
	MineSweeper();
	~MineSweeper();

	int run();
	int autoRun();
};