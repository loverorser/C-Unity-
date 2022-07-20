#include<thread>
#include<vector>
#include"IEnumerator.h"
#include"YieldInstruction.h"

class CoroutineManager {
public:
	static const int frameRate = 60;
private:
	static std::vector<IEnumerator<YieldInstruction>*> v;
	static std::vector<IEnumerator<YieldInstruction>*>::iterator it;
	static void tick();
	
public:

	static void startCoroutine(IEnumerator<YieldInstruction>* i);

	static void startUpdate();

};