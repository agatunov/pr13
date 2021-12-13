#include <iostream>
#include <string>
#include "StringLine.h"

StringLine::StringLine() // Конструктор из пустой строки
{
	str = new char[1];
	str[0] = '\0';
	strLenght = 0;
}
StringLine::StringLine(const char* line) // Конструктор из C-строки
{
	for (strLenght = 0; line[strLenght] != '\0'; strLenght++);
	str = new char[strLenght+1];
	for (int i = 0; i < strLenght; i++) str[i] = line[i];
	str[strLenght] = '\0';
}
StringLine::StringLine(string line) // Конструктор из String
{
	strLenght = line.length();
	str = new char[strLenght+1];
	const char* temp = line.c_str();
	for (int i = 0; i < strLenght; i++) str[i] = temp[i];	
	str[strLenght] = '\0';
}
StringLine::~StringLine() // Деструктор
{
	delete str;
}
StringLine& StringLine::operator=(const StringLine& line) // Оператор присвоения
{
	if (this != &line)
	{
		strLenght = line.strLenght;
		this->str = new char[strLenght + 1];
		for (int i = 0; i <= strLenght; i++) str[i] = line.str[i];
	}
	return *this;
}
char StringLine::operator[](int i) // Получение символа по номеру
{
	return this->str[i];
}
StringLine operator+(const StringLine& firstLine, const StringLine& secondLine)
{
	StringLine* result = new StringLine;
	*result = firstLine;
	return *result += secondLine;
}
bool StringLine::operator==(const StringLine& line)
{
	int firstLineLenght = this->strLenght;
	int secondLineLenght = line.strLenght;
	int firstLineSum = 0;
	int secondLineSum = 0;
	for (int i = 0; i < firstLineLenght; i++) firstLineSum += (int)this->str[i];
	for (int i = 0; i < secondLineLenght; i++) secondLineSum += (int)line.str[i];
	if (firstLineSum == secondLineSum) return true;
	else return false;
}
bool StringLine::operator!=(const StringLine& line)
{
	int firstLineLenght = this->strLenght;
	int secondLineLenght = line.strLenght;
	int firstLineSum = 0;
	int secondLineSum = 0;
	for (int i = 0; i < firstLineLenght; i++) firstLineSum += (int)this->str[i];
	for (int i = 0; i < secondLineLenght; i++) secondLineSum += (int)line.str[i];
	if (firstLineSum == secondLineSum) return false;
	else return true;
}
bool StringLine::operator>(const StringLine& line)
{
	int firstLineLenght = this->strLenght;
	int secondLineLenght = line.strLenght;
	int firstLineSum = 0;
	int secondLineSum = 0;
	for (int i = 0; i < firstLineLenght; i++) firstLineSum += (int)this->str[i];
	for (int i = 0; i < secondLineLenght; i++) secondLineSum += (int)line.str[i];
	if (firstLineSum > secondLineSum) return true;
	else return false;
}
bool StringLine::operator<(const StringLine& line)
{
	int firstLineLenght = this->strLenght;
	int secondLineLenght = line.strLenght;
	int firstLineSum = 0;
	int secondLineSum = 0;
	for (int i = 0; i < firstLineLenght; i++) firstLineSum += (int)this->str[i];
	for (int i = 0; i < secondLineLenght; i++) secondLineSum += (int)line.str[i];
	if (firstLineSum < secondLineSum) return true;
	else return false;
}
bool StringLine::operator>=(const StringLine& line)
{
	int firstLineLenght = this->strLenght;
	int secondLineLenght = line.strLenght;
	int firstLineSum = 0;
	int secondLineSum = 0;
	for (int i = 0; i < firstLineLenght; i++) firstLineSum += (int)this->str[i];
	for (int i = 0; i < secondLineLenght; i++) secondLineSum += (int)line.str[i];
	if (firstLineSum >= secondLineSum) return true;
	else return false;
}
bool StringLine::operator<=(const StringLine& line)
{
	int firstLineLenght = this->strLenght;
	int secondLineLenght = line.strLenght;
	int firstLineSum = 0;
	int secondLineSum = 0;
	for (int i = 0; i < firstLineLenght; i++) firstLineSum += (int)this->str[i];
	for (int i = 0; i < secondLineLenght; i++) secondLineSum += (int)line.str[i];
	if (firstLineSum <= secondLineSum) return true;
	else return false;
}
ostream& operator<<(ostream& os, const StringLine& line)
{
	os << line.str;
	return os;
}
istream& operator>>(istream& is, StringLine& line)
{
	char buff[1024];
	cin.getline(buff, sizeof buff);
	line = buff;
	return is;
}
StringLine& StringLine::operator+=(const StringLine& line)
{
	int lenght = this->GetLenght() + line.strLenght;
	char* temp = new char[lenght + 1];
	for (int i = 0; i < this->GetLenght(); i++) temp[i] = this->str[i];
	int j = 0;
	for (int i = this->GetLenght(); i <= lenght; i++)
	{
		temp[i] = line.str[j];
		j++;
	}
	delete this->str;
	this->str = temp;
	this->strLenght = lenght;
	return *this;
}
int StringLine::GetLenght() // Получение длины
{
	return this->strLenght;

}
StringLine& StringLine::Copy(int startPosition, int lenght) // Копирование
{
	StringLine* result = new StringLine;
	if (startPosition < 0) startPosition = 0;
	if (lenght < 0) lenght = 0;
	if (lenght == 0)
	{
		char* resultArray = new char[1];
		resultArray[0] = '\0';
		result->str = resultArray;
		return *result;
	}
	else
	{
		int i = 0;
		int j = 0;
		char* resultArray = new char[lenght + 1];
		for (i = startPosition; i < startPosition + lenght; i++)
		{
			resultArray[j] = this->str[i];
			j++;
		}
		resultArray[j] = '\0';
		result->str = resultArray;
		result->strLenght = j;
		return *result;
	}
} 
StringLine& StringLine::Delete(int startPosition, int lenght) // Удаление
{
	StringLine* result = new StringLine;
	if (startPosition < 0) startPosition = 0;
	if (lenght < 0) lenght = 0;
	char* resultArray = new char[lenght + 1];
	int i = 0;
	int j = 0;
	for (i = 0; this->str[i] != '\0'; i++)
	{
		if (i < startPosition || i > startPosition + lenght - 1)
		{
			resultArray[j] = this->str[i];
			j++;
		}
	}
	resultArray[j] = '\0';
	result->str = resultArray;
	result->strLenght = j;
	return *result;
}
StringLine& StringLine::Insert(int startPosition, StringLine insertLine)
{
	StringLine* result = new StringLine;
	int firstLineLenght = this->GetLenght();
	int secondLineLenght = insertLine.GetLenght();
	char* resultArray = new char[firstLineLenght + secondLineLenght + 1];
	int i = 0;
	int j = 0;
	int k = 0;
	if (startPosition < 0) startPosition = 0;
	if (startPosition > firstLineLenght) startPosition = firstLineLenght;
	for (i = 0; i < firstLineLenght + secondLineLenght; i++)
	{
		if (i < startPosition || i > startPosition + secondLineLenght - 1)
		{
			resultArray[i] = this->str[j];
			j++;
		}
		else
		{
			resultArray[i] = insertLine.str[k];
			k++;
		}
	}
	resultArray[i] = '\0';
	result->str = resultArray;
	result->strLenght = i;
	return *result;
}
int StringLine::IndexOf(StringLine& line) // Поиск вхождения
{
	int result = 0;
	int test = 0;
	int j = 0;
	int firstLineLenght = this->GetLenght();
	int secondLineLenght = line.GetLenght();
	for (int i = 0; i < firstLineLenght; i++)
	{
		if (this->str[i] == line.str[j])
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
	if (test == secondLineLenght) return result += 1;
	else return result = -1;
}
int StringLine::LastIndexOf(StringLine& line) // Поиск последнего вхождения
{
	int firstLineLenght = this->GetLenght();
	int secondLineLenght = line.GetLenght();
	int result = 0;
	int test = 0;
	int j = secondLineLenght - 1;
	for (int i = firstLineLenght - 1; i >= 0; i--)
	{
		if (this->str[i] == line.str[j])
		{
			test++;
			j--;
		}
		else
		{
			test = 0;
			j = secondLineLenght - 1;
		}
		if (test == secondLineLenght)
		{
			result = i - 1;
			break;
		}
	}
	if (test == secondLineLenght) return result += 1;
	else return result = -1;	
}
StringLine& StringLine::Replace(StringLine& secondLine, StringLine& thirdLine) // Замена
{
	StringLine *result = new StringLine;
	int firstLineLenght = this->GetLenght();
	int secondLineLenght = secondLine.GetLenght();
	int thirdLineLenght = thirdLine.GetLenght();
	char* resultArray = new char[firstLineLenght - secondLineLenght + thirdLineLenght + 1];
	int startPosition = this->IndexOf(secondLine);
	if (startPosition == -1)
	{
		for (int i = 0; i < firstLineLenght; i++)
		{
			resultArray[i] = this->str[i];
		}
		resultArray[firstLineLenght] = '\0';
		result->str = resultArray;
		result->strLenght = firstLineLenght;
		return *result;
	}
	else
	{
		char temp[1024];
		int i = 0;
		int j = 0;
		int k = 0;
		for (i = 0; this->str[i] != '\0'; i++)
		{
			if (i < startPosition || i >= startPosition + secondLineLenght)
			{
				temp[j] = this->str[i];
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
				resultArray[i] = thirdLine.str[k];
				k++;
			}
		}
		resultArray[i] = '\0';
		result->strLenght = i;
		delete []result->str;
		result->str = resultArray;
		return *result;
	}
	
}
StringLine& StringLine::ReplaceAll(StringLine& secondLine, StringLine& thirdLine)
{
	StringLine *result = new StringLine;
	char temp[1024];
	int i = 0;
	int startPosition = this->IndexOf(secondLine);
	bool check = true;
	int count = 0;
	while (check)
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
				*result = this->Replace(secondLine, thirdLine);
				startPosition = result->IndexOf(secondLine);
				count++;
			}
			else
			{
				*result = result->Replace(secondLine, thirdLine);
				startPosition = result->IndexOf(secondLine);
			}
		}
	}
	return *result;
}


