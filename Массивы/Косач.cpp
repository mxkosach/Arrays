#include <iostream>
#include <iomanip>
using namespace std;

void title(int, int = 3, int = 17, char = '=');
int nn = 1;

void myrnd(int[], int, int, int);
void myrnd(double[], int, int, int);
void myout(int[], int, int = -1, int = 4);
void myswap(int&, int&);
void mysrt(int[], int, bool = true);
void transp(int[][10], int);
int scalmult(int[], int[], int);

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));

	{title(nn++);	//1
	const int nv = 100;
	int V[nv];
	const int nrows = 20, ncols = 50;
	double M[nrows][ncols];
	cout << "Размер массива V = " << sizeof(V) << endl
		<< "Размер массива M = " << sizeof(M) << endl;
	}


	{title(nn++);	//2
	const int nx = 5;
	int X[nx];
	cout << "Укажите количество входных данных (max=" << nx << "): ";
	int n; cin >> n;
	for (int i = 0; i < nx; i++)
	{
		if (i == n)
			break;
		cout << "X[" << i << "] = ";
		cin >> X[i];
	}
	cout << "Ввод данных завершён\n";
	}


	{title(nn++);	//3
	int Z[] = { 13,5,0,-3,21,-8,0,7,0,-16,2,0,11,0,-15 };
	int nz = sizeof(Z) / sizeof(Z[0]);
	int sp = 0, sn = 0, n = 0;
	cout << "Массив: ";
	for (int i = 0; i < nz; i++)
	{
		cout << setw(4) << Z[i];
		if (Z[i] > 0)
			sp += Z[i];
		else
			if (Z[i] < 0)
				sn += Z[i];
			else n++;
	}
	cout << endl << setw(22) << left << "Сумма положительных = " << setw(5) << right << sp << endl
		<< setw(22) << left << "Сумма отрицательных = " << setw(5) << right << sn << endl
		<< setw(22) << left << "Число нулей = " << setw(5) << right << n << endl;
	}


	{title(nn++);	//4
	int Z[] = { 13,5,0,-3,21,-8,0,7,0,-16,2,0,11,0,-15 };
	int nz = sizeof(Z) / sizeof(Z[0]);
	int sp = 0, sn = 0, n = 0;
	cout << "Массив: ";
	for (int i = 0; i < nz; i++)
	{
		cout << setw(4) << Z[i];
		if (Z[i] > 0)
		{
			sp += Z[i];
			continue;
		}
		if (Z[i] < 0)
		{
			sn += Z[i];
			continue;
		}
		n++;

	}
	cout << endl << setw(22) << left << "Сумма положительных = " << setw(5) << right << sp << endl
		<< setw(22) << left << "Сумма отрицательных = " << setw(5) << right << sn << endl
		<< setw(22) << left << "Число нулей = " << setw(5) << right << n << endl;
	}


	{title(nn++);	//5
	const int nz = 5;
	int Z[nz];
	cout << "Массив случайных чисел от -100 до 100:\n";
	for (int i = 0; i < nz; i++)
	{
		Z[i] = rand() % 201 - 100;
		cout << setw(5) << Z[i];
	}
	cout << endl;
	}


	{title(nn++);	//6
	const int nx = 20;
	double X[nx];
	cout << "Массив случайных чисел от -3.000 до 5.000:\n";
	for (int i = 0; i < nx; i++)
	{
		X[i] = (rand() % 8001 - 3000) / 1000.;
		cout << fixed << setw(10) << setprecision(3) << right << X[i];
		if ((i + 1) % 5 == 0)
			cout << endl;
	}
	}


	{title(nn++);	//7
	const int na = 20; 	int A[na];
	cout << "Массив случайных одноразрядных целых чисел:\n";
	myrnd(A, na, -9, 9);
	for (int i = 0; i < na; i++)
		cout << setw(3) << A[i];

	const int nb = 10; double B[nb];
	cout << "\n\nМассив случайных вещественных чисел от -37.67 до 69.54\n"
		<< "с двумя цифрами в дробной части:\n";
	myrnd(B, nb, -3782, 6954);
	for (int i = 0; i < nb; i++)
	{
		B[i] /= 100.;
		cout << fixed << setw(7) << setprecision(2) << B[i];
	}
	cout << endl;
	}


	{
		title(nn++);	//8
		const int na = 21; int A[na];
		myrnd(A, na, -9, 9);
		cout << "Вывод в одну строку (4 знакоместа на число):\n";
		myout(A, na);

		myrnd(A, na, -99, 99);
		cout << "Вывод в 6 столбцов (5 знакомест на число):\n";
		myout(A, na, 6, 5);

		myrnd(A, na, -999, 999);
		cout << "\nВывод в 7 столбцов (8 знакомест на число):\n";
		myout(A, na, 7, 8);
	}


	{
		title(nn++);	//9
		int M[5] = { 3,7,2,5,0 };
		cout << "Исходный массив:     "; myout(M, 5);
		if (M[0] > M[1])
			myswap(M[0], M[1]);
		if (M[1] > M[2])
			myswap(M[1], M[2]);
		if (M[2] > M[3])
			myswap(M[2], M[3]);
		if (M[3] > M[4])
			myswap(M[3], M[4]);
		myout(M, 5);

		if (M[0] > M[1])
			myswap(M[0], M[1]);
		if (M[1] > M[2])
			myswap(M[1], M[2]);
		if (M[2] > M[3])
			myswap(M[2], M[3]);
		myout(M, 5);

		if (M[0] > M[1])
			myswap(M[0], M[1]);
		if (M[1] > M[2])
			myswap(M[1], M[2]);
		myout(M, 5);

		if (M[0] > M[1])
			myswap(M[0], M[1]);
		myout(M, 5);

		cout << "Упорядоченный массив:"; myout(M, 5);
	}


	{
		title(nn++);	//10
		const int na = 10; int A[na] = { 6,-5,7,2,-7,-3,8,5,0,4 };
		cout << "Исходный массив:        "; myout(A, na);
		for (int i = na - 1; i > 0; i--)
			for (int j = 0; j < i - 1; j++)
				if (A[j] > A[i])
					myswap(A[j], A[i]);
		cout << "Сортировка по возрастанию:"; myout(A, na);

		mysrt(A, na, 0);
		cout << "Сортировка по убыванию:"; myout(A, na);
	}


	{
		title(nn++);	//11
		const int nrows = 3, ncols = 5;
		int A[nrows][ncols] = {
			{31,74,-58,7,16},
			{74,26,-59,-61,-96},
			{-88,7,14,85,-8}
		};
		cout << "Исходная матрица A\n";
		for (int i = 0; i < nrows; i++)
		{
			for (int j = 0; j < ncols; j++)
				cout << setw(5) << A[i][j];
			cout << endl;
		}

		int mx = A[0][0], imx = 0, jmx = 0;
		for (int i = 0; i < nrows; i++)
			for (int j = 0; j < ncols; j++)
				if (A[i][j] > mx)
				{
					mx = A[i][j]; imx = i; jmx = j;
				}
		cout << "Максимальный элемент A[" << imx << "][" << jmx << "] = " << mx << endl;
	}


	{
		title(nn++);	//12
		const int nrows = 3, ncols = 5;
		int A[nrows][ncols], B[nrows][ncols];

		for (int i = 0; i < nrows; i++)
		{
			myrnd(A[i], ncols, -99, 99);
			myrnd(B[i], ncols, -99, 99);
		}
		cout << "Матрицы A и B:\n";
		for (int i = 0; i < nrows; i++)
		{
			myout(A[i], ncols, ncols + 1);
			cout << "          ";
			myout(B[i], ncols);
		}
		cout << "\nСумма матриц A и B:\n";
		for (int i = 0; i < nrows; i++)
		{
			for (int j = 0; j < ncols; j++)
				cout << setw(5) << (A[i][j] + B[i][j]);
			cout << endl;
		}
	}


	{
		title(nn++);	//13
		const int nr = 20, nc = 10;
		int A[nr][nc], m = 3;
		for (int i = 0; i < m; i++)
			myrnd(A[i], m, -9, 9);
		cout << "Исходная матрица 3x3:" << endl;
		for (int i = 0; i < m; i++)
			myout(A[i], m);
		transp(A, m);
		cout << "Транспонированная матрица 3х3:" << endl;
		for (int i = 0; i < m; i++)
			myout(A[i], m);

		m = 10;
		for (int i = 0; i < m; i++)
			myrnd(A[i], m, -9, 9);
		cout << "Исходная матрица 10x10:" << endl;
		for (int i = 0; i < m; i++)
			myout(A[i], m);
		transp(A, m);
		cout << "Транспонированная матрица 10х10:" << endl;
		for (int i = 0; i < m; i++)
			myout(A[i], m);
	}


	{
		title(nn++);	//14
		//int X[] = { -5,0,1,-4,-7,0,3,9,4,-2,8,9,-2,0,3,-6,-4,0,5,-9 };
		int X[] = { -5,0,1,-4,-7,0,3,9,4,-2,8,9,-2,0,3,-6,-4,0,5,-9,1 };
		int nx = sizeof(X) / sizeof(X[0]);
		cout << "Исходный массив:\n";
		myout(X, nx);

		while (1)
		{
			int n = 0;
			for (int i = 0; i < nx / 2; i++)
				if (X[i] == 0 && X[i + 1] != 0)
				{
					myswap(X[i], X[i + 1]);
					n++;
				}

			for (int i = nx / 2; i < nx; i++)
				if (X[i] == 0 && X[i - 1] != 0)
				{
					myswap(X[i], X[i - 1]);
					n++;
				}
			if (n == 0) break;
		}
		cout << "Итоговый массив:\n";
		myout(X, nx);
	}


	{
		title(nn++); //15
		const int nv = 5;
		int V[nv];
		int n;
		while (1)
		{
			cout << "Введите количество оценок (max=" << nv << "): ";
			cin >> n;
			if (n <= nv)
				break;
			else cout << "Ошибка!\n";
		}
		for (int i = 0; i < n; i++)
		{
			cout << "Оценка №" << i + 1 << " = ";
			cin >> V[i];
			if (V[i] <= 0 || V[i] > 10)
			{
				cout << "Ошибка!\n";
				i--;
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += V[i];
		cout << "\nСредняя экзаменационная оценка = " <<fixed<<setprecision(2)<<1.*sum/n;
	}


	{
		title(nn++); //16
		const int nr = 5;
		int A[nr][nr], B[nr][10];
		cout << "Мартица A:\n";
		for (int i = 0; i < nr; i++)
			myrnd(A[i], nr, 0, 9);
		for (int i = 0; i < nr; i++)
			myout(A[i], nr);
		cout << "Мартица B:\n";
		for (int i = 0; i < nr; i++)
			myrnd(B[i], nr, 0, 9);
		for (int i = 0; i < nr; i++)
			myout(B[i], nr);
		int M[nr][nr];
		transp(B, nr);

		for (int i = 0; i < nr; i++)
			for (int j = 0; j < nr; j++)
				M[i][j] = scalmult(A[i], B[j], nr);
		transp(B, nr);
		cout << "Произведение матриц:\n";
		for (int i = 0; i < nr; i++)
			myout(M[i], nr);
	}


	{
		title(nn++); //17
		const int n = 21;
		int A[n][n] = {};
		int i = n / 2, j = n / 2, k = 1;
		A[i][j] = k;
		while (1)
		{
			int i0 = i, j0 = j, r = rand() % 4;
			if (r == 0)
				j0--;
			else
				if (r == 1)
					i0++;
				else
					if (r == 2)
						j0++;
					else
						i0--;


			if (A[i0][j0] == 0)
			{
				i = i0; j = j0;
				A[i][j] = ++k;
				if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
					break;
				if (A[i - 1][j] != 0 && A[i + 1][j] != 0 && A[i][j - 1] != 0 && A[i][j + 1] != 0)
					break;
			}
		}
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < n; j++)
				if (A[i][j] != 0)
					cout << setw(3) << A[i][j];

				else
					cout << "   ";
			cout << endl;
		}
	}


	cout << endl;
	system("pause");
	return 0;
}

void title(int n, int len1, int len2, char ch)
{
	cout.flags(0); cout << endl;
	for (int i = 0; i < len1; i++) cout << ch;
	cout << " Задание №" << n << " ";
	for (int i = 0; i < len2; i++) cout << ch;
	cout << endl;
}

void myrnd(int M[], int nm, int rmin, int rmax)
{
	for (int i = 0; i < nm; i++)
		M[i] = rmin + rand() % (rmax - rmin + 1);
}

void myrnd(double M[], int nm, int rmin, int rmax)
{
	for (int i = 0; i < nm; i++)
		M[i] = rmin + rand() % (rmax - rmin + 1);
}

void myout(int M[], int nm, int nc, int nw)
{
	if (nc <= 0)
		nc = nm;
	for (int i = 0; i < nm; i++)
	{
		cout << setw(nw) << M[i];
		if ((i + 1) % nc == 0)
			cout << endl;
	}
}

void myswap(int& u, int& v)
{
	if (u == v) return;
	int t = u; u = v; v = t;
}

void mysrt(int X[], int nx, bool inc)
{
	if (inc)
	{	//по возрастанию
		for (int i = nx - 1; i > 0; i--)
			for (int j = 0; j < i - 1; j++)
				if (X[j] > X[i])
					myswap(X[j], X[i]);
	}
	else
	{	//по убыванию
		for (int i = nx - 1; i > 0; i--)
			for (int j = 0; j < i - 1; j++)
				if (X[j] < X[i])
					myswap(X[j], X[i]);
	}
}

void transp(int M[][10], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			myswap(M[i][j], M[j][i]);

}

int scalmult(int A[], int B[], int n)
{
	int ab = 0;
	for (int i = 0; i < n; i++)
	{
		int c = A[i] * B[i];
		ab += c;
	}
	return ab;
}
