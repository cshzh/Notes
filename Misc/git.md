# git 分支相关常用命令 

## 基本命令

```bash
// 查看本地分支
git branch
// 查看远程分支
git branch -r
// 查看分支详细信息
git branch -vv
// 同步远程仓库
git fetch
// 创建分支dev
git branch dev
// 切换到分支dev
git checkout dev
// 删除分支dev
git branch -d dev
// 创建并切换到分支dev
git checkout -b dev
// 合并分支
git merge dev
```

## 远程分支

### 创建远程分支

`git push (远程仓库名) (分支名)` 或

`git push (远程仓库名) (本地分支名:运程分支名)`

```bash
// 创建远程分支dev  
git push origin dev
// 或             
git push origin dev:dev
```

意思为取出本地的dev分支，推送到远程的仓库中的dev分支去。

### 跟踪远程分支

> 从远程分支 `checkout` 出来的本地分支，称为 *跟踪分支* (tracking branch)。跟踪分支是一种和某个远程分支有直接联系的本地分支。在跟踪分支里输入 `git push`，Git 会自行推断应该向哪个服务器的哪个分支推送数据。同样，在这些分支里运行 `git pull` 会获取所有远程索引，并把它们的数据都合并到本地分支中来。

`git checkout -b [分支名] [远程名]/[分支名]`

`git checkout --track origin/dev`

```
// 从远程分支dev创建本地分支feature
git checkout -b feature origin/dev
```

> 在克隆仓库时，Git 通常会自动创建一个名为 `master` 的分支来跟踪 `origin/master`。这正是 `git push` 和 `git pull` 一开始就能正常工作的原因。

```bash
// 将本地分支feature的远程分支设为orgin/dev
git branch --set-upstream-to=origin/dev
```

### 删除远程分支

语法：`git push [远程名] :[分支名]`

```bash
// 删除远程分支dev
git push origin :dev
```
### 更新

从仓库更新更新跟踪的远程分支

```
git pull
git pull origin
```

从远程分支master合并到当前分支

```bash
git pull origin master
```

相当于

```bash
git fetch origin
git merge origin/next
```

参考：[Git-分支-远程分支](https://git-scm.com/book/zh/v1/Git-%E5%88%86%E6%94%AF-%E8%BF%9C%E7%A8%8B%E5%88%86%E6%94%AF)

# 与Github同步

将本地的一个目录下的文件与Github上一个仓库相关联。

```bash
// 初始化本地
git init
// 增加远程仓库地址
git remote add origin git@github.com:Zhao-Hui-Huang/GitLearn.git
// 从远程仓库同步
git fetch
// 检出
git checkout --track origin/master

git add .
git commit -m'add test file'
git push
```

# Git 比较命令

```bash
// 比较工作区与暂存区的文件
git diff
// 比较暂存区与最后一次commit的文件
git diff --cached
// 比较工作区与最后一次commit的文件
git diff HEAD
```