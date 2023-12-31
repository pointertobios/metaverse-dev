# Metaverse内核

基于multiboot2引导的64位内核。

## 试用

* 编译

```bash
make
```

* 编译发布版

```bash
make release=1
```

* 运行

```bash
make run
```

* gdb调试

```bash
make debug
```

> 暂不支持交叉编译和调试

## 依赖项

* nbd
* qemu

## 架构支持

* [x] x86_64
* [ ] aarch64
* [ ] loongarch

## 功能模块

* [x] 内存管理
  * [x] 页分配
  * [ ] 页回收
  * [x] 内存分配器
    * [x] raw_allocator
* [x] tty
* [ ] 内核日志
* [ ] 文件系统
  * [ ] vfs
  * [ ] fat32驱动（移植）
  * [ ] ext4驱动（移植）
* [ ] 驱动管理
* [ ] 进程管理

## 版权声明

版权所有 (c) 2023 - 现在 Random World Studio 保留所有权利。

本软件使用MIT开源许可证进行许可。详细信息请参阅许可证文件。
