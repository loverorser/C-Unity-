#pragma once
//默认yield，在所有协程最开始会自动执行一次并返回true
class YieldInstruction {
public:
	virtual bool tick();
};