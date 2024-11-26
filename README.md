## install PCL ##
sudo apt install libpcl-dev

## clone and create build dir ##
cd utils && mkdir build

## build ##
cd build && cmake ..
make

## play ##
./generate_plane
