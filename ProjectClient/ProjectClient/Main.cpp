#include"YieldInstruction.h"
#include"Enumerator.cpp"
#include"WaitForSeconds.h"
#include"Coroutine.h"
#include<iostream>
using namespace std;
#include"CoroutineManager.h"

IEnumerator<YieldInstruction>* f() {
	Enumerator<YieldInstruction>* e = new Enumerator<YieldInstruction>();
	//int bbb = 333;

	e->yield(new WaitForSeconds(1));
	e->function([=] {
		cout << "a=111" << endl;
		});

	e->yield(new WaitForSeconds(1));
	e->function([=] {
		cout << "a=222" << endl;
		});

	return e;

}

IEnumerator<YieldInstruction>* mainFunc(int a) {
	Enumerator<YieldInstruction>* e = new Enumerator<YieldInstruction>();
	//int bbb = 333;

	e->yield(new WaitForSeconds(1));
	e->function([=] {
		cout << "a=" << a << endl;
		});
	e->yield(new Coroutine(f()));
	e->yield(new WaitForSeconds(1));
	e->function([=] {
		cout << "a=" << a * 10 << endl;
		});

	return e;

}

int main() {
	CoroutineManager::startUpdate();
	CoroutineManager::startCoroutine(mainFunc(1));
	CoroutineManager::startCoroutine(mainFunc(2));
	CoroutineManager::startCoroutine(mainFunc(3));

	int a;
	cin >> a;
}