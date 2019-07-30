官网地址：[kafka](https://kafka.apache.org/intro)

原文：[Consumer-Lag-Evaluation-Rules](https://github.com/linkedin/Burrow/wiki/Consumer-Lag-Evaluation-Rules)

# kafka

![consumer-groups.png](https://kafka.apache.org/22/images/consumer-groups.png)

> A two server Kafka cluster hosting four partitions (P0-P3) with two consumer groups. Consumer group A has two consumer instances and group B has four.

## Kafka as a Messaging System

> Messaging traditionally has two models: [queuing](http://en.wikipedia.org/wiki/Message_queue) and [publish-subscribe](http://en.wikipedia.org/wiki/Publish–subscribe_pattern). In a queue, a pool of consumers may read from a server and each record goes to one of them; in publish-subscribe the record is broadcast to all consumers. Each of these two models has a strength and a weakness. The strength of queuing is that it allows you to divide up the processing of data over multiple consumer instances, which lets you scale your processing. Unfortunately, queues aren't multi-subscriber—once one process reads the data it's gone. Publish-subscribe allows you broadcast data to multiple processes, but has no way of scaling processing since every message goes to every subscriber.
>
> The consumer group concept in Kafka generalizes these two concepts. As with a queue the consumer group allows you to divide up processing over a collection of processes (the members of the consumer group). As with publish-subscribe, Kafka allows you to broadcast messages to multiple consumer groups.

# 消费者lag评估规则

## 评估窗口

滑动窗口的长度，在 [Storage](https://github.com/linkedin/Burrow/wiki/Configuration#Storage) 中配置。默认配置为10。

## 评估规则

1. 如果一个窗口期中的lag值都为0，状态被认为是OK。
2. 如果在一个窗口期中的消费者的offset一直没变，并且lag值是固定的或者在增加，我们认为这个消费者处于ERROR 状态，这个分区被标记为STALLED。消费者仍然在提交offset。
3. 如果消费者的offset一直增加，但是lag值不变或者在增加，那么这个消费者处于WARNING状态。这说明消费者消费速度比较慢，落后了。
4. 如果当前时间与最后一次offset提交的时间的差值大于窗口中最后一次offset提交的时间与窗口中第一次offset提交的时间，这个消费者被认为处于ERROR状态，这个分区被标记为STOPPED。如果当前消费者的offset与该分区上的offset相等，我们不认为这个分区处于error。最近没有消费者提交offset。
5. 如果lag值为-1，这是一个特定值，意味着我们尚未为该分区设置broker的offset值。这只会在burrow启动时发生，这个状态也被认为是OK的。