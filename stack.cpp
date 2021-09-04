#include <iostream>
#include <list>
#include <string>
//Implementation of the Stack using lists
class Stack {
public:
    //Pushes elements to the top
    void Push(size_t value) {
       list_.push_front(value);
       std::cout << value << std::endl;
    }
    //Removes last added element from the stack
    void Pop() {
       list_.pop_front();
    }
    //Returns the size of the stack
    size_t Size() {
        return list_.size();
    }
    //Checks whether the stack is empty or not
    bool Empty() {
        return list_.empty();
    }
    //Back up all the data from the stack
    void Clear() {
        std::cout << "Clear" << std::endl;
        list_.erase(list_.begin(), list_.end());
    }
private:
    std::list<int> list_;
};
void InterfaceTester() {
    Stack stack;
    size_t number;
    std::string input = "";
    std::cin >> number;
    for (size_t i = 0; i < number; i++) {
        std::cin >> input;
        if(input == "Push") {
            int x;
            std::cin >> x;
            stack.Push(x);
        } else if(input == "Pop") {
            stack.Pop();
        } else if(input == "Size") {
            std::cout << stack.Size() << std::endl;
        } else if(input == "Clear") {
            stack.Clear();
        } else if(input == "Empty") {
            std::cout << stack.Empty() << std::endl;
        }
    }
}
int main() {
    InterfaceTester();
    return 0;
}