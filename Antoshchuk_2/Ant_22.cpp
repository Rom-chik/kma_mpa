#include "header.h" //developed by Roman Antoshchuk on 08.02.2024

std::string rpn_to_infix(const std::string& rpn) {
    std::stack<std::string> operands;
    std::istringstream iss(rpn);
    std::string token;

    while (iss >> token) {
        if (is_operator(token[0]) && token.length() == 1) {
            std::string op2 = operands.top(); operands.pop();
            std::string op1 = operands.top(); operands.pop();
            std::string expr = "(" + op1 + " " + token + " " + op2 + ")";
            operands.push(expr);
        }
        else {
            operands.push(token);
        }
    }

    return operands.empty() ? "" : operands.top();
}

int fromRPN() {
    std::ifstream input_file("input_rpn.txt");
    if (!input_file) {
        std::cerr << "Unable to open input file" << std::endl;
        return 1;
    }
    std::ofstream output_file("output_rpn.txt");
    if (!output_file) {
        std::cerr << "Unable to open output file" << std::endl;
        return 1;
    }

    std::string inputLine;
    std::string outputLine;
    while (getline(input_file, inputLine)) {
        std::cout << "RPN line: " << inputLine << std::endl;
        outputLine = rpn_to_infix(inputLine);
        std::cout << "Infix: " << outputLine << "\n" << std::endl;
        output_file << outputLine << std::endl;
    }

    input_file.close();
    output_file.close();

    return 0;
}