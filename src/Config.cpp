/**
 * @file    Config.cpp
 * @ingroup LoggerCpp
 * @brief   Configuration for an Output object
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include "Config.h"
#include "Stream.h"

#include <stdexcept>


namespace Log
{

// Constructor
Config::Config(const char* apName) :
    mName(apName)
{
}


// Destructor
Config::~Config(void)
{
}


// Get a string value
const std::string& Config::getString(const char* apKey) const
{
    Config::Values::const_iterator iValue = mValues.find(apKey);
    if (mValues.end() == iValue)
    {
        /// @todo use a specific Exception class
        throw std::runtime_error(Stream() << "Config::getString(\"" << apKey << "\") no existing value");
    }
    return iValue->second;
}

} // namespace Log
