#include <iostream>
#include <stack>
#include <cstdlib>

bool isOperator(const std::string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int performOperation(int a, int b, const std::string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) {
            throw std::runtime_error("division by zero");
        }
        return a / b;
    }
    throw std::invalid_argument("unknown operator");
}

int evaluateRPN(const std::string& rpn) {
    std::stack<int> st;
    std::string token;
    std::stringstream ss(rpn);
    while (ss >> token) {
        if (isOperator(token)) {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            int result = performOperation(a, b, token);
            st.push(result);
        } else {
            st.push(std::stoi(token));
        }
    }
    return st.top();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
        return EXIT_FAILURE;
    }
    try {
        int result = evaluateRPN(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
