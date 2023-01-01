#include  <regex> 
class FictoRegex{
public:
bool match( std::string entry, std::string rule ) { 
return regex_match(entry, regex(rule)); 
} 
std::string find() {} 
}; 