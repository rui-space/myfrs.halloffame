#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>

#define config_file "configuration.json"
#define run_path "/opt/lynx/halloffame/"

class config
{
public:
    config();
    bool get() ;

    std::string host;
    unsigned short port;
    std::string user;
    std::string password;
    std::string database;
    unsigned short db_triger_port;
    int db_reconnect_interval;
    int game_event_interval;
    int game_over_wait_interval;
    int history_refresh_interval;
    unsigned short game_event_send_port;
    unsigned short game_event_receive_port;
};

#endif // CONFIG_H
