# Linux

`/etc/init/`目录 与 `/etc/init.d`目录的区别

> `/etc/init`：目录包含`Upstart`使用的配置文件。
>
> `/etc/init.d`: 存放`System V init`的配置文件



rc的含义

> **rc**
>
> runcom (as in .bashrc or /etc/rc)



System V init 历史

[https://www.tecmint.com/systemd-replaces-init-in-linux/](https://www.tecmint.com/systemd-replaces-init-in-linux/)

查看启动日志: `journalctl -b`

`init-system-helpers`包

>
> 包含各种帮助工具用于debian包含的各种init系统(sysvinit 和 systemd)的切换。
>
> 如`deb-systemd-helper`,使systemd的unit文件无需依赖运行的systemd.
>
> 提供"service", "invoke-rc.d",  和"update-rc.d"脚本

创建了`/etc/rcn.d`目录

`update-rc.d(8)`

> 安装或者删除System-V style风格的init脚本链接

`invoke-rc.d(8)`

> 执行System-V style风格的init脚本链接



查看当前的运行级别(runlevel)

`who -r`

`runlevel`

查看运行级别与Systemd targets的对应关系`runlevel(8)`

修改默认运行级别 `sudo systemctl set-default graphical.target`

