#pragma once
#include <string>
using namespace std;


class StringCustom
{
private:
	
public: 
	char firstLine[1024];
	// Конструкторы
	StringCustom(char line)
	{
		setFirstLineChar(line);
	}
	StringCustom(char* line) // 2 Копирование из C-строки
	{
		setFirstLine(line);
	}
	StringCustom(string line) // 3 Копирование из String
	{
		setFirstLineToCString(line.c_str());
	}	
	StringCustom(const char* line)
	{
		setConstFirstLineChar(line);
	}
	//Деструктор
	~StringCustom()
	{
		delete firstLine;
	}
	// Сеттеры
	void setFirstLineToCString(const char* line) // Конвертация в C-строку
	{
		int j = 0;
		for (int i = 0; line[i] != '\0'; i++)
		{
			firstLine[i] = line[i];
			j++;
		}
		firstLine[j] = '\0';
	}
	void setFirstLine(char* line) // Базовое присвоение
	{
		int j = 0;
		for (int i = 0; line[i] != '\0'; i++)
		{
			firstLine[j] = line[i];
			j++;
		}
		firstLine[j] = '\0';
	}
	void setFirstLineChar(char line)
	{
		firstLine[0] = line;
		firstLine[1] = '\0';
	}
	void setConstFirstLineChar(const char* line)
	{
		int j = 0;
		for (int i = 0; line[i] != '\0'; i++)
		{
			firstLine[j] = line[i];
			j++;
		}
		firstLine[j] = '\0';
	}
	// Методы и функции
	int GetLenght() // 1 Вычисление длины строки
	{
		int result = 0;
		for (result = 0; firstLine[result] != '\0'; result++);
		return result;
	}
	char* Copy(int startPosition, int lenght) 	// 2 Копирование
	{
		if (startPosition < 0) startPosition = 0;
		if (lenght <= 0)
		{
			lenght = 0;
			char* resultArray = new char[1];
			resultArray[0] = '\0';
			return resultArray;
		}
		else
		{
			char* resultArray = new char[lenght+1];
			int i = 0;
			int j = 0;
			for (i = startPosition; i < startPosition + lenght; i++)
			{
				resultArray[j] = firstLine[i];
				j++;
			}
			resultArray[j] = '\0';
			return resultArray;
		}		
	}
	char* Delete(int startPosition, int lenght) // 3 Удаление
	{
		if (startPosition < 0) startPosition = 0;
		if (lenght <= 0) lenght = 0;
		StringCustom temp = firstLine;
		int lenghtFirstLine = temp.GetLenght();
		char* resultArray = new char[lenghtFirstLine - lenght + 1];
		int j = 0;
		int i = 0;
		for (i = 0; firstLine[i] != '\0'; i++)
		{
			if (i < startPosition || i > startPosition + lenght - 1)
			{
				resultArray[j] = firstLine[i];
				j++;
			}
		}
		resultArray[j] = '\0';
		return resultArray;
	}
	char* Insert(int startPosition, char* secondLine) // 4 Вставка подстроки
	{
		StringCustom lenght1 = firstLine;
		StringCustom lenght2 = secondLine;
		int firstLineLenght = lenght1.GetLenght();
		int seocondLineLenght = lenght2.GetLenght();
		int i;
		int j = 0;
		int k = 0;
		if (startPosition < 0) startPosition = 0;
		if (startPosition > firstLineLenght) startPosition = firstLineLenght;
		char* resultArray = new char[firstLineLenght + seocondLineLenght];
		for (i = 0; i < firstLineLenght + seocondLineLenght; i++)
		{
			if (i < startPosition || i > startPosition + seocondLineLenght - 1)
			{
				resultArray[i] = firstLine[j];
				j++;
			}
			else
			{
				resultArray[i] = secondLine[k];
				k++;
			}
		}
		resultArray[i] = '\0';
		return resultArray;
	}
	int IndexOf(char* secondLine) // 5 Поиск первого вхождения подстроки
	{
		int result = 0;
		int test = 0;
		int j = 0;
		StringCustom lenght1 = firstLine;
		StringCustom lenght2 = secondLine;
		int firstLineLenght = lenght1.GetLenght();
		int secondLineLenght = lenght2.GetLenght();
		for (int i = 0; i < firstLineLenght; i++)
		{
			if (firstLine[i] == secondLine[j])
			{
				test++;
				j++;
			}
			else
			{
				test = 0;
				j = 0;
			}
			if (test == secondLineLenght)
			{
				result = i - secondLineLenght;
				break;
			}
		}
		if (test == secondLineLenght)
		{
			return result += 1;
		}
		else
		{
			return result = -1;
		}
	}
	int LastIndexOf(char* secondLine) // 6 Поиск последнего вхождения
	{
		StringCustom lenght1 = firstLine;
		StringCustom lenght2 = secondLine;
		int firstLineLenght = lenght1.GetLenght();
		int secondLineLenght = lenght2.GetLenght();
		int result = 0;
		int test = 0;
		int j = secondLineLenght - 1;
		for (int i = firstLineLenght - 1; i >= 0; i--)
		{
			if (firstLine[i] == secondLine[j])
			{
				test++;
				j--;
			}
			else
			{
				test = 0;
				j = secondLineLenght - 1;;
			}
			if (test == secondLineLenght)
			{
				result = i - 1;
				break;
			}
		}
		if (test == secondLineLenght)
		{
			return result += 1;
		}
		else
		{
			return result = -1;
		}
	}
	char* Replace(char* secondLine, char* thirdLine) // 7 Замена подстроки
	{
		StringCustom firstLineTemp = firstLine;
		StringCustom secondLineTemp = secondLine;
		StringCustom thirdLineTemp = thirdLine;
		int firstLineLenght = firstLineTemp.GetLenght();
		int secondLineLenght = secondLineTemp.GetLenght();
		int thirdLineLenght = thirdLineTemp.GetLenght();
		int startPosition = firstLineTemp.IndexOf(secondLine);
		char* resultArray = new char[1024];
		if (startPosition == -1)
		{
			for (int i = 0; i < firstLineLenght; i++)
			{
				resultArray[i] = firstLine[i];
			}
			resultArray[firstLineLenght] = '\0';
		}
		else
		{
			char* temp = new char[1024];
			int i = 0;
			int j = 0;
			int k = 0;
			for (int i = 0; firstLine[i] != '\0'; i++)
			{
				if (i < startPosition || i >= startPosition + secondLineLenght)
				{
					temp[j] = firstLine[i];
					j++;
				}
				temp[j] = '\0';
			}
			j = 0;
			for (i = 0; i < firstLineLenght - secondLineLenght + thirdLineLenght; i++)
			{
				if (i < startPosition || i > startPosition + thirdLineLenght - 1)
				{
					resultArray[i] = temp[j];
					j++;
				}
				else
				{
					resultArray[i] = thirdLine[k];
					k++;
				}
			}
			resultArray[i] = '\0';
			return resultArray;
		}
	}
	char* ReplaceAll(char* secondLine, char* thirdLine) // 8 Замена всех вхождений подстроки
	{
		char* resultArray = new char[1024];
		StringCustom firstLineTemp = firstLine;
		int startPosition = IndexOf(secondLine);
		bool check = true;
		int count = 0;
		while (check == true)
		{
			if (startPosition == -1)
			{
				check = false;
				break;
			}
			else
			{
				if (count == 0)
				{
					resultArray = firstLineTemp.Replace(secondLine, thirdLine);
					StringCustom resultArrayTemp = resultArray;
					startPosition = resultArrayTemp.IndexOf(secondLine);
					count++;
				}
				else
				{
					StringCustom resultArrayTemp = resultArray;
					resultArray = resultArrayTemp.Replace(secondLine, thirdLine);
					resultArrayTemp = resultArray;
					startPosition = resultArrayTemp.IndexOf(secondLine);
				}
			}
		}
		return resultArray;
	}
	// Переопределение операторов
	char operator [] (int position) // 2 [] Получение символа по номеру
	{
		char result = this->firstLine[position];	
		return result;
	}
};
bool operator == (StringCustom line1, StringCustom line2)
{
	int lenghtFirstLine = line1.GetLenght();
	int lenghtSecondLine = line2.GetLenght();
	int codeSum1 = 0;
	int codeSum2 = 0;
	if (lenghtFirstLine != lenghtSecondLine)
	{
		return false;
	}
	else
	{
		for (int i = 0; i != lenghtFirstLine; i++)
		{
			codeSum1 += (int)line1[i];
			codeSum2 += (int)line2[i];
		}
	}
	if (codeSum1 == codeSum2) return true;
	else return false;
	
}




/*
StringCustom operator = (char line)
	{
		setFirstLineChar(line);
	}
	StringCustom operator = (char* line)
	{
		setFirstLine(line);
	}
	StringCustom operator = (string line)
	{
		setFirstLineToCString(line.c_str());
	}
	StringCustom operator = (const char* line)
	{
		setConstFirstLineChar(line);
	}




	StringCustom operator + (StringCustom line1, StringCustom line2)
{
	char* resultArray = new char[1024];
	int startPosition = line1.GetLenght();
	int sum = startPosition + line2.GetLenght();
	int i = 0;
	int j = 0;
	for (i; i < sum; i++)
	{
		if (i < startPosition)
		{
			resultArray[i] = line1[j];
			j++;
		}
		else
		{
			if (i == startPosition) j = 0;
			resultArray[i] = line2[j];
			j++;
		}
	}
	resultArray[i] = '\0';
	StringCustom result = resultArray;
	return result;
}
	

*/