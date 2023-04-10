/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    BitcoinExchange.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:07:07 by slammari          #+#    #+#             */
/*   Updated: 2023/03/18 16:35:58 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void Btc::parse_map(std::string data)
{
    std::string date = data.substr(0, data.find(','));
    //std::cout << date << std::endl;
    std::string value = data.substr(data.find(',') + 1, data.length());
    //std::cout << value << std::endl;   
    data_betcoin.insert(std::pair<std::string, float> (date, std::atof(value)));
     //2009-01-02,0
}

void Btc::parser(const char *name)
{
    std::ifstream namefile;
    std::string line;
    
    namefile.open(name, std::ios::in);
    if (namefile.is_open())
    {
        //std::cout << "isopen" << std::endl;
        while (!namefile.eof())
        {
            std::getline(namefile, line);
           // std::cout << line << std::endl;
           if (line != "date,exchange_rate")
           {
                parse_map(line);

           }
        }
    }
    
}


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if ( this != &rhs )
	{
		this->_value = rhs.getValue();
	}
	return *this;
}

std::ostream &operator<<( std::ostream & o, BitcoinExchange const & i )
{
	o << "Value = " << i.getValue();
	return o;
}
