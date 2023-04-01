/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:01:06 by slammari          #+#    #+#             */
/*   Updated: 2023/03/31 20:10:09 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main() 
{
    std::string expr = "5 3 2 * +";
    double result = calculateRPN(expr);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
