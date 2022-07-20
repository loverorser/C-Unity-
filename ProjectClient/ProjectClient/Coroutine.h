#include"YieldInstruction.h"
#include"IEnumerator.h"

class Coroutine :public YieldInstruction {
private:
	IEnumerator<YieldInstruction>* e;
public:
	Coroutine(IEnumerator<YieldInstruction>* e);
	virtual bool tick();
};
