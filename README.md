install PCL:
sudo apt install libpcl-dev

clone and create build dir
cd utils && mkdir build
cd build && cmake ..
make
./generate_plane
