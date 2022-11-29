// #ifndef STACK_H
// #define STACK_H

// #include <vector>
// #include <stdexcept>

// // Use inheritance from std::vector (choose public/private) as appropriate
// template <typename T>
// class Stack : private std::vector<T>
// {
// public:
//     Stack();
//     ~Stack();
//     bool empty() const;
//     size_t size() const;
//     void push(const T& item);
//     void pop();  // throws std::underflow_error if empty
//     const T& top() const; // throws std::underflow_error if empty
//     // Add other members only if necessary

// private:
// 		size_t size_;
// };

// template <typename T>
// Stack<T>::Stack(){
// 	size_ = 0;
	
// }

// template <typename T>
// Stack<T>::~Stack(){
// 	while(Stack<T>::empty()==false){
// 		Stack<T>::pop();
// 	}
// }

// template <typename T>
// bool Stack<T>::empty() const{
// 	return std::vector<T>::empty();
// }

// template <typename T>
// size_t Stack<T>::size() const{
// 	// return std::vector<T>::size();
// 	return size_;
// }

// template <typename T>
// void Stack<T>::push(const T& item){
// 	size_++;
// 	std::vector<T>::push_back(item);
// }

// template <typename T>
// void Stack<T>::pop(){ 
// 	if(Stack<T>::empty()){
// 		throw std::underflow_error("empty");
// 	}
// 	else{
// 		std::vector<T>::vec.pop_back();
// 		size_--;
// 	}

// }
// template <typename T>
// const T& Stack<T>::top() const{ 
// 	if(Stack<T>::empty()){
// 		throw std::underflow_error("empty");
// 	}
// 	else{
// 		return (*this)[std::vector<T>::size()-1];
// 	}
// }

// #endif

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
   
};

template<typename T>
Stack<T> :: Stack(){
   
}

template<typename T>
Stack<T> :: ~Stack(){ 
	while(!Stack<T>::empty()){
		Stack<T>::pop();
 }
}

template<typename T>
bool Stack<T>:: empty() const{ 
  return std::vector<T>::empty();
}

template<typename T>
size_t Stack<T>::size()const{ 
	return std::vector<T>::size();
}

template<typename T>
void Stack<T>::push(const T& item){ 
  std::vector<T>::push_back(item); 
}

template<typename T> 
void Stack<T>::pop(){ 
	if(empty()){
  	throw std::underflow_error("empty");
 }
	else{
    std::vector<T>::pop_back();
	}
}


template<typename T>
const T& Stack<T> ::top()const{
  if(!empty()) return (*this)[std::vector<T>::size()-1];
   
  else{
		throw std::underflow_error("empty");
	}
}



#endif