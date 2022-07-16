# krunnerStocksMarket

View the price of a stock in KRunner.

![01:](https://i.pstorage.space/i/pLX6Zx685/original_01.png)

![02:](https://i.pstorage.space/i/ODo7pM75k/original_02.png)

![03:](https://i.pstorage.space/i/m1P7ZR7R0/original_03.png)

![04:](https://i.pstorage.space/i/yo72Mg2Jm/original_04.png)

Obs.: Market state: **C**lose , **O**pen

Build/Runtime Dependencies
==================

**Debian**

* apt install build-essential cmake extra-cmake-modules libkf5runner-dev

Get
===

$ git clone https://github.com/jacksonlopes/krunnerStocksMarket.git

Compile
=======

**Inside directory 'krunnerStocksMarket':**

**#** cmake -Bbuild -DKDE_INSTALL_PLUGINDIR=$(kf5-config --qt-plugins) -DCMAKE_BUILD_TYPE=Release

**#** cd build

**#** make

**Debian:**

**#** cp build/bin/krunner_stocksmarket.so /usr/lib/x86_64-linux-gnu/qt5/plugins/kf5/krunner

**#** cp ../src/plasma-runner-krunnerstocksmarket.desktop /usr/share/kservices5

**Restart KRunner:**

**#** kquitapp5 krunner

References
==========

[KRunner Development](https://techbase.kde.org/Development/Tutorials/Plasma4/AbstractRunner) - Basic Anatomy of a Runner.

[KDE API Krunner](https://api.kde.org/frameworks/krunner/html/index.html) - KDE API Krunner.

[krunnercrypto](https://github.com/santiacq/krunnercrypto) - CMakeLists.txt, *.desktop

[Yahoo Finance API](https://finance.yahoo.com/quotes/API,Documentation/view/v1) - API Finance.

[Http Request Using Qt 5](https://karanbalkar.com/posts/sending-http-request-using-qt5) - HTTPS Get in QT5.
