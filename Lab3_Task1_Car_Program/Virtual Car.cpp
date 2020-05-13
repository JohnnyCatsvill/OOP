
#include <iostream>
#include "CCar.h"
#include <string>

using namespace std;

void ClearSpaces(std::string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str.erase(i, 1);
        }
    }
}

int DemandNumber(const string &demandMessage, std::string strInt)
{
    while (!(strInt[0] >= '0' && strInt[0] <= '9' || strInt[0] == '-' && strInt[1] >= '0' && strInt[1] <= '9'))
    {
        cout << demandMessage;
        std::getline(cin, strInt);
    }
    return stoi(strInt);
}

string GetGearTrouble(CCar &car, int gear)
{
    if (car.GetMotionSide() != 0 && gear == -1)
    {
        return "Нельзя переключить передачу назад, автомобиль все еще едет";
    }
    else if (car.GetMotionSide() < 0 && gear >= 1)
    {
        return "Нельзя переключить передачу вперёд, автомобиль все еще едет назад";
    }
    else if (car.GetMotionSide() < 0 && gear >= 1)
    {
        return "Нельзя переключить передачу вперёд, автомобиль все еще едет назад";
    }
    else if ((gear == 1 && (0 > car.GetCurrentSpeed() || car.GetCurrentSpeed() > 30)) ||
        (gear == 2 && (20 > car.GetCurrentSpeed() || car.GetCurrentSpeed() > 50)) ||
        (gear == 3 && (30 > car.GetCurrentSpeed() || car.GetCurrentSpeed() > 60)) ||
        (gear == 4 && (40 > car.GetCurrentSpeed() || car.GetCurrentSpeed() > 90)) ||
        (gear == 5 && (50 > car.GetCurrentSpeed() || car.GetCurrentSpeed() > 150)))
    {
        return "Данная передача не расчитана на такие скорости, измените скорость или выберите другую передачу";
    }
    else if (gear < -1 || gear > 5)
    {
        return "Машина не расчитана на такую передачу";
    }
    else if (!car.IsEngineOn())
    {
        return "Двигатель машины заглушен";
    }
    else
    {
        return "Ошибка не опознана";
    }
}

string GetSpeedTrouble(CCar &car, int speed)
{
    if (speed < 0)
    {
    return "Скорость должна быть неотрицательной";
    }
    else if ((car.GetCurrentGear() == -1 && (0 > speed || speed > 20)) ||
        (car.GetCurrentGear() == 1 && (0 > speed || speed > 30)) ||
        (car.GetCurrentGear() == 2 && (20 > speed || speed > 50)) ||
        (car.GetCurrentGear() == 3 && (30 > speed || speed > 60)) ||
        (car.GetCurrentGear() == 4 && (40 > speed || speed > 90)) ||
        (car.GetCurrentGear() == 5 && (50 > speed || speed > 150)))
    {
        return "Данная скорость недостуна на данной передаче";
    }
    else if (!car.IsEngineOn())
    {
        return "Двигатель машины заглушен";
    }
    
    else if (car.GetCurrentGear() == 0 && car.GetCurrentSpeed() < speed)
    {
        return "На текущей передаче нельзя разгоняться";
    }
    else
    {
        return "Ошибка не опознана";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    CCar car;
    std::string command;
    while (std::getline(std::cin, command))
    {
        if (command == "Info")
        {
            cout << "Состояние двигателя - " << (car.IsEngineOn() ? "Включен" : "Выключен") << '\n';
            cout << "Направление движения - " << ((car.GetMotionSide() == 0) ? "Стоит на месте" : (car.GetMotionSide() > 0) ? "Вперёд" : "Назад") << '\n';
            cout << "Текущая скорость - " << car.GetCurrentSpeed() << '\n';
            cout << "Текущая передача - " << car.GetCurrentGear() << '\n';
        }
        else if (command == "EngineOn")
        {
            cout << (car.TurnOnEngine() ? "Машина успешно заведена" : "Ошибка в попытке завести машину") << '\n';
        }
        else if (command == "EngineOff")
        {
            cout << (car.TurnOffEngine() ? "Машина успешно затихла" : "Ошибка в попытке заглушить двигатель") << '\n';
        }
        else if (command.find("SetGear") == 0)
        {
            string strInt = command;
            strInt.erase(0, 7);
            ClearSpaces(strInt);

            int gear = DemandNumber("Введите передачу\n", strInt);

            if (car.SetGear(gear))
            {
                cout << "Передача успешно изменена на " << gear << '\n';
            }
            else
            {
                cout << "Ошибка в попытке изменить передачу\n";
                cout << GetGearTrouble(car, gear) << endl;
            }
        }
        else if (command.find("SetSpeed") == 0)
        {
            string strInt = command;
            strInt.erase(0, 8);
            ClearSpaces(strInt);
            
            int speed = DemandNumber("Введите скорость\n", strInt);

            if (car.SetSpeed(speed))
            {
                cout << "Скорость успешно изменена на " << speed << '\n';
            }
            else
            {
                cout << "Ошибка в попытке изменить скорость\n";
                cout << GetSpeedTrouble(car, speed) << endl;
            }
        }
        else
        {
            cout << "Команда не распознана\n";
        }
    }
}
