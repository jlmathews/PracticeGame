
LUAINC=/usr/include/lua5.3/
LUALIB="/usr/lib/x86_64-linux-gnu;/usr/lib/x86_64-linux-gnu/liblua5.3.so"

mkdir build/
cd build/

# cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH=lib/hiredis/build -DCMAKE_INSTALL_PREFIX=build/lib/ -DREDIS_PLUS_PLUS_BUILD_SHARED=OFF -DREDIS_PLUS_PLUS_BUILD_TEST=OFF -DREDIS_PLUS_PLUS_CXX_STANDARD=17 ..
# cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH=lib/hiredis -DCMAKE_INCLUDE_PATH=lib -DREDIS_PLUS_PLUS_BUILD_TEST=OFF ..
cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_DOC=OFF -DLUA_INCLUDE_DIR=$LUAINC -DLUA_LIBRARIES=$LUALIB ..

if ! make all; then
	printf 'Make failed\n'
	exit 2
fi

echo 'Done'
cd ..

