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

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: no input sequence provided" << std::endl;
        return 1;
    }
    
    std::vector<int> arr(argc-1);
    
    for (int i = 1; i < argc; ++i) {
        try {
            arr[i-1] = std::stoi(argv[i]);
            
            if (arr[i-1] < 0)
                throw std::invalid_argument("");
        } catch (...) {
            std::cerr << "Error: invalid input sequence provided" << std::endl;
            return 1;
        }
    }
    
    mergeSort(arr, 0, arr.size()-1);
    
    for (int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
        
    std::cout << std::endl;
    
    return 0;
}