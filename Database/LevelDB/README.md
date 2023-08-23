# LevelDB

## Q&A

- Q: leveldb 中如果经过多次 compact，底层文件系统产生了很多碎片，WAL 还能保持高效的顺序写性能吗？
- A: 
- Q: leveldb 中 L0 层为什么设计成互相交叠的，而其他层却不交叠？
- A:

# Raft
## Q&A
- Q: raft 如何实现从 follower 读取？
- Q: raft 中大多数节点提交某条日志后，未包含该日志的某个节点能成为 leader 吗？
- Q: raft 论文中 peer 启动的时候是 follower，可以是 candidate 吗？
- Q: raft 如何避免惊群效应？

# Linux
- 磁盘负载百分之百代表什么？
- cpu 负载过高代表什么？
- 文件系统 open 函数执行时，背后从上层到底层发生了什么？
- 虚拟内存的设计有什么好处？
- mmap 共享内存是否破坏了进程间的隔离性？