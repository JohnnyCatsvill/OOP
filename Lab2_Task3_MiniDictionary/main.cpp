#include "MiniDictionary.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    MiniDictionary(std::cin, std::cout);
}