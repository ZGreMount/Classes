#########################################################################
# File Name: Makefile.sh
# Author: zhaohuizhen 
# mail: 1534612574@qq.com 
# Created Time: 2017年09月23日 星期六 21时12分00秒
#########################################################################
#!/bin/bash
#!/bin/bash

test:*.o *.h
	cc -o test *.o *.h

*.o:*.cpp *.h
	cc -c -g *.cpp

clean:
	ls | grep -Ev "*.cpp|*.h|Makefile" | xargs rm -f;rm -f *.o Makefile.sh


