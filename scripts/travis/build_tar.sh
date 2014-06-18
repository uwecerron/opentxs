#!/usr/bin/env bash
set -e

os="linux"
if [[ -z "$1" ]] ; then
    os=$1
fi

build="0"
if [[ -z "$2" ]] ; then
    build="$2"
fi

mkdir package

cp -rf include package/
cp -rf src/otlib/.libs/libot.so package/
cp -rf src/otlib/.libs/libot.so.0 package/
cp -rf src/otlib/.libs/libot.so.0.0.0 package/
cp -rf src/otextensions/.libs/libotextensions.so package/
cp -rf src/otextensions/.libs/libotextensions.so.0 package/
cp -rf src/otextensions/.libs/libotextensions.so.0.0.0 package/
cp -rf src/otapi/.libs/libotapi.so package/
cp -rf src/otapi/.libs/libotapi.so.0 package/
cp -rf src/otapi/.libs/libotapi.so.0.0.0 package/
cp -rf src/.libs/opentxs package/

version=`cat VERSION`
compiler=${CXX}-`${CXX} -dumpversion`
package="opentxs-${version}-${build}-${compiler}-${os}.tar.gz"

tar -vpczf $package package/

mkdir s3
cp ${package} s3/
