#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

// 定义队列结构体
typedef struct {
    uint8_t *data;         // 存储数据的数组
    uint32_t head;         // 队头索引
    uint32_t tail;         // 队尾索引
    uint32_t capacity;     // 队列容量
    uint32_t count;        // 当前队列中的元素数量
} circular_queue_t;

// 初始化队列
void circular_queue_init(circular_queue_t *queue, uint8_t *data, uint32_t capacity);

// 入队操作
bool circular_queue_enqueue(circular_queue_t *queue, uint8_t value);

// 出队操作
bool circular_queue_dequeue(circular_queue_t *queue, uint8_t *value);

// 检查队列是否为空
bool circular_queue_is_empty(const circular_queue_t *queue);

// 检查队列是否已满
bool circular_queue_is_full(const circular_queue_t *queue);

// 获取队列大小
uint32_t circular_queue_size(const circular_queue_t *queue);

// 查看队头元素
bool circular_queue_peek_head(const circular_queue_t *queue, uint8_t *value);

// 查看队尾元素
bool circular_queue_peek_tail(const circular_queue_t *queue, uint8_t *value);

// 清空队列
void circular_queue_clear(circular_queue_t *queue);

#endif // __CIRCULAR_QUEUE_H__