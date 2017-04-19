
#include "dnsquery.h"
int main(int argc,char **argv)
{
   if(argc<=1)
   { 
     printf("eg:./test domain(www.baidu.com)/ipv4_addr(192.168.0.2)\n");
    return -1;
   }
    struct socket_ipinfo_t *test_ipv6=(struct socket_ipinfo_t *)malloc(sizeof(socket_ipinfo_t));
    char *host=argv[1];
    char v6_ip[64] = {0};
    //socket_gethostbyname(host, test_ipv6,2000/*ms*/,dnsserver1);
    getaddrinfo_v6(host, test_ipv6,3000/*ms*/);
   printf("size:%d\n",test_ipv6->size);
    for(int i=0;i<(test_ipv6->size);i++)
    {
        inet_ntop(AF_INET6, &test_ipv6->v6_addr[i].s6_addr, v6_ip, sizeof(v6_ip));
        printf("%s\n",v6_ip);
    }
    free(test_ipv6);
    return 0;
}
