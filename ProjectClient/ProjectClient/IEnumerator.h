#pragma once
template<class T>
class IEnumerator {
public:
	virtual ~IEnumerator() {
		delete current;
		current = nullptr;

	}
private:
	T* current;

public:
	virtual bool moveNext() = 0;
	virtual T* getCurrent() = 0;
	virtual void reset() = 0;
};