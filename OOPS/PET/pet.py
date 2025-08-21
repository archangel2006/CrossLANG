# virtual pet

class Pet:
    def __init__(self,name):
        self.name = name
        self.hunger = 50
        self.happiness = 50
        self.energy = 50

    def feed(self):
        self.hunger = min(self.hunger+20, 100)
        self.happiness = min(self.happiness+5, 100)
        self.energy = min(self.energy+10,100)
        print(f"{self.name} is eating. 🍖")
    
    def play(self):
        if self.energy>10:
            self.happiness = min(self.happiness+20,100)
            self.hunger -= 5
            self.energy -= 10
            print(f"{self.name} is playing.🎾")

    def sleep(self):
        self.energy = min(self.energy+30, 100)
        self.hunger -=10
        print(f"{self.name} is sleepig.💤") 

    def tick(self):
        self.hunger = max(self.hunger-5,0)
        self.happiness = max(self.happiness-5,0)
        self.energy = max(self.energy-5,0)

    def show_status(self):
        print(f"\n--- {self.name}'s Status ---")
        print(f"Hunger: {self.hunger}")
        print(f"Happiness: {self.happiness}")
        print(f"Energy: {self.energy}")

    def is_alive(self):
        return self.hunger > 0 and self.happiness > 0 and self.energy > 0
        
def main():
    name = input("Name Your Pet : ")
    pet = Pet(name)

    while pet.is_alive():
        pet.show_status()
        print("\nChoose action: (1) Feed  (2) Play  (3) Sleep")
        choice = input("> ")

        if choice == "1":
            pet.feed()
        elif choice == "2":
            pet.play()
        elif choice == "3":
            pet.sleep()
        else:
            print("Invalid Choice!")
        
        pet.tick()
    print(f"\nOh no! {name} has passed away.🪦")

if __name__ == "__main__":
    main()

