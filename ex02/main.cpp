/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:08:05 by slammari          #+#    #+#             */
/*   Updated: 2023/04/01 02:28:30 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int arc, char **arv) 
{
  PmergeMe PmergeMe(argc, argv);
  std::cout << PmergeMe << std::endl;
}