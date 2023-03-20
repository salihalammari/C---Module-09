/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:01:06 by slammari          #+#    #+#             */
/*   Updated: 2023/03/20 17:58:37 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <sstream>

int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
        return 1;
    }
    return rpn(argv[1]);
}