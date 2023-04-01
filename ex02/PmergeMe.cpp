/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:08:07 by slammari          #+#    #+#             */
/*   Updated: 2023/04/01 02:29:03 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void mergeSort(std::vector<int>& arr, int low, int high) {
    if (low >= high) return;
    
    int mid = (low + high) / 2;
    
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    
    std::vector<int> tmpArr(high - low + 1);
    
    int i = low, j = mid+1, k = 0;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            tmpArr[k++] = arr[i++];
        else
            tmpArr[k++] = arr[j++];
    }
    
    while (i <= mid)
        tmpArr[k++] = arr[i++];
        
    while (j <= high)
        tmpArr[k++] = arr[j++];
        
    for (int p = 0; p < k; ++p)
        arr[low+p] = tmpArr[p];
}