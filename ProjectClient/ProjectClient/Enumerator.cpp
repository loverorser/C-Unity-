#include"Enumerator.h"	
template<class T>
Enumerator<T>::~Enumerator() {
		delete current;
		current = NULL;
}

template<class T>

Enumerator<T>::Enumerator() {
	break_point = -1;
	index = 0;
	function_index = 0;
	return_index = 0;
	current = new T();
}
template<class T>
bool Enumerator<T>::moveNext() {
	if (index < vector_function_or_return.size()) {
		//如果到了break
		if (index == break_point) {
			return false;
		}
		//如果到了yield块
		if ((vector_function_or_return)[index] == false) {
			current = (vector_return)[return_index];

			index++;
			return_index++;
			return true;

		}
		//如果到了function代码块
		else if ((vector_function_or_return)[index] == true) {
			(vector_function)[function_index]();

			index++;
			function_index++;
			//代码块就继续往下执行
			return moveNext();
		}
	}
	else {
		return false;
	}
	return false;
}
template<class T>
T* Enumerator<T>::getCurrent() {
	return current;
}
template<class T>
void Enumerator<T>::function(std::function<void()> f) {
	vector_function.push_back(f);
	vector_function_or_return.push_back(true);
}
template<class T>
void Enumerator<T>::yield(T* t) {
	vector_return.push_back(t);
	vector_function_or_return.push_back(false);
}
template<class T>
void Enumerator<T>::reset(){
	return;
}
template<class T>
void Enumerator<T>::yieldBreak() {
	if (break_point == -1)
		break_point = Enumerator<T>::vector_function_or_return.size();
}