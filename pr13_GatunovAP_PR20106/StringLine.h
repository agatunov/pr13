#pragma once
#include <string>
using namespace std;

class StringLine
{
private:
	char* str;
	int strLenght;
public:
	// Конструкторы
	StringLine(); // Пустая строка
	StringLine(const char* line);// Копирование из C-строки
	StringLine(string line);// Копирование из String
	~StringLine(); // Деструктор
	//Операторы
	StringLine& operator=(const StringLine&); // Оператор присвоения
	char operator[](int i); // Получение символа по номеру
	friend StringLine operator+(const StringLine&, const StringLine&); //Бинарное сложение
	StringLine& operator+=(const StringLine&); // Унарное сложение
	bool operator==(const StringLine&); // Равенство строк
	bool operator!=(const StringLine&); // Не равенство строк
	bool operator>(const StringLine&); // Больше
	bool operator<(const StringLine&); // Меньше
	bool operator>=(const StringLine&); // Больше или равно
	bool operator<=(const StringLine&); // Меньше или равно
	friend ostream& operator<<(ostream&, const StringLine&); //Вывод
	friend istream& operator>>(istream&, StringLine&); //Ввод
	//Методы
	int GetLenght(); // Получение длины
	StringLine& Copy(int startPosition, int lenght); // Копирование
	StringLine& Delete(int startPosition, int lenght); // Удаление
	StringLine& Insert(int startPosition, StringLine insertLine); // Вставка
	int IndexOf(StringLine& line); // Поиск вхождения
	int LastIndexOf(StringLine& line); // Поиск последнего вхождения
	StringLine& Replace(StringLine& secondLine, StringLine& thirdline); // Замена
	StringLine& ReplaceAll(StringLine& secondLine, StringLine& thirdLine); // Замена всех
	
};

