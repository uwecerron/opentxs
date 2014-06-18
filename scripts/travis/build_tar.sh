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

cp -rf include opentxs/
cp -rf src/otlib/.libs/libot.so opentxs/
cp -rf src/otlib/.libs/libot.so.0 opentxs/
cp -rf src/otlib/.libs/libot.so.0.0.0 opentxs/
cp -rf src/otextensions/.libs/libotextensions.so opentxs/
cp -rf src/otextensions/.libs/libotextensions.so.0 opentxs/
cp -rf src/otextensions/.libs/libotextensions.so.0.0.0 opentxs/
cp -rf src/otapi/.libs/libotapi.so opentxs/
cp -rf src/otapi/.libs/libotapi.so.0 opentxs/
cp -rf src/otapi/.libs/libotapi.so.0.0.0 opentxs/
cp -rf src/.libs/opentxs opentxs/

version=`cat VERSION`
compiler=${CXX}
package="opentxs-${version}-${build}-${os}-${compiler}.tar.gz"

echo "Creating package ${package}"
tar -vpczf ${package} opentxs/

mkdir s3
cp ${package} s3/
