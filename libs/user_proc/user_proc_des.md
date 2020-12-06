# user_proc.dll 覆盖文档

自定义库文件`user_proc.dll`放在程序根目录下，如有需要可以自行覆盖该库。

## 上位机环境

opencv：3.4.10
请在封装dll的时候务必确认好opencv的版本

## 封装注意事项


覆盖该库，请务必实现以下函数：

```
extern "C"   __declspec(dllexport) int frameExchange(cv::Mat & src
        , cv::Mat & dst);
```

该函数的作用是传入一个`cv::Mat`类型的`src`，返回一个`cv::Mat`类型的`dst`。

参数的名字名没有意义。

程序并不关心覆盖者在该函数中实现了什么，对传入的mat做出了怎样的改变。

但是请注意，请将您实现的算法的时间耗时，控制在一个可以接受的范围之内。

封装的过程可以查看下面的`封装过程`：[封装dll的方法](#jump)

##  使用源代码需要注意

可以将已经编译好的库文件放在路径 `$$PWD/libs/users`下，编译后会自动复制文件到输出路径。


## 封装过程

<span id="jump"></span>

### 使用vs2019进行封装

1. 建立一个“库（也有可能叫做动态链接库、DLL）”项目。
2. 修改项目属性。
3. 在“`c/c++-->常规`”中，增加“附加包含目录”的路径为对应`opencv`的`include`路径。
4. 增加“`链接器-->常规`”中“附加库目录为`opencv`的`lib`路径。
5. 增加”`链接器-->输入`”中“附加依赖项”，为`opencv_worldxxx.lib`和`opencv_worldxxxd.lib`
6. 确定修改
7. 新建头文件`yourName.h`，在该头文件中放入任意的你希望执行的函数的函数声明
8. 新建源文件`yourName.cpp`，在该头文件中放入任意的你希望执行的函数的函数实现，这两个文件的内容是自定义的。
9. 新建头文件`user_proc.h`
10. 输入：

```c++
#pragma once

#include <opencv2/opencv.hpp>

extern "C" __declspec(dllexport) int frameExchange(cv::Mat & src, cv::Mat & dct);
```
11. 新建源文件`user_proc.cpp`
12. 输入：
```c++
#include "pch.h"
#include "user_proc.h"
#include "younName.h"

int frameExchange(cv::Mat& src, cv::Mat& dst) {

	......在这里放入你希望对src执行的操作，最后为dst赋值即可。
}

```

13. 生成解决方案
14. 到项目输出路径下（一般就是源路径），根据你的编译方式（debug、release）到对应文件夹中，可以看到已经生成出来的dll文件、lib文件
15. 只需要将dll文件复制替换上位机根目录下的`user_proc.dll`文件，即可完成替换。