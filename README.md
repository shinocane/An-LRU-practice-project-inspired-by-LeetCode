# An-LRU-practice-project-inspired-by-LeetCode
After finishing the problem Leetcode146,I made this project. It's a more detailed and practical version.And I think perhaps it could be applied somewhere like a small game needed to clear cache
# C++ LRU Cache Simulator

## 项目简介
本项目实现了一个基于 C++ 的 LRU（Least Recently Used）缓存系统，
灵感来源于 LeetCode 的经典题目，并扩展为一个可交互的小项目。

## 核心数据结构
- unordered_map：实现 O(1) 查找
- 双向链表：实现 O(1) 插入和删除

## 功能
- get / put 操作
- 自动淘汰最久未使用数据
- 缓存状态展示
- 命中率统计
- 命令行交互

## 使用方式
编译运行后输入：
put 1 10
get 1
show
stats

## 学习收获
- 理解 LRU 缓存机制
- 掌握哈希表 + 双向链表设计
- 从算法题扩展为小型项目
