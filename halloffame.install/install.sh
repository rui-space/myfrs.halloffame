#!/bin/bash

apt update
apt -y install automake curl g++ debconf-utils cmake vim dos2unix libqt5widgets5 libqt5gui5 libqt5core5a libqt5core5a libqt5sql5 libqt5sql5-mysql libqt5network5 libjsoncpp-dev libmysqlclient-dev libreadline-dev git bzip2 make build-essential  openssl autoconf libtool doxygen libc++-dev libssl-dev

if [ $? -ne 0 ] ; then
	echo "install failure"
	return
fi

tar xzvf protobuf-3.5.0.tar.gz

cd protobuf-3.5.0/
dos2unix autogen.sh
./autogen.sh
if [ $? -ne 0 ] ; then
	echo "autogen failure"
	./autogen.sh
fi

./configure --prefix=/usr/local/protobuf
make -j4
#make check 
make install

echo "" >> /etc/profile
echo "export PATH=$PATH:/usr/local/protobuf/bin/" >> /etc/profile
echo "export PKG_CONFIG_PATH=/usr/local/protobuf/lib/pkgconfig/" >> /etc/profile
source /etc/profile

echo "/usr/local/protobuf/lib" >> /etc/ld.so.conf.d/libprotobuf.conf
ldconfig

rm -rvf /usr/lib/x86_64-linux-gnu/libprotobuf.so
rm -rvf /usr/lib/x86_64-linux-gnu/libprotobuf.a
ln -s /usr/local/protobuf/lib/libprotobuf.so /usr/lib/x86_64-linux-gnu/libprotobuf.so
ln -s /usr/local/protobuf/lib/libprotobuf.a /usr/lib/x86_64-linux-gnu/libprotobuf.a

cd ..

dpkg -i --force-overwrite halloffame-1.0.0-Linux.deb
dpkg -i --force-overwrite mycpp-1.0.0-Linux.deb
ldconfig
cp -rvf lightdm.conf /etc/lightdm/
cp -rvf .profile ~/

