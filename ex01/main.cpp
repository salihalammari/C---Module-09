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


int main(int arc, char **arv) 
{
    if (arc != 2)
        std::cerr << "need more param" << std::endl;
    std::stack<int> _stack;
    std::string value = arv[1];
    for (int i = 0; value[i] != '\0' ; ++i)
    {
        char value_input = value[i];
        if (value_input == ' ')
            continue;
        if (check_input(value_input))
            std::cerr<<"Error"<<std::endl;
        if (issignoperator(value_input))
        {
            
        }
    }
}
