#include "queue.h"
#include "port.h"

int default_ports[1239] = { 2048, 1, 2, 3, 4, 5, 32774, 7, 8, 9, 32778, 11, 6547, 13, 15, 2064, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 33, 34, 35, 4132, 37, 38, 39, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 2108, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 4321, 27003, 6145, 13721, 5540, 7100, 13715, 4333, 27005, 242, 243, 244, 245, 246, 247, 248, 2431, 2301, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 13716, 27010, 12345, 280, 281, 282, 12346, 13701, 6147, 4144, 4827, 2049, 13717, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 6148, 321, 13718, 6699, 13708, 2103, 13709, 3128, 13710, 3421, 2105, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589, 590, 591, 592, 593, 594, 595, 596, 597, 598, 599, 600, 603, 606, 607, 608, 609, 610, 611, 617, 5520, 17007, 628, 631, 634, 636, 637, 2067, 18185, 660, 27006, 2500, 666, 2432, 2068, 2501, 674, 3455, 4660, 32779, 691, 13705, 8888, 8892, 704, 706, 3531, 2401, 709, 2766, 4557, 723, 729, 730, 731, 2784, 740, 741, 742, 744, 47557, 747, 748, 749, 750, 751, 752, 753, 754, 758, 759, 760, 761, 762, 763, 764, 765, 767, 769, 770, 771, 772, 773, 774, 775, 776, 13783, 780, 781, 782, 783, 786, 15126, 5550, 49400, 799, 800, 801, 4899, 22321, 808, 27007, 2433, 6969, 3456, 27374, 32780, 6143, 19283, 2065, 7000, 7001, 7002, 7003, 7004, 7005, 7006, 1509, 7008, 7009, 7010, 871, 873, 16959, 2638, 8080, 17300, 888, 6144, 4987, 13713, 4343, 27008, 898, 901, 902, 903, 5000, 5001, 5002, 5003, 9100, 912, 5010, 5011, 5145, 2201, 2120, 7070, 4125, 44442, 7597, 5555, 950, 3000, 953, 5050, 5530, 2053, 3006, 9152, 5060, 975, 3457, 13722, 989, 990, 4480, 992, 993, 994, 995, 996, 997, 998, 999, 1000, 3049, 1002, 3052, 5101, 5102, 1008, 13782, 3064, 6543, 5631, 1023, 1024, 1025, 1026, 1027, 1029, 1030, 1031, 1032, 1033, 2903, 5490, 3086, 1040, 27665, 1043, 13714, 4672, 2564, 1050, 8082, 7200, 7201, 1058, 1059, 31337, 8081, 1067, 1068, 54320, 2121, 2627, 1076, 1080, 1083, 1084, 6666, 6548, 32770, 5560, 3141, 5190, 5191, 5192, 5193, 44334, 22370, 1103, 2628, 2232, 1109, 1110, 1112, 32771, 1127, 5308, 11371, 5232, 1139, 5236, 32772, 1155, 1158, 2241, 3268, 1178, 32773, 7326, 6502, 5300, 5301, 5302, 5303, 5304, 5305, 1212, 6346, 1214, 3264, 1220, 3269, 1222, 1234, 9111, 32775, 1241, 6588, 3292, 4133, 1248, 32787, 3306, 5357, 2600, 32776, 2601, 2602, 9999, 2603, 3333, 2604, 9090, 2605, 18183, 6146, 32777, 2430, 5400, 44443, 5405, 5680, 4998, 7464, 3372, 18184, 18187, 7273, 5432, 1337, 3389, 9535, 1346, 1347, 1348, 1349, 1350, 1351, 1352, 1353, 1354, 1355, 1356, 1357, 1358, 1359, 1360, 1361, 1362, 1363, 1364, 1365, 1366, 1367, 1368, 1369, 1370, 1371, 1372, 1373, 1374, 1375, 1376, 1377, 1378, 1379, 1380, 1381, 1383, 1384, 1385, 1386, 1387, 1388, 1389, 1390, 1391, 1392, 1393, 1394, 1395, 1396, 1397, 1398, 1399, 1400, 1401, 1402, 1403, 1404, 1405, 1406, 1407, 1408, 1409, 1410, 1411, 1412, 1413, 1414, 1415, 1416, 1417, 1418, 1419, 1420, 1421, 1422, 1423, 1424, 1425, 1426, 1427, 1428, 1429, 1430, 1431, 1432, 1433, 1434, 1435, 1436, 1437, 1438, 1439, 1440, 1441, 1442, 1443, 1444, 1445, 1446, 1447, 1448, 1449, 1450, 1451, 1452, 1453, 1454, 1455, 1456, 1457, 1458, 1459, 1460, 1461, 1462, 1463, 1464, 1465, 1466, 1467, 1468, 1469, 1470, 1471, 1472, 1473, 1474, 1475, 1476, 1477, 1478, 1479, 1480, 1481, 1482, 1483, 1484, 1485, 1486, 1487, 1488, 1489, 1490, 1491, 1492, 1493, 1494, 1495, 1496, 1497, 1498, 1499, 1500, 1501, 1502, 1503, 1504, 1505, 1506, 1507, 1508, 40421, 1510, 1511, 1512, 1513, 1514, 1515, 1516, 1517, 1518, 1519, 1520, 1521, 1522, 1523, 1524, 1525, 1526, 1527, 1528, 1529, 1530, 1531, 1532, 1533, 1534, 1535, 1536, 1537, 1538, 1539, 1540, 1541, 1542, 1543, 1544, 1545, 1546, 1547, 1548, 1549, 1550, 1551, 1552, 7007, 2307, 1556, 6667, 32786, 13711, 20005, 3462, 5679, 3632, 6668, 1600, 2998, 18000, 5713, 5714, 5715, 5716, 5717, 3001, 26208, 19150, 5510, 3689, 3005, 1650, 1651, 1652, 8443, 1661, 1662, 1663, 1664, 1665, 1666, 1667, 1668, 1669, 1670, 1671, 1672, 13712, 1680, 9876, 5800, 5801, 5802, 5803, 6558, 1720, 1723, 4444, 27009, 6400, 4045, 4559, 1755, 12000, 1761, 1762, 1763, 1764, 2112, 6401, 6101, 7937, 7938, 18181, 18182, 9991, 9992, 1801, 6103, 5900, 5901, 5902, 5903, 10000, 22289, 2106, 10005, 6105, 6106, 22305, 1827, 2107, 6110, 6111, 3900, 8000, 6112, 8007, 8009, 8021, 22273, 27004, 5977, 5978, 5979, 27000, 10082, 10083, 13706, 13702, 1900, 5997, 5998, 5999, 6000, 6001, 6002, 6003, 6004, 6005, 6006, 6007, 6008, 6009, 27001, 6017, 5100, 4224, 1935, 3984, 3985, 3986, 5632, 4500, 13720, 27002, 3999, 4000, 6050, 4008, 2111, 6544, 2809, 1984, 1986, 1987, 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024, 2025, 2026, 2027, 2028, 2030, 6141, 2032, 2033, 2034, 2035, 6142, 2038, 2040, 2041, 2042, 2043, 2044, 2045, 2046, 2047 };

static int count1 = 0;
static int count2 = 0;
static int num_flag = false;
static unsigned int alive_list[257];
static int open_port[1000];
struct Thread_data{
	struct queue_root *queue;
	unsigned int host;
};

int CheckCIDR(const char *host)
{
	const char* re= "^([0-9]{1,3}.){0,3}[0-9]{1,3}(/[0-9]{1,2}){1}$";
	regex_t reg;
	char errbuf[1024];
	char match[20];
	int err, nm = 1;
	int len;
	regmatch_t pmatch[nm];

	if (regcomp(&reg, re, REG_EXTENDED) < 0) {
		regerror(err, &reg, errbuf, sizeof(errbuf));
		printf("[!] Error: %s\n", errbuf);
	}

	err = regexec(&reg, host, nm, pmatch, 0);

	if (err == REG_NOMATCH) {
		return false;
	}
	else {
		len = pmatch[0].rm_eo - pmatch[0].rm_so;
		if (len) {
			memset(match,'\0',sizeof(match));
			memcpy(match,host+pmatch[0].rm_so,len);
		}
		const char * delim1 = "/";
		const char * delim2 = ".";
		char *prefix = NULL;
		char *subnet = NULL;
		char *token = NULL;
		char *str = match;
		prefix = strsep(&str, delim1);
		subnet = strsep(&str, delim1);
		str = prefix;
		
		while (token = strsep(&str, delim2)) {
			int temp = atoi(token);
			if (temp < 0 || temp > 255) {
				printf("[!] Error: quad %s wrong size. 0 ~ 255\n", token);
				return false;
			}
		}
		
		int net = atoi(subnet);
		if (net < 1 || net > 32) {
			printf("[!] Error: subnet %d wrong size. 0 ~ 255\n", net);
			return false;
		}
		regfree(&reg);
		return true;
	}
}

struct queue_root *ListCIDR(const char *host)
{
	int *ips = NULL;
	const char * delim1 = "/";
 	char *prefix = NULL;
	char *subnet = NULL;
	char token[19];
	char *str = NULL;
	struct queue_root *queue = ALLOC_QUEUE_ROOT();

	strncpy(token, host, strlen(host)+1);
	str = token;
	prefix = strsep(&str, delim1);
	subnet = strsep(&str, delim1);
	int sub = atoi(subnet);	
	if (sub == 32) {
		struct queue_head *item = \
			malloc(sizeof(struct queue_head));
		INIT_QUEUE_HEAD(item);
		item->data = inet_addr(prefix);
		queue_put(item, queue);
		num_flag = true;
	}
	else {
		unsigned long a;
		char s[33];
		int i,j=0;
		unsigned long temp;
		a = inet_addr(prefix);
		for (i = 0; i < (1<<32-sub)-1;i++, j++){
			unsigned char* pip=(unsigned char*)&a;
//			printf("%u.%u.%u.%u\n", *pip,*(pip+1),*(pip+2),*(pip+3)); 
			struct queue_head *item = \
				malloc(sizeof(struct queue_head));
			INIT_QUEUE_HEAD(item);
			item->data = a;
			queue_put(item, queue);
			temp = (1<<sub);
			a += temp;
		}
	}
	return queue;		
}

int check_port(unsigned int host, int port)
{
	int result;	
	int socketfd;
	
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = host;
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	set_timeout(socketfd, 5);	

	result = connect(socketfd, (struct sockaddr*)&addr, sizeof(addr));
	if (result < 0) {
		return false;
		close(socketfd);
	}
	else {
		return true;
		close(socketfd);
	}	
}

void *scan_port(void *_thread_data){
	struct Thread_data *td = (struct Thread_data *)_thread_data;
	struct queue_root  *queue = td->queue;
	struct queue_head  *item = malloc(sizeof(struct queue_head));
	INIT_QUEUE_HEAD(item);
	
	int result;	
	int socketfd;
	
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = td->host;
	
	while (1) {
		item = queue_get(queue);
		if (!item) {
			break;
		}
		unsigned int port = item->data;
		if (port == 0)
			continue;
		
		addr.sin_port = htons(port);
		socketfd = socket(AF_INET, SOCK_STREAM, 0);
		set_timeout(socketfd, 1);	

		result = connect(socketfd, (struct sockaddr*)&addr, sizeof(addr));
		if (result < 0){
			close(socketfd);
			continue;
		} 
		else {
			open_port[count2] = port;
			count2++;
			close(socketfd);
		}
	}
	pthread_exit(NULL);	
}

void binary_insert_sort(int a[],int n)
{  
	int i;
	int j;
    for(i = 1;i < n; i++){  
		int temp = a[i];  
		int low  = 0 ;  
		int high = i;  
		//二分查找插入位置   
		while(low <= high){  
			int mid = (low + high) >> 1;   
			if(temp > a[mid])
				low = mid + 1;  
			else 
				high = mid - 1;   
        }   
        //向后移动数据   
        for(j = i - 1;j >= high + 1;j--)
			a[j+1] = a[j];  
		a[high+1] = temp; //插入   
    }   
}   

int main(int argc, char const *argv[])
{
	printf("==================================================================\n");
	printf("========================== Port Scanner ==========================\n");
	printf("==================================================================\n");
	if (argc < 4 || argc > 8)
	{
		printf("\nUsage: [-H <host>] [-P] [-p <start_port> <end_port>] [-t Threads]\n\n");
		printf("Help:\n\t-H : Target hosts example:10.10.10.130 or 10.10.10.0/24\n");
		printf("\t-P : Use default port_list or not\n");
		printf("\t     <True>  use default port_list\n");
		printf("\t     <False> use start_port to end_port\n");
		printf("\t-p : Port scan range  ,start_port <= end_port\n");
		printf("\t-t : Number of threads ,defualt Threads 100\n\n");
		printf("Example: ./scanner -H 10.10.10.1 -P \n");
		printf("Example: ./scanner -H 10.10.10.1 -P -t 80\n");
		printf("Example: ./scanner -H 10.10.10.1 -p 0 65535 -t 200\n\n");
		exit(0);
	}
	
	int i = 0;
	int thread_num = 100;
	int start_port = 0;
	int end_port = 0;
	int port_flag = false;
	const char *host = NULL;
	
	for (; i < argc; i++)
	{
		if (strcmp("-H", argv[i]) == 0) {
			host = argv[i + 1];
		}
		else if (strcmp("-P", argv[i]) == 0) {
			port_flag = true;
		}
		else if (strcmp("-p", argv[i]) == 0) {
			start_port = atoi(argv[i + 1]);
			end_port = atoi(argv[i + 2]);
		}
		else if (strcmp("-t", argv[i]) == 0) {
			thread_num = atoi(argv[i + 1]);
		}
	}

	// 解析获得扫描目标Ip
	int flag;
	unsigned int r1;
	struct queue_root *host_queue = ALLOC_QUEUE_ROOT();

	r1 = inet_addr(host);   
	if(-1 == r1){  
		flag = CheckCIDR(host);
		if (flag == true) {
			host_queue = ListCIDR(host);
		}
		else {
			printf("[!] Error: IP address not valid!\n");
			exit(0);
		}
	}
	else { 
		struct queue_head *item = malloc(sizeof(struct queue_head));
		INIT_QUEUE_HEAD(item);
		item->data = r1;
		queue_put(item, host_queue);
		num_flag = true;
	}
	
	time_t timer;
	struct tm *tblock;	
	timer = time(NULL);   
	tblock = localtime(&timer);
	
	printf("\n[*] Start Scanning With %d Threads at %s", thread_num, asctime(tblock));
	printf("[*] Testing: Testing hosts alive ...\n");
	
	// 开启多线程探测主机是否alive	
	time_t start = clock();
	struct queue_head  *item = malloc(sizeof(struct queue_head));
	INIT_QUEUE_HEAD(item);
	
	int result;
	while (1){
		item = queue_get(host_queue);
		if (!item) {
		break;
		}
		unsigned int host = item->data;
		if (host == 0)
			continue;
		char *send_buf;
		send_buf = (char *)malloc(64 * sizeof(char));	
		memset(send_buf, 0, strlen(send_buf));
		result = ping(host, send_buf);
		free(send_buf);
		send_buf = NULL;
		if (result < 0){
			continue;
		}
		else {
			struct sockaddr_in addr;
			addr.sin_addr.s_addr = host;
			printf("[+] Success: host %s is up\n", inet_ntoa(addr.sin_addr));
			alive_list[count1] = host;
			count1++;
		}
	}
	free(host_queue);
	host_queue = NULL;
	printf("[+] Over: %d hosts is up\n", count1);
		
	// 设定扫描端口
	
	struct queue_root *port_queue = ALLOC_QUEUE_ROOT();

	if (port_flag == true){
		for (i = 0; i < 1239; i++) {

			struct queue_head *item = malloc(sizeof(struct queue_head));
			INIT_QUEUE_HEAD(item);
			item->data = default_ports[i];
			queue_put(item, port_queue);
		}
	}
	else {
		for (i = start_port; i <= end_port; i++) {
			struct queue_head *item = malloc(sizeof(struct queue_head));
			INIT_QUEUE_HEAD(item);
			item->data = i;
			queue_put(item, port_queue);
		}
	}

	int j = 0;
	init();
	while (alive_list[j] != 0){
		struct Thread_data thread_data;
		thread_data.queue = port_queue;
		thread_data.host = alive_list[j];
		unsigned char* pip=(unsigned char*)&thread_data.host;
		printf("\n[*] Testing: Scanning %u.%u.%u.%u ...\n",*pip,*(pip+1),*(pip+2),*(pip+3));
		for (i = 0; i < thread_num; i++){
			pthread_t threads_id;
			if ((pthread_create(&threads_id, NULL, &scan_port, &thread_data) != 0)){
					printf("[!] Error: Create %d thread error!\n", threads_id);
					exit(1);
			}
			if((pthread_join(threads_id, NULL)) != 0){
				printf("[!] Error: Can't join with %d thread!\n", threads_id);
				exit(1);
			}			
		}	
		binary_insert_sort(open_port, count2);
		struct sockaddr_in addr;
		addr.sin_addr.s_addr = thread_data.host;
		printf("[*] Scan Result For: %s\n", inet_ntoa(addr.sin_addr));
		for (i = 0; i < count2; i++){
			int port = open_port[i];
			printf("[+] %d/tcp\topen\t%s\n", port, get_service(port));
		}
		j++;
		count2 = 0;
	}

	time_t end = clock();
	printf("\n[*] Done: Scanned in %f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);
	return 0;
}
