#ifndef _RENALOG_BASIC_H_
#define _RENALOG_BASIC_H_

namespace rena {

    typedef int errno_t;
    typedef enum {
        INFO,
        WARNING,
        ERROR
    }           lt; // log type

} // namespace rena

#endif // _RENALOG_BASIC_H_