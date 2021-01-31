
EnableTests=OFF
GenerateDocuments=OFF

while getopts td flag
do
    case "${flag}" in
        t)
        EnableTests=ON
        echo "Tests Enabled"
        ;;
        d)
        GenerateDocuments=ON
        echo "Document Generation Enabled"
        ;;
        \?)
        echo "Invalid Option: -$OPTARG" 1>&2
        exit 1
        ;;
    esac
done

LUAINC=/usr/include/lua5.3/
LUALIB="/usr/lib/x86_64-linux-gnu;/usr/lib/x86_64-linux-gnu/liblua5.3.so"

mkdir build/
# Remove old resources directory if it exists
rm -rf build/resources
# Copy resources directory to build directory
cp -r resources/ build/resources
cd build/

# cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH=lib/hiredis/build -DCMAKE_INSTALL_PREFIX=build/lib/ -DREDIS_PLUS_PLUS_BUILD_SHARED=OFF -DREDIS_PLUS_PLUS_BUILD_TEST=OFF -DREDIS_PLUS_PLUS_CXX_STANDARD=17 ..
# cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH=lib/hiredis -DCMAKE_INCLUDE_PATH=lib -DREDIS_PLUS_PLUS_BUILD_TEST=OFF ..
cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_DOC=$GenerateDocuments -DBUILD_TESTS=$EnableTests -DLUA_INCLUDE_DIR=$LUAINC -DLUA_LIBRARIES=$LUALIB ..

echo $EnableTests

if [ $EnableTests = "ON" ]
then
    if ! make test; then
        printf 'Make failed\n'
        exit 2
    fi
elif [ $GenerateDocuments = "ON" ]
then
    if ! make doc_doxygen; then
        printf 'Make failed\n'
        exit 2
    fi
else
    if ! make all; then
        printf 'Make failed\n'
        exit 2
    fi
fi

echo 'Done'
cd ..
