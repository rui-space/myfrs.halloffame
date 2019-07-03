#!/bin/bash

apt-get install -y debconf-utils build-essential cmake dos2unix qt5-default qtcreator libqt5widgets5 libqt5gui5 libqt5core5a libqt5core5a libqt5sql5 libqt5sql5-mysql libqt5network5 libjsoncpp-dev libmysqlclient-dev

rm -rvf /usr/lib/x86_64-linux-gnu/libprotobuf.so
rm -rvf /usr/lib/x86_64-linux-gnu/libprotobuf.a
ln -s /usr/local/protobuf/lib/libprotobuf.so /usr/lib/x86_64-linux-gnu/libprotobuf.so
ln -s /usr/local/protobuf/lib/libprotobuf.a /usr/lib/x86_64-linux-gnu/libprotobuf.a

mkdir -p build_ && cd build_
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
make
make install
make package
