/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:08:07 by slammari          #+#    #+#             */
/*   Updated: 2023/04/16 21:43:39 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(int arc, char **arv)
{
    for(int i = 1; i < arc; i++)
    {
        _vector.push_back(std::atoi(arv[i]));
    }
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
    *this = src;
    return ;
}

PmergeMe& PmergeMe::operator=(const PmergeMe  &obj){
    if (this != &obj){
    }
    return *this;
}

std::vector<int> PmergeMe::mergeInsertSort(std::vector<int> &vector) const
{
    if (vector.size() <= 15)
        return insertionSort(vector);
    std::vector<int> vector1(vector.begin(), vector.begin() + vector.size() / 2);
    std::vector<int> vector2(vector.begin() + vector.size() / 2, vector.end());

    vector1 = mergeInsertSort(vector1);
    vector2 = mergeInsertSort(vector2);
    return mergeSort(vector1, vector2);
}

std::deque<int> PmergeMe::mergeInsertSort(std::deque<int> &deque) const
{
    if (deque.size() <= 15)
        return insertionSort(deque);
    std::deque<int> deque1(deque.begin(), deque.begin() + deque.size() / 2);
    std::deque<int> deque2(deque.begin() + deque.size() / 2, deque.end());

    deque1 = mergeInsertSort(deque1);
    deque2 = mergeInsertSort(deque2);
    return  mergeSort(deque1, deque2);
}

std::vector<int> PmergeMe::mergeSort(std::vector<int> &vector1, std::vector<int> &vector2)  const
{
    std::vector<int> vector;
    while (!vector1.empty() && !vector2.empty()){
        if (vector1.front() < vector2.front()){
            vector.push_back(vector1.front());
            vector1.erase(vector1.begin());
        } else{
            vector.push_back(vector2.front());
            vector2.erase(vector2.begin());
        }
    }
    while (!vector1.empty()){
        vector.push_back(vector1.front());
        vector1.erase(vector1.begin());
    }
    while (!vector2.empty()){
        vector.push_back(vector2.front());
        vector2.erase(vector2.begin());
    }
    return vector;
}

std::deque<int> PmergeMe::mergeSort(std::deque<int> &deque1, std::deque<int> &deque2) const{
    std::deque<int> deque;
    while (!deque1.empty() && !deque2.empty()){
        if (deque1.front() < deque2.front()){
            deque.push_back(deque1.front());
            deque1.pop_front();
        } else {
            deque.push_back(deque2.front());
            deque2.pop_front();
        }
    }
    while (!deque1.empty()){
        deque.push_back(deque1.front());
        deque1.pop_front();
    }
     while (!deque2.empty()){
        deque.push_back(deque2.front());
        deque2.pop_front();
    }
    return deque;
}

std::vector<int> PmergeMe::insertionSort(std::vector<int> &vector) const
{
      for (size_t i = 1; i < vector.size(); i++){
        int j = i;
        while (j >= 0 && vector[j - 1] > vector[j]){
            int tmp = vector[j];
            vector[j] = vector[j - 1];
            vector[j - 1] = tmp;
            j--;
        }
    }
    return vector;
}

std::deque<int> PmergeMe::insertionSort(std::deque<int> &deque) const
{
    for (size_t i = 1; i < deque.size(); i++){
        int key = deque[i];
        int j = i - 1;
        while (j >= 0 && deque[j] > key){
            deque[j + 1] = deque[j];
            j--;
        }
        deque[j + 1] = key;
    }
    return deque;
}

std::ostream &operator<<(std::ostream &out, PmergeMe const &obj)
{
    clock_t start, end;
    
    std::vector<int> tmp(obj.getvector().begin(), obj.getvector().end());
    std::deque<int> deque(obj.getvector().begin(), obj.getvector().end());
    std::vector<int> vector(deque.begin(), deque.end());
    
    out << "befor:";
    for (std::vector<int>::const_iterator it = obj.getvector().begin(); it != obj.getvector().end(); ++it){
        out << " " << *it;
    }
    out << std::endl;
    
    sort(tmp.begin(), tmp.end());
    
    out << "after:";
    for (std::vector<int>::const_iterator it = tmp.begin(); it != tmp.end(); ++it){
        out << " " << *it;
    }
    out << std::endl;
    
    start = clock();
    vector = obj.mergeInsertSort(vector);
    end = clock();
    out << "vector: " << std::fixed << (double)(end - start) / CLOCKS_PER_SEC * 1000000 << " microseconds" << std::endl;

    start = clock();
    deque = obj.mergeInsertSort(deque);
    end = clock();
    out << "deque: " << std::fixed << (double)(end - start) / CLOCKS_PER_SEC * 1000000 << " microseconds" << std::endl;

    return out;
}
