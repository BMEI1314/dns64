**DNS64_getaddrinfo** 
[![License](https://img.shields.io/badge/license-BSD-blue.svg)](../LICENSE)
---
**Brief Description**
 With the lack of ipv4 address，many countries is to promote ipv6.
 The code is to solve the problem that ipv6 host has a access to ipv4(including:1.the IPv6 Internet to an IPv4 network,2.an IPv6 network to the IPv4 Internet,3.an IPv6 network to an IPv4 network).Learning from the APPLE ios9.2 getaddrinfo API,We know that Apple ensure IPv6 DNS64/NAT64 Compatibility.
   I have a test for the API.
   
**Testing environment:**
   - IPV6-only network by apple mac ox sharing
   - iphone6s   version:10.2
   
**Testing  way:**
  -  I invoke the getaddrinfo to query the ipv6_addr of ipv4_only domains 
  
**Testing result:**
  - analyse the returned value of getaddrinfo,I find that the api Getaddrinfo synthesizes the IPv4 address to an IPv6 address by the preifx 2001:2:0:1baa::,which means Apple company set up own DNS64/NAT64 server，the nat64 router prefix is 2001:2:0:1baa::.
 
OK....
   My project is to provide a interface that input domain or ipv4_addr ,return  a struct consisting of ip_num,ipv4_mapped ipv6 address.
   The code is written in C.Currently it is only tested on ubuntu 16.04.
###Method
   I just know three public Dns64 servers.
    1.2001:67c:27e4:15::64
    2.2001:67c:27e4:15::6411
    3.2001:67c:27e4::60
    
  **step**
  ```
  1.Combine dnsquery packet
  2.send to dns64 server(multi_pthread,once one pthread success,return)
  3.revefrom (Nonblocking，timeout default 3seconds)
  4.analyse revePacket
  5.cycle 3 times if revefrom success, break.
  6.if 3 times is all failed,try api getaddrinfo
 ```
 if the input is ipv4 address.
   1.get nat64 prefix(RFC 6052,reference to the code)
   2.replace ()
###How to Build in ubuntu

1. make sure  support ipv6-stack(eg:sudo apt-get install miredo)

2. run scripting language
  ./start.sh
