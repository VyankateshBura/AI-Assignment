class Dog:
    #class attribute
    attr1 = "mammal"
    #Instance attribute
    def __init__(self,name,classname):
        print(f"I am Dog and my name is {name} ")
        self.attr1 = classname
    
    def classname(self):
        print(f"I belong to the {self.attr1} class")
Rocky = Dog("Rocky","mammal")
Moti = Dog("Moti","mammal")

Moti.classname()