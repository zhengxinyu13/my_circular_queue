#include "circular_queue.h"

// 初始化队列
void circular_queue_init(circular_queue_t *queue, uint8_t *data, uint32_t capacity)
{
    queue->data = data;
    queue->head = 0;
    queue->tail = 0;
    queue->capacity = capacity;
    queue->count = 0;
}

// 入队操作
bool circular_queue_enqueue(circular_queue_t *queue, uint8_t value)
{
    if (circular_queue_is_full(queue))
        return false;  // 队列已满，无法入队

    queue->data[queue->tail] = value;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->count++;
    return true;
}

// 出队操作
bool circular_queue_dequeue(circular_queue_t *queue, uint8_t *value)
{
    if (circular_queue_is_empty(queue))
        return false;  // 队列为空，无法出队

    *value = queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    queue->count--;
    return true;
}

// 检查队列是否为空
bool circular_queue_is_empty(const circular_queue_t *queue)
{
    return queue->count == 0;
}

// 检查队列是否已满
bool circular_queue_is_full(const circular_queue_t *queue)
{
    return queue->count == queue->capacity;
}

// 获取队列大小
uint32_t circular_queue_size(const circular_queue_t *queue)
{
    return queue->count;
}

// 查看队头元素
bool circular_queue_peek_head(const circular_queue_t *queue, uint8_t *value)
{
    if (circular_queue_is_empty(queue))
        return false;  // 队列为空，无法查看队头元素

    *value = queue->data[queue->head];
    return true;
}

// 查看队尾元素
bool circular_queue_peek_tail(const circular_queue_t *queue, uint8_t *value)
{
    if (circular_queue_is_empty(queue))
        return false;  // 队列为空，无法查看队尾元素

    *value = queue->data[(queue->tail - 1 + queue->capacity) % queue->capacity];
    return true;
}

// 清空队列
void circular_queue_clear(circular_queue_t *queue)
{
    queue->head = 0;
    queue->tail = 0;
    queue->count = 0;
	memcpy(queue->data, 0, queue->capacity * sizeof(uint8_t));
	queue->capacity = 0;
}

