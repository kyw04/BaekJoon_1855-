#pragma warning(disable: 4996);
#include <iostream>
using namespace std;

int length(char *data)
{
	int i;
	for (i = 0; *(data + i); i++);
	return i;
}

void swap(char *data, int len)
{
	for (int i = 0; i < len / 2; i++)
	{
		char temp = data[i];
 		data[i] = data[len - i - 1];
		data[len - i - 1] = temp;
	}
}
int main()
{
	int n, i, j;
	char str[201];
	char arr[20][201] = {};
	cin >> n;
	cin.ignore();
	cin.getline(str, 200, '\n');
	int t = length(str) / n;
	for (i = 0; i < t; i++)
	{
		for (j = 0; j < n; j++)
		{
			arr[i][j] = str[j];
			str[j] = str[j + n * (i + 1)];
		}
		arr[i][j] = NULL;
		if (i % 2 == 1)
			swap(arr[i], n);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; arr[j][i]; j++)
		{
			cout << arr[j][i];
		}
	}
	return 0;
}