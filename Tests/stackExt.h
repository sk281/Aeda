# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
    stack<T> oficial;
    stack<T> minimos;
public:
	StackExt() {};
	bool empty() const; 
	T &top();
	void pop();
	void push(const T & val);
	T &findMin();
};

// a alterar
template <class T> 
bool StackExt<T>::empty() const{
        if (oficial.empty())
            return true;
        else
            return false;
}

//a alterar
template <class T> 
T& StackExt<T>::top(){
        return oficial.top();
}

//a alterar
template <class T> 
void StackExt<T>::pop(){
    if( !minimos.empty() && minimos.top()==oficial.top())
        minimos.pop();
    if(!oficial.empty())
        oficial.pop();
}



//a alterar
template <class T> 
void StackExt<T>::push(const T & val){
    oficial.push(val);
    if(minimos.empty()){

        minimos.push(val);

        return;

    }

    T topo=minimos.top();
    if(val < topo){
        minimos.push(val);
    }
}

//a alterar
template <class T> 
T& StackExt<T>::findMin(){
    return minimos.top();
}