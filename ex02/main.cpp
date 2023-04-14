/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:08:05 by slammari          #+#    #+#             */
/*   Updated: 2023/04/14 01:43:13 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


#include <deque>
#include <iostream>
#include <string>
#include <vector>

int main(int arc, char **arv) 
{
  PmergeMe PmergeMe(arc, arv);
  std::cout << PmergeMe << std::endl;
}