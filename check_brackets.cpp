#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    int errorPosition = 1;
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket newBracket(next, position+1);
            opening_brackets_stack.push(newBracket);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.empty()) {
              errorPosition = position + 1;
              break;
            }
            Bracket topBracket = opening_brackets_stack.top();
            if (topBracket.Matchc(next)) {
              opening_brackets_stack.pop();
            }
            else {
              errorPosition = position + 1;
              break;
            }
        }
    }

    // Printing answer, write your code here
    if (opening_brackets_stack.empty()) std:: cout << "Success" << std:: endl;
    else if (!opening_brackets_stack.empty()) std:: cout << opening_brackets_stack.top().position << std::endl;
    else std:: cout << errorPosition << std::endl;
    return 0;
}
