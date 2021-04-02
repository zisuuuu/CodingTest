#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string decToBin(int num)
{
	string result = "";
	for (int i = 1; num > 0; i *= 10)
	{
		int bin = num % 2;
		result += to_string(bin);
		num /= 2;
	}

	reverse(result.begin(), result.end());

	return result;
}

void flip(string& str, int index)
{
	if (str.at(index) == '0')
	{
		str.at(index) = '1';
	}
	else
	{
		str.at(index) = '0';
	}
}

bool isZero(string str)
{
	if (str.find("1") == string::npos)
		return true;

	return false;
}

int rule(int num, bool next_rule1)
{
	string str = decToBin(num);

	int count = 0;
	while (isZero(str) == false)
	{
		if (next_rule1)
		{
			bool accept = false;
			for (int i = str.length() - 1; i > 0; i--)
			{
				if (str.at(i) == '1') // 처음 1을 만나면 i-1 flip
				{
					flip(str, i - 1);

					accept = true;
					break;
				}
			}

			next_rule1 = false;

			if (accept == false)
			{
				count = -1;
				break;
			}
		}
		else
		{
			// 맨 마지막 flip
			flip(str, str.length() - 1);

			next_rule1 = true;
		}
		count++;
	}

	return count;
}

int solution(int num)
{
	int count1 = rule(num, true); // start rule1
	int count2 = rule(num, false); // start rule2

	if (count1 == -1 || count2 == -1)
	{
		return max(count1, count2);
	}
	else
	{
		return min(count1, count2);
	}
}

int main()
{
	int num = 13000000;
	cout << "result : " << solution(num) << endl;

	return 0;
}