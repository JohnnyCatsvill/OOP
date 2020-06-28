#define CATCH_CONFIG_MAIN 
#include "catch2/catch.hpp"
#include "../Lab7_Task2_Var3/CMyList.h"

using namespace std;
TEST_CASE("Positive Create int list")
{
	setlocale(LC_ALL, "Russian");
	string expected = "15 1024 42 12 ";
	string actual;
	try
	{
		CMyList<int> intList;
		intList.PushFront(1024);
		intList.PushBack(42);
		intList.Insert(intList.begin(), 15);
		intList.Insert(intList.end(), 12);
		for (CMyList<int>::iterator it = intList.begin(); it != intList.end(); ++it)
		{
			actual += to_string(*it) + " ";
		}
	}
	catch (const CMyListError& error)
	{
		actual = error.what();
	}

	CHECK(actual == expected);
}

TEST_CASE("Positive Create string list")
{
	setlocale(LC_ALL, "Russian");
	string expected = "������������ ������ ��� ������� ����� ";
	string actual;
	try
	{
		CMyList<string> strList;
		strList.PushFront("�������");
		strList.PushBack("���");
		strList.Insert(strList.begin(), "�����");
		strList.Insert(strList.end(), "������������");
		strList.Insert(strList.rbegin(), "������");
		for (CMyList<string>::iterator it = strList.rbegin(); it != strList.rend(); --it)
		{
			actual += *it + " ";
		}
	}
	catch (const CMyListError& error)
	{
		actual = error.what();
	}
	
	CHECK(actual == expected);
}

TEST_CASE("Positive Push testing")
{
	setlocale(LC_ALL, "Russian");
	string expected = "����� ������� ��� ������ ������������ ";
	string actual;
	try
	{
		CMyList<string> strList;
		strList.PushFront("���");
		strList.PushFront("�������");
		strList.PushFront("�����");
		strList.PushBack("������");
		strList.PushBack("������������");
		
		for (CMyList<string>::iterator it = strList.begin(); it != strList.end(); ++it)
		{
			actual += *it + " ";
		}
	}
	catch (const CMyListError& error)
	{
		actual = error.what();
	}

	CHECK(actual == expected);
}

TEST_CASE("Negative Get Element On empty list")
{
	setlocale(LC_ALL, "Russian");
	string expected = "Out of range: end() element can't contain any data";
	string actual;
	try
	{
		CMyList<string> strList;
		actual += *(strList.begin());
	}
	catch (const CMyListError& error)
	{
		actual = error.what();
	}

	CHECK(actual == expected);
}

TEST_CASE("Positive Get Number of elements")
{
	setlocale(LC_ALL, "Russian");
	string expected = "0250";
	string actual;
	try
	{
		CMyList<string> strList;
		actual += to_string(strList.Size());
		strList.PushFront("���");
		strList.PushFront("�������");
		actual += to_string(strList.Size());
		strList.PushFront("�����");
		strList.PushBack("������");
		strList.PushBack("������������");
		actual += to_string(strList.Size());
		strList.Delete(strList.begin());
		strList.Delete(strList.begin());
		strList.Delete(strList.begin());
		strList.Delete(strList.begin());
		strList.Delete(strList.begin());
		actual += to_string(strList.Size());
	}
	catch (const CMyListError& error)
	{
		actual = error.what();
	}

	CHECK(actual == expected);
}

TEST_CASE("Positive Insert testing")
{
	setlocale(LC_ALL, "Russian");
	string expected = "0 1 2 3 4 ";
	string actual;
	try
	{
		CMyList<int> strList;
		CMyList<int>::iterator it = strList.begin();
		for (int i = 0; i < 5; i++)
		{
			strList.Insert(it, i);
		}

		for (CMyList<int>::iterator it = strList.begin(); it != strList.end(); ++it)
		{
			actual += to_string(*it) + " ";
		}
	}
	catch (const CMyListError& error)
	{
		actual = error.what();
	}

	CHECK(actual == expected);
}

TEST_CASE("Negative Insert out of range testing")
{
	setlocale(LC_ALL, "Russian");
	string expected = "Out of range: Can't insert after rend() element";
	string actual;
	try
	{
		CMyList<int> strList;
		strList.Insert(strList.rend(), 15);
	}
	catch (const CMyListError& error)
	{
		actual = error.what();
	}

	CHECK(actual == expected);
}

TEST_CASE("Positive Delete testing")
{
	setlocale(LC_ALL, "Russian");
	string expected = "������� ������ ";
	string actual;
	try
	{
		CMyList<string> strList;
		strList.PushFront("���");
		strList.PushFront("�������");
		strList.PushFront("�����");
		strList.PushBack("������");
		strList.PushBack("������������");

		strList.Delete(strList.begin());
		strList.Delete(strList.rbegin());

		CMyList<string>::iterator it = strList.begin();
		++it;
		strList.Delete(it);

		for (CMyList<string>::iterator it = strList.begin(); it != strList.end(); ++it)
		{
			actual += *it + " ";
		}
	}
	catch (const CMyListError& error)
	{
		actual = error.what();
	}

	CHECK(actual == expected);
}

TEST_CASE("Negative Delete testing out of range")
{
	setlocale(LC_ALL, "Russian");
	string expected = "Out of range: Can't delete end() element";
	string actual;
	try
	{
		CMyList<string> strList;
		strList.PushFront("���");
		strList.PushFront("�������");
		strList.PushFront("�����");
		strList.PushBack("������");
		strList.PushBack("������������");

		strList.Delete(strList.end());
	}
	catch (const CMyListError& error)
	{
		actual = error.what();
	}

	CHECK(actual == expected);
}

TEST_CASE("Positive Copying test")
{
	setlocale(LC_ALL, "Russian");
	string expected = "����� ������� ��� ������ ������������ ";
	string actual;
	try
	{
		CMyList<string> strList;
		strList.PushFront("���");
		strList.PushFront("�������");
		strList.PushFront("�����");
		strList.PushBack("������");
		strList.PushBack("������������");

		CMyList<string> strListCopy(strList);

		strList.PushBack("������");

		for (CMyList<string>::iterator it = strListCopy.begin(); it != strListCopy.end(); ++it)
		{
			actual += *it + " ";
		}
	}
	catch (const CMyListError& error)
	{
		actual = error.what();
	}

	CHECK(actual == expected);
}

TEST_CASE("Positive Assign test")
{
	setlocale(LC_ALL, "Russian");
	string expected = "����� ������� ��� ������ ������������ ";
	string actual;
	try
	{
		CMyList<string> strList;
		CMyList<string> strListCopy;

		strListCopy.PushBack("���������� ��������");

		strList.PushFront("���");
		strList.PushFront("�������");
		strList.PushFront("�����");
		strList.PushBack("������");
		strList.PushBack("������������");

		strListCopy = strList;

		strList.PushBack("������");

		for (CMyList<string>::iterator it = strListCopy.begin(); it != strListCopy.end(); ++it)
		{
			actual += *it + " ";
		}
	}
	catch (const CMyListError& error)
	{
		actual = error.what();
	}

	CHECK(actual == expected);
}