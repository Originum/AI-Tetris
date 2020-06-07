# AI-Tetris
Tetris AI game based on Pierre Dellacherie algorithm.

For randomly generated pieces, the algorithm will determine the optimal action.  
The experiments show it can achieve the elimination of 250,000 lines.  

* The evaluation function calculates the confidence value for each possible action. The maximum corresponds to the optimal action.
* The front and back ends are written in C++. The GUI is written with Qt framework.

> Please check my blog for details: https://blog.csdn.net/Originum/article/details/81570042  俄罗斯方块人工智能
