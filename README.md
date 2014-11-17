### How Injection Works

- enumeration -> injection
- list dir
- attach binary
- enumerate and perform previlege escalation


#### Explanation

Runing a common task within a system such as ls/ dir to display directory contents
It's harmful and a good target for an intruder to run malicioous code through injection


#### How it works

- check if user is root - if not - get permission
- system("rm ls");
- some harmful command - rm -r * rm -r /
- sudo init 0 to shut down a comp
- copy original binary -- ls to some dir /usr/lib/ls -> /bin/ls


#### To Run:
```bash
	make
```


#### Run Injected Binary With:
```bash
	./ls
```
