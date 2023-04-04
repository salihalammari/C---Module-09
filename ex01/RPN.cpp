/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:01:35 by slammari          #+#    #+#             */
/*   Updated: 2023/04/01 02:05:09 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &copy)
{
    (void)copy;
}

RPN::~RPN()
{}

RPN &RPN::operator=(const RPN &copy)
{
    (void)copy;
    return *this;
}

