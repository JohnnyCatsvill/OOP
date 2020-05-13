#pragma once
class CCar
{
public:
	CCar();

	~CCar();

	bool TurnOnEngine();

	bool TurnOffEngine();

	bool SetGear(int gear);

	bool SetSpeed(int speed);

	bool IsEngineOn()const;

	int GetMotionSide()const;

	int GetCurrentSpeed()const;

	int GetCurrentGear()const;

private:
	bool m_engineOn = false;
	int m_motionSide = 0;
	int m_currentSpeed = 0;
	int m_currentGear = 0;
};

