.PHONY : gen-lib build-lib package all build-vendor

NATIVE_INTERFACE_CLASS_PATH=src/main/java/com/wuriyanto/lab/lutisjvm/*.java
NATIVE_CLASS_PATH=src/main/java/com/wuriyanto/lab/lutisjvm/*.class
NATIVE_INTERFACE_CLASS_NAME='com.wuriyanto.lab.lutisjvm.Lutis'
PWD=`pwd`
LUTIS_LIB_FOLDER='lutislib'

build-vendor:
	echo 'build vendor and dependencies' \
	&& ./lutislib/script/imagemagick \
	echo 'finish build vendor and dependencies'

package:
	echo 'build maven project' && mvn clean package

gen-lib:
	echo 'generate lib header' \
	&& javac -h ./lutislib/header $(NATIVE_INTERFACE_CLASS_PATH) \
	&& rm $(NATIVE_CLASS_PATH)

build-lib:
	echo 'run cmake' \
	&& cd $(LUTIS_LIB_FOLDER) && rm -rf build \
	&& mkdir build \
	&& cd build \
	&& cmake .. \
	&& make \
	&& ls \
	&& cd ../.. \
	&& echo 'build native lib finished..'

all: build-vendor gen-lib package build-lib