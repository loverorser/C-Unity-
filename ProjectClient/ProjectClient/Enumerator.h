#pragma once
#include"IEnumerator.h"
#include<vector>
#include<functional>

template<class T>
class Enumerator :public IEnumerator<T> {
public:
	virtual ~Enumerator() override;
private:
	unsigned int index;
	int function_index;
	int return_index;
	int break_point;
	T* current;
	std::vector<std::function<void()>> vector_function;
	std::vector<T*> vector_return;
	std::vector<bool> vector_function_or_return;
public:
	Enumerator();
	virtual bool moveNext() override;
	virtual T* getCurrent() override;
	virtual void reset() override;

	void function(std::function<void()> f);
	void yield(T* t);
	void yieldBreak();
};
