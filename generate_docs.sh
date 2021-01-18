
mkdir build/
cd build/

cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_DOC=ON ..

if ! make all; then
	printf 'Make failed\n'
	exit 2
fi

echo 'Done'
cd ..

