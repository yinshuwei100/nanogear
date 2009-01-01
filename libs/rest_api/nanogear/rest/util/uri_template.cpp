/*
 * Nanogear - C++ web development framework
 * Class to parse URI templates as specified at
 *   http://bitworking.org/projects/URI-Templates/
 *
 * Copyright (C) 2008 Lorenzo Villani.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <map>
#include <string>
#include <exception>
#include <iostream>

#include <boost/regex.hpp>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>


#include "uri_template.hpp"

namespace nanogear {
namespace rest {
namespace util {

std::string& uri_template::operator[](const std::string& key)
{
    return m_vars[key];
}

void uri_template::set_template_string(const std::string& template_string)
{
    m_template_string = template_string;
}
const std::string& uri_template::template_string() const
{
    return m_template_string;
}

std::string uri_template::expanded()
{
    // Define regexp
    const boost::regex command("\\{-(\\w+)\\|(.+)\\|(.+)\\}");
    const boost::regex variable("\\{(\\w+)\\}");
    const boost::regex variable_defval("\\{(\\w+)=(\\w+)\\}");
    
    // Step 1: Normalization
    // TODO: Normalize the URI and %-encode all the character outside the
    //       reserved space
    // Parsing and substitutions (done via regexp parser)
    // Step 2: variable substitutions
    // Step 2-a: simple variables
    boost::match_results<std::string::const_iterator> what;
    
    // Step 1: variables
    std::string pass_vars(m_template_string);
    std::string::const_iterator ib, ie;
    ib = pass_vars.begin(); ie = pass_vars.end();
    while(regex_search(ib, ie, what, variable, boost::match_default)) {
        std::string var(what[1].first, what[1].second);
        boost::algorithm::replace_all(pass_vars, "{" + var + "}", m_vars[var]);
        ib = what[0].second; // move forward
    }

    // Step 2: variables with default values
    std::string pass_vars_defval(pass_vars);
    ib = pass_vars_defval.begin(); ie = pass_vars_defval.end();
    while(regex_search(ib, ie, what, variable_defval, boost::match_default)) {
        std::string var(what[1].first, what[1].second);
        std::string val(what[2].first, what[2].second);
        if (m_vars[var] == "") {
            boost::algorithm::replace_all(pass_vars_defval, "{" + var + "=" + val + "}", val);
        } else {
            boost::algorithm::replace_all(pass_vars_defval, "{" + var + "=" + val + "}", m_vars[var]);
        }
        ib = what[0].second; // move forward
    }
    
    // Step 2: commands
    std::string pass_commands(pass_vars_defval);
    ib = pass_commands.begin(); ie = pass_commands.end();
    while(regex_search(ib, ie, what, command, boost::match_perl)) {
        std::string command(what[1].first, what[1].second);
        std::string parameter(what[2].first, what[2].second);
        std::string varlist(what[3].first, what[3].second);
        std::string command_p("{-" + command + "|" + parameter + "|" + varlist + "}" );
        
        if (command == "opt") { // only single vars
            if (m_vars[varlist] != "") {
                boost::algorithm::replace_all(pass_commands, command_p, parameter);
            } else {
                boost::algorithm::replace_all(pass_commands, command_p, "");
            }
        } else if (command == "neg") { // only single vars
            if (m_vars[varlist] == "") {
                boost::algorithm::replace_all(pass_commands, command_p, parameter);
            } else {
                boost::algorithm::replace_all(pass_commands, command_p, "");
            }
        } else if (command == "prefix") {
        } else if (command == "suffix") {
        } else if (command == "join") {
            
        } else if (command == "list") {
        } else {
            throw std::exception(); // TODO: throw appropriate exception type
        }
        ib = what[0].second; // move forward
    }

    return pass_commands; // FIXME: for now...
}

}
}
}