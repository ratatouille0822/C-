class PropertyDemo(object):
    def __init__(self, num):
        self.__num = num

    def make_prop(self):
        return self.__num

    def add_prop(self, add: int):
        self.__num += add
        return self.__num

    def del_prop(self):
        pass

    Demo = property(make_prop, add_prop, del_prop, "This is a test")


demo = PropertyDemo(100)
num = demo.Demo
print(num)
num += 1
print(num)
print(PropertyDemo.Demo.__doc__)
