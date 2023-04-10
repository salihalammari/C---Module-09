/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:07:12 by slammari          #+#    #+#             */
/*   Updated: 2023/03/18 16:33:25 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "BitcoinExchange.hpp"


// int main(int argc,char *argv[]) 
// {
//     Btc objet;

//     if (argc < 2) 
//     {
//         std::cout << "Usage: btc input_file" << std::endl;
//         return 1;
//     }
//     (void)argv;
//     objet.parser("data.csv");
   
// }

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("data.csv");
    std::vector<std::vector<std::string> > data;
    std::string line;

    while (std::getline(file, line)) {
        std::vector<std::string> lineData;
        std::stringstream lineStream(line);
        std::string cell;

        while (std::getline(lineStream, cell, ',')) {
            lineData.push_back(cell);
        }

        data.push_back(lineData);
    }

    for (std::vector<std::vector<std::string> >::iterator it = data.begin();
         it != data.end(); ++it) {
        for (std::vector<std::string>::iterator it2 = it->begin();
             it2 != it->end(); ++it2) {
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}