/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:08:07 by slammari          #+#    #+#             */
/*   Updated: 2023/04/12 23:46:02 by slammari         ###   ########.fr       */
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

// std::deque<int> PmergeMe::mergeInsertSort(std::deque<int> &deque) const
// {
//     return std::deque<int>();
// }

std::vector<int> PmergeMe::mergeInsertSort(std::vector<int> &vector) const
{
    if (vector.size() <= 10)
        return insertionSort(vector);
    std::vector<int> vector1(vector.begin(), vector.begin() + vector.size() / 2);
    std::vector<int> vector2(vector.begin() + vector.size() / 2, vector.end());

    vector1 = mergeInsertSort(vector1);
    vector2 = mergeInsertSort(vector2);
    return mergeSort(vector1, vector2);
}

std::deque<int> PmergeMe::mergeInsertSort(std::deque<int> &deque) const
{
    if (deque.size() <= 10)
        return mergeInsertSort(deque);
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
        vector1.erase(vector2.begin());
    }
    while (!vector2.empty()){
        vector.push_back(vector1.front());
        vector2.erase(vector2.begin());
    }
    return vector;
}

// std::deque<int> PmergeMe::mergeSort(std::deque<int> &deque1, std::deque<int> &deque2)
// {
//     return std::deque<int>();
// }

std::deque<int> PmergeMe::mergeSort(std::deque<int> &deque1, std::deque<int> &deque2) const{
    std::deque<int> deque;
    while (!deque1.empty() && !deque1.empty()){
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
        while (j > 0 && vector[j - 1] > vector[j]){
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
        int j = i;
        while (j > 0 && deque[j - 1] > deque[j]){
            int tmp = deque[j];
            deque[j] = deque[j - 1];
            deque[j - 1] = tmp;
            j--;
        }
    }
    return deque;
}

std::ostream &operator<<(std::ostream &out, PmergeMe const &obj)
{
    struct timeval start, end;

    std::vector<int> tmp(obj.getvector().begin(), obj.getvector().end());
    std::deque<int> deque(obj.getvector().begin(), obj.getvector().end());
    std::vector<int> vector(obj.getvector().begin(), obj.getvector().end());

    out << "befor :";
    for( size_t i = 0; i < obj.getvector().size(); i++){
        out << " " << obj.getvector()[i];
    }
    out << std::endl;

    gettimeofday(&start, NULL);
    deque = obj.mergeInsertSort(deque);
    gettimeofday(&end, NULL);

    out << "deque: " << std::fixed << end.tv_usec - start.tv_usec << " microseconds" << std::endl;
    gettimeofday(&start, NULL);
    vector = obj.mergeInsertSort(vector);
    gettimeofday(&end, NULL);

    out << "vector: " << std::fixed << end.tv_usec - start.tv_usec << " microseconds" << std::endl;

    return out;
}
