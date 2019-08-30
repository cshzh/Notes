## Redis

## Redis协议

[RESP](https://redis.io/topics/protocol)(REdis Serialization Protocol)

请求-响应模式，有两类情况例外，管道(Pipeling)和(Pub/Sub)

Request: arrays of string

Reply: command-specific data type

- For **Simple Strings** the first byte of the reply is "+"
- For **Errors** the first byte of the reply is "-"
- For **Integers** the first byte of the reply is ":"
- For **Bulk Strings** the first byte of the reply is "$"
- For **Arrays** the first byte of the reply is "`*`"





