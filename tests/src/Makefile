all:
	mkdir -p build \
		&& cd build \
		&& cmake .. \
		&& make
	make run

clean:
	rm -rf build

run:
	MallocNanoZone=0 ./build/test
