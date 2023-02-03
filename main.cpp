#include<bits/stdc++.h>
#include"filesystem/filesystem.h"

using namespace std;

int main(){
    time_t t = get_file_last_modified_time( "E:/program_database.db" );
    cout << ctime( &t );
    cout << get_file_size( "E:/program_database.db" ) << endl;
    return 0;
}