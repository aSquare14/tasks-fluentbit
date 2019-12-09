
To find out what ```flb_pack_print``` does, I went into the source code of fluent-bit and tried to understand it's implementation. It is coded in ```flb_pack.c``` file.

According to this, the ```flb_pack_print``` prints the deserialized object data which in this case is the data that is passed into the function along with it's serial number(cnt++). It will print until the data is able to be unpacked.

