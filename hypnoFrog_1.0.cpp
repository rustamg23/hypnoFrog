#include <windows.h>
#include <iostream>
#include <math.h>

using namespace std;

class Anime 
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	HBRUSH Brush = CreateSolidBrush(RGB(0, 0, 0));
	HPEN Pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
	HPEN Pen1 = CreatePen(PS_SOLID, 5, RGB(255, 255, 63));

public:
	Anime();
	void start();
	void draw(HWND hWnd, HDC hdc, int ySc);
};

Anime::Anime()
{
	start();
}

void Anime::start()
{
	int speed;
	cout << "what speed?" << endl << ':';
	cin >> speed;
	cout << "Exit - Ctrl+C" << endl; system("pause");
	system("cls");
	system("mode con cols=160 lines=73");
	
	while (1)
	{
		for (int j = 0; j < 80; j += 8)
		{
			for (int i = 1; i < 82 - j; i += 5)
			{
				draw(hwnd, hdc, 40 - i);
				if (i % 2) SelectObject(hdc, Pen);
				else SelectObject(hdc, Pen1);
				Sleep(speed);
			}

			for (int i = 79 - j; i > 1; i -= 5)
			{
				draw(hwnd, hdc, 40 - i);
				if (!(i % 2)) SelectObject(hdc, Pen);
				else SelectObject(hdc, Pen1);
				Sleep(speed);
			}
		}
	}
	ReleaseDC(hwnd, hdc);
}


void Anime::draw(HWND hWnd, HDC hdc, int ySc)
{
	
	double x;
	int xScale = 10, yScale = ySc;
	int xO = 300, yO = 300;
	float xBeg = -8.0f, xEnd = 8.0f;
	
	MoveToEx(hdc, xO + xScale * xBeg, yO + yScale * sin(xBeg), NULL);

	for (x = xBeg; x <= xEnd; x += 0.01f)
	{
		LineTo(hdc, xO + xScale * x, yO + yScale * sin(x));
	}
	
	int x1 = 800, y1 = 300;

	MoveToEx(hdc, x1 + xScale * xBeg, y1 + yScale * sin(xBeg), NULL);

	for (x = xBeg; x <= xEnd; x += 0.01f)
	{
		LineTo(hdc, x1 + xScale * x, y1 + yScale * sin(x));
	}

	SelectObject(hdc, GetStockObject(NULL_BRUSH));
	Ellipse(hdc, 200, 200, 400, 400); //глаза
	Ellipse(hdc, 700, 200, 900, 400);
	Ellipse(hdc, 500 + ySc / 2, 500 + ySc / 2, 520, 520 + ySc / 2); //ноздри
	Ellipse(hdc, 580 + ySc / 2, 500 + ySc / 2, 600, 520 + ySc / 2);

	Arc(hdc, 200, 500, 925, 700, 200, 600, 925, 600);
	Arc(hdc, 200, 550, 925, 650, 200, 600, 925, 600);
	
	SetArcDirection(hdc, AD_CLOCKWISE);
	Arc(hdc, 202, 220, 398, 350, 202, 285, 398, 285);
	Arc(hdc, 702, 220, 898, 350, 702, 285, 898, 285);
	Arc(hdc, 167, 100, 500, 475, 50, 450, 655, 250);
	Arc(hdc, 600, 100, 930, 475, 450, 250, 1050, 450);
	Arc(hdc, 425, 260, 675, 420, 380, 100, 720, 100); //переносица
	SetArcDirection(hdc, AD_COUNTERCLOCKWISE);

	Arc(hdc, 100, 100, 1000, 900, 100, 250, 1000, 250);
}

int main()
{
	Anime hfrog;
	return 0;
}






