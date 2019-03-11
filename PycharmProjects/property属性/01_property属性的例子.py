class Foo(object):
    def __init__(self, num: int):
        self.__num = num

    def func(self):
        self.name = "Fool.func"
        print(self.name)

    @property
    def prop(self):
        return self.__num

    @prop.setter
    def prop(self, value):
        self.__num = value
        return self.__num


foo_obj = Foo(100)

foo_obj.func()
num = foo_obj.prop
print(num)
foo_obj.prop = 200
print(foo_obj.prop)