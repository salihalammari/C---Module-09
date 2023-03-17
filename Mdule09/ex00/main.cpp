/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:07:12 by slammari          #+#    #+#             */
/*   Updated: 2023/03/17 02:01:45 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) 
{
    // Define argument parser to take input file path as an argument
    if (argc < 2) {
        std::cout << "Usage: btc input_file" << std::endl;
        return 1;
    }
    std::string input_file_path = argv[1];

    // Create Btc object with path to bitcoin
}