## week11_question

leetcode91、95、96、97、115、120、121、123、132、139

共10题

## week11_exercise

- none

## week11_shared

- **Dijkstra** 算法思路

  - 首先介绍几个图论知识的相关概念

    - $G$ 的顶点数和边数分别用符号$v(G)$和$\varepsilon(G)$ 表示
    - $G$ 的**邻接矩阵**，是一个$v\times v$ 的矩阵$A(G)=[a_{ij}]$ ，其中$a_{ij}$ 是连接$v_i$ 和 $v_j$ 的边的数目.
    - $G$ 的顶点$v$ 的**度** $d_G(v)$ 是指$G$ 中与 $v$ 关联的边的数目，每个环算作两条边. 
    - $G$ 的一条**途径**（或**通道**）是指一个有限非空序列 $W= v_0 e_1 v_1 e_2 v_2\cdots e_kv_k$，它的项交替地为顶点和边，使得对 $1\le i\le k$，$e_i$ 的端点是$v_{i-1}$ 和$v_i$. 称$W$ 是从$v_0$ 到$v_k$ 的一条途径，或一条$(v_0, v_k)$ 途径顶点。$v_0$ 和$v_k$ 分别称为$W$ 的起点和终点，而$v_1,v_2,\cdots, v_{k-1}$ 称为它的内部顶点. 整数$k$ 称为 $W$ 的长.
    - 对$G$ 的每一边$e$，可赋予一个实数$w(e)$，称为$e$ 的权. $G$ 连同它边上的权称为**赋权图**. 

    - $(u,v)$ 路的最小权称为$u$ 和$v$ 之间的距离，并记为$d(u,v)$.

    - 当 $uv\notin E​$ 时，规定$w(uv)= \infty​$.

  1. 假设$S$ 是$V$ 的真子集且$u_0\in S$ ，并以$\overline S $ 记 $S-V$. 若 $P =u_0\cdots \overline u \overline v$ 是从$u_0$ 到$\overline S$ 的最短路，则显然$\overline u\in S$ 且$P$ 的$(u_0,\overline u)$ 节必然是最短$(u_0,\overline u)$ 路，所以

     ​									$d(u_0,\overline v)=d(u_0, \overline u) + w(\overline u \overline v)$   

  2. 从$u_0$ 到$\overline S$ 的距离由公式

     ​									$d(u_0,\overline S) = \min\limits_{u\in S,v\in \overline S} \{d(u_0,u)+w(uv)\}$ 

     给出.

​     这个公式是 Dijkstra 算法的基础. 从集 $S_0=\{u_0\}$ 开始，用下述方法构造一个由$V$ 的子集组成的递增序列$S_0,S_1,\cdots,S_{v-1}$，使得在第$i$ 步结束时，由$u_0$ 到$S_i$ 的所有顶点的最短路均已知.

**tips**：这只是Dijkstra算法的思路，具体算法对此进行优化了一些不必要的重复计算。