# iptables

`SNAT`与`Masquerade`的区别

- `SNAT`只能工作在静态IP上，`MASQUERADE`可以工作在动态IP上。
- `MASQUERADE`比`SNAT`慢

> The Linux kernel provides an additional mechanism to use in firewall solutions: masquerading of IP packets. This means that some or all packets being forwarded by a Linux system can be changed as if there were sent from the local system. So, the source IP address is replaced by the local IP address and the source port is replaced by a locally generated port (e.g., 60005). Because an administration is kept of masqueraded sessions, incoming packets for that port will automatically be ``demasqueraded'' and forwarded to the system that originally initiated the session.

[http://lib.ru/SECURITY/ipfwadm/paper.txt_with-big-pictures.html](http://lib.ru/SECURITY/ipfwadm/paper.txt_with-big-pictures.html)

[https://unix.stackexchange.com/questions/21967/difference-between-snat-and-masquerade](https://unix.stackexchange.com/questions/21967/difference-between-snat-and-masquerade)

Linux开启路由功能

```bash
sudo sysctl -w net.ipv4.ip_forward=1
sudo iptables -A FORWARD -i wlan0 -j ACCEPT
sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
```

[https://www.frozentux.net/iptables-tutorial/iptables-tutorial.html](https://www.frozentux.net/iptables-tutorial/iptables-tutorial.html)

监听模式与混杂模式

> 无线网卡监听模式和混杂模式有什么不同：
>
> 监听模式允许网卡不用连接wifi就可以抓取特性频道的数据，就是在空气中抓取某个波段的数据。可以用在破解wifi密码上
> 混杂模式（连接wifi）就是接收所有经过网卡的数据包，包括不是发给本机的包，即不验证MAC地址

https://blog.csdn.net/jidushanbojueA/article/details/86478845 