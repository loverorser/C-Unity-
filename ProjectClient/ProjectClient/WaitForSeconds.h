#pragma once
#include"YieldInstruction.h"
class WaitForSeconds :public YieldInstruction {
	float m_Seconds;
public:
	WaitForSeconds(float seconds);
	virtual bool tick() override;
};