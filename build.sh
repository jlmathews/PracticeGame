
mkdir build/
cd build/

# Build redis-plus-plus command:
# cd lib/redis-plus-plus
# mkdir build
# cd build
# cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=../../hiredis/build -DHIREDIS_HEADER=../../hiredis/build/include -DHIREDIS_LIB=../../hiredis/build/lib -DREDIS_PLUS_PLUS_BUILD_TEST=OFF ..
# make

# cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH=lib/hiredis/build -DCMAKE_INSTALL_PREFIX=build/lib/ -DREDIS_PLUS_PLUS_BUILD_SHARED=OFF -DREDIS_PLUS_PLUS_BUILD_TEST=OFF -DREDIS_PLUS_PLUS_CXX_STANDARD=17 ..
# cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH=lib/hiredis -DCMAKE_INCLUDE_PATH=lib -DREDIS_PLUS_PLUS_BUILD_TEST=OFF ..
cmake -DCMAKE_BUILD_TYPE=Debug ..

if ! make all; then
	printf 'Make failed\n'
	exit 2
fi

echo 'Done'
cd ..

