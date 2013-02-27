#ifndef COMMON_H
#define COMMON_H

#include <tulip/Algorithm.h>
#include <tulip/TulipPluginHeaders.h>
#include <stdexcept>

#define CHECK_PROP_PROVIDED(PROP, STOR) \
	do { \
		if(!dataSet->get(PROP, STOR)) \
			throw std::runtime_error(std::string("No \"") + PROP + "\" property provided."); \
	} while(0)

#endif /* COMMON_H */
