#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm> 


template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
	

private:
  /// Add whatever helper functions and data members you need below
	size_t _size; //size of the heap
	std::vector<T> vec; //let the heap be a vector
  int m_; 
	PComparator c_;
	void trickleUp(int loc, PComparator c); //helper function for push
	void heapify(int index, PComparator c); //helper function for pop

};

// Add implementation of member functions here

//constructor
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
	
	std::vector<T> vec;
  _size = 0;
	m_=m;
	c_=c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){}


//return the size of the heap
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
	return _size;
}

//return true if the heap is empty
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
	return _size == 0;
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(vec.empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	else{

		//return the first item in the vector 
		return vec[0];
	}
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx, PComparator c){
	
  // finding the smallerChild 
	int smallerChild = m_*idx+1;
	int rChild = smallerChild+1;

  //check if the smallerChild is a leaf node 
	if(smallerChild>=(int)_size) return;

  //keep finding the smallerChild from left to right
	while(rChild < (int)_size){
		if(c(vec[rChild], vec[smallerChild])){
			smallerChild = rChild;
		}
		rChild++;
	}

	//swapping the value and do recursion
	if(c(vec[smallerChild],vec[idx])){
		std::swap(vec[idx], vec[smallerChild]);
		heapify(smallerChild,c_);
	}
}
// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(vec.empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("empty");
  }

	else{
    //set the first element be the value of last element
		vec[0] = vec[_size-1]; 

    //remove the last element
    _size--;
		vec.pop_back();
    //call helper function
		heapify(0,c_);
	}
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc, PComparator c){

  //finding the parent node
	int parent = (loc-1)/m_;
  //swapping the node if it has more priority than the parent node
	while(parent >= 0 && c(vec[loc],vec[parent])){
		std::swap(vec[parent], vec[loc]);
		loc = parent;
		parent = (loc-1)/m_;
	}
	return;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  //add to the back
	_size++;
	vec.push_back(item);
  int i = _size-1;
  //call helper function
	trickleUp(i,c_);
}


#endif

