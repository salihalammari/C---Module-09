/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    BitcoinExchange.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:07:07 by slammari          #+#    #+#             */
/*   Updated: 2023/03/17 02:04:17 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>


// Define constructor to read bitcoin price history from CSV file
Btc::Btc(const std::string &history_file_path)
{
    std::ifstream bitcoin_file(history_file_path);
    if (bitcoin_file) {
        std::string line;
        while (getline(bitcoin_file, line)) 
        {
            std::stringstream ss(line);
            std::string date_str, price_str;
            getline(ss, date_str, ',');
            getline(ss, price_str);
            time_t date = parse_date(date_str);
            double price = stod(price_str);
            bitcoin_prices_[date] = price;
        }
        bitcoin_file.close();
    }
}

// Define function to add a date/value pair to evaluate
void Btc::add_value(const std::string &date_str, double value) {
    time_t date = parse_date(date_str);
    added_values_[date] = value;
}

// Define function to evaluate the bitcoin prices for all added date/value pairs
void Btc::evaluate() const 
{
    for (const auto& [date, value] : added_values_) 
    {
        auto bitcoin_price_it = bitcoin_prices_.find(date);
        if (bitcoin_price_it != bitcoin_prices_.end()) {
            double price = bitcoin_price_it->second;
            double bitcoin_amount = value / price;
            std::cout << "On " << ctime(&date) << ", " << value << " USD is worth " << bitcoin_amount << " BTC" << std::endl;
        } else {
            std::cout << "No data for " << ctime(&date) << std::endl;
        }
    }
}

// Define helper function to parse date from string
time_t Btc::parse_date(const std::string &date_str) 
{
    struct tm tm = {0};
    strptime(date_str.c_str(), "%Y-%m-%d", &tm);
    return mktime(&tm);
}
