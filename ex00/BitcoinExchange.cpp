/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:07:07 by slammari          #+#    #+#             */
/*   Updated: 2023/04/11 02:43:40 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::pair<std::string, float> parse_data(std::string data, char c)
{
	std::map<std::string, float> data_betcoin;
	std::string date = data.substr(0, data.find(c));
	//std::cout << date << std::endl;
	std::string value = data.substr(data.find(c) + 1, data.length());
	//std::cout << value << std::endl;
	data_betcoin[date] = std::atof(value.c_str());
	return make_pair(date, std::atof(value.c_str()));
	// data_betcoin.insert(std::pair<std::string, float> (date, std::atof(value.c_str())));
	 //2009-01-02,0
}

void    read_map(std::map<std::string, float> &data_betcoin)
{
	std::string line;
	std::ifstream namefile;
	namefile.open("data.csv");
	if (namefile.is_open())
	{
		//std::cout << "isopen" << std::endl;
		while (!namefile.eof())
		{
			std::getline(namefile, line);
		   // std::cout << line << std::endl;
		   if (line != "date,exchange_rate")
		   {
				data_betcoin.insert(parse_data(line, ','));
		   }
		}
	}
}
// 2021-09-09
bool check_input(std::string str){

	int year, month, day;
	year = std::atoi(str.substr(0, str.find('-')).c_str());
	month = std::atoi(str.substr(str.find('-') + 1, 2).c_str());
	day = std::atoi(str.substr(str.find_last_of('-') + 1, 2).c_str());
	std::cout << year << " " << month << " " << day << std::endl;
	if (year < 0 || month < 1 || month > 12 || day < 1) {
		return false;
	}
	if (month == 2) {
	if (day > 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
		return false;
	}
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
	if (day > 30) {
		return false;
	}
	} else {
	if (day > 31) {
		return false;
	}
	}

return true;
}


void parser(const char *name)
{
	std::ifstream namefile(name);
	std::string line;
	
	std::map<std::string, float> data_betcoin;
	std::pair<std::string, float> input;
	read_map(data_betcoin);
	if (namefile.is_open())
	{
		//std::cout << "isopen" << std::endl;
		while (!namefile.eof())
		{
			std::getline(namefile, line);
		   // std::cout << line << std::endl;
		   if (line != "data | value" && !line.empty())
		   {
				input = parse_data(line, '|');
				std::cout << input.first << " " << input.second << std::endl;
				if (check_input(input.first))
					std::cout << "Done" << std::endl;
				else
					std::cout << "Error" << std::endl;
		   }
		}
	}
	
}


// #include "BitcoinExchange.hpp"

// BitcoinExchange::BitcoinExchange()
// {
// }

// BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
// {
// }

// BitcoinExchange::~BitcoinExchange()
// {
// }

// BitcoinExchange &BitcoinExchange::operator=( BitcoinExchange const & rhs )
// {
// 	if ( this != &rhs )
// 	{
// 		this->_value = rhs.getValue();
// 	}
// 	return *this;
// }

// std::ostream &operator<<( std::ostream & o, BitcoinExchange const & i )
// {
// 	o << "Value = " << i.getValue();
// 	return o;
// }
