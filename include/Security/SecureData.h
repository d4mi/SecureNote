#ifndef __SECURE_DATA_H__
#define __SECURE_DATA_H__

#include <vector>

namespace Security
{

// Currently vector is enough but someday it may require more functionality..
typedef std::vector<unsigned char> SecureData;

} // namespace Security

#endif // __SECURE_DATA_H__