#ifndef __UTILS_H_
#define __UTILS_H_
#include <string>
#include <aegis.hpp>

void replace(std::string username, std::string item, std::string change);
void deleteSpace();
void pdeath(std::string username, aegis::channel& _chan);

#endif // __UTILS_H_
