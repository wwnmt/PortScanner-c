# PortScanner-c

一个简单的scanner，对输入的ip进行解析，能识别24位subnet的网段。对解析后的所有ip地址使用ICMP方式探测主机是否存活后，存入数组中。使用多线程对存活主机进行端口扫描。
