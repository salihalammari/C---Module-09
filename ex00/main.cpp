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

#include "BitcoinExchange.hpp"


int main(int argc,char *argv[]) 
{
    Btc objet;

    if (argc < 2) 
    {
        std::cout << "Usage: btc input_file" << std::endl;
        return 1;
    }
    (void)argv;
    objet.parser("data.csv");
   
}