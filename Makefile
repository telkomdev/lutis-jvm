.PHONY : gen-lib build-lib package

NATIVE_INTERFACE_CLASS_PATH=src/main/java/com/wuriyanto/lab/lutisjvm/*.java
NATIVE_CLASS_PATH=src/main/java/com/wuriyanto/lab/lutisjvm/*.class
NATIVE_INTERFACE_CLASS_NAME='com.wuriyanto.lab.lutisjvm.Lutis'
PWD=`pwd`
LUTIS_LIB_FOLDER='lutislib'

package:
	mvn clean package

gen-lib:
	javac -h ./lutislib/header $(NATIVE_INTERFACE_CLASS_PATH) \
	&& rm $(NATIVE_CLASS_PATH)

build-lib:
	cd $(LUTIS_LIB_FOLDER) && rm -rf build \
	&& mkdir build \
	&& cd build \
	&& cmake .. \
	&& make \
	&& ls \
	&& cd ../.. \
	&& echo 'build native lib finished..'