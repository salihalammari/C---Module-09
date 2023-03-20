/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:01:35 by slammari          #+#    #+#             */
/*   Updated: 2023/03/20 20:45:20 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <sstream>

int rpn(std::string expr)
{
    std::stack<int> oper;
    std::istringstream iss(expr);

    std::string token;
    while (iss >> token)
    {
        if(token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (oper.size() < 2)
            {
                std::cout << "Error: Invalid expression: " << expr << std::endl;
                return 0;
            }
            std::iterator it;
            for(it = postfix.begin(); it != postfix.end(); it++)
            {
                if(expr(*it) != -1)
                {
                    int op2 = oper.top();
                    oper.pop();
                     int op1 = oper.top();
                    oper.pop();
                }
            }
             
            int result;
            if (token == "+")  
                result = op1 + op2;
            else if (token == "-")
                result = op1 - op2;
            else if (token == "*")
                result = op1 * op2;
            else if (token == "/")
                if (op2 == 0)
                {
                    std::cout << "Error: Division by zero" << std::endl;
                    return 1;
                }
                result = op1 / op2;
            }
            oper.push(result);
            else
            {
                int num;
                if (!(istringstream(token) >> num))
                {
                        std::cout << "Error: Invalid expression: " << expr << std::endl;
                        return 1;
                }
                oper.push(num);
            }
        }
    } 
    if (oper.size() != 1)
    {
        std::cerr << "Error: Too many operands." << std::endl;
        return 1;
    }
    std::cout << oper.top() << std::endl;
    return 0;
}


int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
        return 1;
    }
    return rpn(argv[1]);
}