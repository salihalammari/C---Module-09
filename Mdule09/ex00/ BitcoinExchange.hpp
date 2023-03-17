/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    BitcoinExchange.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:07:10 by slammari          #+#    #+#             */
/*   Updated: 2023/03/17 01:53:24 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_HPP
#define BTC_HPP

#include <string>
#include <map>

class Btc
{
    public:
        Btc(const std::string &history_file_path);
        void add_value(const std::string &date_str, double value);
        
        void evaluate() const;
        
    private:
        static time_t parse_date(const std::string &date_str);
        std::map<time_t, double> bitcoin_price_;
        std::map<time_t, double> added_values_;
};

#endif