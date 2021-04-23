stack<int> s;
stack<int> ss;
MinStack::MinStack() {

    while(s.size()){
        s.pop();
    }
    while(ss.size()){
        ss.pop();
    }
    
}

void MinStack::push(int x) {
    s.push(x);
    
    if(ss.empty()) ss.push(x);
    
    if(ss.top() >= x){
        ss.push(x);
    }
}

void MinStack::pop() {
    if(s.empty()) return;
    if(s.top() == ss.top()){
        ss.pop();
    }
    s.pop();
}

int MinStack::top() {
    if(s.empty()) return -1;
    return s.top();
}

int MinStack::getMin() {
    if(ss.empty()) return -1; 
    return ss.top();
} 

