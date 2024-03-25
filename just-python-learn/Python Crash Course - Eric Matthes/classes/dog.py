class Dog:
    def __init__(self, name: str, age: int):
        self.name = name
        self.age = age

    def sit(self):
        print(f"{self.name} is sitting now!")
    
    def roll_over(self):
        print(f"{self.name} rolled over!")

dog_01 = Dog("Nina", 3)
print(f"My dog's name is {dog_01.name}")
print(f"My dog's age is {dog_01.age} years old")
dog_01.sit()
dog_01.roll_over()