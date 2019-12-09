###Explanation

I have used the [CPU-plugin](https://github.com/fluent/fluent-bit-docs/blob/master/input/cpu.md) and used it to  gather the overall usage and show the information to the output.

I have created two filters for the task.

- The first filter ensures that the hostname of the server is attached to the event, so we can track where it’s coming from.

- The second filter is a lua script that appends the tag name.

The ouput points to stdout that shows the event as a JSON blob.

```
[INPUT]
    Name cpu
    Tag  my_cpu

[FILTER]
    Name          record_hostname
    Match         *
    Record hostname ${PARENT_HOSTNAME}

[FILTER]
    Name          lua
    Match         *
    script        /etc/fluent-bit/scripts/append_tag.lua
    call          append_tag

[OUTPUT]
    Name  stdout
    Format        json
    Match *

```

