/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:19:41 by slammari          #+#    #+#             */
/*   Updated: 2023/03/19 21:00:46 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef BITCOINEXCHANGE_HPP
// #define BITCOINEXCHANGE_HPP

// #include <iostream>
// #include <string>
// #include <map>
// #include <fstream>
// #include <sstream>

// class Btc
// {
//     private:
//         std::map<std::string, float> data_betcoin;
//     public:
//         void parser(const char *name);
//         void parse_map(std::string data);
    
// };

// #endif

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>

class BitcoinExchange
{

	public:

		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		BitcoinExchange &operator=( BitcoinExchange const & rhs );

	private:

};

std::ostream &operator<<( std::ostream & o, BitcoinExchange const & i );

#endif 