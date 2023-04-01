/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:08:09 by slammari          #+#    #+#             */
/*   Updated: 2023/04/01 02:29:15 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP // Header guard to prevent multiple include errors
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>


class PmergeMe {
public:
    static void mergeInsertSort(std::vector<int>& sequence); // Function for merge-insert sort algorithm
};

#endif
