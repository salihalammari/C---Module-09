/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:19:41 by slammari          #+#    #+#             */
/*   Updated: 2023/04/11 02:22:56 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

void    read_map(std::map<std::string, float> &data_betcoin);
void parser(const char *name);
// class Btc
// {
//     private:
//         std::map<std::string, float> data_betcoin;
//     public:
//         void parser(const char *name);
//         void parse_map(std::string data);
    
// };

#endif
