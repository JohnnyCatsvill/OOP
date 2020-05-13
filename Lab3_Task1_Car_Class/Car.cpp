
#include <iostream>
#include "CCar.h"
#include <assert.h>

using namespace std;

void TestCarCreation()
{
    CCar car;
    assert(car.IsEngineOn() == false);
    assert(car.GetMotionSide() == 0);
    assert(car.GetCurrentSpeed() == 0);
    assert(car.GetCurrentGear() == 0);
}

void TestCarNormalDriving()
{
    CCar car;
    assert(car.TurnOnEngine()); //заводимся
    assert(car.SetGear(1));  //разгоняемся
    assert(car.SetSpeed(25));
    assert(car.SetGear(2));
    assert(car.SetSpeed(40));
    assert(car.SetGear(3));
    assert(car.SetSpeed(50)); 
    assert(car.SetSpeed(40)); //притормаживаем
    assert(car.SetGear(2)); //уменьшаем передачу
    assert(car.SetGear(0)); //переходим на нейтралку
    assert(car.SetSpeed(0)); //тормозим
    assert(car.SetGear(-1)); //даем задний ход
    assert(car.SetSpeed(10));
    assert(car.SetSpeed(0)); //тормозим
    assert(car.SetGear(0)); //нейтралка
    assert(car.TurnOffEngine()); //глушим движок
    assert(car.IsEngineOn() == false); //машина как новая
    assert(car.GetMotionSide() == 0);
    assert(car.GetCurrentSpeed() == 0);
    assert(car.GetCurrentGear() == 0);
}

void TestCarWithWrongGears()
{
    CCar car;
    assert(!car.SetGear(1)); //машина не заведена
    car.TurnOnEngine();
    assert(!car.SetGear(2)); //машина стоит
    car.SetGear(1);
    car.SetSpeed(5);
    assert(!car.SetGear(2)); //машине не хватает скорости
    assert(!car.SetGear(6)); //такой передачи нет
    assert(!car.SetGear(-1)); //машина едет вперед
    car.SetSpeed(0);
    car.SetGear(-1);
    assert(!car.SetGear(-2)); //такой передачи нет
    car.SetSpeed(5);
    assert(!car.SetGear(1)); //машина едет назад
    car.SetGear(0);
    car.SetSpeed(4);
    assert(!car.SetGear(1)); //машина все еще едет назад
}

void TestCarWithWrongSpeeds()
{
    CCar car;
    assert(!car.SetSpeed(5)); //машина не заведена
    car.TurnOnEngine();
    car.SetGear(1);
    assert(!car.SetSpeed(-5)); //таких скоростей нет
    assert(!car.SetSpeed(40)); //скорость выше допустимой на текущей передаче
    car.SetSpeed(20);
    car.SetGear(0);
    assert(!car.SetSpeed(25)); //на нейтралке разгоняться нельзя
    car.SetGear(1);
    car.SetSpeed(25);
    car.SetGear(2);
    assert(!car.SetSpeed(10)); //скорость ниже допустимой на текущей передаче
}

void TestCarWrongTurnOnsOffs()
{
    CCar car;
    assert(!car.TurnOffEngine()); //был и так выключен
    car.TurnOnEngine();
    assert(!car.TurnOnEngine()); //был и так включен
    car.SetGear(1);
    assert(!car.TurnOffEngine()); //передача не нейтральная
    car.SetSpeed(5);
    car.SetGear(0);
    assert(!car.TurnOffEngine()); //скорость не нулевая
}

int main()
{
    TestCarCreation();
    TestCarNormalDriving();
    TestCarWithWrongGears();
    TestCarWithWrongSpeeds();
    TestCarWrongTurnOnsOffs();

    return 0;
}