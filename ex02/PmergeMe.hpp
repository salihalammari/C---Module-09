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

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#include <sys/time.h>


class PmergeMe {
    private:
        std::vector<int> _vertor;

std::vector<int> mergeSort(std::vector1<int> &vector, std::vector2<int> &vector) const;
std::deque<int> mergeSort(std::deque1<int> &deque, std::deque2<int> &deque) const;
std::vector<int> insertionSort(std::vector<int> &vector) const;
std::deque<int> insertionSort(std::deque<int> &deque) const;

    public:
        PmergeMe();
        PmergeMe(int arc, char **arv);
        PmergeMe(PmergeMe const &src);
        PmergeMe &operator=(PmergeMe const &copy);
        ~PmergeMe();
        static void mergeInsertSort(std::vector<int>& sequence);
    
    std::vector<int> &getvector() {return _vector; }
    std::vector<int> &getvector() const {return _vector; }

    std::deque<int> mergeInsertSort(std::deque<int> &deque) const;
    std::vector<int> mergeInsertSort(std::vector<int> &vector) const;

};

std::ostream &operator<<(std::ostream &out, const PmergeMe &copy);
#endif
