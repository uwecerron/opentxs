#!/usr/bin/env bash
set -e

os="$1"
if [[ -z "$1" ]] ; then
    os="linux"
fi

build="$2"
if [[ -z "$2" ]] ; then
    build="0"
fi

mkdir opentxs

# opentxs
cp -rf include opentxs/
if [[ "$os" == "linux" ]] ; then
    cp -rf src/otlib/.libs/libot.so opentxs/
    cp -rf src/otlib/.libs/libot.so.0 opentxs/
    cp -rf src/otlib/.libs/libot.so.0.0.0 opentxs/
    cp -rf src/otextensions/.libs/libotextensions.so opentxs/
    cp -rf src/otextensions/.libs/libotextensions.so.0 opentxs/
    cp -rf src/otextensions/.libs/libotextensions.so.0.0.0 opentxs/
    cp -rf src/otapi/.libs/libotapi.so opentxs/
    cp -rf src/otapi/.libs/libotapi.so.0 opentxs/
    cp -rf src/otapi/.libs/libotapi.so.0.0.0 opentxs/
else
    cp -rf src/otlib/.libs/libot.0.dylib opentxs/
    cp -rf src/otlib/.libs/libot.dylib opentxs/
    cp -rf src/otextensions/.libs/libotextensions.0.dylib opentxs/
    cp -rf src/otextensions/.libs/libotextensions.dylib opentxs/
    cp -rf src/otapi/.libs/libotapi.0.dylib opentxs/
    cp -rf src/otapi/.libs/libotapi.dylib opentxs/
fi
cp -rf src/.libs/opentxs opentxs/

# deps
mkdir opentxs/include/misc
cp -rf deps/include/misc/Timer.hpp opentxs/include/misc/
cp -rf deps/include/misc/tinythread.hpp opentxs/include/misc/
cp -rf deps/include/containers opentxs/include/
cp -rf deps/include/irrxml opentxs/include/
cp -rf deps/src/irrxml/.libs/libirrxml.a opentxs/

version=`cat VERSION`
compiler=${CXX}
package="opentxs-${version}-${build}-${os}-${compiler}.tar.gz"

echo "Creating package ${package}"
tar -vpczf ${package} opentxs/

mkdir s3
cp ${package} s3/
