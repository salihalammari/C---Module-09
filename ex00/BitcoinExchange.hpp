/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:07:10 by slammari          #+#    #+#             */
/*   Updated: 2023/03/18 20:53:39 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>

class Btc
{ 
    private:
        static time_t parse_date(const std::string &date_str);
        std::map<time_t, float> bitcoin_price_;
        std::map<time_t, float> added_values_;
    public:
        Btc();
        ~Btc(void);
        Btc(const std::string &history_file_path);
        
        void add_value(const std::string &date_str, float value);
        void evaluate() const;
        
   
    
};

#endif