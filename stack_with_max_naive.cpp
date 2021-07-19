#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <queue>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

bool myfunction (int i,int j) { return (i<j); }

class StackWithMax {
    vector<int> stack;
  public:

    void Push(int value) {
        stack.push_back(value);
        std:: sort(stack.begin(), stack.end(), myfunction);
    }

    void Pop() {
        assert(stack.size());
        stack.pop_back();
        std:: sort(stack.begin(), stack.end(), myfunction);
    }

    int Max() const {
        assert(stack.size());
        return stack[stack.size() - 1];
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;
    std:: queue<int> output;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            //cout << stack.Max() << "\n";
            output.push(stack.Max());
        }
        else {
            assert(0);
        }
    }
    while(!output.empty()) {
      cout << output.front() << std:: endl;
      output.pop();
    }
    return 0;
}
