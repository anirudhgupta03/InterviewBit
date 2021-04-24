stack<int> s;
int minEle;
MinStack::MinStack() {
    
    minEle = INT_MAX;
    while(s.size()){
        s.pop();
    }
}

void MinStack::push(int x) {
    
    if(s.empty()){
        s.push(x);
        minEle = x;
    }
    else if(x < minEle){
        s.push(2*x - minEle);
        minEle = x;
    }
    else{
        s.push(x);
    }
    
}

void MinStack::pop() {
    
    if(s.empty()) return;
    
    if(s.top() < minEle){
        minEle = 2*minEle - s.top();
    }
    s.pop();
}

int MinStack::top() {
    
    if(s.empty()) return -1;
    
    if(s.top() >= minEle)
    return s.top();
    else{
        return minEle;
    }
} 

int MinStack::getMin() {
    if(s.empty()) return -1; 
    return minEle;
} 
