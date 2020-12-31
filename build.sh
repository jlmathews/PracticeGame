
mkdir build/
cd build/

cmake -DCMAKE_BUILD_TYPE=Debug ..

if ! make all; then
	printf 'Make failed\n'
	exit 2
fi

echo 'Done'
cd ..

