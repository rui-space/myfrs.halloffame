#include <QCoreApplication>
#include "Common.pb.h"
#include <google/protobuf/message.h>
#include <asio.hpp>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int j = 0;

    while(true) {

        Common::PlayerScore obj;
        for(int i=0; i<40;i++) {
            Common::PlayerStats *ps = obj.add_values() ;
            ps->set_score(::google::protobuf::uint32(i+j));
            ps->set_score_leader(::google::protobuf::uint32(i+10));
            ps->set_score_follower(::google::protobuf::uint32(i+10));
            ps->set_rank(::google::protobuf::uint32(40-i));
            ps->set_accuracy(float_t(1.0));
            ps->set_collectible(::google::protobuf::uint32(i+10));
        }

        j++;

        asio::io_service io;
        asio::ip::udp::socket socket_(io);
        asio::ip::udp::endpoint receiverEndpoint_(asio::ip::address::from_string("127.0.0.1"), 35606);
        socket_.open(asio::ip::udp::v4());

        asio::streambuf buf;
        std::ostream os(&buf);
        obj.SerializeToOstream(&os);
        socket_.send_to(buf.data(), receiverEndpoint_);

        socket_.close();

        usleep(10);
    }

    exit(0);


    return a.exec();
}
