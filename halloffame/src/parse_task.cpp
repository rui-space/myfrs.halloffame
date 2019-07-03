#include "task.h"
#include "net.h"
#include "parse_task.h"
#include "main_service.h"

parse_task::parse_task(std::shared_ptr<rui::task> p_task, Widget& o) :
    mo_widget(o),
    mp_task(p_task) {
    connect( this, SIGNAL(sigGameStart(const int)), mo_widget.currentThread, SLOT(gameStartSlot(const int)) );
    connect( this, SIGNAL(sigGameOver()), mo_widget.currentThread, SLOT(gameOverSlot()) );
}

void parse_task::run( )
{
    rui::mutex(mp_task.get()->m_lock);

    if ( mp_task.get()->mb_closed )
        goto quit;

    std::cout << mp_task.get()->mv_data << std::endl ;

    //解析http头
    {
        std::string s_vpath;
        rui::http::get_vpath( s_vpath, std::string( mp_task.get()->mv_data.begin() , mp_task.get()->mv_data.end() ), rui::http::GET );

        mp_task.get()->mv_data.assign( s_vpath.begin(), s_vpath.end() ) ;

        URLContainer map_url_arg;
        rui::http::parse_url( map_url_arg, s_vpath );
        std::string s_do( get_map_value( map_url_arg, rui::http::VPATH ) );

        if( s_do != "session.do" ) {
            char msg[1000] = {0x00};
            sprintf(msg,"parse_task(%d) http protocol error", mp_task.get()->mi_fd);
            rlog << msg << std::endl ;
            goto quit;
        }

        std::string s_session_id = get_map_value( map_url_arg, std::string( "session_id" ) );
        std::string s_state = get_map_value( map_url_arg, std::string( "state" ) );

        if( s_session_id.empty() ||
                s_state.empty() )
        {
            char msg[1000] = {0x00};
            sprintf(msg,"parse_task(%d) http protocol error", mp_task.get()->mi_fd);
            rlog << msg << std::endl ;
            goto quit;
        }

        if ( s_state == "2" )
            emit sigGameStart(atoi(s_session_id.c_str()));
        else
            emit sigGameOver();
    }

quit:
    main_service::_instance(mo_widget).del_task(mp_task);
}


