#pragma once
#include <string>
using namespace std;

class StringLine
{
private:
	char* str;
	int strLenght;
public:
	// ������������
	StringLine(); // ������ ������
	StringLine(const char* line);// ����������� �� C-������
	StringLine(string line);// ����������� �� String
	~StringLine(); // ����������
	//���������
	StringLine& operator=(const StringLine&); // �������� ����������
	char operator[](int i); // ��������� ������� �� ������
	friend StringLine operator+(const StringLine&, const StringLine&); //�������� ��������
	StringLine& operator+=(const StringLine&); // ������� ��������
	bool operator==(const StringLine&); // ��������� �����
	bool operator!=(const StringLine&); // �� ��������� �����
	bool operator>(const StringLine&); // ������
	bool operator<(const StringLine&); // ������
	bool operator>=(const StringLine&); // ������ ��� �����
	bool operator<=(const StringLine&); // ������ ��� �����
	friend ostream& operator<<(ostream&, const StringLine&); //�����
	friend istream& operator>>(istream&, StringLine&); //����
	//������
	int GetLenght(); // ��������� �����
	StringLine& Copy(int startPosition, int lenght); // �����������
	StringLine& Delete(int startPosition, int lenght); // ��������
	StringLine& Insert(int startPosition, StringLine insertLine); // �������
	int IndexOf(StringLine& line); // ����� ���������
	int LastIndexOf(StringLine& line); // ����� ���������� ���������
	StringLine& Replace(StringLine& secondLine, StringLine& thirdline); // ������
	StringLine& ReplaceAll(StringLine& secondLine, StringLine& thirdLine); // ������ ����
	
};

