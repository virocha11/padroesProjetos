# Fonte: site GeeksforGeeks

class Singleton(object):
    def __new__(cls):
        if not hasattr(cls, '__instance'):
            cls.__instance = super(Singleton, cls).__new__(cls)
        return cls.__instance

singleton = Singleton()
new_singleton = Singleton()

print(singleton is new_singleton)

singleton.singl_variable = "Singleton Variable"
print(new_singleton.singl_variable)
