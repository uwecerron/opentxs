#!/usr/bin/env bash

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

tar -vpczf "package.tar.gz" $TRAVIS_BUILD_DIR/package/

mkdir s3
cp package.tar.gz $TRAVIS_BUILD_DIR/s3/package.tar.gz

