#include"CoroutineManager.h"


//static CoroutineManager::frameRate	= 60;

void	CoroutineManager::tick() {
	//cout << "Tick";
	for (it = v.begin(); it != v.end();) {
		YieldInstruction* yi = (*it)->getCurrent();

		bool tickResult = false;

		tickResult = yi->tick();
		/*
		if (typeid(*yi) == typeid(YieldInstruction)) {
			tickResult = yi->tick();
		}
		else if (typeid(*yi) == typeid(WaitForSeconds)) {
			tickResult = ((WaitForSeconds*)yi)->tick(1.0 / frameRate);
		}
		else if (typeid(*yi) == typeid(Coroutine)) {
			tickResult = ((Coroutine*)yi)->tick();
		}
		*/
		if (tickResult) {
			if ((*it)->moveNext()) {
				it++;
			}
			else {
				delete (*it);

				it = v.erase(it);

			}
		}
		else {
			it++;
		}
	}
}

void CoroutineManager::startCoroutine(IEnumerator<YieldInstruction>* i) {
	v.push_back(i);
}

void CoroutineManager::startUpdate() {
	std::thread t([] {
		while (true) {
			tick();
			std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 60));
		}
		});
	//t.join();
	t.detach();
}


std::vector<IEnumerator<YieldInstruction>*> CoroutineManager::v;
std::vector<IEnumerator<YieldInstruction>*>::iterator CoroutineManager::it;