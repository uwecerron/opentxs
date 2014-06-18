#!/usr/bin/env bash
set -x

mkdir package

cp -rf $TRAVIS_BUILD_DIR/include $TRAVIS_BUILD_DIR/package/
cp -rf $TRAVIS_BUILD_DIR/src/otlib/.libs/libot.so $TRAVIS_BUILD_DIR/package/
cp -rf $TRAVIS_BUILD_DIR/src/otlib/.libs/libot.so.0 $TRAVIS_BUILD_DIR/package/
cp -rf $TRAVIS_BUILD_DIR/src/otlib/.libs/libot.so.0.0.0 $TRAVIS_BUILD_DIR/package/
cp -rf $TRAVIS_BUILD_DIR/src/otextensions/.libs/libotextensions.so $TRAVIS_BUILD_DIR/package/
cp -rf $TRAVIS_BUILD_DIR/src/otextensions/.libs/libotextensions.so.0 $TRAVIS_BUILD_DIR/package/
cp -rf $TRAVIS_BUILD_DIR/src/otextensions/.libs/libotextensions.so.0.0.0 $TRAVIS_BUILD_DIR/package/
cp -rf $TRAVIS_BUILD_DIR/src/otapi/.libs/libotapi.so $TRAVIS_BUILD_DIR/package/
cp -rf $TRAVIS_BUILD_DIR/src/otapi/.libs/libotapi.so.0 $TRAVIS_BUILD_DIR/package/
cp -rf $TRAVIS_BUILD_DIR/src/otapi/.libs/libotapi.so.0.0.0 $TRAVIS_BUILD_DIR/package/
cp -rf $TRAVIS_BUILD_DIR/src/.libs/opentxs $TRAVIS_BUILD_DIR/package/

version=`cat VERSION`
compiler=${CXX}-`${CXX} -dumpversion`
os=$TRAVIS_OS_NAME
package="opentxs-${version}-${TRAVIS_BUILD_NUMBER}-${compiler}-${os}.tar.gz"

tar -vpczf $package package/

mkdir s3
cp ${package} $TRAVIS_BUILD_DIR/s3/
