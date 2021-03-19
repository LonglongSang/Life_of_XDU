# 1. 检查网络状况
在Linux电脑输入命令netstat -tunlpa | grep 5005
捕捉5005的端口的网络信息，显示如下：
Proto Recv-Q Send-Q Local Address           Foreign Address         State       PID/Program name
tcp        0      0 0.0.0.0:5005            0.0.0.0:*               LISTEN      8597/./server       
tcp        0      0 127.0.0.1:5005          127.0.0.1:42514         ESTABLISHED 8597/./server       
tcp        0      0 127.0.0.1:5005          127.0.0.1:42520         ESTABLISHED 8597/./server       
tcp        0      0 127.0.0.1:42520         127.0.0.1:5005          ESTABLISHED 8636/./client       
tcp        0      0 127.0.0.1:42514         127.0.0.1:5005          ESTABLISHED 8634/./client

服务端和客户端运行在同一个linux电脑上

启动了一个server去监听（LISTEN，第一条），
第2，3条为server建立的tcp socket，使用5005端口去连接client的42520和42514端口。

之后在本机启动了两个client，去连接server，第4，5条为client建立的tcp socket，使用的端口是42520、42514，去连接服务器的5005端口