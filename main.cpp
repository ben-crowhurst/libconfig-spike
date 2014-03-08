#include <cstdlib>
#include <iostream>

using namespace std;

#include <libconfig.h++>

using libconfig::Config;
using libconfig::Setting;
using libconfig::ParseException;
using libconfig::FileIOException;
using libconfig::SettingNotFoundException;

int main( int, char** )
{
    Config cfg;
    
    try
    {
        cfg.readFile( "corvusoft.cfg" );
    }
    catch( const FileIOException& fioe )
    {
        cerr << "I/O error while reading file." << endl;        
    }
    catch ( ParseException& pe )
    {
        cerr << "Parse error at " << pe.getFile( ) << ":" << pe.getLine( ) << " - " << pe.getError( ) << endl;
    }
    
    try
    {
        const Setting& root = cfg.getRoot();
        
        int port = 0;

        string value = "";

        const string& key = "application.base";

        cfg.lookupValue( key, value );

        cout << "value: " << value << endl;
    }
    catch ( const SettingNotFoundException& snfe )
    {
        cerr << "Setting not found" << endl;
    }
    
    return EXIT_SUCCESS;
}
