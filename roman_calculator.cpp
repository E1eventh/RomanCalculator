#include <iostream>
#include <string>

using namespace std;

int from_roman(string number)
{
	int size = number.size(), i_number = 0;
	int *arr_n = new int[size];
	
	for(int i = 0; i < size; i++)
	{
		switch (number[i])
		{
			case 'I':
				arr_n[i] = 1;
				break; 
			case 'V':
				arr_n[i] = 5;
				break;
			case 'X':
				arr_n[i] = 10;
				break;
			case 'L':
				arr_n[i] = 50;
				break;
			case 'C':
				arr_n[i] = 100;
				break;
			case 'D':
				arr_n[i] = 500;
				break;
			case 'M':
				arr_n[i] = 1000;
				break;
		}
	}
	
	if(size == 1)
	{
		i_number = arr_n[0];
		return i_number;
	}
	
	for(int i = size - 1; i >= 0; i--)
	{
		if(i != 0)
		{
			if(arr_n[i - 1] < arr_n[i])
			{
				i_number += arr_n[i] - arr_n[i - 1];
				i--;
			}
			else
			{
				i_number += arr_n[i];
			}
		}
		
		else
		{
			i_number += arr_n[i];
		}
	}
	
	return i_number;
}

string to_roman(int number)
{
	string s_number;
	while(number / 1000 > 0)
	{
		s_number.push_back('M');
		number -= 1000;
	}
	
	while(number / 500 > 0)
	{
		if(number / 100 == 9)
		{
			s_number.push_back('C');
			s_number.push_back('M');
		}
		else
			s_number.push_back('D');
		number -= 500;
	}
	
	while(number / 100 > 0)
	{
		if(number / 100 == 4)
		{
			s_number.push_back('C');
			s_number.push_back('D');
		}
		else
			s_number.push_back('Ñ');
		number -= 100;
	}
	
	while(number / 50 > 0)
	{
		if(number / 10 == 9)
		{
			s_number.push_back('X');
			s_number.push_back('C');
		}
		else
			s_number.push_back('L');
		number -= 50;
	}
	
	while(number / 10 > 0)
	{
		if(number / 10 == 4)
		{
			s_number.push_back('X');
			s_number.push_back('L');
		}
		else
			s_number.push_back('X');
		number -= 10;
	}
	
	while(number / 5 > 0)
	{
		if(number == 9)
		{
			s_number.push_back('I');
			s_number.push_back('X');
		}
		else
			s_number.push_back('V');
		number -= 5;
	}
	
	while(number / 1 > 0)
	{
		if(number == 4)
		{
			s_number.push_back('I');
			s_number.push_back('V');
		}
		else
			s_number.push_back('I');
		number--;
	}
	
	return s_number;
}

int main()
{
	string first_n, second_n, oprt, s_answer;
	int i_first_n = 0, i_second_n = 0, i_answer = 0;
	
	cin >> first_n >> oprt >> second_n;
	
	i_first_n = from_roman(first_n);
	i_second_n = from_roman(second_n);
	
	if(oprt[0] == '+')
	{
		i_answer = i_first_n + i_second_n;
	}
	else
	{
		i_answer = i_first_n - i_second_n;
	}
	
	
	if(i_answer == 0)
	{
		cout << 0;
		return 0;
	}
	s_answer = to_roman(i_answer);
	cout << s_answer;
	return 0;
}
