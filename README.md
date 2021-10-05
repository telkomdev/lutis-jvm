# Lutis JVM

An Experimental C/C++ Graphics Lib binding for `Java Virtual Machine`

### Requirements
- Java 8
- gcc https://gcc.gnu.org/install/binaries.html
- cmake https://cmake.org/download/
- Apache Maven https://maven.apache.org/download.cgi
- JNI

### Building

- Make sure all the requirements are complete
- Run `make all`
- Run stand alone Java archive, and dont forget to specify `OS_NAME` env variable
    ```shell
    $ cd target
    $ OS_NAME=darwin java -jar app.jar
    ```

### Status
    On Going