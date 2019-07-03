#include "config.h"
#include "jsoncpp/json/reader.h"
#include "jsoncpp/json/json.h"
#include "rui.h"

config::config() :
    host(""),
    port(0),
    user(""),
    password(""),
    database(""),
    db_triger_port(0),
    db_reconnect_interval(0),
    game_event_interval(0),
    game_over_wait_interval(0),
    history_refresh_interval(0),
    game_event_send_port(0),
    game_event_receive_port(0) {

}

bool config::get() {
    int	fd = ::open( config_file, O_RDONLY , 0644 );
    if( fd < 0 ) {
        rlog << "open(" << config_file << ") error : "<< strerror((errno)) << ", current dir should be '"<< run_path <<"'" << std::endl ;
        return false ;
    }

    char	buffer[1000] = { 0x00 } ;
    ssize_t ret = ::read( fd, buffer, 1000 );
    if( ret < 0 ) {
        rlog << "read("<< config_file <<") error : " << strerror( errno ) << std::endl ;
        ::close(fd);
        return false ;
    }

    ::close(fd);

    Json::Value root ;
    Json::Reader reader ;

    if ( !reader.parse( buffer, root ) ) {
        rlog << "parse("<< config_file << ") json error" << std::endl ;
        ::close(fd);
        return false ;
    }

    if( !root.isMember( "host" )
            || !root.isMember( "port" )
            || !root.isMember( "user" )
            || !root.isMember( "password" )
            || !root.isMember( "database" )
            || !root.isMember( "db_triger_port" )
            || !root.isMember( "db_reconnect_interval" )
            || !root.isMember( "game_event_interval" )
            || !root.isMember( "game_over_wait_interval" )
            || !root.isMember( "history_refresh_interval" )
            || !root.isMember( "game_event_send_port" )
            || !root.isMember( "game_event_receive_port" ) ) {
        rlog << "json(" << config_file << ") error" << std::endl ;
        return false;
    }

    host = root["host"].asString() ;
    port = atoi(root["port"].asString().c_str()) ;
    user = root["user"].asString() ;
    password = root["password"].asString() ;
    database = root["database"].asString() ;
    db_triger_port = atoi(root["db_triger_port"].asString().c_str()) ;
    db_reconnect_interval = atoi(root["db_reconnect_interval"].asString().c_str()) ;
    game_event_interval = atoi(root["game_event_interval"].asString().c_str()) ;
    game_over_wait_interval = atoi(root["game_over_wait_interval"].asString().c_str()) ;
    history_refresh_interval = atoi(root["history_refresh_interval"].asString().c_str()) ;
    game_event_send_port = atoi(root["game_event_send_port"].asString().c_str()) ;
    game_event_receive_port = atoi(root["game_event_receive_port"].asString().c_str()) ;

    rlog << "host=" << host << std::endl ;
    rlog << "port=" << port << std::endl ;
    rlog << "user=" << user << std::endl ;
    rlog << "password=" << password << std::endl ;
    rlog << "database=" << database << std::endl ;
    rlog << "db_triger_port=" << db_triger_port << std::endl ;
    rlog << "db_reconnect_interval=" << db_reconnect_interval << std::endl ;
    rlog << "game_event_interval=" << game_event_interval << std::endl ;
    rlog << "game_over_wait_interval=" << game_over_wait_interval << std::endl ;
    rlog << "history_refresh_interval=" << history_refresh_interval << std::endl ;
    rlog << "game_event_send_port=" << game_event_send_port << std::endl ;
    rlog << "game_event_receive_port=" << game_event_receive_port << std::endl ;

    return true ;
}
