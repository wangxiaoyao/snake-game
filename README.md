# snake-game

贪吃蛇游戏。终端游戏


## 制作思路

### 1 元素

- 1 墙壁： 蛇爬行的区域范围  用*来表示。碰了墙壁，gameover。
- 2 蛇： 蛇头：用@来表示    蛇身体：用= 来表示。吃了食物会增长，碰了身体gameover
- 3 食物： 用 # 来表示，蛇碰到食物会吃掉它
- 4 移动区域： 空格区域
- 5 提示信息

### 2 游戏规则

- 1 用户按 w,s,a,d 来控制蛇
- 2 食物需要随机生成在屏幕上
- 3 游戏结束： 1 蛇碰到墙壁  2 蛇头碰到身体

### 3 代码实现

1 将游戏看成一个二维数组。x，y轴。 通过改变这个二维数组的内容，并投射到屏幕上

2 将每一个模块分开，各个功能相互依赖又分离实现

- main.cpp  总指挥，调度其他模块 主要的程序入口
- 墙模块
- 蛇模块
- 食物模块

## 后记

这是window平台下。