/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:12:11 by slammari          #+#    #+#             */
/*   Updated: 2023/04/01 02:06:21 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPNCalculator {
public:
    RPNCalculator();
    bool isOperator(const std::string   &token);
    void push(double num);
    double operate(char op);
    bool empty() const;
private:
    std::stack<double> m_nums;
};

#endif
