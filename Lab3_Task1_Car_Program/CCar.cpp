#include "CCar.h"
#include <iostream>

CCar::CCar()
{
}

CCar::~CCar()
{
}

bool CCar::TurnOnEngine()
{
	if (!m_engineOn)
	{
		m_engineOn = true;
		return true;
	}
	else
	{
		return false;
	}
}

bool CCar::TurnOffEngine()
{
	if (m_engineOn && m_currentGear == 0 && m_currentSpeed == 0)
	{
		m_engineOn = false;
		return true;
	}
	else
	{
		return false;
	}
}

bool CCar::SetGear(int gear)
{
	if (m_engineOn &&
		((gear == -1 && 0 == m_currentSpeed) ||
		(gear == 0) ||
		(gear == 1 && 0 == m_currentSpeed && m_currentGear <= 0 ) ||
		(gear == 1 && 0 <= m_currentSpeed && m_currentSpeed <= 30 && m_motionSide == 1) ||
		(gear == 2 && 20 <= m_currentSpeed && m_currentSpeed <= 50 && m_motionSide == 1) ||
		(gear == 3 && 30 <= m_currentSpeed && m_currentSpeed <= 60 && m_motionSide == 1) ||
		(gear == 4 && 40 <= m_currentSpeed && m_currentSpeed <= 90 && m_motionSide == 1) ||
		(gear == 5 && 50 <= m_currentSpeed && m_currentSpeed <= 150 && m_motionSide == 1)) ||
		(!m_engineOn && gear == 0))
	{
		m_currentGear = gear;
		return true;
	}
	else
	{	
		return false;
	}
}

bool CCar::SetSpeed(int speed)
{
	if (m_engineOn &&
		((m_currentGear == -1 && 0 <= speed && speed <= 20) ||
		(m_currentGear == 0 && m_currentSpeed >= speed && speed >= 0) ||
		(m_currentGear == 1 && 0 <= speed && speed <= 30) ||
		(m_currentGear == 2 && 20 <= speed && speed <= 50) ||
		(m_currentGear == 3 && 30 <= speed && speed <= 60) ||
		(m_currentGear == 4 && 40 <= speed && speed <= 90) ||
		(m_currentGear == 5 && 50 <= speed && speed <= 150)))
	{
		m_currentSpeed = speed;

		if (m_currentGear == -1 && speed > 0)
		{
			m_motionSide = -1;
		}
		else if (speed == 0)
		{
			m_motionSide = 0;
		}
		else if (m_currentGear >= 1 && speed > 0)
		{
			m_motionSide = 1;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool CCar::IsEngineOn()const
{
	return m_engineOn;
}

int CCar::GetMotionSide()const
{
	return m_motionSide;
}

int CCar::GetCurrentSpeed()const
{
	return m_currentSpeed;
}

int CCar::GetCurrentGear()const
{
	return m_currentGear;
}