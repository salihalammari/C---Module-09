/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:08:05 by slammari          #+#    #+#             */
/*   Updated: 2023/04/10 22:15:27 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include "PmergeMe.hpp"


int main(int arc, char **arv) 
{
  PmergeMe PmergeMe(arc, arv);
  std::cout << PmergeMe << std::endl;
}