#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary

private:
		size_t size_;
};

template <typename T>
Stack<T>::Stack()::std::vector<T>{
	size_ = 0;
	
}

template <typename T>
Stack<T>::~Stack(){
	while(Stack<T>::empty()){
		Stack<T>::pop();
	}
}

template <typename T>
bool Stack<T>::empty() const{
	return std::vector<T>::empty();
}

template <typename T>
size_t Stack<T>::size() const{
	return size_;
}

template <typename T>
void Stack<T>::push(const T& item){
	size_++;
	std::vector<T>::push_back(item);
}

template <typename T>
void Stack<T>:: pop(){ 
	if(Stack<T>::empty()){
		throw std::underflow_error("empty");
	}
	else{
		std::vector<T>::vec.pop_back();
		size_--;
	}

}
template <typename T>
const Stack<T>:: T& top() const{ 
	if(Stack<T>::empty()){
		throw std::underflow_error("empty");
	}
	else{
		return (*this)[std::vector<T>::size()-1];
	}
}

#endif