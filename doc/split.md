> 入力:"Hello!World?My,C++"

> 区切り文字 [",","!","?"]

> 期待される出力:["Hello","World","My","C++"]

```
delim = [",","!","?"]
for (string s : input)
    if (s = delim)
        hit = nowindex