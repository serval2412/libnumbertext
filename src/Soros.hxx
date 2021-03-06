/* Soros interpreter (see numbertext.org)
 * 2018 (c) László Németh
 * License: LGPL/BSD dual license */

#ifndef SOROS_HXX_
#define SOROS_HXX_

#include <iostream>
#include <iterator>
#include <string>

#ifndef _MSC_VER
#include "config.h"
#endif

#ifdef HAVE_BOOST_REGEX_HPP
  #include <boost/regex.hpp>
#else
  #include <regex>
#endif

class Soros {

public:
    Soros(std::wstring program, std::wstring filtered_lang);
    int run(std::wstring& input);
    static std::wstring translate(std::wstring s,
                std::wstring chars, std::wstring chars2, std::wstring delim);
private:
    void run(std::wstring& input, int& level, bool begin = true, bool end = true);
    static void replace(std::wstring& s, const std::wstring& search,
                const std::wstring& replace);

#ifdef HAVE_BOOST_REGEX_HPP
    std::vector<boost::wregex> patterns;
    static const boost::wregex func;
#else
    std::vector<std::wregex> patterns;
    static const std::wregex func;
#endif
    std::vector<std::wstring> values;
    std::vector<bool> begins;
    std::vector<bool> ends;

    static const std::wstring m, m2, c, c2, slash, pipe;
};

#endif
