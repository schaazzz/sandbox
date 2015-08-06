1.) Untar OpenWrt-SDK-ar71xx-for-Linux-*.tar.bz2                                       ->   "tar xfj OpenWrt-SDK-ar71xx-for-Linux-*.tar.bz2"
2.) Untar openwrt_sandbox.tgz inside the OpenWrt-SDK-ar71xx-for-Linux-* folder         ->   "tar zxvf openwrt_sandbox.tgz"
3.) run "make" inside the sandbox/hello_openwrt/src or sandbox/sock_test/src
4.) For testing sock_test, run it on router and telnet to <router_ip>:17231