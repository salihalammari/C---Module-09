/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:07:12 by slammari          #+#    #+#             */
/*   Updated: 2023/04/11 02:32:41 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc,char *argv[]) 
{

    if (argc < 2) 
    {
        std::cout << "Usage: btc input_file" << std::endl;
        return 1;
    }
    (void)argv;
    std::cout << std::fixed << std::setprecision(2);
    parser(argv[1]);
   
}

