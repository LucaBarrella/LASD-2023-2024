
#ifndef CONTAINERTEST_HPP
#define CONTAINERTEST_HPP

#include "../../container/container.hpp"
using uint = unsigned int;
using ulong = unsigned long;

/* ************************************************************************** */

// Container member functions!

void Empty(uint&, uint&, const lasd::Container&, bool);

void Size(uint&, uint&, const lasd::Container&, bool, ulong);

/* ************************************************************************** */

#endif
