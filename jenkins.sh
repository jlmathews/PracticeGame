
# Remove old results files
rm -f *results.xml

# Build everything
./build.sh

# Run all unit tests
./build.sh -t

# Copy all results files to base directory
find . -name *results.xml -exec cp {} -n . \;

