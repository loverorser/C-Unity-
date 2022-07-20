
//模板需要include cpp文件

#include"Enumerator.cpp"
#include"Coroutine.h"
using namespace std;

Coroutine::Coroutine(IEnumerator<YieldInstruction>* e) {
	this->e = e;
}
bool Coroutine::tick() {
	YieldInstruction* yi = e->getCurrent();

	bool tickResult = false;
	tickResult = yi->tick();
	/*
	if(typeid(*yi) == typeid(YieldInstruction)) {
		tickResult = yi->tick();
	}
	else if (typeid(*yi) == typeid(WaitForSeconds)) {
		tickResult = ((WaitForSeconds*)yi)->tick(1.0 / 60);
	}
	else if (typeid(*yi) == typeid(Coroutine)) {
		tickResult = ((Coroutine*)yi)->tick();
	}*/

	if (tickResult) {
		if (e->moveNext()) {
			return false;
		}
		else {
			delete e;
			return true;
		}
	}
	else {
		return false;
	}
}
