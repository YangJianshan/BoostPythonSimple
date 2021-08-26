from hello_ext import World
from hello_ext import HelloObject

def sg_1(s):
    print('==========')
    print(s)
    print('**********')


h = HelloObject()
h.using_signal_sg_1(sg_1)
h.run()

