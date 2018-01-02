#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netdb.h>
#include <string.h>

/* IP首部长度 */
#define IP_HEADER_LEN sizeof(struct ip)
/* icmp报文长度 */
#define ICMP_PACKET_LEN sizeof(struct icmp)
int seq = 1;
pid_t pid;

unsigned short check_sum(unsigned short *addr, int len)
{
	int size = len;
	unsigned long  cksum = 0;
	unsigned short *w = addr;
	unsigned short answer = 0;

	while(size > 1){
		cksum += *w++;
		size -= sizeof(unsigned short);
	}
	if(size == 1){
		*(unsigned char *)(&answer) = *(unsigned char *)w;
		cksum += answer;
	}
	cksum = (cksum >> 16) + (cksum & 0xffff);
	cksum += (cksum >> 16);
	answer = ~cksum;
	return answer;
}

/* 填充icmp报文 */
struct icmp *fill_icmp_packet(struct icmp *icmp_packet, int icmp_sequ, int length)
{
	pid = getpid();
	icmp_packet->icmp_type = ICMP_ECHO;
	icmp_packet->icmp_code = 0;
	icmp_packet->icmp_cksum = 0;
	icmp_packet->icmp_id = htons(pid);
	icmp_packet->icmp_seq = icmp_sequ;
	/* 填充数据 */
	int i=0;
	/* 发送时间 */
	gettimeofday((struct timeval *)icmp_packet->icmp_data, NULL);
	for (i=7; i < ICMP_PACKET_LEN; i++){
		icmp_packet->icmp_data[i] = 'A';
	}
	/* 校验和 */
	icmp_packet->icmp_cksum = check_sum((unsigned short *)icmp_packet, ICMP_PACKET_LEN);
	return icmp_packet;
}

void set_timeout(int sock, int ms)
{
	struct timeval timeout;
	timeout.tv_sec = 0;
	timeout.tv_usec = ms * 1000;

	if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0)
		printf("setsockopt failed\n");
	if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) < 0)
		printf("setsockopt failed\n");
}

int ping(unsigned int host, char *send_buf)
{
	int SockRaw;
	
	struct sockaddr_in dest;
	char recv_buf[512];
	struct ip *ip_header;
	struct icmp *icmp_packet;
	int ret_len;
	int flag = 0;

	//创建原始套接字
	if ( (SockRaw = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1){
		printf("[!] Fail to create socket!\n");
		exit(0);
	}
	//设置超时时间
	set_timeout(SockRaw, 1);
	//填充目标dest结构体
	bzero(&dest, sizeof(dest));
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = host;

	icmp_packet = fill_icmp_packet((struct icmp *)send_buf, seq, ICMP_PACKET_LEN);
	ret_len = sendto(SockRaw, send_buf, ICMP_PACKET_LEN, 0, (struct sockaddr *)&dest, sizeof(dest));
	if (ret_len < 0){
		printf("[!] Send ICMP faild!\n");	
		return -1;
	}
	memset(recv_buf, 0 ,sizeof(recv_buf));
	ret_len = recv(SockRaw, recv_buf, 64, 0);
	if (ret_len < 0)
		flag = -1;
	else{
		/* 取出ip首部 */
		/* 取出icmp报文 */
		ip_header = (struct ip *)recv_buf;
		icmp_packet = (struct icmp *)(recv_buf + IP_HEADER_LEN);
		if ((icmp_packet->icmp_type == ICMP_ECHOREPLY) && (icmp_packet->icmp_id == htons(pid))) {
			if (icmp_packet->icmp_seq < 0)
		    	flag = -1;	
//			printf("%d byte from %s: icmp_seq=%d ttl=%d \n",
//				ret_len, inet_ntoa(ip_header->ip_src), (icmp_packet->icmp_seq), ip_header->ip_ttl);
			flag = 1;
		}
		else{
			flag = -1;	
		}
	}
	return flag;
}