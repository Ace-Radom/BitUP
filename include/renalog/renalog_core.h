#ifndef _RENALOG_CORE_H_
#define _RENALOG_CORE_H_

#include<time.h>
#include<string>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<io.h>
#include<direct.h>
#include<chrono>
#include<sstream>
#include<list>
#include<vector>
#include<sys/stat.h>

#include"renalog_basic.h"

#define L_OK 0x00
#define L_OPENLOGFILEERROR -( 0x01 )

namespace rena {

    class renalog{

        // Constructor:
        public:
            renalog( std::string __log_folder  );

        // public interface:
        public:
            errno_t open( std::string __log_title  );
            void close();

            void log( lt __lt , std::string __from , std::string __info );
            void comment( std::string __info );
            void wrap();

        // data members:
        protected:
            std::string log_folder_path;
            std::string logfile_path_now;

            time_t time_now;

        // file stream member:
        protected:
            std::fstream File;

        // functional functions:
        private:
            std::string get_microsecondsnow();

            void create_parent_folder( std::string );
            std::string get_parent_folder_from_path( std::string );

            void delete_colon_in_info_from( std::string& );

    }; // class renalog

} // namespace rena

#endif // _RENALOG_CORE_H_